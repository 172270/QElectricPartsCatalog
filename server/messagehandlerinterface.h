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
        database(m_cache.getDatabase())
    {
        ;
    }

    virtual bool checkPermission(){
        return true;
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

    WorkerCache &cache() const {
        return m_cache;
    }

    void setActiveUser(int activeUser)
    {
        database.setActiveUser(activeUser);
    }

protected:
    WorkerCache &m_cache;
    PgInterface &database;
private:

};


