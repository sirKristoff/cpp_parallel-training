#include "mutex.h"
#include <pthread.h>

namespace threading {
	struct mutex_pimpl {
		mutex_pimpl()
		{
			pthread_mutex_init(&mtx_, 0);
		}
		~mutex_pimpl()
		{
			pthread_mutex_destroy(&mtx_);
		}
		pthread_mutex_t mtx_;
	};
}

using namespace threading;

mutex::mutex(): pimpl_(new mutex_pimpl())
{
}

mutex::~mutex()
{
	delete pimpl_;
}

void* mutex::native()
{
	return &pimpl_->mtx_;
}

mutex::lock::lock(mutex& m): m_(m)
{
	pthread_mutex_lock(&m_.pimpl_->mtx_);
}

mutex::lock::~lock()
{
	pthread_mutex_unlock(&m_.pimpl_->mtx_);
}

