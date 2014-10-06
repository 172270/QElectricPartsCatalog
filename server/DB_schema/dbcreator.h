#ifndef DBCREATOR_H
#define DBCREATOR_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

class DbCreator : public QObject
{
    Q_OBJECT
public:
    explicit DbCreator(QObject *parent = 0);
    ~DbCreator(){
        delete query;
    }

    void initialize_database();

signals:

public slots:


private:

    QSqlDatabase db;
    QSqlQuery *query;
};

#endif // DBCREATOR_H
