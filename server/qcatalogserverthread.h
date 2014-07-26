#ifndef EC_THREAD_H
#define EC_THREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QDateTime>

class UserInfo
{
public:
    QString name;
    int ID;
	QDateTime firstLogin;
	QDateTime lastLogin;
	quint32 queriesCount;
	quint32 itemsCount;
	quint32 editionsCount;
};

class QCatalogServerThread : public QThread
{
    Q_OBJECT
public:
    QCatalogServerThread( QObject *parent = 0);
    explicit QCatalogServerThread(qintptr ID, QObject *parent = 0);

signals:
    void error(QTcpSocket::SocketError error);

public slots:
    void readyRead();
    void disconnected();

    // QThread interface
protected:
    void run();

private:
    void req_login(QByteArray &data);
    void req_userAdd(QByteArray &data);
    void req_logout();

    UserInfo user;

    QTcpSocket *socket;
    qintptr socketDescriptor;
    QSqlQuery *query;
    QSqlDatabase *db;

    bool isLogged = false;
};

#endif // EC_THREAD_H
