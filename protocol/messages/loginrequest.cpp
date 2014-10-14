#include "loginrequest.h"

void LoginRequest::set_name(QString &&name)
{
    user::LoginRequest::set_name(name.toStdString());
}

void LoginRequest::set_password(QString &&passwd)
{
    user::LoginRequest::set_password(passwd.toStdString());
}

QByteArray LoginRequest::toArray()
{
    QByteArray ba;
    ba.resize( ByteSize() );
    ba.append( SerializeToArray(ba.data(),ba.size() ));
    return ba;
}

LoginRequest::LoginRequest()
{
}
