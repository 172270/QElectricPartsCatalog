#ifndef TST_SERVERSOCKETTESTS_H
#define TST_SERVERSOCKETTESTS_H

#include <QObject>

#include "../server/socket.h"

class tst_serverSockettests : public QObject
{
    Q_OBJECT
public:
    explicit tst_serverSockettests(QObject *parent = 0);

signals:

private slots:

private:
    QTcpSocket *mySocket;

};

#endif // TST_SERVERSOCKETTESTS_H
