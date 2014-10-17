#ifndef USERREGISTRATIONMESSAGE_H
#define USERREGISTRATIONMESSAGE_H

#include <QString>
#include "user.pb.h"
#include "message.h"

class UserRegistrationMessage : public user::Register, public protocol::Message
{
public:
    UserRegistrationMessage();

    void set_name(QString &&name) { user::Register::set_name(name.toStdString()); }
    void set_address(QString &&address) {user::Register::set_address(address.toStdString()); }
    void set_description(QString &&description){user::Register::set_description(description.toStdString()); }
    void set_email(QString &&email) { user::Register::set_email(email.toStdString());}
    void set_phonenumber(QString &&number){ user::Register::set_phonenumber(number.toStdString()) ;}
    void set_password(QString &&passwd){user::Register::set_password(passwd.toStdString()); }
    void set_password(const QString &passwd){user::Register::set_password(passwd.toStdString()); }
    MsgType type() const;

protected:
    int ByteSize() const;
    bool SerializeToArray(void *data, int size) const;
    bool ParseFromArray(const void *data, int size);
};

class UserRegistrationMessageReplay : public user::RegisterResponse, public protocol::Message
{
public:
    UserRegistrationMessageReplay(){;}

    MsgType type() const
    {
        return MsgType::resAddUser;
    }

protected:
    int ByteSize() const
    {
        return user::RegisterResponse::ByteSize();
    }
    bool SerializeToArray(void *data, int size) const;
    bool ParseFromArray(const void *data, int size);
};

#endif // USERREGISTRATIONMESSAGE_H
