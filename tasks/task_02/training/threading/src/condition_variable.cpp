#include "condition_variable.h"
#include "mutex.h"
#include <pthread.h>
#include <time.h>

namespace threading {
	struct condition_variable_pimpl {
		condition_variable_pimpl()
		{
			pthread_cond_init(&cond_, 0);
		}
		~condition_variable_pimpl()
		{
			pthread_cond_destroy(&cond_);
		}
		pthread_cond_t cond_;
	};
}

using namespace threading;

condition_variable::condition_variable()
	: pimpl_(new condition_variable_pimpl())
{
}

condition_variable::~condition_variable()
{
	delete pimpl_;
}

void condition_variable::wait(mutex &mtx)
{
	pthread_cond_wait(&pimpl_->cond_, (pthread_mutex_t*)mtx.native());
}

bool condition_variable::timed_wait(mutex &mtx, int t)
{
	timespec ts;
	clock_gettime(CLOCK_REALTIME, &ts);
	ts.tv_sec += t;

	return pthread_cond_timedwait(&pimpl_->cond_, (pthread_mutex_t*)mtx.native(), &ts) == 0 ? true : false;
}

void condition_variable::signal()
{
	pthread_cond_signal(&pimpl_->cond_);
}

void condition_variable::broadcast()
{
	pthread_cond_broadcast(&pimpl_->cond_);
}

