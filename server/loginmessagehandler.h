#ifndef LOGINMESSAGEHANDLER_H
#define LOGINMESSAGEHANDLER_H

#include "messages/user.h"
#include "pginterface.h"

class LoginMessageHandler : public QObject
{
    Q_OBJECT
public:
    LoginMessageHandler(QString conName):
        database(conName), user(new User){
        ;
    }
    LoginMessageHandler(QSqlDatabase db):
        database(db.connectionName()), user(new User){
        ;
    }

public:
    void setData(QByteArray &&data);
    void processData();
    User *getUserData();
    QByteArray getResponse();

    bool loginOk();
    void updateLastLogin();
private:
    PgInterface database;
    protbuf::LoginRequest req;
    protbuf::LoginResponse res;
    User *user;
};

#endif // LOGINMESSAGEHANDLER_H
