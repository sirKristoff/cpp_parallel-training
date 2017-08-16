/*
 * thread.cpp
 *
 *  Created on: Jul 27, 2017
 *      Author: ekrzlas
 */

#include "thread.h"

#include <pthread.h>


namespace thd {

struct thread_ctx
{
	pthread_t thread_;
	int arg_;
};
//void *(*start_routine) (void *)
//typedef  void (*ThreadFunction) (int);
thread::thread( ThreadFunction fun, int arg ) : ctx(new thread_ctx())
{
	// int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
    //                    void *(*start_routine) (void *), void *arg);
	ctx->arg_ = arg;
	pthread_create( &(ctx->thread_), NULL, fun, &(ctx->arg_));
}

thread::~thread()
{
	delete ctx;
}


void thread::join()
{
	// int pthread_join(pthread_t thread, void **retval);
	pthread_join(ctx->thread_, NULL);
}

} /* namespace thd */
