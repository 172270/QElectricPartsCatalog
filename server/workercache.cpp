#include "workercache.h"

WorkerCache::WorkerCache(QSqlDatabase dbm):
    m_messageContainer(new MessagesContainer),
    userStats(new UserStatistics ),
    userData(new User),
    m_userStatus(new UserStatus)
{
    db = dbm;
    userStatus()->logged=false;
}

WorkerCache::~WorkerCache()
{
    delete m_userStatus;
    delete m_messageContainer;
    delete userData;
    delete userStats;
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
const QSqlDatabase &WorkerCache::getDb()
{
    return db;
}

void WorkerCache::setDb(const QSqlDatabase &value)
{
    db = value;
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






