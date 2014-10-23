#include "qcatalogserverthread.h"

QCatalogServerThread::QCatalogServerThread(QWebSocket *s, QObject *parent) :
    QThread(parent)
{
    static int id = 0;
    dbConnectionName = QString::number(id++);

    socket = s;
    userIsLogged = false;

    db = new QSqlDatabase(QSqlDatabase::addDatabase("QPSQL", dbConnectionName));
    db->setDatabaseName("ekatalog_tests"); /// TODO change to QSettings
    db->setHostName("localhost");
    db->setUserName("postgres");
    db->setPassword("postgres");

    if (!db->open()){
        throw db->lastError();
    }

    worker = new QCatalogServerWorker(*db);
}

QCatalogServerThread::~QCatalogServerThread()
{
    delete worker;
    QString connection = db->connectionName();
    db->close();
    delete db;
    QSqlDatabase::removeDatabase(connection);
}

void QCatalogServerThread::send(QByteArray ba)
{
    qDebug() << "Sending " << ba.size() << " bytes";
//    qDebug() << ba.toHex();
    if(socket->isValid()){
        bytesWritten += socket->sendBinaryMessage(ba);
    }
}

void QCatalogServerThread::disconnected()
{
    socket->deleteLater();
    exit(0);
}

void QCatalogServerThread::run()
{
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(binaryMessageReceived(QByteArray)), worker, SLOT(readyRead(QByteArray)), Qt::DirectConnection);
    connect(worker, SIGNAL(responseAvalible(QByteArray)), this, SLOT(send(QByteArray)));
    exec();
}
