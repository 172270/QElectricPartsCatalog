#include "parametershandler.h"
#include <QDebug>
AddParameterHandler::AddParameterHandler(WorkerCache *cache):
    MessageHandlerInterface(cache)
{
}

bool AddParameterHandler::parseData(const QByteArray &ba)
{
    resAddParameter.Clear();
    addParameter.Clear();
    return addParameter.fromArray(ba);
}

bool AddParameterHandler::addparameter()
{
    try{
        database.addParameter(addParameter.mutable_parameter());
        resAddParameter.add_replay( protbuf::resAddParameter::addOk);
        return true;
    }
    catch (QSqlError e){
        qDebug()<<e.text();
        resAddParameter.add_replay( protbuf::resAddParameter::parameterExists);
        return false;
    }
}

bool AddParameterHandler::updateParameter()
{
    try{
        if(database.updateParameter(addParameter.parameter())){
            resAddParameter.add_replay(protbuf::resAddParameter::updateOk);
            return true;
        }
        resAddParameter.add_replay(protbuf::resAddParameter::updataFailed_noSuchParameterInDatabase );
    }
    catch (QSqlError e){
        qDebug()<<e.text();
        resAddParameter.add_replay( protbuf::resAddParameter::parameterExists);

    }
    return false;
}

bool AddParameterHandler::processData()
{
    if (addParameter.mode() == protbuf::addParameter_AddMode_update)
        return updateParameter();
    else
        return addparameter();
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
