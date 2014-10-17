#ifndef LOGINREQUEST_H
#define LOGINREQUEST_H

#include "user.pb.h"
#include "message.h"
#include <QString>

class LoginRequest : public user::LoginRequest, public protocol::Message
{
public:
    LoginRequest();
    virtual ~LoginRequest();
    void set_name(QString &&name);
    void set_password(QString &&passwd );

public:
    MsgType type() const;
protected:
    int ByteSize() const;
    bool SerializeToArray(void *data, int size) const
    {
        return user::LoginRequest::SerializeToArray(data,size);
    }
    bool ParseFromArray(const void *data, int size)
    {
        return user::LoginRequest::ParseFromArray(data,size);
    }
};

class LogoutRequest :public user::LogoutRequest, public protocol::Message
{
    MsgType type() const;
protected:
    int ByteSize() const
    {
        return user::LogoutRequest::ByteSize();
    }
    bool SerializeToArray(void *data, int size) const
    {
        return user::LogoutRequest::SerializeToArray(data,size);
    }
    bool ParseFromArray(const void *data, int size)
    {
        return user::LogoutRequest::ParseFromArray(data,size);
    }
};

class LoginRequestResponse : public user::LoginResponse, public protocol::Message
{
public:
    MsgType type() const;
protected:
    int ByteSize() const
    {
        return user::LoginResponse::ByteSize();
    }
    bool SerializeToArray(void *data, int size) const
    {
        return user::LoginResponse::SerializeToArray(data,size);
    }
    bool ParseFromArray(const void *data, int size)
    {
        return user::LoginResponse::ParseFromArray(data,size);
    }
};

#endif // LOGINREQUEST_H
