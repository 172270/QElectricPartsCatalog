#ifndef TST_ITEM_H
#define TST_ITEM_H

#include <QObject>
#include <QTest>

#include "DB_schema/item.h"
#include "DB_schema/user.h"
#include "DB_schema/package.h"
#include "DB_schema/group.h"

class tst_item : public QObject
{
    Q_OBJECT
public:
    explicit tst_item(QObject *parent = 0);

signals:

public slots:

private slots:

    void toArray_formsArray();
};

#endif // TST_ITEM_H
