#ifndef GROUP_H
#define GROUP_H

#include <QString>
#include <QDataStream>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDateTime>

#include "group.pb.h"
#include "DB_schema/parameter.h"

class Group : public groups::Group
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
    QList<parameters::ParameterBasicInformation> getParameters() const;

    groups::GroupBasicInformation getGroupBasicInfoPB();
    Group();
private:
};

#endif // GROUP_H
