#ifndef GROUP_H
#define GROUP_H

#include <QString>
#include <QDataStream>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDateTime>

#include "group.pb.h"
#include "parameter.h"
#include "message.h"

class Group : public protbuf::Group, public protocol::Message
{
public:
    void set_name(const QString &name);
    QString getName() const;

    void setID(quint32 id);
    quint32 getID() const;

    quint32 getParentID() const;

    bool setsAllowed() const;
    bool itemsAllowed() const;

    void setAllowRecipe(bool allow);
    void setAllowItems(bool allow);

    void set_description(const QString &desc);
    QString getDescription() const;

    void set_creationdate(QDateTime &&dt);

    void add_parameter(const Parameter &parameter);
    QList<protbuf::ParameterBasicInformation> getParameters() const;

    protbuf::GroupBasicInformation getGroupBasicInfoPB();
    Group();
private:

    // Message interface
public:
    MsgType type() const
    {
        return MsgType::msgGroup;
    }
    int ByteSize() const
    {
        return protbuf::Group::ByteSize();
    }

protected:
    bool SerializeToArray(void *data, int size) const
    {
        return protbuf::Group::SerializeToArray(data,size);
    }
    bool ParseFromArray(const void *data, int size)
    {
        return protbuf::Group::ParseFromArray(data,size);
    }
};


class RequestGroup : public protbuf::reqGroups, public protocol::Message
{
    // Message interface
public:
    MsgType type() const
    {
        return MsgType::reqGroups;
    }
    int ByteSize() const
    {
        return protbuf::reqGroups::ByteSize();
    }

protected:
    bool SerializeToArray(void *data, int size) const
    {
        return protbuf::reqGroups::SerializeToArray(data,size);
    }
    bool ParseFromArray(const void *data, int size)
    {
        return protbuf::reqGroups::ParseFromArray(data,size);
    }
};

class ResponseGroup : public protbuf::resGroups, public protocol::Message
{
    // Message interface
public:
    MsgType type() const
    {
        return MsgType::resGroups;
    }
    int ByteSize() const
    {
        return protbuf::resGroups::ByteSize();
    }

protected:
    bool SerializeToArray(void *data, int size) const
    {
        return protbuf::resGroups::SerializeToArray(data,size);
    }
    bool ParseFromArray(const void *data, int size)
    {
        return protbuf::resGroups::ParseFromArray(data,size);
    }
};

#endif // GROUP_H
