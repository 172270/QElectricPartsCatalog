#ifndef TST_LOGINHANDLER_H
#define TST_LOGINHANDLER_H

#include <QTest>
#include <QObject>

#include "DB_schema/loginmessage.h"

class tst_loginHandler : QObject
{
    Q_OBJECT
public:
    tst_loginHandler();

private slots:

    void initTestCase();
    void cleanupTestCase();


private:

};

#endif // TST_LOGINHANDLER_H
