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
    explicit QCatalogServerThread(qintptr ID, QObject *parent = 0);

signals:
//    void requestLogin( QByteArray *data );
//    void requestItem(QByteArray* data);


//private slots:
//    void readyRead();
//    void disconnected();

    // QThread interface
protected:
    void run();
private:
    qintptr socketDescriptor;
};

#endif // EC_THREAD_H
