#ifndef EC_SERVER_H
#define EC_SERVER_H

#include <QWebSocketServer>
#include <QSettings>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>

#include "qcatalogserverthread.h"

class QCatalogServer : public QWebSocketServer
{
    Q_OBJECT
public:
    explicit QCatalogServer(QObject *parent = 0);
    ~QCatalogServer(){;}

    void startServer();
signals:

public slots:

    // QTcpServer interface
public:
//    bool hasPendingConnections() const;
//    QTcpSocket *nextPendingConnection();

protected:
//    void incomingConnection(qintptr socketDescriptor) Q_DECL_OVERRIDE;
    QSettings setup;
private slots:
    void incomingConnection();
};

#endif // EC_SERVER_H
