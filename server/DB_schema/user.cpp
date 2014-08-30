#include "user.h"

User::User()
{
}
QString User::getName() const
{
    return name;
}

void User::setName(const QString &value)
{
    if(!value.size())
        throw QString("Empty names not allowed!");
    name = value.trimmed();
}
QString User::getEmail() const
{
    return email;
}

void User::setEmail(const QString &value)
{
    if(!value.size())
        throw QString("Empty emails not allowed!");
    email = value.trimmed().toLower();
    EmailValidator validator;
    int pos =0;
    QValidator::State state = validator.validate(email,pos);
    if (state == QValidator::Invalid ||state ==  QValidator::Intermediate ){
        throw QString("Invalid email address!");
    }
}


EmailValidator::EmailValidator(QObject *parent) :
    QValidator(parent),
    m_validMailRegExp("[a-z0-9._%+-]+@[a-z0-9.-]+\\.[a-z]{2,4}"),
    m_intermediateMailRegExp("[a-z0-9._%+-]*@?[a-z0-9.-]*\\.?[a-z]*")
{
}

QValidator::State EmailValidator::validate(QString &text, int &pos) const
{
    Q_UNUSED(pos)
    if (m_validMailRegExp.exactMatch(text))
        return Acceptable;
    if (m_intermediateMailRegExp.exactMatch(text))
        return Intermediate;
    return Invalid;
}
