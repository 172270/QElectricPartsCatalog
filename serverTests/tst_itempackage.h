#ifndef TST_ITEMPACKAGE_H
#define TST_ITEMPACKAGE_H

#include <QObject>
#include <QTest>

#include "DB_schema/item.h"
#include "DB_schema/user.h"
#include "DB_schema/package.h"
#include "DB_schema/group.h"


class tst_ItemPackage : public QObject
{
    Q_OBJECT
public:
    explicit tst_ItemPackage(QObject *parent = 0);

signals:

public slots:

};

#endif // TST_ITEMPACKAGE_H
