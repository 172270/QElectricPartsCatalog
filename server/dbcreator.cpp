#include "dbcreator.h"
#include <QDebug>
#include <QFile>

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

    addGroupRootNode();
}

void DbCreator::addGroupRootNode()
{
    QString q;
    q.append("insert into groups (parent_id, name, allowRecipe, allowItems, description)"
             " values(NULL, 'ROOT', false, false, 'The base group for all groups');");
    if (!query->exec(q)){
        qDebug()<<query->lastError().text();
    }
}
