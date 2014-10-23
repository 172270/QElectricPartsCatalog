#include "parametershandler.h"
#include <QDebug>
AddParameterHandler::AddParameterHandler(WorkerCache *cache):
    MessageHandlerInterface(cache)
{
}

bool AddParameterHandler::parseData(const QByteArray &ba)
{
    resAddParameter.Clear();
    resParameters.Clear();
    parameter.Clear();
    return parameter.fromArray(ba);
}

bool AddParameterHandler::parseData(QByteArray &&ba)
{
    if(parameters.size())
        parameters.clear();
    resAddParameter.Clear();
    resParameters.Clear();
    parameter.Clear();
    return parameter.fromArray(ba);
}

bool AddParameterHandler::processData()
{
    // add parameter

    if(parameter.IsInitialized()){
        try{
            database.addParameter(parameter);
            resAddParameter.add_replay( protbuf::addParameterReplay::addOk);
            parameters = database.getParameters();
            qDebug()<<"read " << parameters.size() << " parameters from database";
            for(int i=0;i<parameters.size();i++){
                resParameters.add_parameters()
                        ->CopyFrom(static_cast<protbuf::Parameter>(parameters[i]));
            }
        }
        catch (QSqlError){
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
    if( resParameters.parameters().size() > 0)
        m_cache.responseMessage()->addMessage(resParameters);
    return true;

}
