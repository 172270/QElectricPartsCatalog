#ifndef LOGINREQUEST_H
#define LOGINREQUEST_H

#include "user.pb.h"
#include "message.h"
#include <QString>

class LoginRequest : public protbuf::LoginRequest, public protocol::Message
{
public:
    LoginRequest();
    virtual ~LoginRequest();
    void set_name(QString &&name);
    void set_name(const QString &name);
    void set_password(QString &&passwd );
    void set_password(const QString &passwd );
public:
    MsgType type() const;
protected:
    int ByteSize() const;
    bool SerializeToArray(void *data, int size) const
    {
        return protbuf::LoginRequest::SerializeToArray(data,size);
    }
    bool ParseFromArray(const void *data, int size)
    {
        return protbuf::LoginRequest::ParseFromArray(data,size);
    }
};

class LogoutRequest :public protbuf::LogoutRequest, public protocol::Message
{
    MsgType type() const;
protected:
    int ByteSize() const
    {
        return protbuf::LogoutRequest::ByteSize();
    }
    bool SerializeToArray(void *data, int size) const
    {
        return protbuf::LogoutRequest::SerializeToArray(data,size);
    }
    bool ParseFromArray(const void *data, int size)
    {
        return protbuf::LogoutRequest::ParseFromArray(data,size);
    }
};

class LoginRequestResponse : public protbuf::LoginResponse, public protocol::Message
{
public:
    MsgType type() const;
protected:
    int ByteSize() const
    {
        return protbuf::LoginResponse::ByteSize();
    }
    bool SerializeToArray(void *data, int size) const
    {
        return protbuf::LoginResponse::SerializeToArray(data,size);
    }
    bool ParseFromArray(const void *data, int size)
    {
        return protbuf::LoginResponse::ParseFromArray(data,size);
    }
};

#endif // LOGINREQUEST_H
