#ifndef _CATDB_ARCH_H_
#define _CATDB_ARCH_H_

#pragma once

#include "internal/os_arch.h"
#include "architecture/internal/cattypes.h"
#ifndef __cplusplus
 #error C++ compiler required!
#endif /* __cplusplus*/

#ifdef _DB_CAT_WINDOWS
 #include <Windows.h>
 #include <stdio.h>
 #pragma comment(lib, "user32.lib")
 #pragma comment(lib, "ws2_32.lib")
 
 #define _INLINE_  __forceinline
 #define _CDECL_   __cdecl 
#elif defined(_DB_CAT_UNIX)
 #include <pthread.h>  
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <unistd.h>
 #include <fcntl.h>

 #define _INLINE_ inline
 #define _CDECL_ __cdecl
#elif defined(_DB_CAT_LINUX)
 #define _INLINE_ __always_inline
 #define _CDECL_ __cdecl
#else
 #error incompatibility with other compilers!!
#endif /* _DB_CAT_WINDOWS */

#endif /* _CAT_ARCH_H_ */
