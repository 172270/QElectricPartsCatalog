#include "group.h"

void group::setName(const QString &name)
{
    set_name(name.toStdString());
}

QString group::getName() const
{
    return QString::fromStdString(name());
}

void group::setID(quint32 id)
{
    set_id(id);
}

quint32 group::getID() const
{
    return id();
}

void group::setParentID(quint32 id)
{
    set_parentid(id);
}

quint32 group::getParentID() const
{
    return parentid();
}

bool group::setsAllowed() const
{
    return allowsets();
}

bool group::itemsAllowed() const
{
    return allowitems();
}

void group::setAllowSets(bool allow)
{
    set_allowsets(allow);
}

void group::setAllowItems(bool allow)
{
    set_allowitems(allow);
}

void group::setDescription(const QString &desc)
{
    set_description(desc.toStdString());
}

QString group::getDescription() const
{
    return QString::fromStdString(description());
}

QList<Parameter> group::getParametersList() const
{

}

group::group()
{
    set_msgtype(32);
}


QString Parameter::getName() const
{
    return QString::fromStdString(name());
}

void Parameter::setName(const QString &name)
{
    set_name(name.toStdString());
}
