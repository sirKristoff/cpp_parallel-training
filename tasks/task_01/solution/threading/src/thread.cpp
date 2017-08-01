#include <pthread.h>
#include <stdexcept>
#include "thread.h"

using namespace threading;

thread::thread(thread_function tf)
	: tid(new pthread_t(0))
{
	if (pthread_create((pthread_t*)tid, 0, th_f, (void*)tf) != 0) {
		throw std::runtime_error("cannot spawn thread");
	}
}

thread::~thread()
{
	delete (pthread_t*)tid;
}

void thread::join()
{
	if (*((pthread_t*)tid))
		pthread_join(*((pthread_t*)tid), 0);
}

void* thread::th_f(void *f)
{
	thread_function tf = (thread_function) f;
	tf();
	return 0;
}

