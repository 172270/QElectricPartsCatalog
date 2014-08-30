
#include <QTest>
#include <QTimer>
#include <QCoreApplication>

#include "tst_servertests.h"
#include "tst_user.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ServerTests test1;
    tst_user test2;

    //int x= QTest::qExec(&test1, qApp->arguments() );
    int y= QTest::qExec(&test2, qApp->arguments() );

    QTimer::singleShot(1000,&a,SLOT(quit()));
    return a.exec();
}

