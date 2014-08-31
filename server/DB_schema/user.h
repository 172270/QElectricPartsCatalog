#ifndef USER_H
#define USER_H

#include <QString>
#include <QValidator>

#include "storage.h"
#include "user.pb.h"

class User : public user::UserData
{
public:
    User();

    QString getName() const;
    void setName(const QString &value);

    QString getEmail() const;
    void setEmail(const QString &value);

    Storage getStorage() const;
    void setStorage(const quint32 &value);

    void addStorage(Storage s);

    int storagesNumber(){ return storages.size(); }

private:
    QMap<quint32, Storage> storages;
    quint32 defaultStorageId = 0;
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
