#include "logindialog.h"
#include "ui_logindialog.h"

#include <QAbstractSocket>
#include <QTimer>

#include "messages/loginrequest.h"
#include "messages/messagescontainer.h"

#include "adduserdialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog),
    m_socket(new QWebSocket("EKatalog client"))
{
    ui->setupUi(this);
    ui->connection_groupbox->setChecked(false);

    qRegisterMetaType<QAbstractSocket::SocketState>();

    ui->serverIp->setText(setup.value("serverIp", "localhost").toString());
    ui->serverPort->setText(setup.value("serverPort", 6666).toString());
    ui->userLogin->setText(setup.value("login", "").toString() );
    ui->userPassword->setEchoMode(QLineEdit::Password);

    connect(ui->testConnction, SIGNAL(clicked()), this, SLOT(doConnectTest()));

    connect(ui->login, static_cast<void (QPushButton::*)(bool)>(&QPushButton::clicked),
            [=](){
        doReconnect();
        doLogin();
    });

    connect(ui->registerNewUser, static_cast<void (QPushButton::*)(bool)>(&QPushButton::clicked),
            [=](){
        doReconnect();
        if(m_socket->state() == QAbstractSocket::ConnectedState){
            disconnect(m_socket, SIGNAL(binaryMessageReceived(QByteArray)), this, SLOT(readyRead(QByteArray)));
            AddUserDialog *dialog = new AddUserDialog(m_socket, this);
            dialog->exec();
            connect(m_socket, SIGNAL(binaryMessageReceived(QByteArray)), this, SLOT(readyRead(QByteArray)));
        }
        else{
            ui->connectResponseLabel->setText("peer disconnected");
        }
    });

    connect(this, &LoginDialog::loginFailure, [=](){
        ui->connectResponseLabel->setText("Autentification error");
    });

    connect(this, &LoginDialog::loginOk, [=](){
        ui->connectResponseLabel->setText("Autentification succes");
        setup.setValue("login", ui->userLogin->text() );
        setup.setValue("serverIp", ui->serverIp->text() );
        setup.setValue("serverPort", ui->serverPort->text() );
        this->accept();
    });

    connect(m_socket, &QWebSocket::disconnected, [=](){
        qDebug()<<" peer disconnected";
        ui->connectResponseLabel->setText("peer disconnected");
    });

    connect(m_socket, &QWebSocket::connected, [=]() {
        qDebug()<< " peer connected";
    });

    connect(m_socket, SIGNAL(binaryMessageReceived(QByteArray)), this, SLOT(readyRead(QByteArray)));
}

void LoginDialog::readyRead(QByteArray msg){
    MessagesContainer mc;
    mc.fromArray(msg);
    for(int i = 0; i<mc.capsules().size();++i)
        if(mc.getCapsule(i).msgtype() == MsgType::resLogin ){
            qDebug()<<" got login response";
            protbuf::LoginResponse res;
            res.ParseFromString(mc.getCapsule(i).data());
            if(res.replay() == protbuf::Replay::LoginPass){
                emit loginOk();
            }
            else if(res.replay() == protbuf::Replay::LoginDeny ){
                emit loginFailure();
            }
        }
        else if(mc.getCapsule(i).msgtype() == MsgType::msgUser){
            qDebug()<<" got user response";
            user.fromArray(mc.getCapsule(i).getData().data());
        }
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
    }

    if(m_socket->state() == QAbstractSocket::UnconnectedState){
        m_socket->open(url);
        QEventLoop pause;
        QTimer *timer = new QTimer();
        timer->setSingleShot(1000);
        connect(timer, SIGNAL(timeout()), &pause, SLOT(quit()));
        connect(m_socket, SIGNAL( connected() ), &pause, SLOT(quit()));
        pause.exec();
    }
}

void LoginDialog::doLogin()
{
    LoginRequest req;
    req.set_name( ui->userLogin->text() );
    req.set_password( ui->userPassword->text() );

    MessagesContainer mc;
    mc.addMessage(&req);

    qDebug()<<" socket connected!: sending message: "<< QString(mc.toArray().toHex());

    m_socket->sendBinaryMessage(mc.toArray());
}
QWebSocket *LoginDialog::socket() const
{
    return m_socket;
}

void LoginDialog::setSocket(QWebSocket *socket)
{
    m_socket = socket;
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

