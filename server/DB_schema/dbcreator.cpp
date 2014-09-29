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

//    query->exec("CREATE TABLE IF NOT EXISTS users ("
//                "id SERIAL PRIMARY KEY, "
//                "name  varchar(34) NOT NULL UNIQUE CHECK (name <> ''),"
//                "password  char(32) NOT NULL CHECK (name <> ''),"
//                "email  varchar(255) NOT NULL UNIQUE CHECK (name <> ''),"
//                "phonenumber char(10),"
//                "address varchar(1024),"
//                "registrationDate TIMESTAMP NOT NULL DEFAULT NOW(),"
//                "lastlogin TIMESTAMP,"
//                "config json"
//                " );");
//    query->exec("CREATE TABLE \"public\".\"storage\" ("
//                "\"id\" serial NOT NULL , "
//                "\"name\" varchar(255) , "
//                "\"creationDate\" TIMESTAMP NOT NULL DEFAULT NOW() "
//                ");");
//    query->exec("ALTER TABLE \"public\".\"storage\" ADD PRIMARY KEY ( \"id\" );");
//    query->exec("ALTER TABLE \"public\".\"storage\" ADD CONSTRAINT \"storage_uk\" UNIQUE ( \"name\" );");
//    query->exec("CREATE TABLE \"public\".\"user_magazines\" ("
//                "\"storage_id\" integer NOT NULL , "
//                "\"user_id\" integer NOT NULL"
//                "); ");
//    query->exec("ALTER TABLE \"public\".\"user_magazines\" ADD FOREIGN KEY ( \"storage_id\" ) REFERENCES \"public\".\"storage\" ( \"id\" ) MATCH FULL  ON DELETE  NO ACTION  ON UPDATE  NO ACTION;");
//    query->exec("ALTER TABLE \"public\".\"user_magazines\" ADD FOREIGN KEY ( \"users_id\" ) REFERENCES \"public\".\"users\" ( \"id\" ) MATCH FULL  ON DELETE  NO ACTION  ON UPDATE  NO ACTION;");
}
