#include "storage.h"

Storage::Storage()
{
    setID(0);
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

QDateTime Storage::getCreationDate() const
{
    return QDateTime::fromMSecsSinceEpoch(creationdate());
}

void Storage::setCreationDate(const QDateTime &date)
{
     set_creationdate(date.toMSecsSinceEpoch());
}


