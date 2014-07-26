#ifndef ECATALOGSOCKET_H
#define ECATALOGSOCKET_H

#include <QTcpSocket>

/**
 * @brief The ECatalogSocket class contains functions to connect to ECatalogServer
 */

class ECatalogSocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit ECatalogSocket(QTcpSocket *parent = 0);

signals:


public slots:

};


#endif // ECATALOGSOCKET_H
