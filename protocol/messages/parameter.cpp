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

MsgType Parameter::type() const
{
    return MsgType::msgParameter;
}


Parameter::Parameter()
{
    set_id(0);
}

Parameter::~Parameter()
{
}

ParameterConfig::ParameterConfig()
{
}

QString ParameterConfig::toJSON() const
{
    QJsonObject obj;
    QString ret;
    if(has_defaultvalue())
        obj.insert("def_val", defaultvalue() );
    if(has_maxlength())
        obj.insert("max_len", maxlength() );
    if(has_minlength())
        obj.insert("min_len", minlength() );
    if(has_maxvalue())
        obj.insert("max_val", maxvalue() );
    if(has_minvalue())
        obj.insert("min_val", minvalue() );
    if(has_type())
        obj.insert("type", protbuf::Parameter_Config::type() );

    ret = QString(QJsonDocument(obj).toJson(QJsonDocument::Compact));
    return ret;
}

void ParameterConfig::fromJSON(const QByteArray &json)
{
    auto obj = QJsonDocument::fromJson(json).object();

    if(obj.contains("def_val"))
        set_defaultvalue(obj.value("def_val").toString().toStdString() );
    if(obj.contains("max_len"))
        set_maxlength(obj.value("max_len").toInt( ));
    if(obj.contains("min_len"))
        set_minlength(obj.value("min_len").toInt());
    if(obj.contains("max_val"))
        set_maxvalue(obj.value("max_val").toInt());
    if(obj.contains("min_val"))
        set_minvalue(obj.value("min_val").toInt());
    if(obj.contains("type"))
        protbuf::Parameter_Config::set_type(static_cast<protbuf::Parameter_Config_Type>(obj.value("type").toInt()));
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
