#ifndef PARAMETERSHANDLER_H
#define PARAMETERSHANDLER_H

#include "messages/parameter.h"
#include "messagehandlerinterface.h"

class AddParameterHandler : public MessageHandlerInterface
{
public:
    AddParameterHandler(WorkerCache *cache);

    bool parseData(const QByteArray &ba) override;
    bool processData() override;
    bool moveResponseToCache() override;

    bool addparameter();
    bool updateParameter();
private:
    AddParameter addParameter;
    ResponseAddParameter resAddParameter;
};

class ParametersHandler : public MessageHandlerInterface
{
public:
    ParametersHandler(WorkerCache *cache);
    bool parseData(const QByteArray &ba) override;
    bool processData() override;
    bool moveResponseToCache() override;
private:
    QList<Parameter> parameters;
    RequestParameters reqParameters;
    ResponseParameters resParameters;
};

#endif // PARAMETERSHANDLER_H
