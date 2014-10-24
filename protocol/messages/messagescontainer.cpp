#include "messagescontainer.h"
#include <QString>
#include <QDebug>
MessagesContainer::MessagesContainer()
{
    ba = new QByteArray();
}

void MessagesContainer::addMessage(MsgType type, const QByteArray &data)
{
    protbuf::MessageCapsule *mc = add_capsules();
    mc->set_msgtype(type);
    mc->set_data(data.data(), data.size());
}

void MessagesContainer::addMessage(MsgType type, QByteArray &&data)
{
    protbuf::MessageCapsule *mc = add_capsules();
    mc->set_msgtype(type);
    mc->set_data(data.data(), data.size());
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

void MessagesContainer::addMessage(MsgType type, QByteArray *data)
{
    protbuf::MessageCapsule *mc = add_capsules();
    mc->set_msgtype(type);
    mc->set_data(data->data(), data->size());
    delete data;
}

MessageCapsule MessagesContainer::getCapsule(int i)
{
    return static_cast<MessageCapsule>(capsules(i));
}

MsgType MessagesContainer::type() const
{
    return MsgType::msgContainer;
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
