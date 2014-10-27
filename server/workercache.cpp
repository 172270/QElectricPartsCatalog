#include "workercache.h"

WorkerCache::WorkerCache(QSqlDatabase dbm):
    m_messageContainer(new MessagesContainer),
    userStats(new UserStatistics ),
    userData(new User),
    m_userStatus(new UserStatus),
    m_connectionStats(new ConnectionStatistics),
    database(dbm.connectionName())
{
    userStatus()->logged=false;
}

WorkerCache::~WorkerCache()
{
    delete m_userStatus;
    delete m_messageContainer;
    delete userData;
    delete userStats;
    delete m_connectionStats;
}
User *WorkerCache::getUserData() const
{
    return userData;
}

void WorkerCache::setUserData(User *value)
{
    userData = value;
}
UserStatistics *WorkerCache::getUserStats() const
{
    return userStats;
}

void WorkerCache::setUserStats(UserStatistics *value)
{
    userStats = value;
}

MessagesContainer *WorkerCache::responseMessage()
{
    return m_messageContainer;
}

void WorkerCache::setMessageContainer(MessagesContainer *messageContainer)
{
    m_messageContainer = messageContainer;
}

UserStatus *WorkerCache::userStatus() const
{
    return m_userStatus;
}
ConnectionStatistics *WorkerCache::connectionStats() const
{
    return m_connectionStats;
}
PgInterface &WorkerCache::getDatabase()
{
    return database;
}

