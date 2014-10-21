#ifndef QCATALOGSERVERWORKER_H
#define QCATALOGSERVERWORKER_H

#include <QObject>

#include <QDebug>
#include <QDateTime>

#include "workercache.h"
#include "messagehandlerinterface.h"

class QCatalogServerWorker : public QObject
{
    Q_OBJECT
public:
    explicit QCatalogServerWorker(QSqlDatabase db, QObject *parent = 0);
    ~QCatalogServerWorker();

signals:
    void responseAvalible(QByteArray res);
    void messageCorrupted();
    void unknownMessageType( MsgType );

public slots:
    void readyRead(const QByteArray &ba);

private:
    QMap<MsgType, MessageHandlerInterface*> *handlers;
    WorkerCache *workerCache;
};

#endif // QCATALOGSERVERWORKER_H
