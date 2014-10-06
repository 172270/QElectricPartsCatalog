#include "tst_item.h"

tst_item::tst_item(QObject *parent) :
    QObject(parent)
{
}

void tst_item::initTestCase()
{
    longText.clear();
    str.clear();
    ba = new QByteArray();
    QFile f("/home/zawisza/opis.txt");
    f.open(QIODevice::ReadOnly);
    longText.append(f.readAll());
    str.append(longText.toStdString());
}

void tst_item::cleanupTestCase()
{
    delete ba;
}

void tst_item::toArray_formsArray()
{
    Item it;
    Package p;
    User u;
    Group g;

    u.set_id(3);
    p.set_id(4);
    g.set_id(5);

    it.set_id(1);
    it.set_name("NAZWA");
    it.setPackage(p);
    it.setUser(u);
    it.setGroup(g);
    it.set_description(str);
    it.set_symbol("symbol");
    it.set_namespace_("namespace");
    it.set_private(false);
    it.set_adddate(QDateTime::currentDateTime());
    it.set_updatedate(QDateTime::currentDateTime());

    it.addParameter(1,"text parameter");
    it.addParameter(2,1);
    it.addParameter(3,"from -20.0°C to +80.0°C");
    it.addParameter(4,23.54);
    it.addParameter(5, QDateTime::currentDateTime() );
    it.addParameter(6, 'c');

    ba->clear();
    it.toArray(ba);
    Item it2;
    it2.fromArray(ba);

    QVERIFY(it2.id() == it.id() );
    QVERIFY(it2.name() == it.name() );
    QVERIFY(it2.symbol() == it.symbol());
    QVERIFY(it2.namespace_() == it.namespace_() );
    QVERIFY(it2.isPrivate() == it.isPrivate() );
    QVERIFY(it2.getAddDate() == it.getAddDate() );
    QVERIFY(it2.getUpdateDate()== it.getUpdateDate() );

    QVERIFY(it2.package().id()  == it.package().id());
    QVERIFY(it2.group().id()    == it.group().id());
    QVERIFY(it2.getParameters() == it.getParameters() );
    QVERIFY(it2.getAddDate()    == it.getAddDate() );
    QVERIFY(it2.getUpdateDate() == it.getUpdateDate() );
    QVERIFY(it2.description()   == it.description() );
}

void tst_item::specialCharacters_HaveProperEncoding()
{
    Item it;
    Package p;
    User u;
    Group g;

    u.set_id(3);
    p.set_id(4);
    g.set_id(5);

    it.set_id(1);
    it.set_name("!@#$%^&*()≠²³¢€½§·«»¡¿£¼‰∧≈¾±°ΩŒĘ®™¥↑↔ÓÞĄŚÐÆŊ•ƏŁŻŹĆ‘“Ń∞×÷żźć„”ńµąśðæŋ’ə…łó→↓←ß©ęœπ");
    it.setPackage(p);
    it.setUser(u);
    it.setGroup(g);
    it.set_description(str);
    it.set_symbol("symbol");
    it.set_namespace_("namespace");
    it.set_private(false);
    it.set_adddate(QDateTime::currentDateTime());
    it.set_updatedate(QDateTime::currentDateTime());

    it.addParameter(1,"text parameter");
    it.addParameter(2,1);
    it.addParameter(3,"from -20.0°C to +80.0°C");
    it.addParameter(4,23.54);
    it.addParameter(5, QDateTime::currentDateTime() );
    it.addParameter(6, 'c');

    ba->clear();
    it.toArray(ba);
    Item it2;
    it2.fromArray(ba);

    QVERIFY(it2.name() == "!@#$%^&*()≠²³¢€½§·«»¡¿£¼‰∧≈¾±°ΩŒĘ®™¥↑↔ÓÞĄŚÐÆŊ•ƏŁŻŹĆ‘“Ń∞×÷żźć„”ńµąśðæŋ’ə…łó→↓←ß©ęœπ");
}
