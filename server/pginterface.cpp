#include "pginterface.h"
#include <QDebug>
PgInterface::PgInterface()
{
    query = new QSqlQuery(db);
    if (!db.isOpen())
        db.open();
}

uint PgInterface::addUser(User user, QString passwd)
{
    QString q;
    q.append("INSERT INTO USERS ");
    q.append("( name, password, email ) values(:name, :password, :email)");
    if( !query->prepare(q)){
        UserError err;
        err.setErrorNumber(query->lastError().number());
        err.setText(query->lastError().text());
        throw err;
    }
    query->bindValue(":name", user.getName() );
    query->bindValue(":password", passwd );
    query->bindValue(":email", user.getEmail() );

    if( !query->exec()){
        UserError err;
        err.setErrorNumber(query->lastError().number());
        err.setText(query->lastError().text());
        throw err;
    }

    return query->lastInsertId().toUInt();
}

void PgInterface::deleteUser(User user)
{

}

bool PgInterface::checkUserPassword(User user, QString passwd)
{
    return 2;
}
