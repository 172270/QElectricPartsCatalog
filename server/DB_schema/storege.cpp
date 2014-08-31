#include "storage.h"

Storage::Storage()
{
    set_msgtype(16);
}

QString Storage::getName() const
{
    return QString::fromStdString(name() );
}

void Storage::setName(const QString &value)
{
    set_name(value.toStdString());
}
quint32 Storage::getID() const
{
    return id();
}

void Storage::setID(const quint32 &value)
{
    set_id(value);
}


