#include "parameter.h"

#include <QDebug>
void Parameter::set_name(const QString &name)
{
    parameters::Parameter::set_name( name.toStdString() );
}

ParameterConfig &Parameter::config() const {
    return *m_config;
}

Parameter::Parameter() :
   m_config(new ParameterConfig)
{
    set_id(0);
    set_configdata( m_config->toStdString() );
}

Parameter::~Parameter()
{
    delete m_config;
}

ParameterConfig::ParameterConfig()
{
}

void ParameterConfig::clear()
{
    object = QJsonObject();
}

QByteArray ParameterConfig::toBytes() const
{
    return QJsonDocument(object).toJson(QJsonDocument::Compact);
}

QString ParameterConfig::toString() const
{
    return QString::fromStdString(toStdString());
}

std::string ParameterConfig::toStdString() const
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
    object.insert(QStringLiteral("defaultValue"), val);
}

QVariant ParameterConfig::defaultValue()
{
    QVariant v(object.value(QStringLiteral("defaultValue")).toVariant());
    return v;
}

void ParameterConfig::setValueType(QString type)
{
    object.insert(QStringLiteral("valueType"), type);
}

QString ParameterConfig::getValueType()
{
    return object.value(QStringLiteral("valueType")).toString();
}

void ParameterConfig::setMaxValue(QVariant maxVal)
{
    QJsonValue val = QJsonValue::fromVariant(maxVal);
    object.insert(QStringLiteral("maxValue"), val);
}

QVariant ParameterConfig::getMaxValue() const
{
    return object.value(QStringLiteral("maxValue")).toString();
}

void ParameterConfig::setMinValue(QVariant minValue)
{
    QJsonValue val = QJsonValue::fromVariant(minValue);
    object.insert(QStringLiteral("minValue"), val);
}

QVariant ParameterConfig::getMinValue() const
{
    return object.value(QStringLiteral("minValue")).toString();
}
