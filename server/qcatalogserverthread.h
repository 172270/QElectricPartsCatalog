#ifndef EC_THREAD_H
#define EC_THREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QDateTime>


class QCatalogServerThread : public QThread
{
    Q_OBJECT
public:
    explicit QCatalogServerThread(qintptr ID, QObject *parent = 0);

    void choseMessageHandler();
    void setData(QByteArray &&data);
signals:
    void requestLogin( QByteArray *data );
    //    void requestItem(QByteArray* data);


private slots:
    void readyRead();
    void disconnected();

    // QThread interface
protected:
    void run();
private:
    QSqlQuery *query;
    QSqlDatabase *db;
    qintptr socketDescriptor;
    QByteArray *data;
    QTcpSocket *socket;
};

#endif // EC_THREAD_H
