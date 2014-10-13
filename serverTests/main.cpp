
#include <QTest>
#include <QTimer>
#include <QCoreApplication>

#include "tst_servertests.h"
#include "tst_user.h"
#include "tst_magazine.h"
#include "tst_dbschema_user.h"
#include "tst_dbschema_storage.h"
#include "tst_item.h"
#include "tst_itempackage.h"
#include "tst_dbschema_groups.h"
#include "tst_parameterconfig.h"
#include "tst_dbschema_item.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setUserName("postgres");
    db.setPassword("postgres");

    tst_user test2;
    tst_Magazine test3;
    tst_dbschema_user test4;
    tst_dbschema_storage test5;
    tst_item test6;
    tst_ItemPackage test7;
    tst_dbschema_groups test8;
    tst_ParameterConfig test9;
    tst_dbschema_item test10;


    int t2 = QTest::qExec(&test2, qApp->arguments() );
    int t3 = QTest::qExec(&test3, qApp->arguments() );
    int t4 = QTest::qExec(&test4, qApp->arguments() );
    int t5 = QTest::qExec(&test5, qApp->arguments() );
    int t6 = QTest::qExec(&test6, qApp->arguments() );
    int t7 = QTest::qExec(&test7, qApp->arguments() );
    int t8 = QTest::qExec(&test8, qApp->arguments() );
    int t9 = QTest::qExec(&test9, qApp->arguments() );
    int t10= QTest::qExec(&test10,qApp->arguments() );

    QTimer::singleShot(100,&a,SLOT(quit()));
    return a.exec() | t2 | t3 | t4 | t5 | t6 | t7 | t8 | t9 | t10;
}

