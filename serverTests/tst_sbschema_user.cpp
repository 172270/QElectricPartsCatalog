#include "tst_sbschema_user.h"

#include "DB_schema/user.h"

tst_dbschema_user::tst_dbschema_user(QObject *parent) :
    QObject(parent), currentID(0), currentEmail(0)
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
    query->exec("DROP table if exists users;");
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
    User u = database->getUserByName("bad_user_zse");
    QVERIFY(u.hasID()==false);
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
    u.setName( getUniqueName() );
    QVERIFY_EXCEPTION_THROWN(database->addUser(u,"passwordd"), UserError);
}

void tst_dbschema_user::getUser_getsUser()
{
    User u;
    u.setName(getUniqueName());
    u.setEmail(getUniqueEmail());
    u.setPhoneNumber("123123123");
    u.setAddress("address USA");

    database->addUser(u,"passwd");

    User u2 = database->getUserByName( u.getName() );

    QVERIFY(u.getName() == u2.getName());
    QVERIFY(u.getEmail() == u2.getEmail());
    QVERIFY(u.getPhoneNumber() == u2.getPhoneNumber());
    QVERIFY(u.getAddress() == u2.getAddress());
}

void tst_dbschema_user::getUser_getsUserWithRegistrationDate()
{
    User u;
    u.setName(getUniqueName());
    u.setEmail(getUniqueEmail());
    u.setPhoneNumber("123123123");
    u.setAddress("address USA");
    database->addUser(u,"passwd");
    User u2 = database->getUserByName( u.getName() );

    QVERIFY(u2.hasRegistrationDate());
}

void tst_dbschema_user::addUserBenchmark()
{
    QBENCHMARK{
        User u;
        u.setName(getUniqueName());
        u.setEmail(getUniqueEmail());
        u.setPhoneNumber("123123123");
        u.setAddress("address USA");
        database->addUser(u,"passwd");
    }
}

void tst_dbschema_user::deleteUser_deletesUser()
{
    User u;
    u.setName(getUniqueName());
    u.setEmail(getUniqueEmail());
    database->addUser(u,"passwd");
    User u2 = database->getUserByName( u.getName() );
    database->deleteUser( u );
    User u3 = database->getUserByName( u.getName() );

    QVERIFY(u2.hasID() );
    QVERIFY(!u3.hasID() );
}

QString tst_dbschema_user::getUniqueName()
{
    return QString("exampleUniqueUser") + QString::number(currentID++);
}

QString tst_dbschema_user::getUniqueEmail()
{
    return QString("exampleUniqueEmail")
            + QString::number(currentID++)
            + QString("@aa.aa");
}




