#pragma once

#include <QSqlDatabase>
#include "pginterface.h"
#include "workercache.h"

class QByteArray;

class MessageHandlerInterface
{

public:
    explicit MessageHandlerInterface(WorkerCache *cache):
        m_cache(*cache),
        database( m_cache.getDb().connectionName() )
    {
        ;
    }

    virtual ~MessageHandlerInterface(){;}
    /**
     * @brief parseData takes byte array containing some message
     * e.g. MsgType::reqLogin or something else
     * and return 1 when parse fails (data is corrupted)
     */
    virtual bool parseData(const QByteArray &ba) = 0;
    virtual bool parseData(QByteArray &&ba) = 0;

    /**
     * @brief processData: processes data
     * @return true if processing ends without error
     */
    virtual bool processData() = 0;

    /**
     * @brief moveResponseToCache copy response to response container
     * @return
     */
    virtual bool moveResponseToCache() = 0;

protected:
    WorkerCache &m_cache;
    PgInterface database;

private:
    /**
     * @brief clearCacheData clears data connected to this worker
     *  in thread cache object linked at creation of this handler
     * @return true if cache was succesfully cleared
     */
    virtual bool clearCacheData() = 0;
};
