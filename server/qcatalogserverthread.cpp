#include "qcatalogserverthread.h"
#include "messagetype.h"
#include "loginmessagehandler.h"
#include "registerusermessagehandler.h"



QCatalogServerThread::QCatalogServerThread(QWebSocket *s, QObject *parent) :
    QThread(parent)
{
    static int id = 0;
    dbConnectionName = QString::number(id++);
    worker = new QCatalogServerWorker();

    socket = s;
    userIsLogged = false;

    db = new QSqlDatabase(QSqlDatabase::addDatabase("QPSQL", dbConnectionName));
    db->setDatabaseName("ekatalog_tests"); /// TODO change to QSettings
    db->setHostName("localhost");
    db->setUserName("postgres");
    db->setPassword("postgres");

    if (!db->open()){
        QString dbNotOpen = "database can't be opened!!";
        throw dbNotOpen ;
    }
}

QCatalogServerThread::~QCatalogServerThread()
{
}

void QCatalogServerThread::readyRead(QByteArray ba)
{
    qDebug()<<"recived message";
    MessagesContainer requestMessage, responseMessage;
    requestMessage.fromArray(ba);

    for(int i=0;i<requestMessage.capsules().size();i++){
        if(requestMessage.capsules(i).msgtype()== MsgType::reqLogin){
            qDebug()<<"request login";
            LoginMessageHandler handler(dbConnectionName);
            handler.setData( requestMessage.getCapsule(i).getData() );
            handler.processData();
            responseMessage.addMessage(MsgType::resLogin, handler.getResponse());
            if( handler.loginOk() ){
                responseMessage.addMessage(MsgType::msgUser, handler.getUserData()->toArray() );
                userIsLogged = true;
            }
        }

        if(requestMessage.capsules(i).msgtype()== MsgType::addUser){
            qDebug()<<"request add user";
            RegisterUserMessageHandler handler(dbConnectionName);
            handler.setData( requestMessage.getCapsule(i).getData() );
            handler.processData();
            responseMessage.addMessage(MsgType::resAddUser, handler.getResponse());
        }

        if( requestMessage.capsules(i).msgtype() == MsgType::reqLogout){
            qDebug()<<"request user logout";
            userIsLogged = false;
        }

    }

    if(responseMessage.capsules_size()>0)
        socket->sendBinaryMessage(responseMessage.toArray() );
}

void QCatalogServerThread::disconnected()
{
    socket->deleteLater();
    QString connection = db->connectionName();
    db->close();
    delete db;
    QSqlDatabase::removeDatabase(connection);
    exit(0);
}

void QCatalogServerThread::run()
{
    qDebug() << " Thread: "<< this->currentThreadId() << "started with stack size set to" << this->stackSize() ;

    connect(socket, SIGNAL(binaryMessageReceived(QByteArray)), this, SLOT(readyRead(QByteArray)), Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));

    exec();
}
