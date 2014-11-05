#pragma once

#include <QByteArray>
#include <QValidator>
#include "workercache.h"
#include "messagehandlerinterface.h"
#include "user.pb.h"
#include "pginterface.h"

class RegisterUserMessageHandler : public MessageHandlerInterface
{
public:
    RegisterUserMessageHandler(WorkerCache *cache);
    ~RegisterUserMessageHandler(){;}
    bool moveResponseToCache();
    bool processData();
    bool parseData(const QByteArray &ba);
    void checkEmail(bool hasErrors, QValidator::State state);
    bool checkEmail();
private:
    protbuf::Register req;
    protbuf::RegisterResponse res;

    bool clearCacheData();
    bool checkName();
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
