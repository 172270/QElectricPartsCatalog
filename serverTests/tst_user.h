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

    void setRequiredFields();
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
    void setId_setsID();

    void user_shoudContainDefaultMagazine();
    void addStorage_ShoudAddStorage();
    void addStorage_ShoudThrowExeptionWhenStorageIsNotInitialized();
    void addStorage_ShoudThrowExeptionWhenStorageIspartiallyInitialized();

    void user_ShoudCreatePbMessage();
    void createMsgFromUserWithoutName_throwsException();
    void createMsgFromUserWithoutId_throwsException();
    void createMsgFromUserWithoutEmail_throwsException();

    void extractFromByteArray();

private:
    User *user;
};

#endif // TST_LOGINMESSAGE_H
