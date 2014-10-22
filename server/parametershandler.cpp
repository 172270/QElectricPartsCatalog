#include "parametershandler.h"

AddParameterHandler::AddParameterHandler(WorkerCache *cache):
    MessageHandlerInterface(cache)
{
}

bool AddParameterHandler::parseData(const QByteArray &ba)
{
    resParameter.Clear();
    parameter.Clear();
    return parameter.fromArray(ba);
}

bool AddParameterHandler::parseData(QByteArray &&ba)
{
    resParameter.Clear();
    parameter.Clear();
    return parameter.fromArray(ba);
}

bool AddParameterHandler::processData()
{
    // add parameter

    if(parameter.IsInitialized()){
        try{
            database.addParameter(parameter);
            resParameter.add_replay( protbuf::addParameterReplay::addOk);
        }
        catch (QSqlError){
            resParameter.add_replay( protbuf::addParameterReplay::parameterExists);
        }
    }
    else
        return false;
    return true;
}

bool AddParameterHandler::moveResponseToCache()
{
    m_cache.responseMessage()->addMessage(resParameter);
    return true;
}
