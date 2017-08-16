/*
 * conditionvariable.h
 *
 *  Created on: Jul 27, 2017
 *      Author: ekrzlas
 */

#ifndef CONDITIONVARIABLE_H_
#define CONDITIONVARIABLE_H_

namespace thd {

class mutex;
struct condition_variable_ctx;

class condition_variable {
	condition_variable_ctx* ctx;
public:
	condition_variable();
	condition_variable(const condition_variable&) = delete;
	condition_variable& operator=(const condition_variable&) = delete;
	~condition_variable();

	void notify_one();
	void notify_all();
	void wait( thd::mutex& m );

};

} /* namespace thd */

#endif /* CONDITIONVARIABLE_H_ */
