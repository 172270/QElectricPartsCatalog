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
    bool hasName(){ return has_name(); }

    quint32 getID() const;
    void setID(const quint32 &value);
    bool hasID(){ return has_id();}

    QDateTime getCreationDate() const;
    void setCreationDate(const QDateTime &date);
    bool hasCreationDate() const;

    QByteArray *toArray();
    QByteArray *toArray(QByteArray *data);
    void fromArray(QByteArray *ba);
};

#endif // MAGAZINE_H
