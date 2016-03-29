#include <architecture/threading/mutex.h>

#ifdef _DB_CAT_WINDOWS
void mutex_create(mutex_t* mutex) {
   *mutex = CreateMutex(NULL, FALSE, NULL);      
}

void mutex_lock(mutex_t* mutex) {
   WaitForSingleObject(*mutex, INFINITE);
}

void mutex_unlock(mutex_t* mutex) {
   ReleaseMutex(*mutex);
}

void mutex_destroy(mutex_t* mutex) { 
   CloseHandle(*mutex);
}
#elif defined(_DB_CAT_LINUX || _DB_CAT_UNIX)

#endif // _DB_CAT_WINDOWS