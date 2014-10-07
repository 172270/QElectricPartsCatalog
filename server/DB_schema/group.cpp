#include "group.h"

void Group::set_name(const QString &name)
{
    groups::Group::set_name(name.toStdString());
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

void Group::set_parentid(quint32 id)
{
    groups::Group::set_parentid(id);
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

void Group::set_description(const QString &desc)
{
    groups::Group::set_description(desc.toStdString());
}

QString Group::getDescription() const
{
    return QString::fromStdString(description());
}

QMap<quint32, parameters::ParameterBasicInformation> Group::getParameters() const
{
    QMap<quint32, parameters::ParameterBasicInformation> map;
    int paramNumber = parameters().size()-1;

    for(;paramNumber>0;--paramNumber){
        map.insert(parameters(paramNumber).id(), parameters(paramNumber));
    }
    return map;
}

groups::GroupBasicInformation Group::getGroupBasicInfoPB(){
    groups::GroupBasicInformation gbi;
    gbi.set_id(id());
    return gbi;
}

Group::Group()
{
    set_id(0);
}
