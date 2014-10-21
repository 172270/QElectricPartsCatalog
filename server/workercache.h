#pragma once

/**
 * @brief The WorkerCache class contains data that can be reached by
 * all message handlers
 */
#include "messages/user.h"
#include "messages/messagescontainer.h"
#include "QSqlDatabase"

struct UserStatus{
    bool logged;
};

class WorkerCache
{
public:
    WorkerCache(QSqlDatabase db);
    ~WorkerCache();

    User *getUserData() const;
    void setUserData(User *value);

    UserStatistics *getUserStats() const;
    void setUserStats(UserStatistics *value);

    const QSqlDatabase &getDb();
    void setDb(const QSqlDatabase &value);

    MessagesContainer *responseMessage();
    void setMessageContainer(MessagesContainer *responseMessage);

    UserStatus *userStatus() const;

private:
    QSqlDatabase db;

    MessagesContainer *m_messageContainer;
    UserStatistics *userStats;
    User *userData;
    UserStatus *m_userStatus;
};

