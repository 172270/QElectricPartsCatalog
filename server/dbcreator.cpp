#include "dbcreator.h"
#include <QDebug>
#include <QFile>
#include <QCryptographicHash>

DbCreator::DbCreator(QObject *parent) :
    QObject(parent)
{
    query = new QSqlQuery(db);
    if (!db.isOpen())
        db.open();
}

void DbCreator::initialize_database()
{
    QFile file("/home/zawisza/schema.sql");
    file.open(QIODevice::ReadOnly);
    QString schema = file.readAll();
    schema.replace("OTHER", "JSON");
    QStringList queries = schema.trimmed().split(";");

    for(int i=0;i<queries.size() ; i++){
        QString q;
        q.append(queries.at(i).trimmed());
        if(q.isEmpty())
            continue;
        if(!query->exec(q)){
            qDebug()<<query->lastError().text();
        }
    }

    addRootUser();
    addGroupRootNode();
}

void DbCreator::addGroupRootNode()
{
    QString q;
    q.append("insert into groups (parent_id, name, allowRecipe, allowItems, description, user_id)"
             " values(NULL, 'ROOT', false, false, 'The base group for all groups', "+ QString::number(adminId) +");");
    if (!query->exec(q)){
        qDebug()<<query->lastError().text();
    }
}

void DbCreator::addRootUser()
{
    QString q;
    QByteArray pass = QCryptographicHash::hash(QByteArray("qdmin"), QCryptographicHash::Sha512);

    q.append("INSERT INTO users( name, password, email, config) "
             " VALUES ( 'admin', '" + pass +"', 'b.w@linux.pl', '{}');");
    if (!query->exec(q)){
        qDebug()<<query->lastError().text();
    }
    adminId = query->lastInsertId().toInt();
}
