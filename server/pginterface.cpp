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
    q.clear();
    q.append("INSERT INTO USERS ");
    q.append("( name, password, email, config" +
             (user.hasPhoneNumber()? QString(", phonenumber"): QString(""))+
             (user.hasAddress()? QString(", address"): QString(""))+
             ") values(:name, :password, :email, :config"+
             (user.hasPhoneNumber()? QString(", :phonenumber"): QString(""))+
             (user.hasAddress()? QString(", :address"): QString(""))+
             +")");
    query->prepare(q);
    query->bindValue(":name", user.getName() );
    query->bindValue(":password", passwd );
    query->bindValue(":email",user.hasEmail()?user.getEmail():QString() );
    query->bindValue(":config", QString(user.getDefaultConfig()) );
    query->bindValue(":phonenumber", user.getPhoneNumber());
    query->bindValue(":address", user.getAddress());

    if( !query->exec()){
        UserError err;
        err.setErrorNumber(query->lastError().number());
        err.setText(query->lastError().text());
        throw err;
    }

    return query->lastInsertId().toUInt();
}

User PgInterface::getUserByName(QString name)
{
    User u;
    q.clear();
    q.append("SELECT * FROM users WHERE name=:name");
    query->prepare(q);
    query->bindValue(":name", name );

    if( !query->exec()){
        UserError err;
        err.setErrorNumber(query->lastError().number());
        err.setText(query->lastError().text());
        throw err;
    }
    u.setName(name);
    if(query->size() == 1){
        query->first();
        u.setID(query->value("id").toUInt());
        u.setEmail(query->value("email").toString());
        u.setAddress(query->value("address").toString());
        u.setPhoneNumber(query->value("phonenumber").toString().trimmed() ); // char field has constant size
        u.setRegistrationDate(query->value("registrationdate").toDateTime());
        u.setConfig(query->value("registrationdate").toByteArray() );
    }
    return u;
}

void PgInterface::deleteUser(User user)
{
    q.clear();
    q.append("delete from users WHERE name=:name");
    query->prepare(q);
    query->bindValue(":name", user.getName());

    if( !query->exec()){
        UserError err;
        err.setErrorNumber(query->lastError().number());
        err.setText(query->lastError().text());
        throw err;
    }
}

bool PgInterface::checkUserPassword(User user, QString passwd)
{
    q.clear();
    q.append("select password from users WHERE name=:name");
    query->prepare(q);
    query->bindValue(":name", user.getName());
    if(!query->exec()){
        UserError err;
        err.setErrorNumber(query->lastError().number());
        err.setText(query->lastError().text());
        throw err;
    }
    if(query->size() != 1){
        return false;
    }
    query->first();
    QString result = query->value("password").toString().trimmed();
    return (result == passwd)? true : false;
}
