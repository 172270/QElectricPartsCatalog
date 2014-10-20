#pragma once
#include <QObject>

class QByteArray;

class MessageHandlerInterface : public QObject
{
    Q_OBJECT
public:
    explicit MessageHandlerInterface(QObject *parent = 0);

public slots:

signals:
    void responseAvalible();
    void response(QByteArray);

public slots:
    void setData(QByteArray );
};
