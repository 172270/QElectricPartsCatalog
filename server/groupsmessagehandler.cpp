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
    ///TODO server shoud replay with "not login" message
    /// when user is not login :)

    if( m_cache.userStatus()->logged ){
        database.getGroups();
    }
    return true;
}

bool GroupsMessageHandler::moveResponseToCache()
{
    m_cache.responseMessage()->addMessage(resGroups);
    return true;
}
