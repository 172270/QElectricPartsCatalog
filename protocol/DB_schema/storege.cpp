#include "storage.h"

#include <QDataStream>
#include "boost/iostreams/stream.hpp"

namespace boost {
namespace iostreams {

class DataStreamSource
{
public:
    typedef char char_type;
    typedef source_tag  category;

    DataStreamSource( QDataStream *const source ) : m_source(source){
    }
    std::streamsize read(char* buffer, std::streamsize n) {
        return m_source ? m_source->readRawData(buffer, n) : -1;
    }
private:
    QDataStream *const m_source;
};
}
}

Storage::Storage()
{
    setID(0);
}

QString Storage::getName() const
{
    return QString::fromStdString(name() );
}

void Storage::set_name(const QString &value)
{
    storage::Storage::set_name(value.trimmed().toStdString());
}

quint32 Storage::getID() const
{
    return id();
}

void Storage::setID(const quint32 &value)
{
    set_id(value);
}

QDateTime Storage::getCreationDate() const
{
    return QDateTime::fromMSecsSinceEpoch(creationdate());
}

void Storage::setCreationDate(const QDateTime &date)
{
    set_creationdate(date.toMSecsSinceEpoch());
}

QByteArray *Storage::toArray()
{
    if (!IsInitialized()){
        throw QString("Uninitialized message!");
    }

    QByteArray *data = new QByteArray(ByteSize(),'\0' );
    SerializeToArray(data->data(),data->size());

    return data;
}

QByteArray *Storage::toArray( QByteArray *data)
{
    if (!IsInitialized()){
        throw QString("Uninitialized message!");
    }
    if(data->size()< ByteSize() )
        data->resize(ByteSize());

    SerializeToArray(data->data(),data->size());
    return data;
}

void Storage::fromArray(QByteArray *ba)
{
    //    QDataStream *ds = new QDataStream(ba,QIODevice::ReadWrite );
    //    boost::iostreams::stream <boost::iostreams::DataStreamSource > dataStream ( ds );
    //    ParseFromIstream(&dataStream);
    //    delete ds;
    ParseFromArray(ba->data(), ba->size());
}


