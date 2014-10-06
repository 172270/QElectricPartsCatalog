#ifndef PACKAGE_H
#define PACKAGE_H

#include "package.pb.h"

class Package : public package::Package
{
public:
    Package();

    package::PackageBasicInformation getPackageBasicInformation();
};

#endif // PACKAGE_H
