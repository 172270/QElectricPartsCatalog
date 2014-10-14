#ifndef EC_THREAD_H
#define EC_THREAD_H

#include <QThread>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QDateTime>

#include <QWebSocket>
#include "loginmessagehandler.h"

class QCatalogServerThread : public QThread
{
    Q_OBJECT
public:
    explicit QCatalogServerThread(QWebSocket *s, QObject *parent = 0);
    ~QCatalogServerThread();

signals:
    void requestLogin( QByteArray *data );
    //    void requestItem(QByteArray* data);


private slots:
    void readyRead(QByteArray ba);
    void disconnected();

    // QThread interface
protected:
    void run();
private:
    QSqlQuery *query;
    QSqlDatabase *db;
    QWebSocket *socket;
};

#endif // EC_THREAD_H
