#ifndef MESSAGE_H
#define MESSAGE_H

#include "types.pb.h"
#include <type_traits>
#include <QByteArray>
#include <QString>
namespace protocol {

template <class baseClass>
class QMessage : public baseClass
{
public:
    virtual MsgType type() const = 0;

    QByteArray toArray(){
        beforeToArray();
        int size = baseClass::ByteSize();
        QByteArray ba(size ,'\0');
        baseClass::SerializeToArray(ba.data(),size);
        return ba;
    }

    template<class data>
    void toArray(data *ba){
        beforeToArray();
        int size = baseClass::ByteSize();
        ba->resize( size );
        baseClass::SerializeToArray(ba->data(),ba->size());
    }

    template <class array> bool fromArray( array ba){
        bool ret = baseClass::ParseFromArray(ba.data(), ba.size());
        afterFromArray();
        return ret;
    }

    template <class array> bool fromArray( array *ba){
        bool ret = baseClass::ParseFromArray(ba->data(), ba->size());
        afterFromArray();
        return ret;
    }
private:
    virtual void afterFromArray(){;}
    virtual void beforeToArray(){;}
};

}
#endif // MESSAGE_H
