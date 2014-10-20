#include "item.h"

void Item::set_name(const QString &name)
{
    protbuf::Item::set_name(name.toStdString());
}

QString Item::getName() const
{
    return QString::fromStdString(name());
}

void Item::set_symbol(const QString &symbol)
{
    protbuf::Item::set_symbol(symbol.toStdString());
}

QString Item::getSymbol() const
{
    return QString::fromStdString(symbol());
}

void Item::set_name_space(const QString &space)
{
    protbuf::Item::set_name_space(space.toStdString());
}

QString Item::getNamespace() const
{
    return QString::fromStdString(name_space());
}

void Item::set_adddate(const QDateTime &dt)
{
    protbuf::Item::set_adddate(dt.toMSecsSinceEpoch());
}

void Item::set_updatedate(const QDateTime &dt)
{
    protbuf::Item::set_updatedate(dt.toMSecsSinceEpoch());
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

void Item::insertParameter(uint id, QVariant value)
{
    for(int i=0;i<parameters().size();i++){
        if( parameters(i).id() == id){
            mutable_parameters(i)->set_value(value.toString().toStdString() );
            return;
        }
    }
    protbuf::ItemParameters *param = add_parameters();
    param->set_id(id);
    param->set_value(value.toString().toStdString() );
}

QVariantMap Item::getParameters() const
{
    QVariantMap map;
    int paramNumber = parameters().size()-1;

    for(;paramNumber>=0;--paramNumber)
        map.insert(QString::number(parameters(paramNumber).id()), QString::fromStdString(parameters(paramNumber).value()));

    return map;
}

QString Item::getDescription() const
{
     return QString::fromStdString(protbuf::Item::description());
}

QString Item::getParametersAsJSON() const
{
    QJsonObject object = QJsonObject::fromVariantMap( getParameters() );
    return QString::fromStdString(std::string(QJsonDocument(object).toJson(QJsonDocument::Compact).data()));
}

Item::Item()
{
    set_id(0);
    set_adddate(QDateTime());
    set_updatedate(QDateTime());
}
