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

RegisterUserMessageHandler::RegisterUserMessageHandler(QString dbName):
    database(dbName)
{
}

RegisterUserMessageHandler::RegisterUserMessageHandler(QSqlDatabase db):
    database(db.connectionName())
{
}

void RegisterUserMessageHandler::setData(QByteArray &&d)
{
    req.Clear();
    req.ParseFromArray(d.data(),d.size());
    if(!req.IsInitialized()){
        qDebug()<<" message is not initialized!";
    }
}

void RegisterUserMessageHandler::processData()
{
    EmailValidator validator;
    QString email = QString::fromStdString(req.email());
    QString name = QString::fromStdString(req.name());
    int pos = 0;
    QValidator::State state = validator.validate(email,pos);

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
        return;

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
}

QByteArray RegisterUserMessageHandler::getResponse()
{
    QByteArray ba;
    ba.resize(res.ByteSize());
    res.SerializePartialToArray(ba.data(), ba.size() );
    return ba;
}
