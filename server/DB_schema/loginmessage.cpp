#include "loginmessage.h"

LoginMessage::LoginMessage()
{
}

QString LoginMessage::getName() const
{
    return name;
}

void LoginMessage::setName(const QString &value)
{
    name = value;
}

