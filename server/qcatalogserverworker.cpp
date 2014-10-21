#include "qcatalogserverworker.h"

#include "loginmessagehandler.h"
#include "logoutmessagehandler.h"
#include "registerusermessagehandler.h"

QCatalogServerWorker::QCatalogServerWorker(QSqlDatabase db, QObject *parent) :
    QObject(parent),
    workerCache(new WorkerCache(db))
{
    handlers = new QMap<MsgType, MessageHandlerInterface*>();
    handlers->insert(MsgType::reqLogin, new LoginMessageHandler(workerCache));
    handlers->insert(MsgType::addUser, new RegisterUserMessageHandler(workerCache));
    handlers->insert(MsgType::reqLogout, new LogoutMessageHandler(workerCache));
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
}

void QCatalogServerWorker::readyRead(const QByteArray &ba)
{
    workerCache->connectionStats()->bytesRead += ba.size();
    static QByteArray *buf  = new QByteArray();
    workerCache->responseMessage()->Clear();
    static MessagesContainer requestMessage;
    requestMessage.Clear();

    if(!requestMessage.fromArray(ba)){
        emit messageCorrupted();
    }
    else{
        for(int i=0;i<requestMessage.capsules().size();i++){
            if(handlers->contains(requestMessage.capsules(i).msgtype())){
                MessageHandlerInterface *handler = handlers->value(requestMessage.capsules(i).msgtype());

                if (! handler->parseData( requestMessage.getCapsule(i).getData())){
                    emit messageCorrupted();
                    continue;
                }
                handler->processData();
                handler->moveResponseToCache();
            }
            else{
                emit unknownMessageType(requestMessage.capsules(i).msgtype());
            }
        }
    }
    if(workerCache->responseMessage()->capsules().size() > 0){
        workerCache->responseMessage()->toArray(buf);
        workerCache->connectionStats()->bytesWrite += buf->size();
        emit responseAvalible( *buf );
    }
}
