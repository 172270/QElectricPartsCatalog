#ifndef MESSAGE_H
#define MESSAGE_H

#include "types.pb.h"

#include <QByteArray>
#include <QString>
namespace protocol {

class Message
{
public:
    Message(){;}
    virtual MsgType type() const = 0;

    QByteArray toArray() const {
        int size = ByteSize();
        QByteArray ba(size ,'\0');
        SerializeToArray(ba.data(),size);
        return ba;
    }

    void toArray(QByteArray *ba) const{
        int size = ByteSize();
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
