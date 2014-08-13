#include "tst_serversockettests.h"
#include <QSignalSpy>

tst_serverSockettests::tst_serverSockettests(QObject *parent) :
    QObject(parent)
{
   mySocket = new QTcpSocket();
}
