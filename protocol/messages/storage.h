#ifndef MAGAZINE_H
#define MAGAZINE_H

#include <QString>
#include <QList>
#include <QDateTime>

#include "storage.pb.h"
#include "message.h"

class Storage : public protocol::QMessage<protbuf::Storage>
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

public:
    MsgType type() const
    {
        return MsgType::msgStorage;
    }
};

#endif // MAGAZINE_H
