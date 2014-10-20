#include "qcatalogserverworker.h"

#include "messages/messagescontainer.h"
#include "loginmessagehandler.h"
#include "registerusermessagehandler.h"

QCatalogServerWorker::QCatalogServerWorker(QObject *parent) :
    QObject(parent)
{
}

void QCatalogServerWorker::readyRead(QByteArray &ba)
{
    static QByteArray *buf  = new QByteArray();
    qDebug()<<"recived message";
    responseMessage.Clear();
    MessagesContainer requestMessage;
    requestMessage.fromArray(ba);

    for(int i=0;i<requestMessage.capsules().size();i++){
        if(requestMessage.capsules(i).msgtype()== MsgType::reqLogin){
            qDebug()<<"request login";
            LoginMessageHandler handler(getDbConnectionName());
            handler.setData( requestMessage.getCapsule(i).getData() );
            handler.processData();
            responseMessage.addMessage(MsgType::resLogin, handler.getResponse());
            if( handler.loginOk() ){
                responseMessage.addMessage(MsgType::msgUser, handler.getUserData()->toArray() );
            }
        }

        if(requestMessage.capsules(i).msgtype()== MsgType::addUser){
            qDebug()<<"request add user";
            RegisterUserMessageHandler handler(getDbConnectionName());
            handler.setData( requestMessage.getCapsule(i).getData() );
            handler.processData();
            responseMessage.addMessage(MsgType::resAddUser, handler.getResponse());
        }

        if( requestMessage.capsules(i).msgtype() == MsgType::reqLogout){
            qDebug()<<"request user logout";
        }
    }

    if(responseMessage.capsules().size() > 0){
        responseMessage.toArray(buf);
        emit responseAvalible( buf );
    }
}
QString QCatalogServerWorker::getDbConnectionName() const
{
    return dbConnectionName;
}

void QCatalogServerWorker::setDbConnectionName(const QString &value)
{
    dbConnectionName = value;
}

