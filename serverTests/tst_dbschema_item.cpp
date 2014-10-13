#include "tst_dbschema_item.h"

tst_dbschema_item::tst_dbschema_item(QObject *parent) :
    QObject(parent)
{
}

void tst_dbschema_item::initTestCase()
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

    query->exec("DROP schema public cascade;");
    query->exec("create schema public;");

    creator = new DbCreator(this);
    creator->initialize_database();

    database = new PgInterface();
}

void tst_dbschema_item::saveItemWithBasicInfo()
{
    Group primaryGroup1, primaryGroup2, child1, child2;
    Parameter p1, p2;
    Package c1;
    User u1;

    c1.set_name("TO92");
    c1.set_pinnumber(3);

    database->addPackage(c1);

    u1.set_name("admin1");
    u1.set_email("cszawisza1@gmail.com");
    database->addUser(u1, QStringLiteral("sadasd"));

    p1.set_name("Parameter1");
    p1.config().setDefaultValue("N/A");
    p1.config().setValueType("String");

    p2.set_name("Parameter2");
    p2.config().setDefaultValue(21);
    p2.config().setValueType("int");

    p1.set_id(database->addParameter(p1));
    p2.set_id(database->addParameter(p2));

    primaryGroup1.set_parentid(1);
    primaryGroup1.set_name("primary group 1");
    primaryGroup1.set_description("description for primary 1");
    primaryGroup1.setAllowItems(true);
    primaryGroup1.setAllowRecipe(false);
    primaryGroup1.set_id(database->addGroup(primaryGroup1));

    primaryGroup2.set_parentid(1);
    primaryGroup2.set_name("primary group 2");
    primaryGroup2.set_description("description for primary 2");
    primaryGroup2.setAllowItems(true);
    primaryGroup2.setAllowRecipe(false);
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

    database->linkParameterToGroup(primaryGroup1, p1);
    database->linkParameterToGroup(primaryGroup2, p2);
    database->linkParameterToGroup(primaryGroup2, p1);

    Item i1;
    i1.set_name("Name1");
    i1.set_symbol("SYM0001");
    i1.set_name_space("std");
    i1.set_private(true);

    i1.setPackage(c1);
    i1.setUser(u1);
    i1.setGroup(child1);
    i1.set_description("kjfhsd");
    i1.insertParameter(1,"asdasd");
    i1.insertParameter(2,324);

    database->addItem(i1);

    QVERIFY(i1.id() != 0);
}
