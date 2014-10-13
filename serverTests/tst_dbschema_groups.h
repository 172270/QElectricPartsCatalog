#ifndef TST_DBSCHEMA_GROUPS_H
#define TST_DBSCHEMA_GROUPS_H

#include <QObject>
#include <QTest>
#include <QSql>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>

#include "DB_schema/dbcreator.h"
#include "DB_schema/group.h"
#include "DB_schema/parameter.h"
#include "pginterface.h"

class tst_dbschema_groups : public QObject
{
    Q_OBJECT
public:
    explicit tst_dbschema_groups(QObject *parent = 0);

signals:

public slots:

private slots:
    void init();
    void initTestCase();
    void cleanupTestCase();
    void cleanup();

    void addGroupToDatabase_shoudSaveGroupWithAllInformation();
    void addMeanygroups_givesSerialIDNumbers();
    void databaseShoudAllowCreateGroupsWithSameNameAndDifferentParent();
    void databaseThrowsExceptionWhenDoubleGroupAdd();
    void linkGroupWithParameter_linksGroupWithParameter();
    void getGroup_getsGroupInfo();
    void getGroup_getsGroupParameters();

private:
    QSqlQuery *query;
    QSqlDatabase db;
    DbCreator *creator;
    PgInterface *database;
};

#endif // TST_DBSCHEMA_GROUPS_H
