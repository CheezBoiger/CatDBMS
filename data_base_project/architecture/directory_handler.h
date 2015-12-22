#ifndef _DIRECTORY_HANDLER_H_
#define _DIRECTORY_HANDLER_H_
#pragma once

#include "catdb_arch.h"

#if defined(_DB_CAT_WINDOWS)
<<<<<<< HEAD

 #define create_folder(filename, mode) CreateDirectory(filename, mode);
=======
/* macro intended to use a filename and mode. Be sure to document this. */
#define create_folder(filename, mode) CreateDirectory(filename, mode);
>>>>>>> f7cf62d0cc198af92d9494179a6d6ab537854e1d

#elif defined(_DB_CAT_LINUX) || defined(_DB_CAT_UNIX)

<<<<<<< HEAD
 #define create_folder(filename, mode) mkdir(filename, mode);
=======
#define create_folder(filename, mode) mkdir(filename, mode);
>>>>>>> f7cf62d0cc198af92d9494179a6d6ab537854e1d

#endif /* _DB_CAT_WINDOWS */

#endif /* _DIRECTORY_HANDLER_H_ */
