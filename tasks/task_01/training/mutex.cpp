/*
 * mutex.cpp
 *
 *  Created on: Jul 27, 2017
 *      Author: ekrzlas
 */

#include "mutex.h"
#include <pthread.h>
#include "mutexctx.h"


namespace thd {

mutex::mutex() : ctx(new mutex_ctx())
{
}

mutex::~mutex()
{
	delete ctx;
}


void mutex::lock()
{
	pthread_mutex_lock(&(ctx->mutex_));
}
void mutex::unlock()
{
	pthread_mutex_unlock(&(ctx->mutex_));
}

} /* namespace threads */
