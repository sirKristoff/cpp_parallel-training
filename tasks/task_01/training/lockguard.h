/*
 * lockguard.h
 *
 *  Created on: Jul 27, 2017
 *      Author: ekrzlas
 */

#ifndef LOCKGUARD_H_
#define LOCKGUARD_H_

namespace thd {

class mutex;

class lock_guard {
	mutex& mutex_;
public:
	lock_guard( mutex& m );
	~lock_guard();
};

} /* namespace thd */

#endif /* LOCKGUARD_H_ */
