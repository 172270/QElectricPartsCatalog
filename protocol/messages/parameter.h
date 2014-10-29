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
    QString valueType();

    void setMaxValue(double maxVal);
    double getMaxValue() const;
    bool hasMaxValue() const;

    void setMinValue(double minValue);
    double getMinValue() const;
    bool hasMinValue()const;

    void setMinTextLength(int value);
    int minTextLength() const;
    bool hasMinTextLength() const;

    void setMaxTextLength(int value);
    int maxTextLength() const;
    bool hasMaxTextLength() const;
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
    void ParametersModel(){ afterFromArray(); }
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
