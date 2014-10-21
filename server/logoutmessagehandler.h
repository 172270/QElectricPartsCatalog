#ifndef LOGOUTMESSAGEHANDLER_H
#define LOGOUTMESSAGEHANDLER_H

#include "messagehandlerinterface.h"
#include "messages/user.h"

class LogoutMessageHandler : public MessageHandlerInterface
{
public:
    LogoutMessageHandler(WorkerCache *cache);
    ~LogoutMessageHandler(){;}
    bool processData()
    {
        if( message.logout()){
            m_cache.userStatus()->logged = false;
            resMessage.Clear();
            resMessage.set_replay(protbuf::LogoutOk);
        }
        return true;
    }
    bool moveResponseToCache()
    {
        int size = resMessage.ByteSize();
        if (!resMessage.IsInitialized())
            return false;
        QByteArray *ba = new QByteArray(size,'\0');
        resMessage.SerializeToArray(ba->data(), size );
        m_cache.responseMessage()->addMessage(MsgType::resLogout, ba);
        return true;
     }
    bool parseData(QByteArray &&ba)
    {
        message.Clear();
        return message.ParseFromArray(ba.data(),ba.size());
    }
    bool parseData(const QByteArray &ba)
    {
        message.Clear();
        return message.ParseFromArray(ba.data(),ba.size());
    }

private:
    protbuf::LogoutRequest message;
    protbuf::LogoutResponse resMessage;
};

#endif // LOGOUTMESSAGEHANDLER_H
