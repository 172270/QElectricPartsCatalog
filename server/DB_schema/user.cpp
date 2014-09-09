#include "user.h"

#include "boost/iostreams/stream.hpp"

User::User() :
    defaultStorageId(0)
{
    set_msgtype(5);
}

QString User::getName() const
{
    return QString::fromStdString(name());
}

void User::setName(const QString &value)
{
    if(!value.size())
        throw QString("Empty names not allowed!");
    set_name(value.trimmed().toStdString());
}
QString User::getEmail() const
{
    return QString::fromStdString(email());
}

void User::setEmail(const QString &value)
{
    if(!value.size())
        throw QString("Empty emails not allowed!");
    EmailValidator validator;
    int pos =0;
    QString mail = value.trimmed().toLower();
    QValidator::State state = validator.validate(mail,pos);
    if (state == QValidator::Invalid ||state ==  QValidator::Intermediate ){
        throw QString("Invalid email address!");
    }
    else
        set_email(mail.toStdString());
}
Storage User::getStorage() const
{
    return storages[defaultStorageId];
}

void User::setStorage(const quint32 &value)
{
    defaultStorageId = value;
}

void User::addStorage( Storage s )
{
    if (!s.IsInitialized() )
        throw QString("storage is not initialized!");
    storages.insert(s.getID(), s);
}

void User::setPhoneNumber(const QString &number)
{
    set_phonenumber(number.toStdString());
}

QString User::getPhoneNumber() const
{
    return QString::fromStdString(phonenumber());
}

QByteArray* User::toArray()
{
    if (!IsInitialized()){
        throw QString("Uninitialized message!");
    }

    QByteArray *data = new QByteArray(ByteSize(),'\0' );
    SerializeToArray(data->data(),data->size());

    return data;
}

void User::fromArray(const QByteArray *data){
        this->ParseFromArray(data->data(), data->size());
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

