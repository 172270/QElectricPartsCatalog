#include "user.h"

#include "boost/iostreams/stream.hpp"

User::User()
{
    set_userconfig(QString(getDefaultConfig()).toStdString() );
}

QString User::getName() const
{
    return QString::fromStdString(name());
}

void User::setName(const QString &name)
{
    // ^\w(?:\w*(?:[.-]\w+)?)*(?<=^.{4,32})$

    ///TODO name validator
    if(name.trimmed().size()<4 || name.trimmed().size()> 32)
        throw QString("Bad length!");

    set_name(name.trimmed().toStdString());
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
    if (storagesNumber() == 0 ){
        return Storage() ;
    }
    if( storagesNumber() == 1){
        Storage s;
        s.CopyFrom(storages(0));
        return s;
    }
}

void User::addStorage(const Storage &s )
{
    if (!s.IsInitialized() )
        throw QString("storage is not initialized!");
    storage::Storage *store = add_storages();
    store->CopyFrom(s);
}

void User::addStorages(QList<Storage> st)
{
    foreach (Storage s, st){
        addStorage(s);
    }
}

QList<Storage*> User::getStoragesList()
{
    QList<Storage*> store;
    for(int i; i<storagesNumber();i++){
        store.append( dynamic_cast<Storage*>(mutable_storages(i)));
    }
    return store;
}

int User::storagesNumber() const{ return storages_size();}

void User::clearAddress()
{
    clear_address();
}

void User::setPhoneNumber(const QString &number)
{
    set_phonenumber(number.toStdString());
}

QString User::getPhoneNumber() const
{
    return QString::fromStdString(phonenumber());
}

bool User::hasPhoneNumber() const
{
    return has_phonenumber();
}

void User::clearPhoneNumber()
{
    clear_phonenumber();
}

void User::setRegistrationDate(QDateTime registrationDate)
{
    set_firstlogin(registrationDate.toMSecsSinceEpoch());
}

QDateTime User::getRegistrationDate()
{
    return QDateTime::fromMSecsSinceEpoch(firstlogin());
}

void User::setConfig(QByteArray conf)
{
    set_userconfig(QString(conf).toStdString());
}

bool User::hasConfig()
{
    return has_userconfig();
}

QByteArray User::getDefaultConfig()
{
    QJsonObject json;
    json.insert("last_group", QJsonValue(0));

    return QJsonDocument(json).toJson(QJsonDocument::Compact);
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


QString UserError::text() const
{
    return m_text;
}

void UserError::setText(const QString &text)
{
    m_text = text;
}
int UserError::errorNumber() const
{
    return m_errorNumber;
}

void UserError::setErrorNumber(int errorNumber)
{
    m_errorNumber = errorNumber;
}

