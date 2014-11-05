#include "loginmessagehandler.h"

#include <QDebug>
#include <QCryptographicHash>

LoginMessageHandler::LoginMessageHandler(WorkerCache *cache):
    MessageHandlerInterface(cache)
{
}

void LoginMessageHandler::getUserData()
{
    cache().getUserData()->Clear();
    cache().getUserData()->CopyFrom(database.getUserByName( QString::fromStdString(req.name()) ));
    cache().getUserData()->updateConfig();
}

void LoginMessageHandler::updateLastLogin()
{
    if(cache().getUserData()->IsInitialized()){
        database.updateLastLogin(); // active user in database shoud be updated
    }
    if(cache().getUserData()->id() == 0){
        cache().getUserData()->MergeFrom(database.getUserByName(m_cache.getUserData()->getName()));
        cache().getUserData()->updateConfig();
        database.updateLastLogin();
    }
}

bool LoginMessageHandler::parseData(const QByteArray &ba)
{
    return req.fromArray(ba);
}

bool LoginMessageHandler::processData()
{
    if(!m_cache.userStatus()->logged ){
        QByteArray pass = QCryptographicHash::hash(QByteArray(req.password().data(), req.password().size() ), QCryptographicHash::Sha512);
        bool loginOk = database.checkUserPassword(req, pass.toHex() );

        if(loginOk){
            res.set_replay(protbuf::Replay::LoginPass);
            m_cache.userStatus()->logged = true;
            getUserData();
            cache().getDatabase().setActiveUser(cache().getUserData()->id() );
            updateLastLogin();
        }
        else{
            res.set_replay(protbuf::Replay::LoginDeny);
        }
    }
    else{
        res.set_replay(protbuf::Replay::UserAlreadyLogged);
    }
    return true;
}

bool LoginMessageHandler::moveResponseToCache()
{
    QByteArray *ba = new QByteArray(res.ByteSize(),'\0');
    res.SerializePartialToArray(ba->data(), ba->size() );
    m_cache.responseMessage()->addMessage(MsgType::resLogin, ba);
    if(m_cache.userStatus()->logged)
        m_cache.responseMessage()->addMessage(m_cache.getUserData());
    return true;
}
