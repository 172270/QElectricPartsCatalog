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
    return user::Register::ByteSize();
}

bool UserRegistrationMessage::SerializeToArray(void *data, int size) const
{
    return user::Register::SerializeToArray(data,size);
}

bool UserRegistrationMessage::ParseFromArray(const void *data, int size)
{
    return user::Register::ParseFromArray(data,size);
}


bool UserRegistrationMessageReplay::SerializeToArray(void *data, int size) const
{
    return user::RegisterResponse::SerializeToArray(data,size);
}

bool UserRegistrationMessageReplay::ParseFromArray(const void *data, int size)
{
    return user::RegisterResponse::ParseFromArray(data,size);
}
