#include "package.h"

Package::Package()
{
    set_id(0);
}

protbuf::PackageBasicInformation Package::getPackageBasicInformation()
{
    protbuf::PackageBasicInformation pbi;
    pbi.set_id(id());
    return pbi;
}
