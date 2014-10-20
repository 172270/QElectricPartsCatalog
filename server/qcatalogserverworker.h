#ifndef QCATALOGSERVERWORKER_H
#define QCATALOGSERVERWORKER_H

#include <QObject>

#include <QDebug>
#include <QDateTime>

#include "messages/messagescontainer.h"
#include "loginmessagehandler.h"
#include "registerusermessagehandler.h"

class QCatalogServerWorker : public QObject
{
    Q_OBJECT
public:
    explicit QCatalogServerWorker(QSqlDatabase db, QObject *parent = 0);

signals:
    void responseAvalible(QByteArray res);
    void messageCorrupted();
    void unknownMessageType( MsgType );

public slots:
    void readyRead(const QByteArray &ba);

private:
    MessagesContainer responseMessage;
    RegisterUserMessageHandler userRegisterHandler;
    LoginMessageHandler loginHandler;
};

#endif // QCATALOGSERVERWORKER_H
