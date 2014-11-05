#include "groupsmessagehandler.h"

GetGroupsMessageHandler::GetGroupsMessageHandler(WorkerCache *cache):
MessageHandlerInterface(cache)
{
}

bool GetGroupsMessageHandler::parseData(const QByteArray &ba)
{
    // in this message only msg type is importent, not the content of message
    Q_UNUSED(ba);
    return true;
}

bool GetGroupsMessageHandler::processData()
{
    database.getGroups(); ///TODO finish up
    return true;
}

bool GetGroupsMessageHandler::moveResponseToCache()
{
    m_cache.responseMessage()->addMessage(resGroups);
    return true;
}


AddGroupMessageHandler::AddGroupMessageHandler(WorkerCache *cache):
    MessageHandlerInterface(cache)
{

}
