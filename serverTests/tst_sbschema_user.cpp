#include "tst_sbschema_user.h"

#include "DB_schema/user.h"

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
    db.setUserName("postgres");
    db.setPassword("postgres");

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

    creator = new DbCreator(this);
    creator->initialize_database();

    database = new PgInterface();
}

void tst_dbschema_user::cleanupTestCase()
{
    if(!query->exec("DROP table users;")){
        qDebug() << query->lastError().text();
    }
    if (db.isOpen()){
        db.close();
    }
    delete query;
}

void tst_dbschema_user::cleanup()
{

}

void tst_dbschema_user::createUserShoudGiveNewId()
{
    User u;
    u.setName("admin");
    u.setEmail("cszawisza@gmail.com");

    QVERIFY(database->addUserToDatabase(u,"MY NEW PASSWORD! FUCK YEAH") != 0 );
}

void tst_dbschema_user::createUserWithSameNameOrEmail_throwaException()
{
    User u;
    u.setName("admin");
    u.setEmail("sdfsdfsdfs@gmail.com");

    QVERIFY_EXCEPTION_THROWN(database->addUserToDatabase(u,"passwordd"), UserError);

    u.setName("noname");
    u.setEmail("cszawisza@gmail.com");
    QVERIFY_EXCEPTION_THROWN(database->addUserToDatabase(u,"passwordd"), UserError);
}

void tst_dbschema_user::createUserWithoutNeededFields_throwsException()
{
    
}




