#ifndef PGINTERFACE_H
#define PGINTERFACE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include "DB_schema/user.h"
#include "DB_schema/package.h"
#include "DB_schema/parameter.h"
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
    bool checkUserPassword(QString user, QString passwd);
    void linkStorageToUser(const User &user, const Storage &storage);
    QList<Storage> getUserStorages(User &user);

    uint addStorage(const Storage &storage);
    uint addPackage(Package &package);

    quint32 addParameter(Parameter &parameter);

    quint32 addGroup(const Group &group);
    Group getGroup(uint id);
    void linkParameterToGroup(Group &group, const Parameter &parameter);

    quint32 addItem(Item &item);
private:
    QSqlDatabase db;
    QSqlQuery *query;
    QString q;
};

#endif // PGINTERFACE_H
