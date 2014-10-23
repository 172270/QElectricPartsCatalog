#ifndef PARAMETERSHANDLER_H
#define PARAMETERSHANDLER_H

#include "messages/parameter.h"
#include "messagehandlerinterface.h"

class AddParameterHandler : public MessageHandlerInterface
{
public:
    AddParameterHandler(WorkerCache *cache);

    bool parseData(const QByteArray &ba) override;
    bool parseData(QByteArray &&ba) override;
    bool processData();
    bool moveResponseToCache();

private:
    QList<Parameter> parameters;
    Parameter parameter;
    ResponseParameters resParameters;
    ResponseAddParameter resAddParameter;
};

#endif // PARAMETERSHANDLER_H
