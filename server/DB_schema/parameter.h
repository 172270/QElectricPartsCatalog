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

class ParameterValue{

};

class ParameterConfig
{
public:
    ParameterConfig();
    void clear();
    QByteArray toBytes(){return QJsonDocument(object).toJson(QJsonDocument::Compact);}
    std::string toStdString();
    void fromStdString(const std::string &conf);

    void setDefaultValue(QVariant value);
    QVariant defaultValue();

    void setValueType( QString type);
    QString getValueType();
private:
    QJsonObject object;
};

class Parameter : public parameters::Parameter
{
public:
    Parameter();
    void set_name(const QString &name);
    QString getName() const {return QString::fromStdString( name() );}
    ParameterConfig* getConfig() const {return m_config;}
private:
    ParameterConfig *m_config;
};

#endif // PARAMETER_H
