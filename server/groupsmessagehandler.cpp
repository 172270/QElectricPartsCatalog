#include "groupsmessagehandler.h"

GroupsMessageHandler::GroupsMessageHandler(WorkerCache *cache):
MessageHandlerInterface(cache)
{
}

bool GroupsMessageHandler::parseData(const QByteArray &ba)
{
    return reqGroups->fromArray(ba);
}

bool GroupsMessageHandler::parseData(QByteArray &&ba)
{
    return reqGroups->fromArray(ba);
}

bool GroupsMessageHandler::processData()
{
    return true;
}

bool GroupsMessageHandler::moveResponseToCache()
{
    m_cache.responseMessage()->addMessage(resGroups);
    return true;
}
