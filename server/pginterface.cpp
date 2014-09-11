#include "pginterface.h"
#include <QDebug>
PgInterface::PgInterface()
{
    query = new QSqlQuery(db);
    if (!db.isOpen())
        db.open();
}

int PgInterface::addUserToDatabase(User user, QString passwd)
{
    QString q;
    q.append("INSERT INTO USERS ");
    q.append("( name, password, email ) values(:name, :password, :email)");
    if( !query->prepare(q)){
        qDebug() << query->lastError().text();
        UserError err;
        err.setText(query->lastError().text());
        throw err;
    }
    query->bindValue(":name", user.getName() );
    query->bindValue(":password", passwd );
    query->bindValue(":email", user.getEmail() );

    if( !query->exec()){
        qDebug() << query->lastError().text();
        UserError err;
        err.setText(query->lastError().text());
        throw err;
    }
    return 1;
}

bool PgInterface::checkUserPassword(User user, QString passwd)
{
    return 2;
}
