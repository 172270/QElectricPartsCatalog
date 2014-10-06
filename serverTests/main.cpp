
#include <QTest>
#include <QTimer>
#include <QCoreApplication>

#include "tst_servertests.h"
#include "tst_user.h"
#include "tst_magazine.h"
#include "tst_dbschema_user.h"
#include "tst_dbschema_storage.h"
#include "tst_item.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setUserName("postgres");
    db.setPassword("postgres");
    tst_user test2;
    tst_Magazine test3;
//    tst_dbschema_user test4;
//    tst_dbschema_storage test5;
    tst_item test6;

    int t2 = QTest::qExec(&test2, qApp->arguments() );
    int t3 = QTest::qExec(&test3, qApp->arguments() );
    int t4 = 0;//QTest::qExec(&test4, qApp->arguments() );
    int t5 = 0;//QTest::qExec(&test5, qApp->arguments() );
    int t6 = QTest::qExec(&test6, qApp->arguments() );

    QTimer::singleShot(1,&a,SLOT(quit()));
    return a.exec() | t2 | t3 | t4 | t5 | t6;
}

