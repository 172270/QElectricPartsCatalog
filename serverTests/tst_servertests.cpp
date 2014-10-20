#include "tst_servertests.h"

#include "messages/userregistrationmessage.h"
#include "messages/loginrequest.h"

#include <QSignalSpy>

bool signalSign = false;
tst_ServerWorkerTests::tst_ServerWorkerTests()
{
}

void tst_ServerWorkerTests::onResponseAvalible(QByteArray ba)
{
    binaryMessage->clear();
    binaryMessage->append(ba);
}

void tst_ServerWorkerTests::init()
{
}

void tst_ServerWorkerTests::initTestCase()
{
    mc = new MessagesContainer();
    worker = new QCatalogServerWorker(QSqlDatabase::database());
    responseSignalSpy = new QSignalSpy(worker, SIGNAL(responseAvalible(QByteArray)));
    connect(worker, SIGNAL(responseAvalible(QByteArray)), this, SLOT(onResponseAvalible(QByteArray)));
    worker->setDbConnectionName("");
    binaryMessage = new QByteArray();
}

void tst_ServerWorkerTests::cleanupTestCase()
{
    delete mc;
    delete binaryMessage;
    delete worker;
    delete responseSignalSpy;
}

void tst_ServerWorkerTests::cleanup()
{
    mc->Clear();
    responseSignalSpy->clear();
    binaryMessage->clear();
}


void tst_ServerWorkerTests::serverDontRespondToUnknownData()
{
    QSignalSpy spy(worker, SIGNAL(messageCorrupted() ));
    const QByteArray ba = QByteArray(1000,'\0');
    worker->readyRead(ba);
    QVERIFY( spy.count() == 1 );
}

void tst_ServerWorkerTests::addBasicUserToServer()
{
    UserRegistrationMessage registrationMessage;
    UserRegistrationMessageReplay registerResponse;

    registrationMessage.set_name(QStringLiteral("testuser"));
    registrationMessage.set_password(QStringLiteral("some_password"));
    registrationMessage.set_email("valid@email.com");

    mc->addMessage(&registrationMessage);
    QByteArray ba = mc->toArray();
    worker->readyRead(ba);

    ba.clear();
    mc->Clear();
    QVERIFY( mc->fromArray(binaryMessage) );

    ba = QByteArray (mc->getCapsule(0).toArray());

    QVERIFY( registerResponse.fromArray(ba));
    QVERIFY( registerResponse.replay(0) == protbuf::Replay::UserAddOk );
}

void tst_ServerWorkerTests::loginToServer()
{
    LoginRequest loginRequest;
    LoginRequestResponse loginResponse;

    loginRequest.set_name(QStringLiteral("testuser"));
    loginRequest.set_password(QStringLiteral("some_password"));

    mc->addMessage( &loginRequest );

    QByteArray ba = mc->toArray();
    worker->readyRead(ba);

    mc->Clear();
    QVERIFY(mc->fromArray(binaryMessage));
    QVERIFY(loginResponse.fromArray(mc->getCapsule(0).getData()));
    QVERIFY(loginResponse.replay() == protbuf::Replay::LoginPass);
}

void tst_ServerWorkerTests::loginChangesUserStatus()
{
    LoginRequest loginRequest;
    LoginRequestResponse loginResponse;

    loginRequest.set_name(QStringLiteral("testuser"));
    loginRequest.set_password(QStringLiteral("some_password"));

    mc->addMessage( &loginRequest );

    QByteArray ba = mc->toArray();
    worker->readyRead(ba);

    mc->Clear();
    QVERIFY(mc->fromArray(binaryMessage));
    QVERIFY(loginResponse.fromArray(mc->getCapsule(0).getData()));
    QVERIFY(loginResponse.replay() == protbuf::Replay::UserAlreadyLogged);
}

void tst_ServerWorkerTests::logoutFromServer()
{
//    socket.write(Protocol::getLogoutPB());
//    QVERIFY2( socket.waitForBytesWritten(100)!= 0, "can't write data to server");
//    QVERIFY2( socket.waitForDisconnected(250), "server don't want to disconnect");
}

void tst_ServerWorkerTests::loginWhileLogged()
{
//    user::LoginReplay ar ;
//    Protocol p = Protocol(&socket);
//    ar = p.login("admin","passwd");
//    QVERIFY2(ar.replay() == user::LOGIN_OK, "Loggin should be loged!!");
//    ar = p.login("admin","passwd");
//    QVERIFY2(ar.replay() == user::USER_ALREADY_LOGGED_IN, "Loggin should be already loged!!");
//    p.logout();
}

void tst_ServerWorkerTests::logoutWhileNotLoged()
{
//    user::LoginReplay ar ;
//    Protocol p = Protocol(&socket);
//    socket.connectToHost("127.0.0.1",2345);
//    QVERIFY(socket.waitForConnected(150));
//    p.logout();
}

void tst_ServerWorkerTests::loginToServerBadPasswd()
{
//    user::LoginReplay ar ;
//    Protocol p = Protocol(&socket);
//    ar = p.login("admin","bad_pass");
//    QVERIFY2(ar.replay() == user::BAD_USER_OR_PASSWD, "Loggin should be BAD_PASSWORD!!");
//    p.logout();
}

void tst_ServerWorkerTests::loginToServerBadUser()
{
//    user::LoginReplay ar ;
//    Protocol p = Protocol(&socket);
//    ar = p.login("bad_user","bad_pass");
//    QVERIFY2(ar.replay() == user::BAD_USER_OR_PASSWD, "Loggin should be BAD_PASSWORD!!");
//    p.logout();
}

void tst_ServerWorkerTests::userAdd()
{
//    QByteArray ba = Protocol::getUserAddPB("jakas_nazwa", "jakies_haslo", "cycki@wp.pl","","93248573");
//    socket.connectToHost("127.0.0.1",2345);
//    QVERIFY(socket.waitForConnected(150));
//    socket.write(ba);
//    socket.waitForBytesWritten(100);

}
