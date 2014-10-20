#ifndef PACKAGE_H
#define PACKAGE_H

#include <QString>
#include "package.pb.h"
#include "message.h"

class PackageConfig{
public:
    QString toString(){return QString();}
};

class Package : public protbuf::Package , public protocol::Message
{
public:
    Package();

    protbuf::PackageBasicInformation getPackageBasicInformation();


    QString getName() const { return QString::fromStdString(name());}
    QString getMountType()const { return QString::fromStdString(mounttype());}
    PackageConfig& config() {return m_config;}

private:
    PackageConfig m_config;

    // Message interface
public:
    MsgType type() const
    {
        return MsgType::msgPackage;
    }
    int ByteSize() const
    {
        return protbuf::Package::ByteSize();
    }

protected:
    bool SerializeToArray(void *data, int size) const
    {
        return protbuf::Package::SerializeToArray(data,size);
    }
    bool ParseFromArray(const void *data, int size)
    {
        return protbuf::Package::ParseFromArray(data,size);
    }
};

#endif // PACKAGE_H
