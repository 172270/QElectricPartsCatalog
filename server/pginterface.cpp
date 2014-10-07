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
    u.set_id(id);
    if(query->size() == 1){
        query->first();
        u.set_name(query->value("name").toString());
        u.set_email(query->value("email").toString());
        u.set_address(query->value("address").toString());
        u.set_phonenumber(query->value("phonenumber").toString().trimmed() ); // char field has constant size
        u.set_registrationdate(query->value("registrationdate").toDateTime());
        u.setConfig(query->value("registrationdate").toByteArray() );
    }
    return u;
}

uint PgInterface::addUser(User &user, QString passwd)
{
    q.clear();
    q.append("INSERT INTO USERS ");
    q.append("( name, password, email, config" +
             (user.has_phonenumber()? QString(", phonenumber"): QString(""))+
             (user.has_address()? QString(", address"): QString(""))+
             ") values(:name, :password, :email, :config"+
             (user.has_phonenumber()? QString(", :phonenumber"): QString(""))+
             (user.has_address()? QString(", :address"): QString(""))+
             +")");
    query->prepare(q);
    query->bindValue(":name", user.getName() );
    query->bindValue(":password", passwd );
    query->bindValue(":email",user.has_email()?user.getEmail():QString() );
    query->bindValue(":config", QString(user.getDefaultConfig()) );
    query->bindValue(":phonenumber", user.getPhoneNumber());
    query->bindValue(":address", user.getAddress());

    if( !query->exec()){
        UserError err;
        err.setErrorNumber(query->lastError().number());
        err.setText(query->lastError().text());
        throw err;
    }
    user.set_id( query->lastInsertId().toUInt() );
    Storage storage;
    storage.set_name(user.getName() + QString("_default"));
    storage.setID(addStorage(storage));
    linkStorageToUser(user, storage);
    user.addStorage(storage);
    return user.id();
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
    u.set_name(name);
    if(query->size() == 1){
        query->first();
        u.set_id(query->value("id").toUInt());
        u.set_email(query->value("email").toString());
        u.set_address(query->value("address").toString());
        u.set_phonenumber(query->value("phonenumber").toString().trimmed() ); // char field has constant size
        u.set_registrationdate(query->value("registrationdate").toDateTime());
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

void PgInterface::linkStorageToUser(const User &user, const Storage &storage)
{
    q.clear();
    q.append("insert into user_storage(storage_id, user_id) values (:sid, :uid)");
    query->prepare(q);
    query->bindValue(":uid", user.id() );
    query->bindValue(":sid", storage.getID() );

    if(!query->exec()){
        UserError err;
        err.setErrorNumber(query->lastError().number());
        err.setText(query->lastError().text());
        throw err;
    }
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
             " user_storage.user_id = "+ QString::number(user.id()) + ";");
    if(!query->exec()){
        UserError err;
        err.setErrorNumber(query->lastError().number());
        err.setText(query->lastError().text());
        throw err;
    }

    while(query->next() ){
        Storage s;
        s.setID(query->value(0).toUInt());
        s.set_name(query->value(1).toString() );
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

uint PgInterface::addStorage(const Storage &storage)
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

quint32 PgInterface::addParameter(const Parameter &parameter)
{
    if(parameter.IsInitialized()){
        q.clear();
        q.append("INSERT INTO parameters(parameter_id, name, config) VALUES(:pid, :name, :config);");
        query->prepare(q);
        query->bindValue(":pid", parameter.id() );
        query->bindValue(":name", parameter.getName() );
        query->bindValue(":config", parameter.getConfig() );
        query->exec();

        return query->lastInsertId().toUInt();
    }
    return 0;
}

quint32 PgInterface::addGroup(const Group &group)
{
    if(group.IsInitialized()){
        q.clear();
        q.append("INSERT INTO groups( parent_id, name, description, allowrecipe, allowitems)"
                 " VALUES(:pgid, :name, :desc, :allowrecipe, :allowitems);");
        query->prepare(q);
        query->bindValue(":pgid", group.parentid() );
        query->bindValue(":name", group.getName() );
        query->bindValue(":desc", group.getDescription() );
        query->bindValue(":allowrecipe", group.allowsets() );
        query->bindValue(":allowitems", group.allowitems() );
        if(!query->exec()){
            throw QString(query->lastError().text() );
        }

        return query->lastInsertId().toUInt();
    }
    return 0;
}

void PgInterface::linkParameterToGroup(const Group &group, const Parameter &parameter)
{
    q.clear();
    q.append("insert into group_parameter(parameter_id, group_id) values (:pid, :gid)");
    query->prepare(q);
    query->bindValue(":pid", parameter.id() );
    query->bindValue(":gid", group.id() );

    if(!query->exec()){
        UserError err;
        err.setErrorNumber(query->lastError().number());
        err.setText(query->lastError().text());
        throw err;
    }
}

quint32 PgInterface::addItem(const Item &item)
{

}
