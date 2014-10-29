#include "parameter.h"

#include <QDebug>
void Parameter::set_name(const QString &name)
{
    protbuf::Parameter::set_name( name.toStdString() );
}

void Parameter::set_symbol(const QString &symbol)
{
    protbuf::Parameter::set_symbol(symbol.toStdString());
}

void Parameter::set_description(const QString &desc)
{
    protbuf::Parameter::set_description(desc.toStdString());
}

ParameterConfig &Parameter::config() {
    return m_config;
}



MsgType Parameter::type() const
{
    return MsgType::msgParameter;
}

void Parameter::afterFromArray()
{
    m_config.fromStdString( configdata() );
}

void Parameter::beforeToArray()
{
    QString s = m_config.toString();
    std::string str = s.toStdString();
    set_configdata( str);
}

Parameter::Parameter()
{
    set_id(0);
    set_configdata( m_config.toStdString() );
}

Parameter::~Parameter()
{
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
    return std::string(toBytes().data(), toBytes().size() );
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

void ParameterConfig::setMaxTextLength(int value)
{
    auto val = QJsonValue(value);
    object.insert(QStringLiteral("maxTextLength"), val);
}

void ParameterConfig::setMinTextLength(int value)
{
    auto val = QJsonValue(value);
    object.insert(QStringLiteral("minTextLength"), val);
}

int ParameterConfig::maxTextLength() const
{
    QVariant v(object.value(QStringLiteral("maxTextLength")).toVariant());
    return v.toInt();
}

int ParameterConfig::minTextLength() const
{
    QVariant v(object.value(QStringLiteral("minTextLength")).toVariant());
    return v.toInt();
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

QString ParameterConfig::valueType()
{
    return object.value(QStringLiteral("valueType")).toString();
}

void ParameterConfig::setMaxValue(double maxVal)
{
    auto val = QJsonValue(maxVal);
    object.insert(QStringLiteral("maxValue"), val);
}

double ParameterConfig::getMaxValue() const
{
    return object.value(QStringLiteral("maxValue")).toDouble();
}

void ParameterConfig::setMinValue(double minValue)
{
    auto val = QJsonValue(minValue);
    object.insert(QStringLiteral("minValue"), val);
}

double ParameterConfig::getMinValue() const
{
    return object.value(QStringLiteral("minValue")).toDouble();
}

MsgType RequestParameters::type() const
{
    return MsgType::reqParameters;
}


MsgType ResponseAddParameter::type() const
{
    return MsgType::resAddParameter;
}


MsgType ResponseParameters::type() const
{
    return MsgType::resParameters;
}
