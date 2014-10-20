#include "userregistrationmessage.h"

UserRegistrationMessage::UserRegistrationMessage()
{
}

MsgType UserRegistrationMessage::type() const
{
    return MsgType::addUser;
}

int UserRegistrationMessage::ByteSize() const
{
    return protbuf::Register::ByteSize();
}

bool UserRegistrationMessage::SerializeToArray(void *data, int size) const
{
    return protbuf::Register::SerializeToArray(data,size);
}

bool UserRegistrationMessage::ParseFromArray(const void *data, int size)
{
    return protbuf::Register::ParseFromArray(data,size);
}


MsgType UserRegistrationMessageReplay::type() const
{
    return MsgType::resAddUser;
}

int UserRegistrationMessageReplay::ByteSize() const
{
    return protbuf::RegisterResponse::ByteSize();
}

bool UserRegistrationMessageReplay::SerializeToArray(void *data, int size) const
{
    return protbuf::RegisterResponse::SerializeToArray(data,size);
}

bool UserRegistrationMessageReplay::ParseFromArray(const void *data, int size)
{
    return protbuf::RegisterResponse::ParseFromArray(data,size);
}
