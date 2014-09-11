#ifndef PGINTERFACE_H
#define PGINTERFACE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include "DB_schema/user.h"

class PgInterface
{
public:
    PgInterface();

    int addUserToDatabase(User user, QString passwd);
    bool checkUserPassword(User user, QString passwd);
private:
    QSqlDatabase db;
    QSqlQuery *query;
};

#endif // PGINTERFACE_H
