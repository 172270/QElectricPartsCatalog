#ifndef MESSAGE_H
#define MESSAGE_H

#include "types.pb.h"

#include <QByteArray>

namespace protocol {

class Message
{
public:
    Message(){;}
    virtual MsgType type() const = 0;

    QByteArray toArray() const {
        QByteArray ba;
        ba.resize( ByteSize() );
        SerializeToArray(ba.data(),ba.size());
        return ba;
    }

    void toArray(QByteArray *ba) const{
        int size = ByteSize();
        if(ba->size() < size)
            ba->resize( size );
        SerializeToArray(ba->data(),ba->size());
    }

    bool fromArray(const QByteArray *ba){
        return ParseFromArray(ba->constData(), ba->size());
    }

    bool fromArray( QByteArray &&ba){
        return ParseFromArray(ba.constData(), ba.size());
    }

    bool fromArray(const QByteArray &ba ){
        return ParseFromArray(ba.constData(), ba.size());
    }

    virtual int ByteSize() const = 0;

protected:
    virtual bool SerializeToArray(void* data, int size) const = 0;
    virtual bool ParseFromArray(const void* data, int size) = 0;
};
}
#endif // MESSAGE_H
