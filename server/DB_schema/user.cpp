#include "user.h"

#include "boost/iostreams/stream.hpp"

User::User():
    defaultStorageID(0)
{
    user::UserData::set_config(QString(getDefaultConfig()).toStdString() );
}

void User::set_name(const QString &name)
{
    user::UserData::set_name(name.trimmed().toStdString());
}

QString User::getName() const
{
    return QString::fromStdString(name());
}

void User::set_email(const QString &value)
{
    //    if(!value.size())
    //        throw QString("Empty emails not allowed!");
    //    EmailValidator validator;
    //    int pos =0;
    //    QString mail = value.trimmed().toLower();
    //    QValidator::State state = validator.validate(mail,pos);
    //    if (state == QValidator::Invalid ||state ==  QValidator::Intermediate ){
    //        throw QString("Invalid email address!");
    //    }
    //    else
    user::UserData::set_email(value.trimmed().toStdString());

}

QString User::getEmail() const
{
    return QString::fromStdString(email());
}

Storage* User::getStorage()
{
    if( storagesNumber() == 1){
        return static_cast<Storage*>(mutable_storages(0));
    }
    QList<Storage*> list = getStoragesList();
    for(int i=0;i<storagesNumber();i++) {
        if(list.at(i)->getID() == defaultStorageID ){
            return list.at(i);
        }
    }
    Storage *s = new Storage();
    return s;
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

void User::setDefaultStorageId(quint32 id)
{
    defaultStorageID = id;
}

QList<Storage*> User::getStoragesList()
{
    QList<Storage*> store;
    for(int i = 0; i<storagesNumber();i++){
        store.append( static_cast<Storage*>(mutable_storages(i)));
    }
    return store;
}

int User::storagesNumber() const{ return storages_size();}

void User::set_phonenumber(const QString &number)
{
    user::UserData::set_phonenumber(number.toStdString());
}

QString User::getPhoneNumber() const
{
    return QString::fromStdString(phonenumber());
}

void User::set_registrationdate(QDateTime registrationDate)
{
    user::UserData::set_registrationdate(registrationDate.toMSecsSinceEpoch());
}

QDateTime User::get_registrationdate()
{
    return QDateTime::fromMSecsSinceEpoch(registrationdate());
}

void User::setConfig(QByteArray conf)
{
    user::UserData::set_config(QString(conf).toStdString());
}



QByteArray User::getDefaultConfig()
{
    QJsonObject json;
    json.insert("last_group", QJsonValue(0));
    json.insert("last_storage_id", QJsonValue(0));

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

QByteArray *User::toArray(QByteArray *ba)
{
    if (!IsInitialized()){
        throw QString("Uninitialized message!");
    }

    if(ba->size()< ByteSize() )
        ba->resize(ByteSize());
    SerializeToArray(ba->data(),ba->size());

    return ba;
}

user::UserBasicInformation User::getPBPackage()
{
    user::UserBasicInformation ubi;
    ubi.set_name(name() );
    ///TODO check if user want's to give his email in, find information in config
    ubi.set_email(email());
    return ubi;
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

