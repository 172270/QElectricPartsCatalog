#ifndef MAGAZINE_H
#define MAGAZINE_H

#include <QString>
#include <QList>
#include <QDateTime>
#include "storage.pb.h"

class Storage : public protbuf::Storage
{
public:
    Storage();

    QString getName() const;
    void set_name(const QString &value);

    quint32 getID() const;
    void setID(const quint32 &value);
    bool hasID(){ return has_id();}

    QDateTime getCreationDate() const;
    void setCreationDate(const QDateTime &date);

    QByteArray *toArray();
    QByteArray *toArray(QByteArray *data);
    void fromArray(QByteArray *ba);
};

#endif // MAGAZINE_H
