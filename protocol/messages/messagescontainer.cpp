#include "messagescontainer.h"
#include <QString>

MessagesContainer::MessagesContainer()
{
}

void MessagesContainer::addMessage(MsgType type, QByteArray &&data)
{
    container::MessageCapsule *mc = add_container();
    mc->set_msgtype(type);
    mc->set_data(QString(data).toStdString());
}

QByteArray MessagesContainer::getCapsuleAsArray(int i)
{
    std::string msg = container(i).SerializeAsString();
    QString ba = QString::fromStdString(msg);
    return ba.toLatin1();
}

QByteArray MessagesContainer::toArray()
{
    QByteArray ba;
    ba.resize( ByteSize() );
    ba.append( SerializeToArray(ba.data(),ba.size() ));
    return ba;
}

void MessagesContainer::fromArray(QByteArray &ba)
{
    ParseFromArray(ba.data(), ba.size() );
}

MessageCapsule::MessageCapsule(QByteArray &&capsule)
{
    ParseFromArray(capsule.data(), capsule.size());
}

QByteArray MessageCapsule::encapsulateMessage()
{
    QString dataString = QString::fromStdString(data());
    return dataString.toLatin1();
}
