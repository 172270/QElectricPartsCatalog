#include "group.h"

void Group::setName(const QString &name)
{
    set_name(name.toStdString());
}

QString Group::getName() const
{
    return QString::fromStdString(name());
}

void Group::setID(quint32 id)
{
    set_id(id);
}

quint32 Group::getID() const
{
    return id();
}

void Group::setParentID(quint32 id)
{
    set_parentid(id);
}

quint32 Group::getParentID() const
{
    return parentid();
}

bool Group::setsAllowed() const
{
    return allowsets();
}

bool Group::itemsAllowed() const
{
    return allowitems();
}

void Group::setAllowRecipe(bool allow)
{
    set_allowsets(allow);
}

void Group::setAllowItems(bool allow)
{
    set_allowitems(allow);
}

void Group::setDescription(const QString &desc)
{
    set_description(desc.toStdString());
}

QString Group::getDescription() const
{
    return QString::fromStdString(description());
}

QList<Parameter> Group::getParametersList() const
{

}

groups::Group Group::getPBPackage()
{
     return static_cast<groups::Group>(*this);
}

Group::Group()
{
}


QString Parameter::getName() const
{
    return QString::fromStdString(name());
}

void Parameter::setName(const QString &name)
{
    set_name(name.toStdString());
}
