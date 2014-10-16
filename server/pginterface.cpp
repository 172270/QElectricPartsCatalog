#include "pginterface.h"
#include <QDebug>
PgInterface::PgInterface()
{
    query = new QSqlQuery(db);
    if (!db.isOpen())
        db.open();
}

PgInterface::~PgInterface()
{
    delete query;
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
        u.set_lastlogin(query->value("lastlogin").toDateTime());
        u.set_description(query->value("description").toString());
        u.setConfig(query->value("config").toByteArray() );
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
             (user.has_description()? QString(", description"): QString("")) +
             ") values(:name, :password, :email, :config"+
             (user.has_phonenumber()? QString(", :phonenumber"): QString(""))+
             (user.has_address()? QString(", :address"): QString(""))+
             (user.has_description()? QString(", :desc"): QString(""))+
             +")");
    query->prepare(q);
    query->bindValue(":name", user.getName() );
    query->bindValue(":password", passwd );
    query->bindValue(":email",(user.getEmail().size()?user.getEmail():QString() ));
    query->bindValue(":config", QString(user.getDefaultConfig()) );
    query->bindValue(":phonenumber", user.getPhoneNumber());
    query->bindValue(":address", user.getAddress());
    query->bindValue(":desc", user.getDescription() );

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

bool PgInterface::userNameExists(QString &name)
{
    q.clear();
    q.append("SELECT exists(select true from users where name = :name); ");

    query->prepare(q);
    query->bindValue(":name",(name.size()? name :QString() ));
    query->exec();

    query->first();
    return query->value(0).toBool();
}

bool PgInterface::userEmailExists(QString &email)
{
    q.clear();
    q.append("SELECT exists(select true from users where email = :email); ");

    query->prepare(q);
    query->bindValue(":email",(email.size()? email :QString() ));
    query->exec();

    query->first();
    return query->value(0).toBool();
}

void PgInterface::updateLastLogin(User &u)
{
    q.clear();
    q.append("UPDATE users SET lastlogin = now() WHERE id = "+ QString::number( u.id()) +";");
    query->exec(q);
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
        u.set_phonenumber(query->value("phonenumber").toString() );
        u.set_registrationdate(query->value("registrationdate").toDateTime());
        u.set_lastlogin(query->value("lastlogin").toDateTime());
        u.set_description(query->value("description").toString());
        u.setConfig(query->value("config").toByteArray() );
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

bool PgInterface::checkUserPassword(QString user, QString passwd)
{
    q.clear();
    q.append("select password from users WHERE name=:name");
    query->prepare(q);
    query->bindValue(":name", user);
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

uint PgInterface::addPackage(Package &package)
{
    if(package.IsInitialized()){
        q.clear();
        q.append("INSERT INTO packages(name" +
                 (package.has_pinnumber()? QString(QStringLiteral(",pinNr")):QString()) +
                 (package.has_mounttype()? QString(QStringLiteral(",mountType")):QString()) +
                 (package.has_config()? QString(QStringLiteral(",config")):QString()) +
                 ") VALUES(:name"+
                 (package.has_pinnumber()? QString(QStringLiteral(",:pinNr")):QString()) +
                 (package.has_mounttype()? QString(QStringLiteral(",:mountType")):QString()) +
                 (package.has_config()? QString(QStringLiteral(",:config")):QString()) +
                 ");");
        query->prepare(q);
        query->bindValue(":name", package.getName() );
        if(package.has_pinnumber())
            query->bindValue(":pinNr", package.pinnumber() );
        if(package.has_mounttype())
            query->bindValue(":mountType", package.getMountType());
        if(package.has_config())
            query->bindValue(":config", package.config().toString() );

        if(!query->exec()){
            qDebug()<<query->lastError().text();
        }

        package.set_id(query->lastInsertId().toUInt());
        return package.id();
    }
    return 0;
}

quint32 PgInterface::addParameter(Parameter &parameter)
{
    if(parameter.IsInitialized()){
        q.clear();
        q.append("INSERT INTO parameters(name, config) VALUES(:name, :config);");
        query->prepare(q);
        query->bindValue(":name", parameter.getName() );
        query->bindValue(":config", parameter.config().toString() );
        if(!query->exec()){
            qDebug()<<query->lastError().text();
        }

        parameter.set_id(query->lastInsertId().toUInt());
        return parameter.id();
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

Group PgInterface::getGroup(uint id)
{
    Group g;
    q.clear();
    q.append("SELECT "
             "group_id, "
             "parent_id, "
             "name, "
             "description, "
             "creationtime, "
             "allowitems, "
             "allowrecipe "
           "FROM "
             "groups "
           "WHERE "
             "group_id =" + QString::number(id) );
    if(!query->exec(q)){
        qDebug()<<query->lastError().text();
    }
    int size = query->size();
    if(size == 1){
        query->first();
        g.set_id(query->value("group_id").toUInt());
        g.set_name(query->value("name").toString());
        g.set_parentid(query->value("parent_id").toUInt());
        g.set_description(query->value("description").toString());
        g.set_creationdate(query->value("creationtime").toDateTime());
        g.setAllowItems(query->value("allowitems").toBool() );
        g.setAllowRecipe(query->value("allowrecipe").toBool() );

       q.clear();
       q.append("SELECT parameter_id FROM group_parameter WHERE group_id =" + QString::number(g.id()));
       if(!query->exec(q)){
           qDebug()<<query->lastError().text();
       }
       while(query->next()){
           Parameter p;
           p.set_id(query->value("parameter_id").toUInt());
           g.add_parameter(p);
       }
    }
    return g;
}

void PgInterface::linkParameterToGroup(Group &group, const Parameter &parameter)
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
        qDebug()<<err.text() << query->lastQuery();
        throw err;
    }

    group.add_parameter(parameter);
}

quint32 PgInterface::addItem(Item &item)
{
    if(item.IsInitialized() ){
        q.clear();
        q.append("insert into items(users_id, case_id, group_id, name, symbol, namespace, parameters, isrecipe, isitem, update"
                 + (item.has_description() ? QString(", description") : QString()) +
                 ") VALUES (:uid, :cid, :gid, :name, :symbol, :namespace, :parameters, :isRecipe, :isItem, :up"
                 + (item.has_description() ? QString(", :desc") : QString()) + ");");
        if (!query->prepare(q)){
            qDebug() << query->lastError().text();
        }

        query->bindValue(":uid", item.user().id());
        query->bindValue(":cid", item.package().id());
        query->bindValue(":gid", item.group().id());
        query->bindValue(":name", item.getName());
        query->bindValue(":symbol", item.getSymbol());
        query->bindValue(":namespace", item.getNamespace());
        query->bindValue(":parameters", item.getParametersAsJSON());
        query->bindValue(":isRecipe", false);
        query->bindValue(":isItem", true);
        query->bindValue(":up", "now()");

        if(item.has_description()){
            query->bindValue(":desc", item.getDescription());
        }

        if(!query->exec()){
            qDebug()<<query->lastError().text();
        }
        item.set_id(query->lastInsertId().toUInt());
    }
    return item.id();
}
