#include "tst_user.h"

tst_user::tst_user(QObject *parent) :
    QObject(parent)
{
}

void tst_user::user_ShoudCreatePbMessage()
{
    setRequiredFields();
    QByteArray *ba = user->toArray();
    QVERIFY( ba->size() > 0 );
}


void tst_user::initTestCase()
{
}

void tst_user::cleanupTestCase()
{
}

void tst_user::init()
{
    user = new User();
}

void tst_user::cleanup()
{
    delete user;
}

void tst_user::userShoudContainName()
{
    QVERIFY(user->getName() == "" );
}

void tst_user::setName_shoudSetName()
{
    QVERIFY( user->getName() == "" );
    user->setName("stefan");
    QVERIFY( user->getName() == "stefan" );
}

void tst_user::nameShoudBeTrimmed()
{
    QVERIFY( user->getName() == "" );
    user->setName(" stefan");
    QVERIFY( user->getName() == "stefan" );
}

void tst_user::setName_shoudNotAllowEmptyStrings()
{
    QVERIFY_EXCEPTION_THROWN (user->setName(""), QString );
}

void tst_user::nameMustBeLongerThen3Letters()
{
    QVERIFY_EXCEPTION_THROWN (user->setName("aas"), QString );
}

void tst_user::nameMustBeShorterThen33Letters()
{
    QVERIFY_EXCEPTION_THROWN (user->setName("asdfghjklasdfghjklasdfghjklasdfgs"), QString );
}

void tst_user::nameCanHaveDotsAndDashes()
{
    user->setName("abc.def");
    QVERIFY( user->getName() == "abc.def" );
    user->setName("abc_def");
    QVERIFY( user->getName() == "abc_def" );
}

void tst_user::userShoudContainEMail()
{
    QVERIFY( user->getEmail() == "" );
}

void tst_user::setEmail_shoudSetEmail()
{
    QVERIFY( user->getEmail() == "" );
    user->setEmail("stefan@s.xx");
    QVERIFY( user->getEmail() == "stefan@s.xx" );
}

void tst_user::spacesShoudBeRemovedFromEmail()
{
    QVERIFY( user->getEmail() == "" );
    user->setEmail(" stefan@s.xx");
    QVERIFY( user->getEmail() == "stefan@s.xx" );
}

void tst_user::setEmail_shoudNotAllowEmptyStrings()
{
    QVERIFY_EXCEPTION_THROWN (user->setEmail(""), QString );
}

void tst_user::setEmail_ShoudLowerTheLetters()
{
    QVERIFY( user->getEmail() == "" );
    user->setEmail("STeFAN@s.Xx");
    QVERIFY( user->getEmail() == "stefan@s.xx" );
}

void tst_user::badEmail_ShoudThrowException()
{
    QVERIFY_EXCEPTION_THROWN (user->setEmail("abx@"), QString );
    QVERIFY_EXCEPTION_THROWN (user->setEmail("xxxx"), QString );
    QVERIFY_EXCEPTION_THROWN (user->setEmail("wu @ab"), QString );
}

void tst_user::goodEmail_shoudNot_throwAnExeption()
{
    try{
        user->setEmail("sdfs@a.bb");
        user->setEmail("d223zxc@b.cc");
        user->setEmail("ab.c@w.ll");
    }
    catch(QString e){
        QVERIFY(0);
    }
}

void tst_user::defoultIdIsZero()
{
    QVERIFY(user->getID() == 0);
}

void tst_user::setId_setsID()
{
    user->setID(5);
    QVERIFY( user->getID() == 5);
}

void tst_user::setAddress_setsAddress()
{
    user->setAddress("New York, 2/3");
    QVERIFY(user->getAddress() == "New York, 2/3");
}

void tst_user::setPhoneNumber_setsPhoneNumber()
{
    user->setPhoneNumber( QString("123456789") );
    QVERIFY(user->getPhoneNumber() == "123456789");
}

void tst_user::user_shoudContainDefaultMagazine()
{
    Storage s = user->getStorage();
    QVERIFY( s.getID() == 0 );
}

void tst_user::addStorage_ShoudAddStorage()
{
    Storage s;
    s.setID(1);
    s.setName("jakas nazwa");
    QVERIFY( user->storagesNumber() == 0);
    user->addStorage(s);
    QVERIFY( user->storagesNumber()  == 1);
}

void tst_user::addStorage_ShoudThrowExeptionWhenStorageIsNotInitialized()
{
    Storage s;
    QVERIFY_EXCEPTION_THROWN (user->addStorage(s), QString );
}

void tst_user::addStorage_ShoudThrowExeptionWhenStorageIspartiallyInitialized()
{
    Storage s;
    s.setID(5);
    QVERIFY_EXCEPTION_THROWN (user->addStorage(s), QString );
    Storage s2;
    s2.setName("assas");
    QVERIFY_EXCEPTION_THROWN (user->addStorage(s), QString );
}

void tst_user::createMsgFromUserWithoutName_throwsException()
{
    setRequiredFields();

    user->clearName();
    QVERIFY_EXCEPTION_THROWN(user->toArray(), QString );
}

void tst_user::createMsgFromUserWithoutId_throwsException()
{
    setRequiredFields();

    user->clearID();
    QVERIFY_EXCEPTION_THROWN(user->toArray(), QString );
}

void tst_user::setRequiredFields()
{
    user->setID(10);
    user->setName("NAME");
    user->setEmail("email@ww.ww");
}

void tst_user::createMsgFromUserWithoutEmail_throwsException()
{
    setRequiredFields();

    user->clearEmail();
    QVERIFY_EXCEPTION_THROWN(user->toArray(), QString );
}

void tst_user::toArray_createsAByteArray()
{
    setRequiredFields();
    user->setStorage(2);
    user->setAddress("adress");
    user->setPhoneNumber("123123123");

    QByteArray *ba = user->toArray();

    QVERIFY(ba->size() > 0);}

void tst_user::toArray_createsAProperMessage()
{
    setRequiredFields();
    user->setStorage(2);
    user->setAddress("adress");
    user->setPhoneNumber("123123123");
    QByteArray *ba = user->toArray();

    User decodedUser;
    decodedUser.fromArray(ba);
    QVERIFY(*ba == *decodedUser.toArray() );
}
