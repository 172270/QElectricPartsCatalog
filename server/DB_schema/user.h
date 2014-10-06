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

    void set_name(const QString  &name);
    QString getName() const;

    void set_email(const QString &value);
    QString getEmail() const;

    Storage *getStorage();
    void addStorage(const Storage &s);
    void addStorages(QList<Storage> storages);
    void setDefaultStorageId(quint32 id);
    QList<Storage *> getStoragesList();
    int storagesNumber() const;

    void set_address(const QString adr){  user::UserData::set_address(adr.toStdString() ); }
    QString getAddress() const { return QString::fromStdString(address()); }

    void set_phonenumber(const QString &number);
    QString getPhoneNumber() const;

    void set_registrationdate( QDateTime registrationDate );
    QDateTime get_registrationdate();

    void setConfig(QByteArray conf);
    QByteArray getDefaultConfig();

    QByteArray* toArray();
    QByteArray* toArray(QByteArray *ba);
    user::UserBasicInformation getPBPackage();
    void fromArray(const QByteArray *data);

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
