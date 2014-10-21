#include "registerusermessagehandler.h"

#include <QCryptographicHash>
#include <QDebug>

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

RegisterUserMessageHandler::RegisterUserMessageHandler(WorkerCache *cache):
    MessageHandlerInterface(cache)
{
}

bool RegisterUserMessageHandler::parseData(const QByteArray &ba)
{
    req.Clear();
    return req.ParseFromArray(ba.data(),ba.size());
}

bool RegisterUserMessageHandler::parseData(QByteArray &&ba)
{
    req.Clear();
    return req.ParseFromArray(ba.data(),ba.size());
}

bool RegisterUserMessageHandler::clearCacheData()
{
    m_cache.getUserData()->Clear();
    m_cache.getUserStats()->Clear();
    return true;
}

bool RegisterUserMessageHandler::checkName()
{
    bool hasErrors = false;

    if(req.name().size()>34){
        qDebug()<<"user name to long";
        res.add_replay(protbuf::Replay::UserNameToLong);
        hasErrors = true;
    }

    if(req.name().size()<2){
        qDebug()<<"user name to short";
        res.add_replay(protbuf::Replay::UserNameToShort);
        hasErrors = true;
    }

    return hasErrors;
}

bool RegisterUserMessageHandler::checkEmail()
{
    EmailValidator validator;
    QString email = QString::fromStdString(req.email());
    int pos = 0;
    QValidator::State state = validator.validate(email,pos);
    bool hasErrors = false;
    if(req.email().size()>255){
        qDebug()<<"user email to long";
        res.add_replay(protbuf::Replay::EmailAddressToLong);
        hasErrors = true;
    }

    if(state != QValidator::Acceptable){
        qDebug()<<"email not validate";
        res.add_replay(protbuf::Replay::EmailNotValidate);
        hasErrors = true;
    }

    return hasErrors;
}

bool RegisterUserMessageHandler::processData()
{
    QString name = QString::fromStdString(req.name());
    QString email = QString::fromStdString(req.email());
    bool hasErrors = false;

    hasErrors += checkName();
    hasErrors += checkEmail();

    if(req.password().size()==0){
        qDebug()<<"user has no password";
        res.add_replay(protbuf::Replay::PasswordToShort);
        hasErrors = true;
    }

    if(database.userEmailExists(email)){
        qDebug()<<"user email exists";
        res.add_replay(protbuf::Replay::EmailExists);
        hasErrors = true;
    }

    if(database.userNameExists(name)){
        qDebug()<<"user name exists";
        res.add_replay(protbuf::Replay::UserAlreadyExists);
        hasErrors = true;
    }

    if (hasErrors)
        return false;

    User u;
    u.set_name(req.name());
    u.set_email(req.email());

    if(req.has_address())
        u.set_address(req.address());
    if(req.has_description())
        u.set_description( req.description() );
    if(req.has_phonenumber())
        u.set_phonenumber(req.phonenumber());
    if(req.has_avatar()){} ///TODO implement AVATAR

    QByteArray pass = QCryptographicHash::hash(QByteArray(req.password().data(), req.password().size() ), QCryptographicHash::Sha512);
    try{
        database.addUser(u, pass.toHex() );
        res.add_replay(protbuf::Replay::UserAddOk);
    }
    catch(UserError e){
        qDebug()<<e.text();
    }
    return true;
}

bool RegisterUserMessageHandler::moveResponseToCache()
{
    int size = res.ByteSize();
    if (!res.IsInitialized())
        return false;
    QByteArray *ba = new QByteArray(size,'\0');
    res.SerializeToArray(ba->data(), size );
    m_cache.responseMessage()->addMessage(MsgType::resAddUser, ba);
    return true;
}
