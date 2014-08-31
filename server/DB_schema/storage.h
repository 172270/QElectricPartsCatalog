#ifndef MAGAZINE_H
#define MAGAZINE_H

#include <QString>
#include "storage.pb.h"

class Storage : public storage::Storage
{
public:
    Storage();

    QString getName() const;
    void setName(const QString &value);

    quint32 getID() const;
    void setID(const quint32 &value);

};

#endif // MAGAZINE_H
