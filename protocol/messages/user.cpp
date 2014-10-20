#include "user.h"

User::User():
    defaultStorageID(0)
{
    set_id(0);
    protbuf::UserData::set_config(QString(getDefaultConfig()).toStdString() );
}

void User::set_name(const QString &name)
{
    protbuf::UserData::set_name(name.trimmed().toStdString());
}

void User::set_name(const std::string & name)
{
    protbuf::UserData::set_name(name);
}

QString User::getName() const
{
    return QString::fromStdString(name());
}

void User::set_email(const QString &value)
{
    protbuf::UserData::set_email(value.trimmed().toStdString());
}

void User::set_email(const std::string &email)
{
    protbuf::UserData::set_email(email); ///TODO test for trimmed
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
    protbuf::Storage *store = add_storages();
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
    protbuf::UserData::set_phonenumber(number.toStdString());
}

QString User::getPhoneNumber() const
{
    return QString::fromStdString(phonenumber());
}

void User::set_lastlogin(QDateTime lastlogin){
    protbuf::UserData::set_lastlogin(lastlogin.toMSecsSinceEpoch());
}
bool User::isLogged() const
{
    return m_isLogged;
}

void User::setIsLogged(bool value)
{
    m_isLogged = value;
}


MsgType User::type() const
{
    return MsgType::msgUser;
}

int User::ByteSize() const
{
    return protbuf::UserData::ByteSize();
}

bool User::SerializeToArray(void *data, int size) const
{
    return protbuf::UserData::SerializeToArray(data,size);
}

bool User::ParseFromArray(const void *data, int size)
{
    return protbuf::UserData::ParseFromArray(data,size);
}

void User::set_registrationdate(QDateTime registrationDate)
{
    protbuf::UserData::set_registrationdate(registrationDate.toMSecsSinceEpoch());
}

QDateTime User::get_registrationdate()
{
    return QDateTime::fromMSecsSinceEpoch(registrationdate());
}

void User::setConfig(QByteArray conf)
{
    protbuf::UserData::set_config(QString(conf).toStdString());
}

QByteArray User::getDefaultConfig()
{
    QJsonObject json;
    json.insert("last_group", QJsonValue(0));
    json.insert("last_storage_id", QJsonValue(0));

    return QJsonDocument(json).toJson(QJsonDocument::Compact);
}

protbuf::UserBasicInformation User::getPBPackage()
{
    protbuf::UserBasicInformation ubi;
    ubi.set_name(name() );
    ubi.set_id(id() );
    ubi.set_email(email());
    return ubi;
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

