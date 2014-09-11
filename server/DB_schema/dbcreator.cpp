#include "dbcreator.h"
#include <QDebug>

DbCreator::DbCreator(QObject *parent) :
    QObject(parent)
{
    query = new QSqlQuery(db);
    if (!db.isOpen())
        db.open();
}

void DbCreator::initialize_database()
{
    query->exec("CREATE TABLE IF NOT EXISTS users ("
                "id SERIAL PRIMARY KEY, "
                "name  varchar(64) NOT NULL UNIQUE CHECK (name <> ''),"
                "password  char(32) NOT NULL CHECK (name <> ''),"
                "email  varchar(255) NOT NULL UNIQUE CHECK (name <> ''),"
                "phonenumber char(10),"
                "registrationDate TIMESTAMP NOT NULL DEFAULT NOW(),"
                "lastlogin TIMESTAMP,"
                "config json"
                " );");

}
