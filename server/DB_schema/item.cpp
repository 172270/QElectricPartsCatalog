#include "item.h"

quint32 Item::getID() const
{
    return id();
}

void Item::set_name(const QString &name)
{
    item::Item::set_name(name.toStdString());
}

QString Item::getName() const
{
    return QString::fromStdString(name());
}

void Item::set_symbol(const QString &symbol)
{
    item::Item::set_symbol(symbol.toStdString());
}

QString Item::getSymbol() const
{
    return QString::fromStdString(symbol());
}

void Item::set_namespace_(const QString &space)
{
    item::Item::set_namespace_(space.toStdString());
}

QString Item::getNamespace() const
{
    return QString::fromStdString(namespace_());
}

void Item::set_adddate(const QDateTime &dt)
{
    item::Item::set_adddate(dt.toMSecsSinceEpoch());
}

void Item::set_updatedate(const QDateTime &dt)
{
    item::Item::set_updatedate(dt.toMSecsSinceEpoch());
}

QDateTime Item::getUpdateDate()
{
    return QDateTime::fromMSecsSinceEpoch(adddate());
}

QDateTime Item::getAddDate() const
{
    return QDateTime::fromMSecsSinceEpoch(adddate());
}

void Item::set_private(bool isPrivate)
{
    set_privateitem(isPrivate);
}

bool Item::isPrivate()
{
    return privateitem();
}

void Item::setPackage(Package &package)
{
    mutable_package()->CopyFrom( package.getPackageBasicInformation());
}


void Item::setUser(User &user)
{
    mutable_user()->CopyFrom(user.getPBPackage() );
}

void Item::setGroup(Group &group)
{
    mutable_group()->CopyFrom( group.getGroupBasicInfoPB());
}

void Item::addParameter(int id, QVariant value)
{
    item::ItemParameters *param = add_parameters();
    param->set_id(id);
    param->set_value(value.toString().toStdString());
}

QMap<quint32, QVariant> Item::getParameters()
{
    QMap<quint32, QVariant> map;
    int paramNumber = parameters().size()-1;

    for(;paramNumber>0;--paramNumber){
        map.insert(parameters(paramNumber).id(), QString::fromStdString(parameters(paramNumber).value()));
    }
    return map;
}

Item::Item()
{
}

QByteArray *Item::toArray()
{
    if (!IsInitialized()){
        throw QString("Uninitialized message!");
    }

    QByteArray *data = new QByteArray(ByteSize(),'\0' );
    SerializeToArray(data->data(),data->size());

    return data;
}

QByteArray *Item::toArray(QByteArray *data)
{
    if (!IsInitialized()){
        throw QString("Uninitialized message!");
    }
    if(data->size()< ByteSize() )
        data->resize(ByteSize());

    SerializeToArray(data->data(),data->size());
    return data;
}

void Item::fromArray(QByteArray *data)
{
    this->ParseFromArray(data->data(), data->size());
}
