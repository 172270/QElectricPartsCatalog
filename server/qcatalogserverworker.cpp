#include "qcatalogserverworker.h"

#include "messages/messagescontainer.h"
#include "loginmessagehandler.h"
#include "registerusermessagehandler.h"

QCatalogServerWorker::QCatalogServerWorker(QObject *parent) :
    QObject(parent)
{
}

void QCatalogServerWorker::readyRead(QByteArray ba)
{
    qDebug()<<"recived message";
    responseMessage.Clear();
    MessagesContainer requestMessage;
    requestMessage.fromArray(ba);

//    for(int i=0;i<requestMessage.capsules().size();i++){
//        if(requestMessage.capsules(i).msgtype()== MsgType::reqLogin){
//            qDebug()<<"request login";
//            LoginMessageHandler handler;
//            handler.setData( requestMessage.getCapsule(i).getData() );
//            handler.processData();
//            responseMessage.addMessage(MsgType::resLogin, handler.getResponse());
//            if( handler.loginOk() ){
//                responseMessage.addMessage(MsgType::msgUser, handler.getUserData()->toArray() );
////                userIsLogged = true;
//            }
//        }

//        if(requestMessage.capsules(i).msgtype()== MsgType::addUser){
//            qDebug()<<"request add user";
//            RegisterUserMessageHandler handler;
//            handler.setData( requestMessage.getCapsule(i).getData() );
//            handler.processData();
//            responseMessage.addMessage(MsgType::resAddUser, handler.getResponse());
//        }

//        if( requestMessage.capsules(i).msgtype() == MsgType::reqLogout){
//            qDebug()<<"request user logout";
////            userIsLogged = false;
//        }


}
