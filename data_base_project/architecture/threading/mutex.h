#ifndef _MUTEX_H_
#define _MUTEX_H_
#pragma once

#include <architecture/catdb_arch.h>

#if defined(_DB_CAT_WINDOWS)
 typedef HANDLE mutex_t;
#elif defined(_DB_CAT_LINUX || _DB_CAT_UNIX)
 typedef pthread_mutex_t mutex_t;
#endif // _DB_CAT_WINDOWS

void mutex_create(mutex_t* mutex);

void mutex_lock(mutex_t* mutex);

void mutex_unlock(mutex_t* mutex);

void mutex_destroy(mutex_t* mutex);

#endif // _MUTEX_H_
