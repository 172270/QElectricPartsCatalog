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

    user::Login userLoginMsg;
    user::LoginReplay userLoginReplayMsg;

};

#endif // LOGINMESSAGEHANDLER_H
