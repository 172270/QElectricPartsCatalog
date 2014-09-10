#ifndef DB_QUERIES_H
#define DB_QUERIES_H

#include <QString>
#include <QVariant>

#include <QSql>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>

#include <QDebug>

class db_information_schema_tester
{
public:
    db_information_schema_tester(){
        query = new QSqlQuery(db);
        if (!db.isOpen())
            db.open();
        m_dbName = "ekatalog_tests";
    }

    void setTable(QString table){
        m_table = table;
    }

    bool columnExists(QString column){
        QString q = "select exists (select * from information_schema.columns "
                " where table_catalog= '"
                +m_dbName.toLower()
                +"' and table_name = '"
                +m_table.toLower()
                +"' AND column_name = '"
                +column.toLower()
                +"');";
        if(!query->exec(q))
        {
            qDebug()<<query->lastError().text();
        }
        query->first();
        QString data = query->value(0).toString().toLower();
        return data == "true";
    }

    bool columnTypeCorrect( QString col, QString type){
        QString q = "select * from information_schema.columns "
                " where table_catalog= '"
                +m_dbName.toLower()
                +"' and table_name = '"
                +m_table.toLower()
                +"' AND column_name = '"
                +col.toLower()
                +"';";
        if(!query->exec(q))
        {
            qDebug()<<query->lastError().text();
        }
        query->first();

        QString data = query->value("udt_name").toString().toLower();
        return data == type;
    }

private:
    QSqlDatabase db;
    QSqlQuery *query;
    QString m_table;
    QString m_dbName;
};






#endif // DB_QUERIES_H
