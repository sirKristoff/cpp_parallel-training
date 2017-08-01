#include <iostream>
#include <vector>
#include <list>
#include <memory>

#include <stdlib.h>
#include <time.h>

#include "threading/mutex.h"
#include "threading/condition_variable.h"
#include "threading/thread.h"

using namespace std;
typedef shared_ptr<threading::thread> thread_ptr;
typedef vector<thread_ptr> threads;

class queue {
	bool run_;
	list<int> q_;
	threading::mutex mtx_;
	threading::condition_variable cond_;
public:
	queue(): run_(true) {}
	void push(int i) {
		threading::mutex::lock l(mtx_);
		q_.push_back(i);
		cond_.signal();
	}
	bool pop(int &i) {
		bool res = true;
		threading::mutex::lock l(mtx_);
		while (run_ && q_.empty())
			cond_.wait(mtx_);
		if (!q_.empty()) {
		//if (run_) {
			i = q_.front();
			q_.pop_front();
		}
		else {
			res = false;
		}
		return res;
	}
	void stop() {
		threading::mutex::lock l(mtx_);
		run_ = false;
		cond_.broadcast();
	}
};

queue Q;
threading::mutex IO_MTX;

void consumer();

int main(int argc, const char *argv[])
{
	if (argc != 3) {
		cout << "invalid argument count" << endl;
		return 1;
	}

	const int m = atoi(argv[1]);
	const int n = atoi(argv[2]);

	srand(time(0));

	threads ths;
	for (int i = 0; i < n; ++i) {
		ths.push_back(thread_ptr(new threading::thread(consumer)));
	}

	time_t begin_time = time(0);
	time_t now = 0;
	do {
		int i = rand() % 1000 + 1;
		Q.push(i);
		now = time(0);
	} while ((now - begin_time) < m);

	Q.stop();

	for (auto i = ths.begin(); i != ths.end(); ++i) {
		(*i)->join();
	}

	return 0;
}

void consumer()
{
	bool run = true;
	do {
		int i;
		run = Q.pop(i);
		if (run) {
			//threading::mutex::lock l(IO_MTX);
			cout << i << endl;
		}
	} while (run);
}

