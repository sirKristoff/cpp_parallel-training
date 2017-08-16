/*
 * mutex_ctx.h
 *
 *  Created on: Jul 27, 2017
 *      Author: ekrzlas
 */

#ifndef MUTEXCTX_H_
#define MUTEXCTX_H_

#include <pthread.h>


namespace thd {

struct mutex_ctx
{
	pthread_mutex_t mutex_;

	mutex_ctx(): mutex_(PTHREAD_MUTEX_INITIALIZER)
	{
//		pthread_mutex_init(&mutex_, NULL);
	}
	~mutex_ctx()
	{
//		pthread_mutex_destroy(&mutex_);
	}

};

} /* namespace threads */


#endif /* MUTEXCTX_H_ */
