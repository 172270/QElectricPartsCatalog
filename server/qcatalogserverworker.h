#ifndef QCATALOGSERVERWORKER_H
#define QCATALOGSERVERWORKER_H

#include <QObject>

#include <QDebug>
#include <QSqlDatabase>
#include <QDateTime>

#include "messages/messagescontainer.h"
#include "loginmessagehandler.h"
#include "registerusermessagehandler.h"

class QCatalogServerWorker : public QObject
{
    Q_OBJECT
public:
    explicit QCatalogServerWorker(QSqlDatabase db, QObject *parent = 0);

    QString getDbConnectionName() const;
    void setDbConnectionName(const QString &value);

signals:
    void responseAvalible(QByteArray res);
    void messageCorrupted();
    void unknownMessageType( MsgType );

public slots:

    void readyRead(QByteArray &ba);

private:
    MessagesContainer responseMessage;
    LoginMessageHandler loginHandler;
    QString dbConnectionName;
};

#endif // QCATALOGSERVERWORKER_H
