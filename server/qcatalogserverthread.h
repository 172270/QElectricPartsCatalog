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
//    QCatalogServerThread( QObject *parent = 0);
    explicit QCatalogServerThread(qintptr ID, QObject *parent = 0);

signals:


public slots:
    void readyRead();
    void disconnected();

    // QThread interface
protected:
    void run();

//    bool isLogged = false;
//    UserInfo user;
    QTcpSocket *socket;
    QSqlQuery *query;
    QSqlDatabase *db;
    QByteArray *data;
private:
//    void req_login(QByteArray *data);
//    void req_userAdd(QByteArray &data);
//    void req_logout();

    qintptr socketDescriptor;
};

#endif // EC_THREAD_H
