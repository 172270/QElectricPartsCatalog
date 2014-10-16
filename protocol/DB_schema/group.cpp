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

void Group::set_creationdate(QDateTime &&dt)
{
    groups::Group::set_creationdate(dt.toMSecsSinceEpoch());
}

void Group::add_parameter(const Parameter &parameter)
{
    add_parameters()->set_id( parameter.id() );
}

QList<parameters::ParameterBasicInformation> Group::getParameters() const
{
    QList<parameters::ParameterBasicInformation> list;
    int paramNumber = parameters().size()-1;

    for(;paramNumber>=0;--paramNumber)
        list.append(parameters(paramNumber));
    return list;
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