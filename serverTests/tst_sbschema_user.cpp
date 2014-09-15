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

    QVERIFY(database->addUser(u,"MY NEW PASSWORD! FUCK YEAH") != 0 );
}

void tst_dbschema_user::everyCreatedUser_shoudHaveUniqueId()
{
    User u1, u2, u3;
    u1.setName("exampleUser10");
    u1.setEmail("exampleUser10@example.com");
    u2.setName("exampleUser11");
    u2.setEmail("exampleUser11@example.com");
    u3.setName("exampleUser12");
    u3.setEmail("exampleUser12@example.com");

    uint startId = database->addUser(u1,"passwd");
    QVERIFY(database->addUser(u2,"passwd") == startId+1);
    QVERIFY(database->addUser(u3,"passwd") == startId+2);
}

void tst_dbschema_user::getBadUser_returnsEmptyUser()
{
//    User u = database->getUser("bad_user_zse");
}

void tst_dbschema_user::createdUser_getsRegisterDate()
{
    User u;
    u.setName("exampleUser1");
    u.setEmail("exampleuser1@example.ex");

    QVERIFY(database->addUser(u,"examplePasswd") != 0 );
}

void tst_dbschema_user::createUserWithSameNameOrEmail_throwaException()
{
    User u1,u2;

    u1.setName("admin");
    u1.setEmail("sdfsdfsdfs@gmail.com");
    u2.setName("noname");
    u2.setEmail("cszawisza@gmail.com");

    QVERIFY_EXCEPTION_THROWN(database->addUser(u1,"passwordd"), UserError);
    QVERIFY_EXCEPTION_THROWN(database->addUser(u2,"passwordd"), UserError);
}



void tst_dbschema_user::createUserWithoutNeededFields_throwsException()
{
    User u;
    u.setName("admin");
    QVERIFY_EXCEPTION_THROWN(database->addUser(u,"passwordd"), UserError);
}




