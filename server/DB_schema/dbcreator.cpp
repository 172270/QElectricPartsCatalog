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
    if (!query->exec("CREATE TABLE if not exists users ("
                     "id SERIAL PRIMARY KEY, "
                     "name  varchar(64) NOT NULL CHECK (name <> ''),"
                     "password  char(32) NOT NULL CHECK (name <> ''),"
                     "email  varchar(255),"
                     "phonenumber char(10),"
                     "registrationDate TIMESTAMP NOT NULL DEFAULT NOW(),"
                     "config json"
                     " );")){
        qDebug()<<query->lastError().text();
    }
}
