#ifndef USER_H
#define USER_H

#include <QString>
#include <QValidator>
#include <QDataStream>

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

class User : protected user::UserData
{
public:
    User();

    int getID(){ return id(); }
    void setID(const int id){ set_id(id);}
    void clearID(){ clear_id(); }

    QString getName() const;
    void setName(const QString &name);
    void clearName(){ clear_name(); }

    QString getEmail() const;
    void setEmail(const QString &value);
    void clearEmail(){ clear_email(); }

    Storage getStorage() const;
    void setStorage(const quint32 &value);
    void addStorage(Storage s);
    int storagesNumber(){ return storages.size(); }

    void setAddress(const QString adr){ set_address(adr.toStdString() ); }
    QString getAddress() const { return QString::fromStdString(address()); }

    void setPhoneNumber(const QString &number);
    QString getPhoneNumber() const;

    QByteArray* toArray();

private:
    QMap<quint32, Storage> storages;
    quint32 defaultStorageId;

public:
    //    void Clear();
    //    bool IsInitialized() const;
    void fromArray(const QByteArray *data);
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
