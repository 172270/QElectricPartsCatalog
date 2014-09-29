#ifndef TST_DBSCHEMA_STORAGE_H
#define TST_DBSCHEMA_STORAGE_H

#include <QObject>
#include <QTest>
#include <QSql>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>

#include "DB_schema/dbcreator.h"

#include "pginterface.h"


class tst_dbschema_storage : public QObject
{
    Q_OBJECT
public:
    explicit tst_dbschema_storage(QObject *parent = 0);

signals:

private slots:
    void init();
    void initTestCase();
    void cleanupTestCase();
    void cleanup();

    void createStorege_givesID();
private:
    QSqlQuery *query;
    QSqlDatabase db;
    DbCreator *creator;
    PgInterface *database;
    void removeTable(QString tblName);
};

#endif // TST_DBSCHEMA_STORAGE_H
