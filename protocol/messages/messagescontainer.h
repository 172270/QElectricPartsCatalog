#ifndef MESSAGESCONTAINER_H
#define MESSAGESCONTAINER_H

#include "message_conteiner.pb.h"
#include "message.h"
#include "types.pb.h"

#include <QByteArray>

class MessageCapsule;

class MessagesContainer : public protbuf::MessageContainer, public protocol::Message
{
public:
    MessagesContainer();
    void addMessage(protocol::Message *msg);
    void addMessage(MsgType type, const QByteArray &ba);
    void addMessage(MsgType type, QByteArray &&ba);
    void addMessage(MsgType type, const QString &data);
    void addMessage(MsgType type, QString &&data);
    void addMessage(MsgType type, QByteArray *ba);
    MessageCapsule getCapsule(int i);

    MsgType type() const;
    int ByteSize() const;
protected:
    bool SerializeToArray(void *data, int size) const;
    bool ParseFromArray(const void *data, int size);
};

class MessageCapsule : public protbuf::MessageCapsule, public protocol::Message
{
public:
    MessageCapsule(QByteArray &&capsule);
    MessageCapsule(const protbuf::MessageCapsule &other);

    QByteArray getData();
    MsgType type() const;

protected:
    int ByteSize() const;
    bool SerializeToArray(void *data, int size) const;
    bool ParseFromArray(const void *data, int size);
};

#endif // MESSAGESCONTAINER_H
