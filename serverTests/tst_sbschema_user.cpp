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

    tester = new db_information_schema_tester();
    tester->setTable("users");

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

void tst_dbschema_user::databaseContains_users_table()
{
    if( !query->exec ("SELECT EXISTS("
                      "SELECT true "
                      "FROM   pg_catalog.pg_class c "
                      "JOIN   pg_catalog.pg_namespace n ON n.oid = c.relnamespace "
                      "WHERE  c.relname = 'users' "
                      "AND    c.relkind = 'r' "
                      ");"))
    {
        qDebug() << query->lastError().text();
    }
    query->first();

    QVERIFY(query->size()==1);
    QVERIFY(query->value(0).toString() == "true" );
}

void tst_dbschema_user::usersTable_containsColumns()
{
    QVERIFY(tester->columnExists("name"));
    QVERIFY(tester->columnExists("email"));
    QVERIFY(tester->columnExists("id"));
    QVERIFY(tester->columnExists("password"));
    QVERIFY(tester->columnExists("config"));
    QVERIFY(tester->columnExists("registrationDate"));
    QVERIFY(tester->columnExists("lastlogin"));
    QVERIFY(tester->columnExists("phonenumber"));
}

void tst_dbschema_user::typesAreCorrect()
{
    QVERIFY(tester->columnTypeCorrect("name", "varchar"));
    QVERIFY(tester->columnTypeCorrect("email", "varchar"));
    QVERIFY(tester->columnTypeCorrect("phonenumber", "bpchar"));
    QVERIFY(tester->columnTypeCorrect("id", "int4"));
    QVERIFY(tester->columnTypeCorrect("password", "bpchar"));
    QVERIFY(tester->columnTypeCorrect("registrationDate","timestamp"));
    QVERIFY(tester->columnTypeCorrect("lastlogin","timestamp"));
    QVERIFY(tester->columnTypeCorrect("config","json"));
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


