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

class Group : public protocol::QMessage<protbuf::Group>
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
};

class RequestAddGroup : public protocol::QMessage<protbuf::addGroup>
{
public:
    MsgType type() const
    {
        return MsgType::addGroup;
    }
};

class ResponseAddGroup : public protocol::QMessage<protbuf::resAddGroup>
{
  public:
    MsgType type() const{
        return MsgType::resAddGroup;
    }
};

class ResponseGroup : public protocol::QMessage<protbuf::resGroups>
{
    // Message interface
public:
    MsgType type() const
    {
        return MsgType::resGroups;
    }
};

#endif // GROUP_H
