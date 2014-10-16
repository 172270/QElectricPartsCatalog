#include "loginmessagehandler.h"

#include <QDebug>
#include <QCryptographicHash>

void LoginMessageHandler::setData(QByteArray &&d)
{
    req.ParseFromArray( d.data(),d.size() ); ///TODO change to some normall class
}

void LoginMessageHandler::processData()
{
    qDebug()<< "User "<< QString::fromStdString(req.name()) << "try to login";
    QString userName = QString::fromStdString(req.name());

    QByteArray pass = QCryptographicHash::hash(QByteArray(req.password().data(), req.password().size() ), QCryptographicHash::Sha512);
    bool loginOk = database.checkUserPassword(userName, pass.toHex() );

    if(loginOk){
        res.set_replay(user::Replay::LoginPass);
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

    User *u = new User;

    u->MergeFrom(database.getUserByName( QString::fromStdString(req.name()) ));

    return u;
}

QByteArray LoginMessageHandler::getResponse()
{
    QByteArray ba;
    ba.resize(res.ByteSize());
    res.SerializePartialToArray(ba.data(), ba.size() );
    return ba;
}
