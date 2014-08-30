#include "tst_magazine.h"

tst_Magazine::tst_Magazine(QObject *parent):
    QObject(parent)
{
}

void tst_Magazine::init()
{
    mag = new Magazine();
}

void tst_Magazine::cleanup()
{
    delete mag;
}

void tst_Magazine::magazine_shoudHaveName()
{
    QVERIFY (mag->getName() == "" );
}

void tst_Magazine::magazine_shoudHaveID()
{
    QVERIFY (mag->getID() != 0 );
}
