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

class PgInterface
{
public:
    PgInterface(QString connectionName);
    ~PgInterface();

    User getUserById(uint id);
    User getUserByName(const QString &name);
    uint addUser(User &protbuf, QString passwd);
    bool userNameExists(QString &name);
    bool userEmailExists(QString &email);
    void updateLastLogin(User &u);
    void updateConfig(User &u);

    void deleteUser(User &protbuf);
    bool checkUserPassword(QString protbuf, QString passwd);
    void linkStorageToUser(const User &protbuf, const Storage &storage);
    QList<Storage> getUserStorages(User &protbuf);

    uint addStorage(const Storage &storage);
    uint addPackage(Package &package);

    quint32 addParameter(Parameter &parameter);
    QList<Parameter> getParameters();

    quint32 addGroup(const Group &group);
    Group getGroup(uint id);
    QList<Group> getGroups();

    void linkParameterToGroup(Group &group, const Parameter &parameter);

    quint32 addItem(Item &item);
    void saveGroupParametersIDs(Group &g);

    int activeUser() const;
    void setActiveUser(int activeUser);

private:
    int m_activeUser = 0;
    QSqlDatabase db;
    QSqlQuery *query;
    QString q;
};

#endif // PGINTERFACE_H
