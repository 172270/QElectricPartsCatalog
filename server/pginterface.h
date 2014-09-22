#ifndef PGINTERFACE_H
#define PGINTERFACE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include "DB_schema/user.h"
#include "DB_schema/storage.h"

class PgInterface
{
public:
    PgInterface();

    uint addUser(User &user, QString passwd);
    User getUserByName(QString name);
    void deleteUser(User user);
    bool checkUserPassword(User user, QString passwd);

    uint addStorage(Storage &storage);

    QList<Storage> getUserStorages(User user);
private:
    QSqlDatabase db;
    QSqlQuery *query;
    QString q;
};

#endif // PGINTERFACE_H
