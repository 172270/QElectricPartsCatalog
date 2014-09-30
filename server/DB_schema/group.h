#ifndef GROUP_H
#define GROUP_H

#include <QString>
#include <QValidator>
#include <QDataStream>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDateTime>

#include "group.pb.h"

class Parameter : protected groups::Parameter
{
    QString getName() const;
    void setName(const QString &name);
};

class group : protected groups::Group
{
public:
    void setName(const QString &name);
    QString getName() const;

    void setID(quint32 id);
    quint32 getID() const;

    void setParentID( quint32 id);
    quint32 getParentID() const;

    bool setsAllowed() const;
    bool itemsAllowed() const;

    void setAllowSets(bool allow);
    void setAllowItems(bool allow);

    void setDescription(const QString &desc);
    QString getDescription() const;

    QList<Parameter> getParametersList() const;

    group();

private:
};

#endif // GROUP_H
