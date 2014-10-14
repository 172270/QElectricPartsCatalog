#include "loginmessagehandler.h"

#include <QDebug>

void LoginMessageHandler::setData(QByteArray &&d)
{
    req.ParseFromArray( d.data(),d.size() ); ///TODO change to some normall class
}

void LoginMessageHandler::processData()
{
    qDebug()<< "User "<< QString::fromStdString(req.name()) << "try to login";
    QString userName = QString::fromStdString(req.name());
    bool loginOk = database.checkUserPassword(userName, QString::fromStdString(req.password())); ///TODO hash passwd

    if(loginOk){
        res.set_replay(user::Replay::LOGIN_OK);
        qDebug()<<" login succesfull";
    }
    else{
        res.set_replay(user::Replay::BAD_USER_OR_PASSWD);
        qDebug()<<" bad user or password";
    }
}

QByteArray LoginMessageHandler::getResponse()
{
    QByteArray ba;
    ba.resize(res.ByteSize());
    res.SerializePartialToArray(ba.data(), ba.size() );
    return ba;
}
