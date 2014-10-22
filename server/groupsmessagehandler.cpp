#include "groupsmessagehandler.h"

GroupsMessageHandler::GroupsMessageHandler(WorkerCache *cache):
MessageHandlerInterface(cache)
{
}

bool GroupsMessageHandler::parseData(const QByteArray &ba)
{
    // in this message only msg type is importent, not the content of message
    Q_UNUSED(ba);
    return true;
}

bool GroupsMessageHandler::parseData(QByteArray &&ba)
{
    // in this message only msg type is importent, not the content of message
    Q_UNUSED(ba);
    return true;
}

bool GroupsMessageHandler::processData()
{
        database.getGroups(); ///TODO finish up
    return true;
}

bool GroupsMessageHandler::moveResponseToCache()
{
    m_cache.responseMessage()->addMessage(resGroups);
    return true;
}
