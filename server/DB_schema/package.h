#ifndef PACKAGE_H
#define PACKAGE_H

#include "package.pb.h"

class Package : public package::Package
{
public:
    Package();

    package::Package getPBPackage();
};

#endif // PACKAGE_H
