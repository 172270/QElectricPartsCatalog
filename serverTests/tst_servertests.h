#ifndef TST_SERVERTESTS_H
#define TST_SERVERTESTS_H

#include <QString>
#include <QtTest>
#include <QHostAddress>

#include <qcatalogserverworker.h>

class tst_ServerWorkerTests : public QObject
{
    Q_OBJECT

public:
    tst_ServerWorkerTests();

    void waitForSignal(QSignalSpy spy);
public slots:

    void onResponseAvalible(QByteArray ba);
private Q_SLOTS:
    void init();
    void initTestCase();
    void cleanupTestCase();
    void cleanup();

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
private:

    QCatalogServerWorker *worker;
    MessagesContainer *mc;
    QByteArray *binaryMessage;

    QSignalSpy *responseSignalSpy;
};

#endif // TST_SERVERTESTS_H
