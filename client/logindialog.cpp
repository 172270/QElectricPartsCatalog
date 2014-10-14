#include "logindialog.h"
#include "ui_logindialog.h"

#include <QAbstractSocket>
#include <QTimer>

#include "messages/loginrequest.h"
#include "messages/messagescontainer.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog),
    m_socket(new QWebSocket("EKatalog client"))
{
    ui->setupUi(this);

    qRegisterMetaType<QAbstractSocket::SocketState>();

    ui->serverIp->setText(setup.value("serverIp", "localhost").toString());
    ui->serverPort->setText(setup.value("serverPort", 6666).toString());
    ui->userLogin->setText(setup.value("login", "").toString() );
    ui->userPassword->setEchoMode(QLineEdit::Password);

    connect(ui->testConnction, SIGNAL(clicked()), this, SLOT(doConnectTest()));
    connect(ui->login, static_cast<void (QPushButton::*)(bool)>(&QPushButton::clicked),
            [=](){
        doReconnect();
    });

    connect(this, &LoginDialog::loginFailure, [=](){
        ui->connectResponseLabel->setText("Autentification error");
    });

    connect(this, &LoginDialog::loginOk, [=](){
        ui->connectResponseLabel->setText("Autentification succes");
    });

    connect(m_socket, &QWebSocket::disconnected, [=](){
        qDebug()<<" peer disconnected";
        isConnected = false;
    });

    connect(m_socket, &QWebSocket::connected, [=]() {
        qDebug()<< " peer connected";
        isConnected = true;
        doLogin();
    });

    connect(m_socket, &QWebSocket::binaryMessageReceived, [=](QByteArray msg){
        qDebug()<<"recived message: "<< msg.toHex();
        MessagesContainer mc;
        mc.fromArray(msg);
        MessageCapsule mcap = MessageCapsule(mc.getCapsuleAsArray(0));

        if(mcap.msgtype() == MsgType::resLogin ){
            qDebug()<<" got login response";
            user::LoginResponse res;
            res.ParseFromString(mcap.data());
            if(res.replay() == user::Replay::LOGIN_OK){
                emit loginOk();
            }
            else if(res.replay() == user::Replay::BAD_USER_OR_PASSWD ){
                emit loginFailure();
            }
        }
    });
}

void LoginDialog::doReconnect(){
    static QString host = "";
    static int port = 0;

    QUrl url;
    url.setHost(ui->serverIp->text());
    url.setPort(ui->serverPort->text().toInt());
    url.setScheme("ws");

    if( host != url.host() || port != url.port() ){
        port = url.port();
        host = url.host();
        qDebug() << "closing socket";
        m_socket->close();
        isConnected = false;
    }

    if(!isConnected){
        m_socket->open(url);
    }
    else{
        doLogin();
    }
}

void LoginDialog::doLogin()
{
    LoginRequest req;
    req.set_name( ui->userLogin->text() );
    req.set_password( ui->userPassword->text() );

    MessagesContainer mc;
    mc.addMessage(MsgType::reqLogin, req.toArray());

    qDebug()<<" socket connected!: sending message: "<< QString(mc.toArray());

    m_socket->sendBinaryMessage(mc.toArray());
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::doConnectTest()
{
    static QWebSocket *socket = new QWebSocket();
    QUrl url;
    url.setHost(ui->serverIp->text());
    url.setPort(ui->serverPort->text().toInt());
    url.setScheme("ws");

    connect(socket, &QWebSocket::connected, [=]() {
        ui->connectResponseLabel->setText("connection ok!");
        socket->close(QWebSocketProtocol::CloseCodeNormal, "Test connection, sorry for interrupt ;)");
        socket->disconnect();
    });

    connect(socket, static_cast< void(QWebSocket::*)(QAbstractSocket::SocketError)>(&QWebSocket::error), [=](QAbstractSocket::SocketError e){
        qDebug()<<"error" << e;
        ui->connectResponseLabel->setText("connection error: " + QString::number(e));
        socket->disconnect();
    });

    qDebug()<<" try to connect to " << url.toString();
    socket->open(url);
}

