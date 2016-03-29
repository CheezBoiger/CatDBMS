#include <architecture/threading/thread.h>
#include <process.h>

// Start the thread routine
void create_thread(thread_t* thread, start_routine s_routine, void* arg) { 
   *thread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)s_routine, arg, 0, NULL);
}

void begin_thread(thread_t* thread, call_funct call, void* args) { 
   *thread = (HANDLE)_beginthread(call, 0, 0);
}