#ifndef LOGINMESSAGEHANDLER_H
#define LOGINMESSAGEHANDLER_H

#include "qcatalogserverthread.h"

#include "user.pb.h"


class LoginMessageHandler : public QObject
{
    Q_OBJECT
public:
    LoginMessageHandler();

    // AbstractProtocolHandler interface
public:
    virtual void setData(QByteArray *data);
    virtual void processData();


    QByteArray *data;
    void extractPBMessage();

private:
    void getWorker();

    user::Login userLoginMsg;
    user::LoginReplay userLoginReplayMsg;

};

#endif // LOGINMESSAGEHANDLER_H
