#include "qcatalogserver.h"

QCatalogServer::QCatalogServer(QObject *parent) :
    QTcpServer(parent)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("ekatalog");
    db.setUserName("postgres");
    db.setPassword("postgres");
}

void QCatalogServer::startServer()
{
    int port = 2345; /// TODO odczyt z qsettings

    if(!this->listen(QHostAddress::Any, port))
    {
        qDebug() << "Could not start server";
    }
    else
    {
        qDebug() << "Listening to port " << port << "...";
    }
}


//bool EC_Server::hasPendingConnections() const
//{
//}
//QTcpSocket *EC_Server::nextPendingConnection()
//{
//}

void QCatalogServer::incomingConnection(qintptr socketDescriptor)
{
    // We have a new connection
    qDebug() << socketDescriptor << " Connecting...";

    // Every new connection will be run in a newly created thread
    QCatalogServerThread *thread = new QCatalogServerThread(socketDescriptor, this);

    // connect signal/slot
    // once a thread is not needed, it will be beleted later
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    thread->start();
}
