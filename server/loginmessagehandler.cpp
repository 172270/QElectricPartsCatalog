#include "loginmessagehandler.h"

#include <QDebug>
#include <QCryptographicHash>

void LoginMessageHandler::setData(QByteArray &&d)
{
    req.ParseFromArray( d.data(),d.size() );
}

void LoginMessageHandler::processData()
{
    qDebug()<< "User "<< QString::fromStdString(req.name()) << "try to login";
    QString userName = QString::fromStdString(req.name());

    QByteArray pass = QCryptographicHash::hash(QByteArray(req.password().data(), req.password().size() ), QCryptographicHash::Sha512);
    bool loginOk = database.checkUserPassword(userName, pass.toHex() );

    if(loginOk){
        res.set_replay(user::Replay::LoginPass);
        getUserData();
        updateLastLogin();
        qDebug()<<" login succesfull";
    }
    else{
        res.set_replay(user::Replay::LoginDeny);
        qDebug()<<" bad user or password";
    }

}

User* LoginMessageHandler::getUserData()
{
    ///TODO get all user data (info about files etc.)
    user->MergeFrom(database.getUserByName( QString::fromStdString(req.name()) ));
    ///TODO add getUser method that take pointer to user, and pass user to that function instead
    /// marging data from other user
    return user;
}

QByteArray LoginMessageHandler::getResponse()
{
    QByteArray ba;
    ba.resize(res.ByteSize());
    res.SerializePartialToArray(ba.data(), ba.size() );
    return ba;
}

void LoginMessageHandler::updateLastLogin()
{
    if(user->IsInitialized()){
        database.updateLastLogin(*user);
    }
    if(user->id() == 0){
        user->MergeFrom(database.getUserByName(user->getName()));
        database.updateLastLogin(*user);
    }
}
