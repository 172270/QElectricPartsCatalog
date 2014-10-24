#ifndef ITEM_H
#define ITEM_H

#include "item.pb.h"

#include "user.h"
#include "group.h"
#include "package.h"
#include "message.h"

#include <QObject>
#include <QDateTime>
#include <QString>

class Item : public protocol::QMessage<protbuf::Item>
{
public:

    void set_name(const QString& name);
    QString getName() const;

    void set_symbol(const QString& symbol);
    QString getSymbol() const;

    void set_name_space(const QString&space);
    QString getNamespace() const;

    void set_adddate(const QDateTime &dt );
    QDateTime getAddDate() const;

    void set_updatedate(const QDateTime &dt);
    QDateTime getUpdateDate();

    void set_private( bool isPrivate );
    bool isPrivate();

    void setUser(User &user);
    void setGroup(Group &group);

    void insertParameter(uint id, QVariant value);
    QVariantMap getParameters() const;

    QString getDescription() const;

    QString getParametersAsJSON() const;

    Item();

    void setPackage(Package &package);

    // Message interface
public:
    MsgType type() const
    {
        return MsgType::msgItem;
    }
};

#endif // ITEM_H
