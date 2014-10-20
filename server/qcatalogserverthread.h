#ifndef EC_THREAD_H
#define EC_THREAD_H

#include <QThread>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QDateTime>
#include <QWebSocket>

#include "qcatalogserverworker.h"


class QCatalogServerThread : public QThread
{
    Q_OBJECT
public:
    explicit QCatalogServerThread(QWebSocket *s, QObject *parent = 0);
    ~QCatalogServerThread();

public slots:
    void send(const QByteArray &ba);
signals:
    void requestLogin( QByteArray &data );

private slots:
    void disconnected();

protected:
    void run();
private:

    bool userIsLogged;
    QSqlDatabase *db;
    QWebSocket *socket;

    QCatalogServerWorker *worker;
    QString dbConnectionName;
    quint64 bytesWritten = 0;
};

#endif // EC_THREAD_H
