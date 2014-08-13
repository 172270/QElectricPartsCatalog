#ifndef MESSAGETYPE_H
#define MESSAGETYPE_H

#include <QByteArray>
#include <QList>

enum PBMsgType {
    LOGIN = 1,
    LOGOUT = 2,
    USERADD = 3,
    USERADDREPLAY = 4,
    USERDEL = 5,
    LOGINREPLAY = 14
};

class PBMessageTypeChecker
{
public:
    PBMessageTypeChecker( QByteArray *d ) {
        data = d;
        type = getMsgType();

        addType(PBMsgType::LOGIN);
        addType(PBMsgType::LOGOUT);
        addType(PBMsgType::USERADD);
        addType(PBMsgType::USERADDREPLAY);
        addType(PBMsgType::USERDEL);
        addType(PBMsgType::LOGINREPLAY);
    }

    PBMsgType getMsgType(){
        return  static_cast<PBMsgType>(data->at(1));
    }

    ///TODO corrent implementation
    bool isValid(){
        if (typesList.contains( type ))
            return true;
        return false;
    }

    PBMsgType getType() const
    {
        return type;
    }

private:

    void addType( PBMsgType t){
        if( ! typesList.contains( t ))
            typesList.append(t);
    }

    QList<PBMsgType> typesList;
    QByteArray *data;
    PBMsgType type;
};



#endif // MESSAGETYPE_H

