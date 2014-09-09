#ifndef TST_SBSCHEMA_USER_H
#define TST_SBSCHEMA_USER_H

#include <QObject>
#include <QTest>
#include <QSql>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>

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

private:
    QSqlQuery *query;
    QSqlDatabase db;
};

#endif // TST_SBSCHEMA_USER_H
