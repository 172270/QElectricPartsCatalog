#include "loginrequest.h"

void LoginRequest::set_name(QString &&name)
{
    user::LoginRequest::set_name(name.toStdString());
}

void LoginRequest::set_password(QString &&passwd)
{
    user::LoginRequest::set_password(passwd.toStdString());
}

MsgType LoginRequest::type() const
{
    return MsgType::reqLogin;
}

int LoginRequest::ByteSize() const
{
    return user::LoginRequest::ByteSize();
}

LoginRequest::LoginRequest() :
    user::LoginRequest(),
    protocol::Message()
{
}

LoginRequest::~LoginRequest()
{

}

MsgType LoginRequestResponse::type() const
{
    return MsgType::resLogin;
}

MsgType LogoutRequest::type() const
{
    return MsgType::reqLogout;
}
