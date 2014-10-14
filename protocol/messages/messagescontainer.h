#ifndef MESSAGESCONTAINER_H
#define MESSAGESCONTAINER_H

#include "message_conteiner.pb.h"
#include "types.pb.h"

#include <QByteArray>

class MessagesContainer : public container::MessageContainer
{
public:
    MessagesContainer();

    void addMessage(MsgType type, QByteArray &&data);
    QByteArray getCapsuleAsArray(int i);

    QByteArray toArray();
    void fromArray(QByteArray &ba);
};

class MessageCapsule : public container::MessageCapsule
{
public:
    MessageCapsule(QByteArray &&capsule);
    QByteArray encapsulateMessage();
};

#endif // MESSAGESCONTAINER_H
