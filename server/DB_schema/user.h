#ifndef USER_H
#define USER_H

#include <QString>
#include <QValidator>
#include <QDateTime>
#include <QDataStream>
#include <QJsonObject>
#include <QJsonDocument>

#include "storage.h"
#include "user.pb.h"

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

class User : public user::UserData
{
public:
    User();

    int getID(){ return id(); }
    void setID(const int id){ set_id(id);}
    void clearID(){ clear_id(); }
    bool hasID(){return has_id();}

    QString getName() const;
    void setName(const QString &name);
    void clearName(){ clear_name(); }

    QString getEmail() const;
    void setEmail(const QString &value);
    void clearEmail(){ clear_email(); }
    bool hasEmail(){return has_email();}

    Storage *getStorage();
    void addStorage(const Storage &s);
    void addStorages(QList<Storage> storages);
    void setDefaultStorageId(quint32 id);
    QList<Storage *> getStoragesList();
    int storagesNumber() const;

    void setAddress(const QString adr){ set_address(adr.toStdString() ); }
    QString getAddress() const { return QString::fromStdString(address()); }
    bool hasAddress() const {return has_address();}
    void clearAddress();

    void setPhoneNumber(const QString &number);
    QString getPhoneNumber() const;
    bool hasPhoneNumber() const;
    void clearPhoneNumber();

    void setRegistrationDate( QDateTime registrationDate );
    QDateTime getRegistrationDate();
    bool hasRegistrationDate(){return has_firstlogin(); }

    void setConfig(QByteArray conf);
    bool hasConfig();
    QByteArray getDefaultConfig();

    QByteArray* toArray();

    UserData* getPBPackage();

public:
    void fromArray(const QByteArray *data);

    quint32 getDefaultStorage();
private:
    quint32 defaultStorageID;
};



QT_BEGIN_NAMESPACE
class QRegExp;
QT_END_NAMESPACE

class EmailValidator : public QValidator
{
    Q_OBJECT
public:
    explicit EmailValidator(QObject *parent = 0);
    State validate(QString &text, int &pos) const;

private:
    const QRegExp m_validMailRegExp;
    const QRegExp m_intermediateMailRegExp;
};

#endif // USER_H
