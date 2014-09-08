#ifndef LOGINMESSAGEHANDLER_H
#define LOGINMESSAGEHANDLER_H

#include "qcatalogserverthread.h"

#include "DB_schema/user.h"

class LoginMessageHandler : public QObject
{
    Q_OBJECT
public:
    LoginMessageHandler();

public:
    void setData(QByteArray *data);
    void processData();
    QByteArray *data;
    void extractPBMessage();
private:
    void getWorker();

    user::LoginRequest userLoginMsg;
    user::LoginResponse userLoginReplayMsg;

};

#endif // LOGINMESSAGEHANDLER_H
