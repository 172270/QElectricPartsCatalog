#ifndef REGISTERUSERMESSAGEHANDLER_H
#define REGISTERUSERMESSAGEHANDLER_H

#include <QByteArray>
#include <QValidator>
#include "user.pb.h"
#include "pginterface.h"

class RegisterUserMessageHandler
{
public:
    RegisterUserMessageHandler(QString dbName);
    void setData(QByteArray &&d);
    void processData();
    QByteArray getResponse();
private:
    PgInterface database;
    protbuf::Register req;
    protbuf::RegisterResponse res;
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


#endif // REGISTERUSERMESSAGEHANDLER_H
