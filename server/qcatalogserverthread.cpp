#include "qcatalogserverthread.h"

QCatalogServerThread::QCatalogServerThread(QWebSocket *s, QObject *parent) :
    QThread(parent)
{
    static int id = 0;
    dbConnectionName = QString::number(id++);
    worker = new QCatalogServerWorker();
    worker->setDbConnectionName(dbConnectionName);
    socket = s;
    userIsLogged = false;

    db = new QSqlDatabase(QSqlDatabase::addDatabase("QPSQL", dbConnectionName));
    db->setDatabaseName("ekatalog_tests"); /// TODO change to QSettings
    db->setHostName("localhost");
    db->setUserName("postgres");
    db->setPassword("postgres");

    if (!db->open()){
        QString dbNotOpen = "database can't be opened!!";
        throw dbNotOpen ;
    }
}

QCatalogServerThread::~QCatalogServerThread()
{
}

void QCatalogServerThread::send(const QByteArray *ba){
    bytesWritten += socket->sendBinaryMessage(*ba);
}

void QCatalogServerThread::disconnected()
{
    socket->deleteLater();
    QString connection = db->connectionName();
    db->close();
    delete db;
    QSqlDatabase::removeDatabase(connection);
    exit(0);
}

void QCatalogServerThread::run()
{
    qDebug() << " Thread: "<< this->currentThreadId() << "started with stack size set to" << this->stackSize() ;

    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(binaryMessageReceived(QByteArray&)), worker, SLOT(readylRead(QByteArray&)), Qt::DirectConnection);
    connect(worker, SIGNAL(responseAvalible(QByteArray)), this, SLOT(send(const QByteArray*)));

    exec();
}
