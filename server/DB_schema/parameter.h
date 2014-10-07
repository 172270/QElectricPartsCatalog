#ifndef PARAMETER_H
#define PARAMETER_H

#include <QString>
#include "parameters.pb.h"

class Parameter : public parameters::Parameter
{
public:
    QString getName() const {return QString::fromStdString( name() );}
    QByteArray getConfig() const { return QByteArray(config().data() ); }
    Parameter();
};

#endif // PARAMETER_H
