#ifndef EC_SERVER_H
#define EC_SERVER_H

#include <QTcpServer>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>

#include "qcatalogserverthread.h"

class QCatalogServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit QCatalogServer(QObject *parent = 0);

    void startServer();
signals:

public slots:

    // QTcpServer interface
public:
//    bool hasPendingConnections() const;
//    QTcpSocket *nextPendingConnection();

protected:
    void incomingConnection(qintptr socketDescriptor) Q_DECL_OVERRIDE;
};

#endif // EC_SERVER_H
