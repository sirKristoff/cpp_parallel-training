/*
 * thread.h
 *
 *  Created on: Jul 27, 2017
 *      Author: ekrzlas
 */

#ifndef THREAD_H_
#define THREAD_H_

namespace thd {

typedef  void* (*ThreadFunction) (void*);

struct thread_ctx;

class thread
{
	thread_ctx* ctx;
public:
	thread( ThreadFunction fun, int arg );
	thread(const thread&) = delete;
	thread& operator=(const thread&) = delete;
	virtual ~thread();

	void join();
};

} /* namespace thd */

#endif /* THREAD_H_ */
