#ifndef MAGAZINE_H
#define MAGAZINE_H

#include <QString>
#include <QList>
#include <QDateTime>

#include "storage.pb.h"
#include "message.h"

class Storage : public protbuf::Storage, public protocol::Message
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
    int ByteSize() const
    {
        return protbuf::Storage::ByteSize();
    }

protected:
    bool SerializeToArray(void *data, int size) const
    {
        return protbuf::Storage::SerializeToArray(data,size);
    }
    bool ParseFromArray(const void *data, int size)
    {
        return protbuf::Storage::ParseFromArray(data,size);
    }
};

#endif // MAGAZINE_H
