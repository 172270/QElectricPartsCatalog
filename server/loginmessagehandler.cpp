#include "loginmessagehandler.h"

#include <QDebug>
#include <QCryptographicHash>

void LoginMessageHandler::setData(QByteArray &&d)
{
    req.Clear();
    res.Clear();

    req.ParseFromArray( d.data(),d.size() );
}

void LoginMessageHandler::processData()
{

    if(!user->isLogged() ){
        QString userName = QString::fromStdString(req.name());

        QByteArray pass = QCryptographicHash::hash(QByteArray(req.password().data(), req.password().size() ), QCryptographicHash::Sha512);
        bool loginOk = database.checkUserPassword(userName, pass.toHex() );

        if(loginOk){
            res.set_replay(protbuf::Replay::LoginPass);
            user->setIsLogged(true);
            getUserData();
            updateLastLogin();
        }
        else{
            res.set_replay(protbuf::Replay::LoginDeny);
        }
    }
    else{
        res.set_replay(protbuf::Replay::UserAlreadyLogged);
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

bool LoginMessageHandler::loginOk(){
    return res.replay()==protbuf::Replay::LoginPass;
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
