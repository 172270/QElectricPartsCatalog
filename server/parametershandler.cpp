#include "parametershandler.h"
#include <QDebug>
AddParameterHandler::AddParameterHandler(WorkerCache *cache):
    MessageHandlerInterface(cache)
{
}

bool AddParameterHandler::parseData(const QByteArray &ba)
{
    resAddParameter.Clear();
    parameter.Clear();
    return parameter.fromArray(ba);
}

bool AddParameterHandler::parseData(QByteArray &&ba)
{
    resAddParameter.Clear();
    parameter.Clear();
    return parameter.fromArray(ba);
}

bool AddParameterHandler::processData()
{
    if(parameter.IsInitialized()){
        try{
            database.addParameter(parameter);
            resAddParameter.add_replay( protbuf::addParameterReplay::addOk);
        }
        catch (QSqlError e){
            qDebug()<<e.text();
            resAddParameter.add_replay( protbuf::addParameterReplay::parameterExists);
        }
    }
    else
        return false;
    return true;
}

bool AddParameterHandler::moveResponseToCache()
{
    m_cache.responseMessage()->addMessage(resAddParameter);
    return true;
}


ParametersHandler::ParametersHandler(WorkerCache *cache):
    MessageHandlerInterface(cache)
{

}

bool ParametersHandler::parseData(const QByteArray &ba)
{
    reqParameters.Clear();
    resParameters.Clear();
    return reqParameters.fromArray(ba);
}

bool ParametersHandler::parseData(QByteArray &&ba)
{
    reqParameters.Clear();
    resParameters.Clear();
    return reqParameters.fromArray(ba);
}

bool ParametersHandler::processData()
{
    parameters = database.getParameters();
    for(int i=0;i<parameters.size();i++){
        resParameters.add_parameters()
                ->CopyFrom(static_cast<protbuf::Parameter>(parameters[i]));
    }
    return true;
}

bool ParametersHandler::moveResponseToCache()
{
    cache().responseMessage()->addMessage(resParameters);
    return true;
}
