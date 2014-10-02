#include "item.h"

void Item::setID(quint32 id)
{
    set_id(id);
}

quint32 Item::getID() const
{
    return id();
}

void Item::setName(const QString &name)
{
    set_name(name.toStdString());
}

QString Item::getName() const
{
    return QString::fromStdString(name());
}

void Item::setSymbol(const QString &symbol)
{
    set_symbol(symbol.toStdString());
}

QString Item::getSymbol() const
{
    return QString::fromStdString(symbol());
}

void Item::setNamespace(const QString &space)
{
    set_namespace_(space.toStdString());
}

QString Item::getNamespace() const
{
    return QString::fromStdString(namespace_());
}

void Item::setAddDate(QDateTime &dt)
{
    set_adddate(dt.toMSecsSinceEpoch());
}

QDateTime Item::getAddDate() const
{
    return QDateTime::fromMSecsSinceEpoch(adddate());
}

void Item::setIsPrivate(bool isPrivate)
{
    set_privateitem(isPrivate);
}

bool Item::isPrivate()
{
    return privateitem();
}

void Item::setPackage(const Package &package)
{
//    package_
}

Item::Item()
{
}
