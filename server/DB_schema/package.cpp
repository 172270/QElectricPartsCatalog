#include "package.h"

Package::Package()
{
}

package::Package Package::getPBPackage()
{
    return static_cast<package::Package>(*this);
}
