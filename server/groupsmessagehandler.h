#ifndef GROUPSMESSAGEHANDLER_H
#define GROUPSMESSAGEHANDLER_H

#include "messagehandlerinterface.h"
#include "messages/group.h"

class GetGroupsMessageHandler : public MessageHandlerInterface
{
public:
    GetGroupsMessageHandler(WorkerCache *cache);
    ~GetGroupsMessageHandler(){;}

    bool parseData(const QByteArray &ba) override;
    bool parseData(QByteArray &&ba) override;
    bool processData();
    bool moveResponseToCache();

private:
    ResponseGroup *resGroups;
};

class AddGroupMessageHandler : public MessageHandlerInterface
{
public:
    AddGroupMessageHandler(WorkerCache *cache);

    bool parseData(const QByteArray &ba){
        requestMsg.Clear();
        responseMsg.Clear();

        return requestMsg.fromArray(ba);
    }

    bool parseData(QByteArray &&ba){
        requestMsg.Clear();
        responseMsg.Clear();

        return requestMsg.fromArray(ba);
    }

    bool processData()
    {
        return true;
    }
    bool moveResponseToCache()
    {
        return true;
    }

private:
    RequestAddGroup requestMsg;
    ResponseAddGroup responseMsg;
};

#endif // GROUPSMESSAGEHANDLER_H
