#include "pginterface.h"
#include <QDebug>
PgInterface::PgInterface()
{
    query = new QSqlQuery(db);
    if (!db.isOpen())
        db.open();
}

User PgInterface::getUserById(uint id)
{
    User u;
    q.clear();
    q.append("SELECT * FROM users WHERE id=:id");
    query->prepare(q);
    query->bindValue(":id", id );

    if( !query->exec()){
        UserError err;
        err.setErrorNumber(query->lastError().number());
        err.setText(query->lastError().text());
        throw err;
    }
    u.setID(id);
    if(query->size() == 1){
        query->first();
        u.setName(query->value("name").toString());
        u.setEmail(query->value("email").toString());
        u.setAddress(query->value("address").toString());
        u.setPhoneNumber(query->value("phonenumber").toString().trimmed() ); // char field has constant size
        u.setRegistrationDate(query->value("registrationdate").toDateTime());
        u.setConfig(query->value("registrationdate").toByteArray() );
    }
    return u;
}

uint PgInterface::addUser(User &user, QString passwd)
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
    user.setID( query->lastInsertId().toUInt() );
    Storage storage;
    storage.setName(user.getName() + QString("_default"));
    storage.setID(addStorage(storage));
    linkStorageToUser(user, storage);

    return user.getID();
}

User PgInterface::getUserByName(const QString &name)
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

    u.addStorages( getUserStorages(u) );

    return u;
}

void PgInterface::deleteUser(User &user)
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

bool PgInterface::checkUserPassword(User &user, QString passwd)
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

void PgInterface::linkStorageToUser(User &user, Storage &storage)
{
    q.clear();
    q.append("insert into user_storage(storage_id, user_id) values (:sid, :uid)");
    query->prepare(q);
    query->bindValue(":uid", user.getID() );
    query->bindValue(":sid", storage.getID() );

    if(!query->exec()){
        UserError err;
        err.setErrorNumber(query->lastError().number());
        err.setText(query->lastError().text());
        throw err;
    }

    user.addStorage(storage);
}

QList<Storage> PgInterface::getUserStorages(User &user)
{
    QList<Storage> storages;
    q.clear();
    q.append("SELECT "
             " storage.id, "
             " storage.name, "
             " storage.creationdate "
             "FROM "
             " public.user_storage, "
             " public.storage "
             "WHERE "
             " user_storage.storage_id = storage.id AND "
             " user_storage.user_id = "+ QString::number(user.getID()) + ";");
    if(!query->exec()){
        UserError err;
        err.setErrorNumber(query->lastError().number());
        err.setText(query->lastError().text());
        throw err;
    }

    while(query->next() ){
        Storage s;
        s.setID(query->value(0).toUInt());
        s.setName(query->value(1).toString() );
        s.setCreationDate(query->value(2).toDateTime());
        storages.append(s);
    }

    return storages;
}

//QList<File> PgInterface::getUserFiles(User &user)
//{
////    SELECT
////      files.name,
////      files.filesize,
////      files.sha,
////      files.mimetype
////    FROM
////      public.files,
////      public.user_files
////    WHERE
////      user_files.file_id = files.file_id;
//    return QList<File>();
//}

uint PgInterface::addStorage(Storage &storage)
{
    if(storage.IsInitialized() ){
        q.clear();
        q.append("INSERT INTO storage(name) VALUES (:name);");
        query->prepare(q);
        query->bindValue(":name", storage.getName() );
        query->exec();

        return query->lastInsertId().toUInt();
    }
    return 0;
}
