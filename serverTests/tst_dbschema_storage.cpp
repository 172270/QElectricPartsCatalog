#include "tst_dbschema_storage.h"

tst_dbschema_storage::tst_dbschema_storage(QObject *parent) :
    QObject(parent)
{
}

void tst_dbschema_storage::init()
{

}

void tst_dbschema_storage::initTestCase()
{

    db = QSqlDatabase::database();
    query = new QSqlQuery(db);
    if(!db.open()){
        qDebug()<<db.lastError().text();
    }

    query->exec("CREATE DATABASE ekatalog_tests;");

    db.close();
    db.setDatabaseName("ekatalog_tests");

    if(!db.open()){
        qDebug()<<db.lastError().text();
    }
    query->exec("DROP table if exists users;");
    creator = new DbCreator(this);
    creator->initialize_database();

    database = new PgInterface();
}

void tst_dbschema_storage::cleanupTestCase()
{
    if(!query->exec("DROP table user_magazines;")){
        qDebug() << query->lastError().text();
    }
    if(!query->exec("DROP table storage;")){
        qDebug() << query->lastError().text();
    }
    if(!query->exec("DROP table users;")){
        qDebug() << query->lastError().text();
    }
    if (db.isOpen()){
        db.close();
    }
    delete query;
}

void tst_dbschema_storage::cleanup()
{

}

void tst_dbschema_storage::createStorege_givesID()
{
    int id = 0;
    Storage s;
    s.setName("some");
    QVERIFY(database->addStorage(s) != id);
}
