#include "tst_sbschema_user.h"

tst_dbschema_user::tst_dbschema_user(QObject *parent) :
    QObject(parent)
{
}

void tst_dbschema_user::init()
{

}

void tst_dbschema_user::initTestCase()
{
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
//    db.setDatabaseName("ekatalog_tests");
    db.setUserName("postgres");
    db.setPassword("postgres");

    query = new QSqlQuery(db);
    if(!db.open()){
        qDebug()<<db.lastError().text();
    }
    query->exec("CREATE DATABASE ekatalog_tests;");
}

void tst_dbschema_user::cleanupTestCase()
{
    //query->exec("DROPDB \"ekatalog_tests\";");
    if (db.isOpen()){
        db.close();
    }
    delete query;
}

void tst_dbschema_user::cleanup()
{

}
