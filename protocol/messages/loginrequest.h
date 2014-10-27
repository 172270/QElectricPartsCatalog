#ifndef LOGINREQUEST_H
#define LOGINREQUEST_H

#include "user.pb.h"
#include "message.h"
#include <QString>

class LoginRequest : public protocol::QMessage<protbuf::LoginRequest>
{
public:
    LoginRequest();
    virtual ~LoginRequest();
    void set_name(QString &&name);
    void set_name(const QString &name);
    QString getName(){ return QString::fromStdString(name()); }
    void set_password(QString &&passwd );
    void set_password(const QString &passwd );
public:
    MsgType type() const;
};

class LogoutRequest : public protocol::QMessage<protbuf::LogoutRequest>
{
public:
    MsgType type() const;
};

class LoginRequestResponse : public protocol::QMessage<protbuf::LoginResponse>
{
public:
    MsgType type() const;
};

#endif // LOGINREQUEST_H
