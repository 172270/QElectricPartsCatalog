#ifndef TST_SBSCHEMA_USER_H
#define TST_SBSCHEMA_USER_H

#include <QObject>
#include <QTest>
#include <QSql>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>

#include "DB_schema/dbcreator.h"

#include "db_queries.h"
#include "pginterface.h"

class tst_dbschema_user : public QObject
{
    Q_OBJECT
public:
    explicit tst_dbschema_user(QObject *parent = 0);

signals:

public slots:

private slots:
    void init();
    void initTestCase();
    void cleanupTestCase();
    void cleanup();

    void databaseContains_users_table();
    void usersTable_containsColumns();
    void typesAreCorrect();
    void createUserShoudGiveNewId();
    void createUserWithSameNameOrEmail_throwaException();
    void createUserWithoutNeededFields_throwsException();

private:
    QSqlQuery *query;
    QSqlDatabase db;
    DbCreator *creator;

    db_information_schema_tester *tester;
    PgInterface *database;
};

#endif // TST_SBSCHEMA_USER_H
