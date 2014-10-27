#include "qcatalogserverworker.h"

#include "loginmessagehandler.h"
#include "logoutmessagehandler.h"
#include "registerusermessagehandler.h"
#include "parametershandler.h"

QCatalogServerWorker::QCatalogServerWorker(QSqlDatabase db, QObject *parent) :
    QObject(parent),
    workerCache(new WorkerCache(db))
{
    buf  = new QByteArray();
    handlers = new QMap<MsgType, MessageHandlerInterface*>();
    handlers->insert(MsgType::reqLogin, new LoginMessageHandler(workerCache));
    handlers->insert(MsgType::addUser, new RegisterUserMessageHandler(workerCache));
    handlers->insert(MsgType::reqLogout, new LogoutMessageHandler(workerCache));
    handlers->insert(MsgType::addParameter, new AddParameterHandler(workerCache));
}

QCatalogServerWorker::~QCatalogServerWorker()
{
    QList<MsgType> kays = handlers->keys();
    for(int i =0;i<kays.size();i++){
        MessageHandlerInterface *h = handlers->value(kays.at(i));
        handlers->remove(kays.at(i));
        delete h;
    }
    delete handlers;
    delete workerCache;
    delete buf;
}

void QCatalogServerWorker::readyRead(const QByteArray &ba)
{
    workerCache->connectionStats()->bytesRead += ba.size();
    workerCache->responseMessage()->Clear();
    MessagesContainer requestMessage;
    requestMessage.Clear();

    if(!requestMessage.fromArray(ba)){
        emit messageCorrupted();
    }
    else
    {
        if(workerCache->userStatus()->logged)
        {
            for(int i=0;i<requestMessage.capsules().size();i++)
            {
                MsgType type = requestMessage.capsules(i).msgtype();
                if(handlers->contains(type))
                {
                    MessageHandlerInterface *handler = handlers->value(requestMessage.capsules(i).msgtype());

                    if (! handler->parseData( requestMessage.getCapsule(i).getData()))
                    {
                        emit messageCorrupted();
                        continue;
                    }
                    handler->processData();
                    handler->moveResponseToCache();
                }
                else
                {
                    emit unknownMessageType(requestMessage.capsules(i).msgtype());
                }
            }
        }
        else
        {
            // user is not logged in
            MsgType type = requestMessage.capsules(0).msgtype();
            if(type != MsgType::reqLogin && type != MsgType::addUser ){
                workerCache->responseMessage()->addMessage(MsgType::msgUserNotLogged, QByteArray() );
            }
            else{
                MessageHandlerInterface *handler = handlers->value(requestMessage.capsules(0).msgtype());
                if (! handler->parseData( requestMessage.getCapsule(0).getData())){
                    emit messageCorrupted();
                }
                handler->processData();
                handler->moveResponseToCache();
            }
        }
    }
    if(workerCache->responseMessage()->capsules().size() > 0){
        workerCache->responseMessage()->toArray(buf);
        workerCache->connectionStats()->bytesWrite += buf->size();
        emit responseAvalible( *buf );
    }
}
