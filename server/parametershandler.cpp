#include "parametershandler.h"

AddParameterHandler::AddParameterHandler(WorkerCache *cache):
    MessageHandlerInterface(cache)
{
    resParameter.Clear();
    parameter.Clear();
}

bool AddParameterHandler::parseData(const QByteArray &ba)
{
    return parameter.fromArray(ba);
}

bool AddParameterHandler::parseData(QByteArray &&ba)
{
    return parameter.fromArray(ba);
}

bool AddParameterHandler::processData()
{
    // add parameter

    if(parameter.IsInitialized()){
        database.addParameter(parameter);
        resParameter.add_replay( protbuf::addParameterReplay::addOk );
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
