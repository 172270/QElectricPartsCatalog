#include "parameter.h"

#include <QDebug>
void Parameter::set_name(const QString &name)
{
    parameters::Parameter::set_name( name.toStdString() );
}

Parameter::Parameter()
{
}

ParameterConfig::ParameterConfig()
{
}

void ParameterConfig::clear()
{
    object = QJsonObject();
}

std::string ParameterConfig::toStdString()
{
    return std::string(toBytes().data());
}

void ParameterConfig::fromStdString(const std::string &conf)
{
    QByteArray ba = QByteArray( conf.data(), conf.size());
    QJsonDocument doc = QJsonDocument::fromJson( ba );
    object = doc.object();
}

void ParameterConfig::setDefaultValue(QVariant value)
{
    QJsonValue val = QJsonValue::fromVariant(value);
    object.insert(QStringLiteral("default_value"), val);
}

QVariant ParameterConfig::defaultValue()
{
    QVariant v(object.value(QStringLiteral("default_value")).toVariant());
    return v;
}

void ParameterConfig::setValueType(QString type)
{
    object.insert(QStringLiteral("type"), type);
}

QString ParameterConfig::getValueType()
{
    return object.value(QStringLiteral("type")).toString();
}
