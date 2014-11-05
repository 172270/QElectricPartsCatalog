#ifndef PGINTERFACE_H
#define PGINTERFACE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include "messages/user.h"
#include "messages/package.h"
#include "messages/parameter.h"
#include "messages/group.h"
#include "messages/storage.h"
#include "messages/file.h"
#include "messages/item.h"
#include "messages/loginrequest.h"

class PgInterface
{
public:
    PgInterface(QString connectionName);
    ~PgInterface();

    User getUserByName(const QString &name);
    uint addUser(User &protbuf, QString passwd);
    bool userNameExists(QString &name);
    bool userEmailExists(QString &email);
    void updateLastLogin();
    void updateConfig(User &u);
    void deleteUser(User &protbuf);
    bool checkUserPassword(LoginRequest &user, QString passwd);
    bool checkUserPassword(User &user, QString passwd);

    void linkStorageToUser(const User &protbuf, const Storage &storage);
    QList<Storage> getUserStorages(User &protbuf);

    uint addStorage(Storage &storage);
    uint addPackage(Package &package);

    quint32 addParameter(Parameter &parameter);
    QList<Parameter> getParameters();

    quint32 addGroup(Group &group);
    Group getGroup(uint id);
    QList<Group> getGroups();



    quint32 addItem(Item &item);
    void saveGroupParametersIDs(Group &g);

    int activeUser() const;
    void setActiveUser(int activeUser);

    quint32 addParameter(Parameter *parameter);
    bool updateParameter(const Parameter &parameter);
private:
    int m_activeUser = 0;
    QSqlDatabase db;
    QSqlQuery *query;
    QString q;

    void linkParametersToGroup(Group &group);
};

#endif // PGINTERFACE_H
