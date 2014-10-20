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

    QString getDbConnectionName() const;
    void setDbConnectionName(const QString &value);

signals:
    void responseAvalible(QByteArray *res);

public slots:

    void readyRead(QByteArray &ba);

private:
    MessagesContainer responseMessage;
    QString dbConnectionName;
};

#endif // QCATALOGSERVERWORKER_H
