
#include <QTest>
#include <QCoreApplication>

#include "tst_servertests.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ServerTests test1;

    int x= QTest::qExec(&test1, qApp->arguments() );

    return a.exec();
}

