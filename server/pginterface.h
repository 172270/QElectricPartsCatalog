#ifndef PGINTERFACE_H
#define PGINTERFACE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include "DB_schema/user.h"
#include "DB_schema/group.h"
#include "DB_schema/storage.h"
#include "DB_schema/file.h"
#include "DB_schema/item.h"

class PgInterface
{
public:
    PgInterface();

    User getUserById(uint id);
    User getUserByName(const QString &name);

    uint addUser(User &user, QString passwd);
    void deleteUser(User &user);
    bool checkUserPassword(User &user, QString passwd);
    void linkStorageToUser(User &user, Storage &storage);
    QList<Storage> getUserStorages(User &user);

    uint addStorage(const Storage &storage);

    quint32 addGroup(const Group &group);

    quint32 addItem(const Item &item);
private:
    QSqlDatabase db;
    QSqlQuery *query;
    QString q;
};

#endif // PGINTERFACE_H
