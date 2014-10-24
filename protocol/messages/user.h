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

class User : public protocol::QMessage<protbuf::UserData>
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
    void setDefaultStorageId(int id);
    quint32 getDefaultStorageId() const;
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


    QByteArray getDefaultConfig();

    protbuf::UserBasicInformation getPBPackage();

    void set_description(QString &&description){ protbuf::UserData::set_description(description.toStdString());}
    void set_description(const ::std::string &adr){protbuf::UserData::set_description(adr);}
    QString getDescription()const{ return QString::fromStdString(description());}
    void set_lastlogin(QDateTime lastlogin);

private:
    void setConfigValue(QString key, QJsonValue val);
    QJsonObject m_config;
public:
    MsgType type() const;


    // QMessage interface
private:
    void afterFromArray()
    {
        auto str = config();
        auto doc = QJsonDocument::fromJson(QString::fromStdString(str).toLatin1());
        m_config = doc.object();
    }
    void beforeToArray()
    {
        auto doc = QJsonDocument(m_config);
        auto str = std::string(doc.toJson().data(), doc.toJson().size() );
        set_config(str);
    }
};

class UserStatistics : public protocol::QMessage<protbuf::UserActivityStatistics>
{
    // Message interface
public:
    MsgType type() const;

};

#endif // USER_H
