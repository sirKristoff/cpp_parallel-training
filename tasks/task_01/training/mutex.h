/*
 * mutex.hpp
 *
 *  Created on: Jul 27, 2017
 *      Author: ekrzlas
 */

#ifndef MUTEX_H_
#define MUTEX_H_

namespace thd {

class condition_variable;
struct mutex_ctx;

class mutex
{
	friend class condition_variable;
	mutex_ctx* ctx;
public:
	mutex();
    mutex(const mutex&) = delete;
    mutex& operator=(const mutex&) = delete;
	~mutex();

	void lock();
	void unlock();
};

} /* namespace thd */

#endif /* MUTEX_H_ */
