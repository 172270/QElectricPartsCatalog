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
    ///TODO server shoud replay with "not login" message
    /// when user is not login :)

    if( m_cache.userStatus()->logged ){
        database.getGroup();
    }
    return true;
}

bool GroupsMessageHandler::moveResponseToCache()
{
    m_cache.responseMessage()->addMessage(resGroups);
    return true;
}
