#include "tst_servertests.h"

#include "messages/userregistrationmessage.h"
#include "messages/loginrequest.h"

#include <QSignalSpy>

bool signalSign = false;
tst_ServerTests::tst_ServerTests()
{
}

void tst_ServerTests::init()
{
}

void tst_ServerTests::initTestCase()
{
    mc = new MessagesContainer();
    socket = new QWebSocket();
    binaryMessage = new QByteArray();
}

void tst_ServerTests::cleanupTestCase()
{
    delete mc;
    delete binaryMessage;
}

void tst_ServerTests::cleanup()
{
    mc->Clear();
    binaryMessage->clear();
}

bool tst_ServerTests::doConnect()
{
    QString url("ws://localhost:6666");
    socket->open(url);
    QEventLoop loop;
    bool ret = false;
    QTimer::singleShot(1000,&loop,SLOT(quit()));
    connect(socket, SIGNAL(connected()), &loop, SLOT(quit()));
    connect(socket, &QWebSocket::connected, [&](){
        if (socket->state() == QAbstractSocket::ConnectedState)
            ret = true;
    });
    loop.exec();
    return ret;
}


void tst_ServerTests::signalArrived(){
    signalSign = true;
}

void tst_ServerTests::signalArrived(QByteArray ba){
    qDebug()<<ba.toHex();
}

bool tst_ServerTests::waitForSignal( const char * amember, quint64 waitTime ){
    QSignalSpy spy(socket, amember);

    spy.wait(waitTime);
    if(spy.count())
        return true;
    return false;

//    QEventLoop loop;
//    bool ret = false;
//    QTimer::singleShot(waitTime,&loop,SLOT(quit()));
//    connect(socket, amember, this, SLOT(signalArrived()), Qt::DirectConnection);
//    connect(socket, amember, &loop, SLOT(quit()), Qt::DirectConnection);
//    loop.exec();
//    disconnect(socket, amember, this, SLOT(signalArrived()));
//    disconnect(socket, amember, &loop, SLOT(quit()));
//    if (signalSign)
//        ret = true;
//    signalSign = false;

//    return ret;
}

bool tst_ServerTests::waitForBinaryMessage(){
    QEventLoop loop;
    bool ret = false;
    QTimer::singleShot(1000,&loop,SLOT(quit()));

    connect(socket, &QWebSocket::binaryMessageReceived, [&](QByteArray mes){
        binaryMessage->append(mes);
        ret = true;
    });

    loop.exec();
    return ret;
}

void tst_ServerTests::connectToServer()
{
    QVERIFY( doConnect() );

}

void tst_ServerTests::serverResponseToPing()
{
    socket->ping();
    QVERIFY( waitForSignal(SIGNAL(pong(quint64, QByteArray)), 100));
}

void tst_ServerTests::serverDontRespondToUnknownData()
{
    socket->sendBinaryMessage(QByteArray(10000,'s'));
    QVERIFY(  waitForSignal(SIGNAL(bytesWritten(qint64))));
    QVERIFY( !waitForSignal(SIGNAL(binaryFrameReceived(const QByteArray, bool)),100));
}

void tst_ServerTests::addBasicUserToServer()
{
    UserRegistrationMessage registrationMessage;
    UserRegistrationMessageReplay registerResponse;

    registrationMessage.set_name(QStringLiteral("testuser"));
    registrationMessage.set_password(QStringLiteral("some_password"));
    registrationMessage.set_email("valid@email.com");

    mc->addMessage(MsgType::addUser, registrationMessage.toArray());
    socket->sendBinaryMessage(mc->toArray());

    QVERIFY( waitForBinaryMessage() );
    mc->Clear();
    QVERIFY( mc->fromArray(binaryMessage) );
    QByteArray ba = QByteArray (mc->getCapsule(0).toArray().data(), mc->getCapsule(0).toArray().size());

    QVERIFY( registerResponse.fromArray(ba));
    QVERIFY( registerResponse.replay(0) == user::Replay::UserAddOk );
}

void tst_ServerTests::loginToServer()
{
    LoginRequest loginRequest;
    LoginRequestResponse loginResponse;

    loginRequest.set_name(QStringLiteral("testuser"));
    loginRequest.set_password(QStringLiteral("some_password"));

    mc->addMessage( &loginRequest );

    socket->sendBinaryMessage(mc->toArray());
    QVERIFY( waitForBinaryMessage() );

    mc->Clear();
    QVERIFY(mc->fromArray(binaryMessage));
    QVERIFY(loginResponse.fromArray(mc->getCapsule(0).getData()));
    QVERIFY(loginResponse.replay() == user::Replay::LoginPass);
}

void tst_ServerTests::logoutFromServer()
{
//    socket.write(Protocol::getLogoutPB());
//    QVERIFY2( socket.waitForBytesWritten(100)!= 0, "can't write data to server");
//    QVERIFY2( socket.waitForDisconnected(250), "server don't want to disconnect");
}

void tst_ServerTests::loginWhileLogged()
{
//    user::LoginReplay ar ;
//    Protocol p = Protocol(&socket);
//    ar = p.login("admin","passwd");
//    QVERIFY2(ar.replay() == user::LOGIN_OK, "Loggin should be loged!!");
//    ar = p.login("admin","passwd");
//    QVERIFY2(ar.replay() == user::USER_ALREADY_LOGGED_IN, "Loggin should be already loged!!");
//    p.logout();
}

void tst_ServerTests::logoutWhileNotLoged()
{
//    user::LoginReplay ar ;
//    Protocol p = Protocol(&socket);
//    socket.connectToHost("127.0.0.1",2345);
//    QVERIFY(socket.waitForConnected(150));
//    p.logout();
}

void tst_ServerTests::loginToServerBadPasswd()
{
//    user::LoginReplay ar ;
//    Protocol p = Protocol(&socket);
//    ar = p.login("admin","bad_pass");
//    QVERIFY2(ar.replay() == user::BAD_USER_OR_PASSWD, "Loggin should be BAD_PASSWORD!!");
//    p.logout();
}

void tst_ServerTests::loginToServerBadUser()
{
//    user::LoginReplay ar ;
//    Protocol p = Protocol(&socket);
//    ar = p.login("bad_user","bad_pass");
//    QVERIFY2(ar.replay() == user::BAD_USER_OR_PASSWD, "Loggin should be BAD_PASSWORD!!");
//    p.logout();
}

void tst_ServerTests::userAdd()
{
//    QByteArray ba = Protocol::getUserAddPB("jakas_nazwa", "jakies_haslo", "cycki@wp.pl","","93248573");
//    socket.connectToHost("127.0.0.1",2345);
//    QVERIFY(socket.waitForConnected(150));
//    socket.write(ba);
//    socket.waitForBytesWritten(100);

}
