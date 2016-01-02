#ifndef _DIRECTORY_HANDLER_H_
#define _DIRECTORY_HANDLER_H_
#pragma once

#include "architecture/catdb_arch.h"

#if defined(_DB_CAT_WINDOWS)
/* macro intended to use a filename and mode. Be sure to document this. */
 #define create_folder(path, mode) CreateDirectory(path, mode);
 #define create_file(path, share_mode) CreateFile(path, GENERIC_READ | GENERIC_WRITE, share_mode, \
										NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL) 
#elif defined(_DB_CAT_LINUX) || defined(_DB_CAT_UNIX)
 #define create_folder(filename, mode) mkdir(filename, mode);
 #define create_file(path, share_mode) open(path, O_RDWR | O_CREAT, share_mode)
#endif /* _DB_CAT_WINDOWS */

#endif /* _DIRECTORY_HANDLER_H_ */
