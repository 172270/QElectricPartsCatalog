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
        QCatalogServerThread* thread;
        try{
            thread = new QCatalogServerThread(ws, this);
        }
        catch(QSqlError e){
            qDebug()<<e.databaseText()<<e.driverText();
            ws->close();
        }
        if (thread){
            connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
            thread->start();
            thread->setPriority(QThread::LowestPriority);
        }
    }
}
