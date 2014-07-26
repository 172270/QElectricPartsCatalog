#include "loginmessagehandler.h"

#include "protocol.h"

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

LoginMessageHandler::LoginMessageHandler()
{
}


void LoginMessageHandler::setData(QByteArray *d)
{
    data = d;
}

user::Login LoginMessageHandler::extractPBMessage()
{
    QDataStream *ds = new QDataStream(*data);
    user::Login ua;
    boost::iostreams::stream < boost::iostreams::DataStreamSource > dataStream ( ds );
    ua.ParseFromIstream(&dataStream);
}

void LoginMessageHandler::processData()
{
    /// TODO use HASH for password

    user::Login ua = extractPBMessage();


    user::LoginReplay replay;
    QString q;

    replay.set_msgtype(14);
    //    qDebug()<< " User " << QString::fromStdString(ua.name()) << " require login! ";
    /// TODO use prepared statements

    q.append("SELECT id, password from USERS where name = '" + QString::fromStdString(ua.name()) + "';");

//    qDebug() << q;

    if (isLogged){
        replay.set_replay(user::USER_ALREADY_LOGGED_IN);
    }
    else {
        if ( !query->exec(q) ){
            qDebug()<< query->lastError().text();
            replay.set_replay(user::BAD_USER_OR_PASSWD);
        }
        else{
            if (!query->first()){
                qDebug()<< "No souch user in database";
                replay.set_replay(user::BAD_USER_OR_PASSWD);
            }
            else
            {
                if( !query->value("password").toString().compare( QString::fromStdString(ua.password() ))){
                    qDebug()<< "LOGIN OK!";
                    replay.set_replay( user::LOGIN_OK );
                    user.ID = query->value("id").toInt();
                    user.name = QString::fromStdString(ua.name());
                    isLogged = true;
                }
                else
                {
                    qDebug()<< "password incorect";
                    replay.set_replay(user::BAD_USER_OR_PASSWD);
                }
            }
        }
    }

    QByteArray ba = QByteArray(replay.ByteSize(),'\0');
    replay.SerializeToArray(ba.data(),ba.size());

    socket->write(ba);
}
