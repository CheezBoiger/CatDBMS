#ifndef _CATDB_ARCH_H_
#define _CATDB_ARCH_H_

#pragma once

#include "internal/os_arch.h"

#ifndef __cplusplus
 #error C++ compiler required!
#endif /* __cplusplus*/

#ifdef _DB_CAT_WINDOWS
 #include <Windows.h>
 #define _INLINE_  __forceinline
 #define _CDECL_   __cdecl 
#elif defined(_DB_CAT_UNIX)
 #define _INLINE_ inline
 #define _CDECL_
#elif defined(_DB_CAT_LINUX)
 #define _INLINE_ __always_inline
 #define _CDECL_ 
#else
 #error incompatibility with other compilers!!
#endif /* _DB_CAT_WINDOWS */

#endif /* _CAT_ARCH_H_ */
