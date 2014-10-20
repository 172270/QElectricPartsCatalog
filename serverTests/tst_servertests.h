#ifndef TST_SERVERTESTS_H
#define TST_SERVERTESTS_H

#include <QString>
#include <QtTest>
#include <QtWebSockets>
#include <QHostAddress>

#include "messages/messagescontainer.h"

class tst_ServerTests : public QObject
{
    Q_OBJECT

public:
    tst_ServerTests();

    bool doConnect();
    bool waitForSignal(const char *amember, quint64 waitTime = 1000);
    bool waitForBinaryMessage();
protected slots:
    void signalArrived();
    void signalArrived(QByteArray);
private Q_SLOTS:
    void init();
    void initTestCase();
    void cleanupTestCase();
    void cleanup();

    void connectToServer();
    void serverResponseToPing();
    void serverDontRespondToUnknownData();

    void addBasicUserToServer();

    void loginToServer();
    void loginChangesUserStatus();
    void logoutFromServer();
    void loginWhileLogged();
    void logoutWhileNotLoged();
    void loginToServerBadPasswd();
    void loginToServerBadUser();

    void userAdd();
//    void userDel();


    //    void loginReciveLastLoginTime();

private:

    QWebSocket *socket;
    MessagesContainer *mc;
    QByteArray *binaryMessage;
};

#endif // TST_SERVERTESTS_H
