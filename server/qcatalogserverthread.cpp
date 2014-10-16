#include "qcatalogserverthread.h"
#include "messagetype.h"
#include "loginmessagehandler.h"
#include "registerusermessagehandler.h"

#include "messages/messagescontainer.h"



QCatalogServerThread::QCatalogServerThread(QWebSocket *s, QObject *parent) :
    QThread(parent)
{
    static int databaseDescription = 0;
    socket = s;

    db = new QSqlDatabase(QSqlDatabase::cloneDatabase(QSqlDatabase::database(), QString::number(databaseDescription++)));
    if (!db->open()){
        QString dbNotOpen = "database can't be opened!!";
        throw dbNotOpen ;
    }
    query = new QSqlQuery();
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
            LoginMessageHandler handler;
            handler.setData( requestMessage.getCapsule(i).getData() );
            handler.processData();
            responseMessage.addMessage(MsgType::resLogin, handler.getResponse());
            if( handler.loginOk() )
                responseMessage.addMessage(MsgType::msgUser, handler.getUserData()->toArray() );
        }

        if(requestMessage.capsules(i).msgtype()== MsgType::addUser){
            qDebug()<<"request add user";
            RegisterUserMessageHandler handler;
            handler.setData( requestMessage.getCapsule(i).getData() );
            handler.processData();
            responseMessage.addMessage(MsgType::resAddUser, handler.getResponse());
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
    delete query;

    QSqlDatabase::removeDatabase(connection);
    exit(0);
}

void QCatalogServerThread::run()
{
    qDebug() << " Thread started";

    connect(socket, SIGNAL(binaryMessageReceived(QByteArray)), this, SLOT(readyRead(QByteArray)), Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));

    exec();
}
