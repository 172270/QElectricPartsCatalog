#include "protocol.h"

#include "boost/iostreams/stream.hpp"
#include <QDataStream>

#include "msgConstc.h"

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

Protocol::Protocol(QTcpSocket *s)
{
    socket = s;
}

QByteArray Protocol::getLoginPB(QString name, QString pass)
{
    user::Login package;
    package.set_msgtype(MSG_LOGIN_ID);
    package.set_name(name.toStdString());
    package.set_password(pass.toStdString());

    QByteArray data = QByteArray(package.ByteSize(),'\0' );
    package.SerializeToArray(data.data(),data.size());

    return data;
}

QByteArray Protocol::getLogoutPB()
{
    user::Logout package;
    package.set_msgtype(MSG_LOGOUT_ID);

    QByteArray data = QByteArray(package.ByteSize(),'\0' );
    package.SerializeToArray(data.data(),data.size());
    return data;
}

QByteArray Protocol::getUserAddPB(QString name, QString passwd, QString email, QString address, QString phoneNum)
{
    user::Add package;
    package.set_msgtype(MSG_USERADD_ID);
    package.set_name(name.toStdString());
    package.set_password(passwd.toStdString());
    package.set_email(email.toStdString());

    if(!address.isEmpty()){
        package.set_address(address.toStdString());
    }
    if(!phoneNum.isEmpty()){
        package.set_phonenumber(phoneNum.toStdString());
    }

    QByteArray data = QByteArray(package.ByteSize(),'\0' );
    package.SerializeToArray(data.data(),data.size());
    return data;
}

QByteArray Protocol::getLoginMessagePB(bool login_ok, quint64)
{
    user::LoginReplay package;
    package.set_msgtype(1);


    /// TODO last login info
    if(login_ok){
        package.set_replay(user::LOGIN_OK);
        //        package.add_optionaldata();
        //        package.optionaldata(0).set_key("last_login");
        //        package.optionaldata(0).set_value(QString::number(lastLogin));
    }
    else
    {
        package.set_replay(user::BAD_USER_OR_PASSWD);
    }


    QByteArray data = QByteArray(package.ByteSize(),'\0' );
    package.SerializeToArray(data.data(),data.size());

    return data;
}

user::Login Protocol::extractUserActrionPB(QByteArray &data)
{
    QDataStream *ds = new QDataStream(data);
    user::Login ua;
    boost::iostreams::stream <boost::iostreams::DataStreamSource > dataStream ( ds );
    ua.ParseFromIstream(&dataStream);
    return ua;
}

user::LoginReplay Protocol::extractUserActrionReplayPB(QByteArray &data)
{
    QDataStream *ds = new QDataStream(data);
    user::LoginReplay ua;
    boost::iostreams::stream <boost::iostreams::DataStreamSource > dataStream ( ds );
    ua.ParseFromIstream(&dataStream);
    return ua;
}

user::Add Protocol::extractUserAddPB(QByteArray &data)
{
    QDataStream *ds = new QDataStream(data);
    user::Add ua;
    boost::iostreams::stream <boost::iostreams::DataStreamSource > dataStream ( ds );
    ua.ParseFromIstream(&dataStream);
    return ua;
}

user::LoginReplay Protocol::login(QString name, QString pass)
{
    if (socket->state() != QAbstractSocket::ConnectedState ){
        // connect again
        /// TODO set proper IP address
        socket->connectToHost("127.0.0.1",2345);
        socket->waitForConnected(150);
    }

    QByteArray data = Protocol::getLoginPB(name, pass);

    socket->write(data);
    socket->waitForBytesWritten(100);
    socket->waitForReadyRead(1000);

    data.clear();
    data.append(socket->readAll());


    user::LoginReplay ar = Protocol::extractUserActrionReplayPB( data );
    return ar;
}

void Protocol::logout()
{
    socket->write(getLogoutPB());
    socket->waitForBytesWritten(100);
    socket->waitForDisconnected(250);
}
