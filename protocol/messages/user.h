#ifndef USER_H
#define USER_H

#include <QString>
#include <QDateTime>
#include <QJsonObject>
#include <QJsonDocument>

#include "storage.h"
#include "user.pb.h"
#include "message.h"

class UserError{
public:
    QString text() const;
    void setText(const QString &text);

    int errorNumber() const;
    void setErrorNumber(int errorNumber);

private:
    QString m_text;
    int m_errorNumber;
};

class User : public protbuf::UserData, public protocol::Message
{
public:
    User();

    void set_name(const QString  &name);
    void set_name(const std::string &name);
    QString getName() const;

    void set_email(const QString &value);
    void set_email(const ::std::string &email);
    QString getEmail() const;

    Storage *getStorage();
    void addStorage(const Storage &s);
    void addStorages(QList<Storage> storages);
    void setDefaultStorageId(quint32 id);
    QList<Storage *> getStoragesList();
    int storagesNumber() const;

    void set_address(const QString &adr){  protbuf::UserData::set_address(adr.toStdString() ); }
    void set_address(const ::std::string &adr){protbuf::UserData::set_address(adr);}
    QString getAddress() const { return QString::fromStdString(address()); }

    void set_phonenumber(const QString &number);
    void set_phonenumber(const ::std::string &number){ protbuf::UserData::set_phonenumber(number);}
    QString getPhoneNumber() const;

    void set_registrationdate( QDateTime registrationDate );
    QDateTime get_registrationdate();

    void setConfig(QByteArray conf);
    QByteArray getDefaultConfig();

    protbuf::UserBasicInformation getPBPackage();

    void set_description(QString &&description){ protbuf::UserData::set_description(description.toStdString());}
    void set_description(const ::std::string &adr){protbuf::UserData::set_description(adr);}
    QString getDescription()const{ return QString::fromStdString(description());}
    void set_lastlogin(QDateTime lastlogin);
private:
    quint32 defaultStorageID;
    bool m_isLogged = false;
public:
    MsgType type() const;
    int ByteSize() const;

    bool isLogged() const;
    void setIsLogged(bool value);

protected:
    bool SerializeToArray(void *data, int size) const;
    bool ParseFromArray(const void *data, int size);
};

#endif // USER_H
