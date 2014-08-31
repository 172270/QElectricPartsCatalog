#ifndef TST_LOGINMESSAGE_H
#define TST_LOGINMESSAGE_H

#include <QObject>
#include <QTest>

#include "user.h"

class tst_user : public QObject
{
    Q_OBJECT
public:
    explicit tst_user(QObject *parent = 0);

signals:

public slots:

private slots:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();

    void userShoudContainName();
    void setName_shoudSetName();
    void spacesShoudBeRemovedFromName();
    void setName_shoudNotAllowEmptyStrings();

    void userShoudContainEMail();
    void setEmail_shoudSetEmail();
    void spacesShoudBeRemovedFromEmail();
    void setEmail_shoudNotAllowEmptyStrings();
    void setEmail_ShoudLowerTheLetters();
    void badEmail_ShoudThrowException();
    void goodEmail_shoudNot_throwAnExeption();

    void user_shoudContainDefaultMagazine();
    void addStorage_ShoudAddStorage();
    void addStorage_ShoudThrowExeptionWhenStorageIsNotInitialized();
    void addStorage_ShoudThrowExeptionWhenStorageIspartiallyInitialized();

private:

    User *user;


};

#endif // TST_LOGINMESSAGE_H
