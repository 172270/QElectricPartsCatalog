#ifndef PACKAGE_H
#define PACKAGE_H

#include <QString>
#include "package.pb.h"

class PackageConfig{
public:
    QString toString(){return QString();}
};

class Package : public protbuf::Package
{
public:
    Package();

    protbuf::PackageBasicInformation getPackageBasicInformation();


    QString getName() const { return QString::fromStdString(name());}
    QString getMountType()const { return QString::fromStdString(mounttype());}
    PackageConfig& config() {return m_config;}

private:
    PackageConfig m_config;
};

#endif // PACKAGE_H
