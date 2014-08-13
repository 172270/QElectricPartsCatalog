#include "qcatalogserverthread.h"
#include "messagetype.h"
#include "loginmessagehandler.h"


QCatalogServerThread::QCatalogServerThread(qintptr ID, QObject *parent) :
    QThread(parent), socketDescriptor(ID)
{
//    socket = new QTcpSocket();
//    data = new QByteArray();
//    if(!socket->setSocketDescriptor(this->socketDescriptor))
//    {
//        QString socketNotOpen = "socket can't be opened!!";
//        throw socketNotOpen ;
//    }
//    db = new QSqlDatabase(QSqlDatabase::cloneDatabase(QSqlDatabase::database(), QString::number(socketDescriptor)));
//    if (!db->open()){
//        QString dbNotOpen = "database can't be opened!!";
//        throw dbNotOpen ;
//    }
//    query = new QSqlQuery(*db);
}



//void QCatalogServerThread::readyRead()
//{
//        data->append(socket->readAll());
//        PBMessageTypeChecker * mt = new PBMessageTypeChecker( data );

//        if (mt->getType() == PBMsgType::LOGIN)
//            emit requestLogin(data);
//        else if( data->at(1) == PBMsgType::LOGOUT){
////            req_logout();
//        }
//        else if( data->at(1) == PBMsgType::USERADD ){
////            req_userAdd(data);
//        }

//        data->clear();
//}

//void QCatalogServerThread::disconnected()
//{
//    qDebug() << socketDescriptor << " Disconnected";
//    socket->deleteLater();
//    QString connection = db->connectionName();
//    db->close();
//    delete db;
//    QSqlDatabase::removeDatabase(connection);
//    exit(0);
//}

void QCatalogServerThread::run()
{
        // thread starts here
        qDebug() << " Thread started";

        // note - Qt::DirectConnection is used because it's multithreaded
        //        This makes the slot to be invoked immediately, when the signal is emitted.

//        connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
//        connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));

        // We'll have multiple clients, we want to know which is which
        qDebug() << socketDescriptor << " Client connected";

        // make this thread a loop,
        // thread will stay alive so that signal/slot to function properly
        // not dropped out in the middle when thread dies
        exec();
}
