#include "messagescontainer.h"
#include <QString>
#include <QDebug>
MessagesContainer::MessagesContainer()
{
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

QByteArray MessagesContainer::toArray()
{
    QByteArray ba;
    int size = ByteSize();
    ba.resize(size);
    SerializeToArray(ba.data(), size );
    return ba;
}

void MessagesContainer::fromArray(QByteArray &ba)
{
    ParseFromArray(ba.data(), ba.size() );
}

void MessageCapsule::fromArray(QByteArray &ba){
    ParseFromArray(ba.data(), ba.size());
}

MessageCapsule::MessageCapsule(QByteArray &&capsule)
{
    fromArray(capsule);
}

MessageCapsule::MessageCapsule(const container::MessageCapsule &other)
{
    this->MergeFrom(other);
}

QByteArray MessageCapsule::getData()
{
    return QByteArray(data().data(), data().size());
}
