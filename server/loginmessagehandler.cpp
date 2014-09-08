#include "loginmessagehandler.h"

#include "protocol.h"

void LoginMessageHandler::setData(QByteArray *d)
{
    data = d;
}

void LoginMessageHandler::extractPBMessage()
{
//    QDataStream *ds = new QDataStream(*data);
//    boost::iostreams::stream < boost::iostreams::DataStreamSource > dataStream ( ds );
//    userLoginMsg.ParseFromIstream(&dataStream);
//    delete ds;
}

void LoginMessageHandler::processData()
{
//    /// TODO use HASH for password

//     extractPBMessage();
//    user::LoginReplay replay;

//    QString q;

//    replay.set_msgtype(14);
//    //    qDebug()<< " User " << QString::fromStdString(ua.name()) << " require login! ";
//    /// TODO use prepared statements

//    q.append("SELECT id, password from USERS where name = '" + QString::fromStdString(userLoginMsg.name()) + "';");

////    qDebug() << q;

//    if (isLogged){
//        replay.set_replay(user::USER_ALREADY_LOGGED_IN);
//    }
//    else {
//        if ( !query->exec(q) ){
//            qDebug()<< query->lastError().text();
//            replay.set_replay(user::BAD_USER_OR_PASSWD);
//        }
//        else{
//            if (!query->first()){
//                qDebug()<< "No souch user in database";
//                replay.set_replay(user::BAD_USER_OR_PASSWD);
//            }
//            else
//            {
//                if( !query->value("password").toString().compare( QString::fromStdString(userLoginMsg.password() ))){
//                    qDebug()<< "LOGIN OK!";
//                    replay.set_replay( user::LOGIN_OK );
//                    user.ID = query->value("id").toInt();
//                    user.name = QString::fromStdString(userLoginMsg.name());
//                    isLogged = true;
//                }
//                else
//                {
//                    qDebug()<< "password incorect";
//                    replay.set_replay(user::BAD_USER_OR_PASSWD);
//                }
//            }
//        }
//    }

//    QByteArray ba = QByteArray(replay.ByteSize(),'\0');
//    replay.SerializeToArray(ba.data(),ba.size());

//    socket->write(ba);
}
