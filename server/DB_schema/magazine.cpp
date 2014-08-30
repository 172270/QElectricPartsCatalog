#include "magazine.h"

Magazine::Magazine()
{
    ID = 1;
}

QString Magazine::getName() const
{
    return name;
}

void Magazine::setName(const QString &value)
{
    name = value;
}
quint32 Magazine::getID() const
{
    return ID;
}

void Magazine::setID(const quint32 &value)
{
    ID = value;
}


