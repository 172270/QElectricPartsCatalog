#ifndef PACKAGE_H
#define PACKAGE_H

#include <QString>
#include "package.pb.h"
#include "message.h"

class PackageConfig{
public:
    QString toString(){return QString();}
};

class Package : public protocol::QMessage<protbuf::Package>
{
public:
    Package();
    MsgType type() const;
    protbuf::PackageBasicInformation getPackageBasicInformation();

    QString getName() const { return QString::fromStdString(name());}
    QString getMountType()const { return QString::fromStdString(mounttype());}
    PackageConfig& config() { return m_config; }

private:
    PackageConfig m_config;

    // QMessage interface
public:
    void afterFromArray()
    {
    }
    void beforeToArray()
    {
    }
};

#endif // PACKAGE_H
