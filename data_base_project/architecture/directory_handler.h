#ifndef _DIRECTORY_HANDLER_H_
#define _DIRECTORY_HANDLER_H_
#pragma once

#include "catdb_arch.h"

#if defined(_DB_CAT_WINDOWS)
/* macro intended to use a filename and mode. Be sure to document this. */
#define create_folder(filename, mode) CreateDirectory(filename, mode);

#elif defined(_DB_CAT_LINUX)

#define create_folder(filename, mode) mkdir(filename, mode);

#endif /* _DB_CAT_WINDOWS */

#endif /* _DIRECTORY_HANDLER_H_ */
