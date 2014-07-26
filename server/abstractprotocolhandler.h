#ifndef ABSTRACTPROTOCOLHANDLER_H
#define ABSTRACTPROTOCOLHANDLER_H

#include "qcatalogserverthread.h"


class AbstractProtocolHandler : public QCatalogServerThread
{
    Q_OBJECT
public:
    explicit AbstractProtocolHandler(QCatalogServerThread *parent = 0) { Q_UNUSED(parent);}

    // ustawia wskaźnik do odebranych danych
    virtual void setData(QByteArray * data) = 0;

    // przetwarza i odsyła dane do klienta
    virtual void processData() = 0;

};

#endif // ABSTRACTPROTOCOLHANDLER_H
