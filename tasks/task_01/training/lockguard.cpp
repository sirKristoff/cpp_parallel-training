/*
 * lockguard.cpp
 *
 *  Created on: Jul 27, 2017
 *      Author: ekrzlas
 */

#include "lockguard.h"
#include "mutex.h"

namespace thd {

lock_guard::lock_guard( mutex& m ) : mutex_(m)
{
	mutex_.lock();
}

lock_guard::~lock_guard()
{
	mutex_.unlock();
}

} /* namespace thd */
