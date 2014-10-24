#ifndef LOGINMESSAGEHANDLER_H
#define LOGINMESSAGEHANDLER_H

#include "messagehandlerinterface.h"
#include "messages/user.h"
#include "messages/loginrequest.h"
#include "pginterface.h"

class LoginMessageHandler : public MessageHandlerInterface
{
public:
    LoginMessageHandler(WorkerCache *cache);
    ~LoginMessageHandler(){;}

    bool processData();
    bool moveResponseToCache();
    bool parseData(const QByteArray &ba) override;
    bool parseData(QByteArray &&ba) override;

private:
    LoginRequest req;
    protbuf::LoginResponse res;
    void updateLastLogin();
    void getUserData();
};

#endif // LOGINMESSAGEHANDLER_H
