#ifndef MESSAGESCONTAINER_H
#define MESSAGESCONTAINER_H

#include "message_conteiner.pb.h"
#include "types.pb.h"

#include <QByteArray>

class MessageCapsule;
class MessagesContainer : public container::MessageContainer
{
public:
    MessagesContainer();

    void addMessage(MsgType type, const QByteArray &ba);
    void addMessage(MsgType type, QByteArray &&ba);
    void addMessage(MsgType type, const QString &data);
    void addMessage(MsgType type, QString &&data);
    void addMessage(MsgType type, QByteArray *ba);
    MessageCapsule getCapsule(int i);

    QByteArray toArray();
    void fromArray(QByteArray &ba);
};

class MessageCapsule : public container::MessageCapsule
{
public:
    MessageCapsule(QByteArray &&capsule);
    MessageCapsule(const container::MessageCapsule &other);
    QByteArray getData();
    void fromArray(QByteArray &ba);
};

#endif // MESSAGESCONTAINER_H
