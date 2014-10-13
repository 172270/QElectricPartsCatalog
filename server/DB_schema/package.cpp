#include "package.h"

Package::Package()
{
    set_id(0);
}

package::PackageBasicInformation Package::getPackageBasicInformation()
{
    package::PackageBasicInformation pbi;
    pbi.set_id(id());
    return pbi;
}
