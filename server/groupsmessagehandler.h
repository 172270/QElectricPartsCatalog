#ifndef GROUPSMESSAGEHANDLER_H
#define GROUPSMESSAGEHANDLER_H

#include "messagehandlerinterface.h"
#include "messages/group.h"

class GroupsMessageHandler : public MessageHandlerInterface
{
public:
    GroupsMessageHandler(WorkerCache *cache);
    ~GroupsMessageHandler(){;}

    bool parseData(const QByteArray &ba) override;
    bool parseData(QByteArray &&ba) override;
    bool processData();
    bool moveResponseToCache();

private:
    ResponseGroup *resGroups;
};

#endif // GROUPSMESSAGEHANDLER_H
