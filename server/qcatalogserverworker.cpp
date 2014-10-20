#include "qcatalogserverworker.h"


QCatalogServerWorker::QCatalogServerWorker(QSqlDatabase db, QObject *parent) :
    QObject(parent), userRegisterHandler(db), loginHandler(db)
{
}

void QCatalogServerWorker::readyRead(const QByteArray &ba)
{
    static QByteArray *buf  = new QByteArray();
    responseMessage.Clear();
    MessagesContainer requestMessage;
    if(!requestMessage.fromArray(ba)){
        emit messageCorrupted();
    }
    else{
        for(int i=0;i<requestMessage.capsules().size();i++){
            if(requestMessage.capsules(i).msgtype()== MsgType::reqLogin){
                loginHandler.setData( requestMessage.getCapsule(i).getData() );
                loginHandler.processData();
                responseMessage.addMessage(MsgType::resLogin, loginHandler.getResponse());
                if( loginHandler.loginOk() ){
                    responseMessage.addMessage(MsgType::msgUser, loginHandler.getUserData()->toArray() );
                }
            }
            else if(requestMessage.capsules(i).msgtype()== MsgType::addUser){
                userRegisterHandler.setData( requestMessage.getCapsule(i).getData() );
                userRegisterHandler.processData();
                responseMessage.addMessage(MsgType::resAddUser, userRegisterHandler.getResponse());
            }
            else if( requestMessage.capsules(i).msgtype() == MsgType::reqLogout){
            }
            else{
                emit unknownMessageType(requestMessage.capsules(i).msgtype());
            }
        }
    }
    if(responseMessage.capsules().size() > 0){
        responseMessage.toArray(buf);
        emit responseAvalible( *buf );
    }
}
