#include "tst_servertests.h"


ServerTests::ServerTests()
{
}

void ServerTests::initTestCase()
{
    socket.connectToHost("127.0.0.1",2345);
    QVERIFY(socket.waitForConnected(150));
}

void ServerTests::cleanupTestCase()
{
    // socked should be opened
    QVERIFY(socket.state() == QAbstractSocket::ConnectedState );
    socket.disconnectFromHost();
    if (socket.state() == QAbstractSocket::UnconnectedState ||
            socket.waitForDisconnected(1000)){}
}

void ServerTests::loginToServer()
{
//    QByteArray data = Protocol::getLoginPB("admin", "passwd");

////     socked should be opened
//    QVERIFY(socket.state() == QAbstractSocket::ConnectedState );

//    socket.write(data);
//    QVERIFY2( socket.waitForBytesWritten(100)!= 0, "can't write data to server");
//    QVERIFY2( socket.waitForReadyRead(1000), "No replay from server");

//    data.clear();
//    data.append(socket.readAll());
//    QVERIFY2( data.at(1) == 14, "Message type not corrent");

//    user::LoginResponse ar = Protocol::extractUserActrionReplayPB( data );
//    QVERIFY2(ar.replay() == user::LOGIN_OK, "Loggin should be OK");
}

void ServerTests::logoutFromServer()
{
//    socket.write(Protocol::getLogoutPB());
//    QVERIFY2( socket.waitForBytesWritten(100)!= 0, "can't write data to server");
//    QVERIFY2( socket.waitForDisconnected(250), "server don't want to disconnect");
}

void ServerTests::loginWhileLogged()
{
//    user::LoginReplay ar ;
//    Protocol p = Protocol(&socket);
//    ar = p.login("admin","passwd");
//    QVERIFY2(ar.replay() == user::LOGIN_OK, "Loggin should be loged!!");
//    ar = p.login("admin","passwd");
//    QVERIFY2(ar.replay() == user::USER_ALREADY_LOGGED_IN, "Loggin should be already loged!!");
//    p.logout();
}

void ServerTests::logoutWhileNotLoged()
{
//    user::LoginReplay ar ;
//    Protocol p = Protocol(&socket);
//    socket.connectToHost("127.0.0.1",2345);
//    QVERIFY(socket.waitForConnected(150));
//    p.logout();
}

void ServerTests::loginToServerBadPasswd()
{
//    user::LoginReplay ar ;
//    Protocol p = Protocol(&socket);
//    ar = p.login("admin","bad_pass");
//    QVERIFY2(ar.replay() == user::BAD_USER_OR_PASSWD, "Loggin should be BAD_PASSWORD!!");
//    p.logout();
}

void ServerTests::loginToServerBadUser()
{
//    user::LoginReplay ar ;
//    Protocol p = Protocol(&socket);
//    ar = p.login("bad_user","bad_pass");
//    QVERIFY2(ar.replay() == user::BAD_USER_OR_PASSWD, "Loggin should be BAD_PASSWORD!!");
//    p.logout();
}

void ServerTests::userAdd()
{
//    QByteArray ba = Protocol::getUserAddPB("jakas_nazwa", "jakies_haslo", "cycki@wp.pl","","93248573");
//    socket.connectToHost("127.0.0.1",2345);
//    QVERIFY(socket.waitForConnected(150));
//    socket.write(ba);
//    socket.waitForBytesWritten(100);

}
