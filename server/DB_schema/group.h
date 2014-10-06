#ifndef GROUP_H
#define GROUP_H

#include <QString>
#include <QValidator>
#include <QDataStream>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDateTime>

#include "group.pb.h"

class Group : public groups::Group
{
public:
    void set_name(const QString &name);
    QString getName() const;

    void setID(quint32 id);
    quint32 getID() const;

    void set_parentid( quint32 id);
    quint32 getParentID() const;

    bool setsAllowed() const;
    bool itemsAllowed() const;

    void setAllowRecipe(bool allow);
    void setAllowItems(bool allow);

    void setDescription(const QString &desc);
    QString getDescription() const;

    QMap<quint32, ::groups::Parameter> getParameters() const;

    groups::GroupBasicInformation getGroupBasicInfoPB();

    Group();

private:
};

#endif // GROUP_H
