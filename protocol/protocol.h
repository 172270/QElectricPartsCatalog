#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <QString>
#include <QByteArray>
#include <QTcpSocket>

#include "user.pb.h"

class Protocol
{

public:
    Protocol(QTcpSocket *s);

    static QByteArray getLoginPB(QString name, QString pass);
    static QByteArray getLogoutPB();
    static QByteArray getUserAddPB(QString name, QString passwd, QString email, QString address="", QString phoneNum="");
    static QByteArray getLoginMessagePB(bool login_ok, quint64 lastLogin );

    static user::LoginRequest extractUserActrionPB( QByteArray &data );
    static user::LoginResponse extractUserActrionReplayPB( QByteArray &data );
    static user::Add extractUserAddPB( QByteArray &data );

    user::LoginResponse login(QString name, QString pass);
    void logout();


private:

    QTcpSocket *socket;
};

#endif // PROTOCOL_H
