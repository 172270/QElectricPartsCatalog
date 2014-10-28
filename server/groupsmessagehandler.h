#ifndef GROUPSMESSAGEHANDLER_H
#define GROUPSMESSAGEHANDLER_H

#include "messagehandlerinterface.h"
#include "messages/group.h"

#include <QDebug>

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
        Group group;
        group.set_name(requestMsg.getName());
        group.set_parentid(requestMsg.parentid());
        group.set_allowitems(requestMsg.allowitems());
        group.set_allowsets(requestMsg.allowsets());
        for(int i=0;i<requestMsg.parameters().size();i++){
            group.add_parameters()->CopyFrom(requestMsg.parameters(i));
        }
        try{
            database.addGroup(group);
            if(group.id() != 0){
                responseMsg.add_replay(protbuf::resAddGroup::addOk);
            }
        }
        catch (QSqlError e){
            qDebug()<<e.text();
        }

        return true;
    }
    bool moveResponseToCache()
    {
        cache().responseMessage()->addMessage(responseMsg);
        return true;
    }

private:
    RequestAddGroup requestMsg;
    ResponseAddGroup responseMsg;
};

#endif // GROUPSMESSAGEHANDLER_H
