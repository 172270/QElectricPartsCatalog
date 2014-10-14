#include "qcatalogserverthread.h"
#include "messagetype.h"
#include "loginmessagehandler.h"

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

    for(int i=0;i<requestMessage.container().size();i++){
        if(requestMessage.container(i).msgtype()== MsgType::reqLogin){
            qDebug()<<"request login";
            LoginMessageHandler handler;
            MessageCapsule mc = MessageCapsule(requestMessage.getCapsuleAsArray(i));
            handler.setData( mc.encapsulateMessage() );
            handler.processData();
            responseMessage.addMessage(MsgType::resLogin, handler.getResponse());
        }
    }
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
