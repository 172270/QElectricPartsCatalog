#include "loginmessagehandler.h"

#include <QDebug>
#include <QCryptographicHash>

LoginMessageHandler::LoginMessageHandler(WorkerCache *cache):
    MessageHandlerInterface(cache)
{
}

void LoginMessageHandler::getUserData()
{
    m_cache.getUserData()->Clear();
    m_cache.getUserData()->CopyFrom(database.getUserByName( QString::fromStdString(req.name()) ));
}

void LoginMessageHandler::updateLastLogin()
{
    if(m_cache.getUserData()->IsInitialized()){
        database.updateLastLogin(*m_cache.getUserData());
    }
    if(m_cache.getUserData()->id() == 0){
        m_cache.getUserData()->MergeFrom(database.getUserByName(m_cache.getUserData()->getName()));
        database.updateLastLogin(*m_cache.getUserData());
    }
}

bool LoginMessageHandler::parseData(const QByteArray &ba)
{
    return req.ParseFromArray( ba.data(),ba.size() );
}

bool LoginMessageHandler::parseData(QByteArray &&ba)
{
    return req.ParseFromArray( ba.data(),ba.size() );
}

bool LoginMessageHandler::processData()
{
    if(!m_cache.userStatus()->logged ){
        QString userName = QString::fromStdString(req.name());

        QByteArray pass = QCryptographicHash::hash(QByteArray(req.password().data(), req.password().size() ), QCryptographicHash::Sha512);
        bool loginOk = database.checkUserPassword(userName, pass.toHex() );

        if(loginOk){
            res.set_replay(protbuf::Replay::LoginPass);
            m_cache.userStatus()->logged = true;
            getUserData();
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
