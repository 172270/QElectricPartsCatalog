#ifndef MESSAGESCONTAINER_H
#define MESSAGESCONTAINER_H

#include "message_conteiner.pb.h"
#include "message.h"
#include "types.pb.h"

#include <QByteArray>

class MessageCapsule;

class MessagesContainer : public protocol::QMessage<protbuf::MessageContainer>
{
public:
    MessagesContainer();
    template <class baseClass>
    void addMessage(baseClass msg)
    {
        protbuf::MessageCapsule *mc = add_capsules();
        mc->set_msgtype(msg.type());
        msg.toArray(ba);
        mc->set_data(ba->data(), ba->size());
    }

    template <class baseClass>
    void addMessage( baseClass *msg)
    {
        protbuf::MessageCapsule *mc = add_capsules();
        mc->set_msgtype(msg->type());
        msg->toArray(ba);
        mc->set_data(ba->data(), ba->size());
    }

    void addMessage(MsgType type, const QByteArray &data);
    void addMessage(MsgType type, QByteArray &&data);
    void addMessage(MsgType type, const QString &data);
    void addMessage(MsgType type, QString &&data);
    void addMessage(MsgType type, QByteArray *data);
    MessageCapsule getCapsule(int i);

    MsgType type() const;

private:
    QByteArray *ba;
};

class MessageCapsule : public protocol::QMessage<protbuf::MessageCapsule>
{
public:
    MessageCapsule(QByteArray &&capsule);
    MessageCapsule(const protbuf::MessageCapsule &other);

    QByteArray getData();
    MsgType type() const;
};

#endif // MESSAGESCONTAINER_H
