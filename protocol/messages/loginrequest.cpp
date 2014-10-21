#include "loginrequest.h"

void LoginRequest::set_name(QString &&name)
{
    protbuf::LoginRequest::set_name(name.toStdString());
}

void LoginRequest::set_name(const QString &name)
{
    protbuf::LoginRequest::set_name(name.toStdString());
}

void LoginRequest::set_password(QString &&passwd)
{
    protbuf::LoginRequest::set_password(passwd.toStdString());
}

void LoginRequest::set_password(const QString &passwd)
{
    protbuf::LoginRequest::set_password(passwd.toStdString());
}

MsgType LoginRequest::type() const
{
    return MsgType::reqLogin;
}

int LoginRequest::ByteSize() const
{
    return protbuf::LoginRequest::ByteSize();
}

LoginRequest::LoginRequest() :
    protbuf::LoginRequest(),
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
