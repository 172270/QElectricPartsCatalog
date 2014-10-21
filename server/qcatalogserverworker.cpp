#include "qcatalogserverworker.h"


QCatalogServerWorker::QCatalogServerWorker(QSqlDatabase db, QObject *parent) :
    QObject(parent),
    workerCache(new WorkerCache(db))
{
    handlers = new QMap<MsgType, MessageHandlerInterface*>();
    handlers->insert(MsgType::reqLogin, new LoginMessageHandler(workerCache));
    handlers->insert(MsgType::addUser, new RegisterUserMessageHandler(workerCache));
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
                handlers->value(requestMessage.capsules(i).msgtype())
                        ->parseData( requestMessage.getCapsule(i).getData());
                handlers->value(requestMessage.capsules(i).msgtype())
                        ->processData();
                handlers->value(requestMessage.capsules(i).msgtype())
                        ->moveResponseToCache();
            }
            else{
                emit unknownMessageType(requestMessage.capsules(i).msgtype());
            }
        }
    }
    if(workerCache->responseMessage()->capsules().size() > 0){
        workerCache->responseMessage()->toArray(buf);
        emit responseAvalible( *buf );
    }
}
