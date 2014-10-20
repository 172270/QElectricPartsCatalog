#include "qcatalogserver.h"

#include <QWebSocket>
#include <QPointer>

QCatalogServer::QCatalogServer(QObject *parent) :
    QWebSocketServer(QStringLiteral("EKATALOG"),QWebSocketServer::NonSecureMode, parent)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("ekatalog_tests");
    db.setUserName("postgres");
    db.setPassword("postgres");
}

void QCatalogServer::startServer()
{
    quint16 port = setup.value("listenPort", 6666).toUInt();
     if(!this->listen(QHostAddress::Any, port)){
         qDebug() << "Could not start server";
     }
     else{
         qDebug() << "Listening to port " << port << "...";
     }

     connect(this, SIGNAL(newConnection()), this, SLOT(incomingConnection()));
}


void QCatalogServer::incomingConnection()
{
    if(hasPendingConnections()){
        QWebSocket *ws;
        ws = nextPendingConnection();
        // We have a new panding connection
        qDebug() << ws->peerAddress() << " Connecting...";

        QCatalogServerThread* thread;
        thread = new QCatalogServerThread(ws, this);

        if (thread){
            connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
            thread->start();
            thread->setPriority(QThread::LowestPriority);
        }
    }
}
