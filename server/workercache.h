#pragma once

/**
 * @brief The WorkerCache class contains data that can be reached by
 * all message handlers
 */

#include "messages/user.h"

class WorkerCache
{
public:
    WorkerCache();

    User userData;
};

