#include "package.h"

Package::Package()
{
}

package::PackageBasicInformation Package::getPackageBasicInformation()
{
    package::PackageBasicInformation pbi;
    pbi.set_id(id());
    return pbi;
}
