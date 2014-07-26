#include "qcatalogserverthread.h"
#include "messagetype.h"
#include "loginmessagehandler.h"


QCatalogServerThread::QCatalogServerThread(qintptr ID, QObject *parent) :
    QThread(parent), socketDescriptor(ID)
{
    socket = new QTcpSocket();
    data = new QByteArray();
    if(!socket->setSocketDescriptor(this->socketDescriptor))
    {
        QString socketNotOpen = "socket can't be opened!!";
        throw socketNotOpen ;
    }
    db = new QSqlDatabase(QSqlDatabase::cloneDatabase(QSqlDatabase::database(), QString::number(socketDescriptor)));
    if (!db->open()){
        QString dbNotOpen = "database can't be opened!!";
        throw dbNotOpen ;
    }
    query = new QSqlQuery(*db);
}



void QCatalogServerThread::readyRead()
{
        data->append(socket->readAll());
        PBMessageTypeChecker * mt = new PBMessageTypeChecker( data );

        if (data->at(1) == PBMsgType::LOGIN){
//            req_login(data);
        }
        else if( data->at(1) == PBMsgType::LOGOUT){
//            req_logout();
        }
        else if( data->at(1) == PBMsgType::USERADD ){
//            req_userAdd(data);
        }

        data->clear();
}

void QCatalogServerThread::disconnected()
{
    qDebug() << socketDescriptor << " Disconnected";
    socket->deleteLater();
    QString connection = db->connectionName();
    db->close();
    delete db;
    QSqlDatabase::removeDatabase(connection);
    exit(0);
}

void QCatalogServerThread::run()
{
        // thread starts here
        qDebug() << " Thread started";

        // note - Qt::DirectConnection is used because it's multithreaded
        //        This makes the slot to be invoked immediately, when the signal is emitted.

        connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
        connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));

        // We'll have multiple clients, we want to know which is which
        qDebug() << socketDescriptor << " Client connected";

        // make this thread a loop,
        // thread will stay alive so that signal/slot to function properly
        // not dropped out in the middle when thread dies
        exec();
}

//void QCatalogServerThread::req_login(QByteArray *data)
//{
//    LoginMessageHandler msgHandler = LoginMessageHandler();
////    msgHandler.setData(data);

//}

//void QCatalogServerThread::req_userAdd(QByteArray &data)
//{
////    QElapsedTimer t;
////    t.start();
////    user::Add ua = Protocol::extractUserAddPB(data);
////    user::AddUserReplay ur;

////    ur.set_msgtype(MSG_USERADDREPLAY_ID);
////    QString q;
////    /// NOTE nie potrzeba blokowac tabeli, kolumna z uzytkownikiem jest unique

//////    PREPARE fooplan (int, text, bool, numeric) AS
//////        INSERT INTO foo VALUES($1, $2, $3, $4);
//////    EXECUTE fooplan(1, 'Hunter Valley', 't', 200.00);

////    /// TODO zaimplementowac dodawanie uzytkowanikow
////    q.append("INSERT INTO USERS (name,password,email "+
////             (ua.has_address()     ? (QString(',')+QString::fromStdString("address")     ): QString("") ) +
////             (ua.has_phonenumber() ? (QString(',')+QString::fromStdString("phonenumber") ): QString("") ) +
////             ") VALUES (?,?,? " +
////             (ua.has_address()     ? (QString(',')+QString('?')) : QString("") ) +
////             (ua.has_phonenumber() ? (QString(',')+QString('?')) : QString("") ) +
////             ");");
////    qDebug()<< q;
//}

//void QCatalogServerThread::req_logout()
//{
//    isLogged = false;
//    socket->disconnectFromHost();
//}
