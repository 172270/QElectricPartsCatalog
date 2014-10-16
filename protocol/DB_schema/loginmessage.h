#ifndef LOGINMESSAGE_H
#define LOGINMESSAGE_H

#include <QString>

class LoginMessage
{
public:
    LoginMessage();

    QString getName() const;
    void setName(const QString &value);

private:

    QString name;
};

#endif // LOGINMESSAGE_H
