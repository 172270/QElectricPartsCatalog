#include "messagescontainer.h"
#include <QString>
#include <QDebug>
MessagesContainer::MessagesContainer()
{
}

void MessagesContainer::addMessage(protocol::Message *msg)
{
    container::MessageCapsule *mc = add_capsules();
    mc->set_msgtype(msg->type());
    QByteArray ba = msg->toArray();
    mc->set_data(ba.data(), ba.size());
}

void MessagesContainer::addMessage(MsgType type, const QByteArray &ba)
{
    container::MessageCapsule *mc = add_capsules();
    mc->set_msgtype(type);
    mc->set_data(ba.data(), ba.size());
}

void MessagesContainer::addMessage(MsgType type, QByteArray &&ba)
{
    container::MessageCapsule *mc = add_capsules();
    mc->set_msgtype(type);
    mc->set_data(ba.data(), ba.size());
}

void MessagesContainer::addMessage(MsgType type, const QString &data)
{
    container::MessageCapsule *mc = add_capsules();
    mc->set_msgtype(type);
    mc->set_data(data.toStdString());
}

void MessagesContainer::addMessage(MsgType type,QString &&data){
    container::MessageCapsule *mc = add_capsules();
    mc->set_msgtype(type);
    mc->set_data(data.toStdString());
}

void MessagesContainer::addMessage(MsgType type, QByteArray *ba)
{
    container::MessageCapsule *mc = add_capsules();
    mc->set_msgtype(type);
    mc->set_data(ba->data(), ba->size());
    delete ba;
}

MessageCapsule MessagesContainer::getCapsule(int i)
{
    return static_cast<MessageCapsule>(capsules(i));
}

int MessagesContainer::ByteSize() const
{
    return container::MessageContainer::ByteSize();
}

bool MessagesContainer::ParseFromArray(const void *data, int size)
{
   return container::MessageContainer::ParseFromArray(data,size);
}

bool MessagesContainer::SerializeToArray(void *data, int size) const
{
    return container::MessageContainer::SerializeToArray(data,size);
}

MsgType MessagesContainer::type() const
{
    return MsgType::msgContainer;
}

int MessageCapsule::ByteSize() const
{
    return container::MessageCapsule::ByteSize();
}

bool MessageCapsule::SerializeToArray(void *data, int size) const
{
    return container::MessageCapsule::SerializeToArray(data,size);
}

bool MessageCapsule::ParseFromArray(const void *data, int size)
{
    return container::MessageCapsule::ParseFromArray(data,size);
}

MsgType MessageCapsule::type() const
{
    return MsgType::msgCapsule;
}

MessageCapsule::MessageCapsule(const container::MessageCapsule &other)
{
    this->MergeFrom(other);
}

QByteArray MessageCapsule::getData()
{
    return QByteArray(data().data(), data().size());
}

//MsgType MessagesContainer::type() const
//{
//    return MsgType::msgContainer;
//}
