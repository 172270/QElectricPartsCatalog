#ifndef PGINTERFACE_H
#define PGINTERFACE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include "DB_schema/user.h"
#include "DB_schema/storage.h"
#include "DB_schema/file.h"

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
    QList<File> getUserFiles(User &user);

    uint addStorage(Storage &storage);
private:
    QSqlDatabase db;
    QSqlQuery *query;
    QString q;
};

#endif // PGINTERFACE_H
