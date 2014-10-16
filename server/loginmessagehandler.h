#ifndef LOGINMESSAGEHANDLER_H
#define LOGINMESSAGEHANDLER_H

#include "DB_schema/user.h"
#include "pginterface.h"

class LoginMessageHandler : public QObject
{
    Q_OBJECT
public:
    LoginMessageHandler(): user(new User){;}

public:
    void setData(QByteArray &&data);
    void processData();
    User *getUserData();
    QByteArray getResponse();
    bool loginOk(){ return res.replay()==user::Replay::LoginPass; }
    void updateLastLogin();
private:
    PgInterface database;
    user::LoginRequest req;
    user::LoginResponse res;
    User *user;
};

#endif // LOGINMESSAGEHANDLER_H
