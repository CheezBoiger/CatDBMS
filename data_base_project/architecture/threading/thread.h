/*

 Thread handling header.

 */
#ifndef _THREAD_H_
#define _THREAD_H_
#pragma once

#include "architecture/catdb_arch.h"

#ifdef _DB_CAT_WINDOWS

typedef HANDLE thread_t;
typedef DWORD worss;
#elif defined(_DB_CAT_UNIX)


#elif defined(_DB_CAT_LINUX)

#endif /* _DB_CAT_WINDOWS */

// routine start function pointer.
typedef void* (*start_routine) (void*);
typedef void (*call_funct) (void*);

void create_thread(thread_t* thread, start_routine s_routine, void* arg);
void begin_thread(thread_t* thread, call_funct call, void* arg);

#endif /* _THREAD_H_ */
