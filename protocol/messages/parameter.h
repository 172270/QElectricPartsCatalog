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

class Parameter : public protocol::QMessage<protbuf::Parameter>
{
public:
    Parameter();
    ~Parameter();
    void set_symbol(const QString &symbol);
    void set_name(const QString &name);
    QString getName() const {return QString::fromStdString( name() );}
    QString getSymbol() const {return QString::fromStdString( symbol() );}
    void set_description(const QString &desc);
    QString getDescription() const {return QString::fromStdString( description() );}

    ParameterConfig &config();

    MsgType type() const;
private:
    ParameterConfig m_config;
    void afterFromArray();
    void beforeToArray();
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
