#ifndef QCATALOGSERVERWORKER_H
#define QCATALOGSERVERWORKER_H

#include <QObject>

#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QDateTime>
#include "messages/messagescontainer.h"

class QCatalogServerWorker : public QObject
{
    Q_OBJECT
public:
    explicit QCatalogServerWorker(QObject *parent = 0);

signals:

public slots:

    void readyRead(QByteArray ba);


private:
    MessagesContainer responseMessage;
};

#endif // QCATALOGSERVERWORKER_H
