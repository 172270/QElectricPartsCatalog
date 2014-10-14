#ifndef LOGINREQUEST_H
#define LOGINREQUEST_H

#include "user.pb.h"

#include <QString>

class LoginRequest : public user::LoginRequest
{
public:
    void set_name(QString &&name);
    void set_password(QString &&passwd );
    QByteArray toArray();
    LoginRequest();
};

#endif // LOGINREQUEST_H
