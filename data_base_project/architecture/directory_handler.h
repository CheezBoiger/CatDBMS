#ifndef _DIRECTORY_HANDLER_H_
#define _DIRECTORY_HANDLER_H_
#pragma once

#include "architecture/catdb_arch.h"

#if defined(_DB_CAT_WINDOWS)
/* macro intended to use a filename and mode. Be sure to document this. */
 #define create_folder(path, mode) CreateDirectory(path, mode);
 #define _ERR_ DWORD
 #define _BOOL_ BOOL
#define _OBTAIN_LAST_ERROR GetLastError()
#elif defined(_DB_CAT_LINUX) || defined(_DB_CAT_UNIX)
 #define create_folder(filename, mode) mkdir(filename, mode);
 #define _ERR_ 
 #define _BOOL_ int
 #define _OBTAIN_LAST_ERROR
#endif /* _DB_CAT_WINDOWS */

#endif /* _DIRECTORY_HANDLER_H_ */
