#include "messagescontainer.h"
#include <QString>
#include <QDebug>
MessagesContainer::MessagesContainer()
{
}

void MessagesContainer::addMessage(const protocol::Message &msg)
{
    static QByteArray *ba = new QByteArray();
    protbuf::MessageCapsule *mc = add_capsules();
    mc->set_msgtype(msg.type());
    msg.toArray(ba);
    mc->set_data(ba->data(), ba->size());
}

void MessagesContainer::addMessage(protocol::Message *msg)
{
    static QByteArray *ba = new QByteArray();
    protbuf::MessageCapsule *mc = add_capsules();
    mc->set_msgtype(msg->type());
    msg->toArray(ba);
    mc->set_data(ba->data(), ba->size());
}

void MessagesContainer::addMessage(MsgType type, const QByteArray &ba)
{
    protbuf::MessageCapsule *mc = add_capsules();
    mc->set_msgtype(type);
    mc->set_data(ba.data(), ba.size());
}

void MessagesContainer::addMessage(MsgType type, QByteArray &&ba)
{
    protbuf::MessageCapsule *mc = add_capsules();
    mc->set_msgtype(type);
    mc->set_data(ba.data(), ba.size());
}

void MessagesContainer::addMessage(MsgType type, const QString &data)
{
    protbuf::MessageCapsule *mc = add_capsules();
    mc->set_msgtype(type);
    mc->set_data(data.toStdString());
}

void MessagesContainer::addMessage(MsgType type,QString &&data){
    protbuf::MessageCapsule *mc = add_capsules();
    mc->set_msgtype(type);
    mc->set_data(data.toStdString());
}

void MessagesContainer::addMessage(MsgType type, QByteArray *ba)
{
    protbuf::MessageCapsule *mc = add_capsules();
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
    return protbuf::MessageContainer::ByteSize();
}

bool MessagesContainer::ParseFromArray(const void *data, int size)
{
   return protbuf::MessageContainer::ParseFromArray(data,size);
}

bool MessagesContainer::SerializeToArray(void *data, int size) const
{
    return protbuf::MessageContainer::SerializeToArray(data,size);
}

MsgType MessagesContainer::type() const
{
    return MsgType::msgContainer;
}

int MessageCapsule::ByteSize() const
{
    return protbuf::MessageCapsule::ByteSize();
}

bool MessageCapsule::SerializeToArray(void *data, int size) const
{
    return protbuf::MessageCapsule::SerializeToArray(data,size);
}

bool MessageCapsule::ParseFromArray(const void *data, int size)
{
    return protbuf::MessageCapsule::ParseFromArray(data,size);
}

MsgType MessageCapsule::type() const
{
    return MsgType::msgCapsule;
}

MessageCapsule::MessageCapsule(const protbuf::MessageCapsule &other)
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
