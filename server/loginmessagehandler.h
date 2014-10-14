#ifndef LOGINMESSAGEHANDLER_H
#define LOGINMESSAGEHANDLER_H

#include "DB_schema/user.h"
#include "pginterface.h"

class LoginMessageHandler : public QObject
{
    Q_OBJECT
public:
    LoginMessageHandler(){;}

public:
    void setData(QByteArray &&data);
    void processData();
    QByteArray getResponse();
private:
    PgInterface database;
    user::LoginRequest req;
    user::LoginResponse res;
};

#endif // LOGINMESSAGEHANDLER_H
