#include "loginmessagehandler.h"

#include <QDebug>
#include <QCryptographicHash>

LoginMessageHandler::LoginMessageHandler(WorkerCache *cache):
    MessageHandlerInterface(cache)
{
}

void LoginMessageHandler::setData(QByteArray &&d)
{
    req.Clear();
    res.Clear();

    req.ParseFromArray( d.data(),d.size() );
}

void LoginMessageHandler::getUserData()
{
    m_cache.getUserData()->MergeFrom(database.getUserByName( QString::fromStdString(req.name()) ));
}

QByteArray LoginMessageHandler::getResponse()
{
    QByteArray ba;
    ba.resize(res.ByteSize());
    res.SerializePartialToArray(ba.data(), ba.size() );
    return ba;
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

bool LoginMessageHandler::clearCacheData()
{
    return true;
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
    return true;
}
