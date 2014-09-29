#ifndef MAGAZINE_H
#define MAGAZINE_H

#include <QString>
#include <QList>
#include <QDateTime>
#include "storage.pb.h"

class Storage : public storage::Storage
{
public:
    Storage();

    QString getName() const;
    void setName(const QString &value);

    quint32 getID() const;
    void setID(const quint32 &value);

    QDateTime getCreationDate() const;
    void setCreationDate(const QDateTime &date);
};

#endif // MAGAZINE_H
