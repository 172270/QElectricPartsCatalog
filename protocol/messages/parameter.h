#ifndef PARAMETER_H
#define PARAMETER_H

#include <QString>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QVariant>

#include <string>

#include "parameters.pb.h"
#include "message.h"

class ParameterConfig : public protocol::QMessage<protbuf::Parameter_Config>
{
public:
    ParameterConfig();
    QString toJSON() const;
    void fromJSON(const QByteArray &json);

    QString defaultvalue() const{
        return QString::fromStdString(protbuf::Parameter_Config::defaultvalue());
    }
    protbuf::Parameter_Config::Type valueType() const {
        return protbuf::Parameter_Config::type();
    }

    MsgType type() const
    {
        return MsgType::msgParameterConfig;
    }
};

class Parameter : public protocol::QMessage<protbuf::Parameter>
{
public:
    Parameter();
    ~Parameter();
    void set_symbol(const QString &symbol);
    QString getSymbol() const {return QString::fromStdString( symbol() );}

    void set_name(const QString &name);
    QString getName() const {return QString::fromStdString( name() );}

    void set_description(const QString &desc);
    QString getDescription() const {return QString::fromStdString( description() );}

    MsgType type() const;

    void set_config(QByteArray &&conf){
        mutable_config()->fromJSON(conf);
    }

    ParameterConfig *mutable_config(){
        return static_cast<ParameterConfig*>(protbuf::Parameter::mutable_config()) ;
    }

    const ParameterConfig &config() const {
        return static_cast<const ParameterConfig&>(protbuf::Parameter::config()) ;
    }

};

class AddParameter : public protocol::QMessage<protbuf::addParameter>
{
public:
    const Parameter &parameter() const { return static_cast<const Parameter&>(protbuf::addParameter::parameter());}
    Parameter *mutable_parameter() { return static_cast<Parameter*>(protbuf::addParameter::mutable_parameter());}

    MsgType type() const
    {
        return MsgType::addParameter;
    }
};

class ResponseParameters : public protocol::QMessage<protbuf::resParameters>
{
public:
    MsgType type() const;
};

class RequestParameters : public protocol::QMessage<protbuf::reqParameters>
{
public:
    MsgType type() const;
};

class ResponseAddParameter : public protocol::QMessage<protbuf::resAddParameter>
{
public:
    MsgType type() const;
};

#endif // PARAMETER_H
