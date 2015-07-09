/**
 * ModSecurity, http://www.modsecurity.org/
 * Copyright (c) 2015 Trustwave Holdings, Inc. (http://www.trustwave.com/)
 *
 * You may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * If any of the files related to licensing are missing or if you have any
 * other questions related to licensing please contact Trustwave Holdings, Inc.
 * directly using the email address security@modsecurity.org.
 *
 */

#include <ctime>
#include <iostream>

#include "modsecurity/modsecurity.h"
#include "src/config.h"
#include "src/unique_id.h"


namespace ModSecurity {

/**
 * @name    ModSecurity
 * @brief   Initilizes ModSecurity CPP API
 *
 * ModSecurity initializer.
 *
 * Example Usage:
 * @code
 *
 * using ModSecurity::ModSecurity;
 *
 * ModSecurity *msc = new ModSecurity();
 *
 * @endcode
 */
ModSecurity::ModSecurity() {
    UniqueId::uniqueId();
    srand(time(NULL));
}


/**
 * @name    whoAmI
 * @brief   Return information about this ModSecurity version and platform.
 *
 * Platform and version are two questions that community will ask prior to
 * provide support. Making it available internally and to the connector as
 * well.
 *
 * @note This information maybe will be used by a log parser. If you want to
 *       update it, make it in a fashion that won't break the existent parsers.
 *       (e.g. adding extra information _only_ to the end of the string)
 */
std::string ModSecurity::whoAmI() {
    std::string platform("Unknown platform");

#if AIX
    platform = "AIX";
#elif LINUX
    platform = "Linux";
#elif OPENBSD
    platform = "OpenBSD";
#elif SOLARIS
    platform = "Solaris";
#elif HPUX
    platform = "HPUX";
#elif MACOSX
    platform = "MacOSX";
#elif FREEBSD
    platform = "FreeBSD";
#elif NETBSD
    platform = "NetBSD";
#elif WIN32
    platform = "Windows";
#endif

    return std::string("ModSecurity v" MODSECURITY_VERSION \
        " (" + platform + ")");
}


/**
 * @name    msc_who_am_i
 * @brief   Return information about this ModSecurity version and platform.
 *
 * Platform and version are two questions that community will ask prior to
 * provide support. Making it available internally and to the connector as
 * well.
 *
 * @note This information maybe will be used by a log parser. If you want to
 *       update it, make it in a fashion that won't break the existent parsers.
 *       (e.g. adding extra information _only_ to the end of the string)
 */
extern "C" const char *msc_who_am_i(ModSecurity *msc) {
    return msc->whoAmI().c_str();
}


/**
 * @name    msc_init
 * @brief   Initilizes ModSecurity C API
 *
 * ModSecurity initializer.
 *
 * Example Usage:
 * @code
 *
 * ModSecurity msc = msc_init();
 *
 * @endcode
 */
extern "C" ModSecurity *msc_init() {
    ModSecurity *modsec = new ModSecurity();

    return modsec;
}

}  // namespace ModSecurity
