#ifndef TST_MAGAZINE_H
#define TST_MAGAZINE_H

#include <QObject>
#include <QTest>

#include "DB_schema/magazine.h"

class tst_Magazine :public QObject
{
    Q_OBJECT
public:
    tst_Magazine(QObject *parent = 0);

private slots:
    void init();
    void cleanup();

    void magazine_shoudHaveName();
    void magazine_shoudHaveID();

private:

    Magazine *mag;
};

#endif // TST_MAGAZINE_H
