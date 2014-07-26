#ifndef DATASTREAMSOURCE_H
#define DATASTREAMSOURCE_H

#include "boost/iostreams/stream.hpp"

namespace boost {
namespace iostreams {

class DataStreamSource
{
public:
    typedef char char_type;
    typedef source_tag  category;

    DataStreamSource( QDataStream * const source ) : m_source(source){
    }
    std::streamsize read(char *buffer, std::streamsize n) {
        return m_source ? m_source->readRawData(buffer, n) : -1;
    }

private:
    QDataStream * const m_source;
};
}
}

LoginMessageHandler::LoginMessageHandler()
{
}


#endif // DATASTREAMSOURCE_H
