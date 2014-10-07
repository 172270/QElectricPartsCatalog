#include "tst_dbschema_groups.h"

tst_dbschema_groups::tst_dbschema_groups(QObject *parent) :
    QObject(parent)
{
}

void tst_dbschema_groups::init()
{

}

void tst_dbschema_groups::initTestCase()
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

    database = new PgInterface();
}

void tst_dbschema_groups::cleanupTestCase()
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

void tst_dbschema_groups::cleanup()
{

}

void tst_dbschema_groups::addGroupToDatabase_shoudSaveGroupWithAllInformation()
{
    Group g;
    g.set_parentid(1);
    g.set_name("first group");
    g.set_description("description 1");
    g.setAllowItems(true);
    g.setAllowRecipe(true);

    g.set_id(database->addGroup(g));

    QVERIFY(g.id() != 0);
}

void tst_dbschema_groups::addMeanygroups_givesSerialIDNumbers()
{
    Group g, g2;
    g.set_parentid(1);
    g.set_name("second group");
    g.set_description("description 2");
    g.setAllowItems(true);
    g.setAllowRecipe(true);

    g2.set_parentid(1);
    g2.set_name("third group");
    g2.set_description("description 3");
    g2.setAllowItems(true);
    g2.setAllowRecipe(false);

    g.set_id(database->addGroup(g));
    g2.setID(database->addGroup(g2));

    QVERIFY(g2.getID() == g.getID() + 1);
}

void tst_dbschema_groups::databaseShoudAllowCreateGroupsWithSameNameAndDifferentParent()
{
    Group primaryGroup1, primaryGroup2, child1, child2;
    primaryGroup1.set_parentid(1);
    primaryGroup1.set_name("primary group 1");
    primaryGroup1.set_description("description for primary 1");
    primaryGroup1.setAllowItems(true);
    primaryGroup1.setAllowRecipe(true);
    primaryGroup1.set_id(database->addGroup(primaryGroup1));

    primaryGroup2.set_parentid(1);
    primaryGroup2.set_name("primary group 2");
    primaryGroup2.set_description("description for primary 2");
    primaryGroup2.setAllowItems(true);
    primaryGroup2.setAllowRecipe(true);
    primaryGroup2.set_id(database->addGroup(primaryGroup2));

    child1.set_parentid(primaryGroup1.id() );
    child1.set_name("CHILD");
    child1.setAllowItems(true);
    child1.setAllowRecipe(true);
    child1.set_id(database->addGroup(child1));

    child2.set_parentid(primaryGroup2.id() );
    child2.set_name("CHILD");
    child2.setAllowItems(true);
    child2.setAllowRecipe(true);
    child2.set_id(database->addGroup(child2));

    QVERIFY(child1.id() != 0);
    QVERIFY(child2.id() != 0);
    QVERIFY(child1.id() != child2.id());
}

void tst_dbschema_groups::databaseThrowsExceptionWhenDoubleGroupAdd()
{
    Group primaryGroup1;
    primaryGroup1.set_parentid(1);
    primaryGroup1.set_name("some group");
    primaryGroup1.setAllowItems(true);
    primaryGroup1.setAllowRecipe(true);
    primaryGroup1.set_id(database->addGroup(primaryGroup1));
    QVERIFY_EXCEPTION_THROWN(primaryGroup1.set_id(database->addGroup(primaryGroup1)), QString );
}

void tst_dbschema_groups::linkGroupWithParameter_linksGroupWithParameter()
{
    Group primaryGroup;
    primaryGroup.set_parentid(1);
    primaryGroup.set_name("Parameter_test");
    primaryGroup.setAllowItems(true);
    primaryGroup.setAllowRecipe(true);
    primaryGroup.set_id(database->addGroup(primaryGroup));

    Parameter p;
    p.set_name("Parameter1");
}
