#pragma once

/**
 * @brief The WorkerCache class contains data that can be reached by
 * all message handlers
 */
#include "messages/user.h"
#include "messages/messagescontainer.h"
#include "pginterface.h"

struct UserStatus{
    bool logged;
};

struct ConnectionStatistics{
    ConnectionStatistics(){
        bytesRead = 0;
        bytesWrite = 0;
    }

    unsigned int bytesRead;
    unsigned int bytesWrite;
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
    ConnectionStatistics *connectionStats() const;

    PgInterface& getDatabase();
private:

    MessagesContainer *m_messageContainer;
    UserStatistics *userStats;
    User *userData;
    UserStatus *m_userStatus;
    ConnectionStatistics *m_connectionStats;
    PgInterface database;
};

