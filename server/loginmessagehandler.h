#ifndef LOGINMESSAGEHANDLER_H
#define LOGINMESSAGEHANDLER_H

#include "abstractprotocolhandler.h"

#include "user.pb.h"


class LoginMessageHandler : public AbstractProtocolHandler
{
public:
    LoginMessageHandler();

    // AbstractProtocolHandler interface
public:
    virtual void setData(QByteArray *data);
    virtual void processData();


    QByteArray *data;
    user::Login extractPBMessage();
};

#endif // LOGINMESSAGEHANDLER_H
