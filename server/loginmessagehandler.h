#ifndef LOGINMESSAGEHANDLER_H
#define LOGINMESSAGEHANDLER_H

#include "messagehandlerinterface.h"
#include "messages/user.h"
#include "pginterface.h"

class LoginMessageHandler : public MessageHandlerInterface
{
public:
    LoginMessageHandler(WorkerCache *cache);
    ~LoginMessageHandler(){;}
    void setData(QByteArray &&data);
    QByteArray getResponse();
    bool processData();
    bool moveResponseToCache();
    bool parseData(const QByteArray &ba) override;
    bool parseData(QByteArray &&ba) override;

private:
    protbuf::LoginRequest req;
    protbuf::LoginResponse res;
    void updateLastLogin();
    bool clearCacheData();
    void getUserData();
};

#endif // LOGINMESSAGEHANDLER_H
