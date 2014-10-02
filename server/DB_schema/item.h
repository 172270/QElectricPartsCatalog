#ifndef ITEM_H
#define ITEM_H

#include "item.pb.h"

#include "user.h"
#include "group.h"
#include "package.h"

#include <QObject>
#include <QDateTime>
#include <QString>

class Item : public item::Item
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

    void setAddDate(const QDateTime &dt );
    QDateTime getAddDate() const;

    void setIsPrivate( bool isPrivate );
    bool isPrivate();

    void setPackage(Package *package);
    Package *getPackage();

    void setUser(User *user);
    void setGroup( Group *group);

    Item();

    QByteArray* toArray();
};

#endif // ITEM_H
