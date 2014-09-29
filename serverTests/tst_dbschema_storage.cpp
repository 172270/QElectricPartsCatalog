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
    if(!query->exec("DROP schema public cascade;")){
        qDebug() << query->lastError().text();
    }
    QTest::qSleep(10);
    if(!query->exec("create schema public;")){
        qDebug() << query->lastError().text();
    }

    creator = new DbCreator(this);
    creator->initialize_database();
    delete creator;
    database = new PgInterface();
}
void tst_dbschema_storage::removeTable(QString tblName)
{
    if(!query->exec("DROP table " + tblName + ";")){
        qDebug() << query->lastError().text();
    }
}
void tst_dbschema_storage::cleanupTestCase()
{

    if(!query->exec("DROP schema public cascade;")){
        qDebug() << query->lastError().text();
    }
    if(!query->exec("create schema public;")){
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
    uint id = 0;
    Storage s;
    s.setName("some");
    QVERIFY(database->addStorage(s) != id);
}
