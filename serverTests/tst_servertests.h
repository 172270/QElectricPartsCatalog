#ifndef TST_SERVERTESTS_H
#define TST_SERVERTESTS_H

#include <QString>
#include <QtTest>
#include <QTcpSocket>
#include <QHostAddress>

class ServerTests : public QObject
{
    Q_OBJECT

public:
    ServerTests();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void loginToServer();
    void logoutFromServer();
    void loginWhileLogged();
    void logoutWhileNotLoged();
    void loginToServerBadPasswd();
    void loginToServerBadUser();

    void userAdd();
//    void userDel();


    //    void loginReciveLastLoginTime();

private:

    QTcpSocket socket;
};

#endif // TST_SERVERTESTS_H
