#ifndef ITEM_H
#define ITEM_H

#include "item.pb.h"

#include "user.h"
#include "group.h"
#include "package.h"

#include <QObject>
#include <QDateTime>
#include <QString>

class Item : protected item::Item
{
public:

    void setID(quint32 id);
    quint32 getID() const;

    void setName(const QString&name);
    QString getName() const;

    void setSymbol(const QString&symbol);
    QString getSymbol() const;

    void setNamespace(const QString&space);
    QString getNamespace() const;

    void setAddDate( QDateTime &dt );
    QDateTime getAddDate() const;

    void setIsPrivate( bool isPrivate );
    bool isPrivate();

    void setPackage(const Package &package);
//    Package

    Item();
};

#endif // ITEM_H
