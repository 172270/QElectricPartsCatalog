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

class ParameterConfig
{
public:
    ParameterConfig();
    void clear();
    QByteArray toBytes() const;
    QString toString() const;
    std::string toStdString() const ;
    void fromStdString(const std::string &conf);

    void setDefaultValue(QVariant value);
    QVariant defaultValue();

    void setValueType( QString type);
    QString getValueType();

    void setMaxValue(QVariant maxVal);
    QVariant getMaxValue() const;

    void setMinValue(QVariant minValue);
    QVariant getMinValue() const;
private:
    QJsonObject object;
};

class Parameter : public protbuf::Parameter , public protocol::Message
{
public:
    Parameter();
    ~Parameter();
    void set_name(const QString &name);
    QString getName() const {return QString::fromStdString( name() );}
    ParameterConfig &config() const;
    void syncConfig();
private:
    ParameterConfig *m_config;

public:
    MsgType type() const
    {
        return MsgType::msgParameter;
    }
    int ByteSize() const
    {
        return protbuf::Parameter::ByteSize();
    }

protected:
    bool SerializeToArray(void *data, int size) const
    {
        return protbuf::Parameter::SerializeToArray(data,size);
    }
    bool ParseFromArray(const void *data, int size)
    {
        return protbuf::Parameter::ParseFromArray(data,size);
    }
};

class ResponseParameters : public protbuf::resParameters , public protocol::Message
{
public:
    MsgType type() const
    {
        return MsgType::resParameters;
    }
    int ByteSize() const
    {
        return protbuf::resParameters::ByteSize();
    }

protected:
    bool SerializeToArray(void *data, int size) const
    {
        return protbuf::resParameters::SerializeToArray(data,size);
    }
    bool ParseFromArray(const void *data, int size)
    {
        return protbuf::resParameters::ParseFromArray(data,size);
    }
};

class ResponseAddParameter : public protbuf::resAddParameter , public protocol::Message
{
public:
    MsgType type() const
    {
        return MsgType::resAddParameter;
    }
    int ByteSize() const
    {
        return protbuf::resAddParameter::ByteSize();
    }

protected:
    bool SerializeToArray(void *data, int size) const
    {
        return protbuf::resAddParameter::SerializeToArray(data,size);
    }
    bool ParseFromArray(const void *data, int size)
    {
        return protbuf::resAddParameter::ParseFromArray(data,size);
    }
};

#endif // PARAMETER_H
