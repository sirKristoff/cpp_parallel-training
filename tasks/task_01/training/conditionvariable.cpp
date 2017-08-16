/*
 * conditionvariable.cpp
 *
 *  Created on: Jul 27, 2017
 *      Author: ekrzlas
 */

#include "conditionvariable.h"
#include "mutex.h"
#include "mutexctx.h"

#include <pthread.h>


namespace thd {

struct condition_variable_ctx
{
	pthread_cond_t cond_;
	condition_variable_ctx() : cond_(PTHREAD_COND_INITIALIZER)
	{
//		int pthread_cond_init(pthread_cond_t *restrict cond,
//		                      const pthread_condattr_t *restrict attr);

	}
	~condition_variable_ctx()
	{
//		int pthread_cond_destroy(pthread_cond_t *cond);
	}
};



condition_variable::condition_variable() : ctx(new condition_variable_ctx())
{
}

condition_variable::~condition_variable()
{
	delete ctx;
}

void condition_variable::notify_one()
{
//	int pthread_cond_signal(pthread_cond_t *cond);
	pthread_cond_signal(&(ctx->cond_));
}

void condition_variable::notify_all()
{
//	int pthread_cond_broadcast(pthread_cond_t *cond);
	pthread_cond_broadcast(&(ctx->cond_));
}

void condition_variable::wait( thd::mutex& m )
{
//	int pthread_cond_wait(pthread_cond_t *cond, pthread_mutex_t *mutex);
	pthread_cond_wait( &(ctx->cond_), &(m.ctx->mutex_));
}

} /* namespace thd */
