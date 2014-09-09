
#include <QTest>
#include <QTimer>
#include <QCoreApplication>

#include "tst_servertests.h"
#include "tst_user.h"
#include "tst_magazine.h"
#include "tst_sbschema_user.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    tst_user test2;
    tst_Magazine test3;
    tst_dbschema_user test4;

    int t2 = QTest::qExec(&test2, qApp->arguments() );
    int t3 = QTest::qExec(&test3, qApp->arguments() );
    int t4 = QTest::qExec(&test4, qApp->arguments() );

    QTimer::singleShot(1,&a,SLOT(quit()));
    return a.exec() | t2 | t3 | t4 ;
}

