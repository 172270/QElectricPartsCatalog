
#include <QTest>
#include <QTimer>
#include <QCoreApplication>

#include "tst_servertests.h"
#include "tst_user.h"
#include "tst_magazine.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ServerTests test1;
    tst_user test2;
    tst_Magazine test3;

    //int x= QTest::qExec(&test1, qApp->arguments() );
    int t2 = QTest::qExec(&test2, qApp->arguments() );
    int t3 = QTest::qExec(&test3, qApp->arguments() );

    QTimer::singleShot(1000,&a,SLOT(quit()));
    return a.exec() ;
}

