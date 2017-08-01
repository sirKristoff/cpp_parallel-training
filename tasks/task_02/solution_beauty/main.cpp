#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <list>
#include <vector>
#include <memory>

using namespace std;
template <typename T>
class queue {
	list<T> q_;
	mutex mtx_;
	condition_variable cond_;
	queue(const queue&);
	queue& operator=(const queue&);
public:
	queue() {}
	void push_back(const T& e) {
		unique_lock<mutex> l(mtx_);
		q_.push_back(e);
		cond_.notify_one();
	}

	void push_front(const T& e) {
		unique_lock<mutex> l(mtx_);
		q_.push_front(e);
		cond_.notify_one();
	}

	T pop() {
		T res;
		unique_lock<mutex> l(mtx_);
		while (q_.empty()) cond_.wait(l);
		res = q_.front();
		q_.pop_front();
		return res;
	}
};

typedef queue<pair<bool, int> > int_queue;

class consument {
	int_queue& q_;
public:
	typedef shared_ptr<consument> ptr;
	consument(int_queue& q): q_(q) {}
	void operator()() {
		while (1) {
			auto e = q_.pop();
			if (e.first) {
				cout << e.second << endl;
			}
			else {
				break;
			}
		}
	}
};

int main (int c, char** v) {
	size_t n = atoi(v[1]);
	size_t m = atoi(v[2]);

	int_queue q;
	vector<consument::ptr> cs;
	vector<shared_ptr<thread> > ths;
	for (size_t i = 0; i < n; ++i) {
		consument::ptr c(new consument(q));
		cs.push_back(c);
		ths.push_back(shared_ptr<thread>(new thread(std::ref(*c))));
	}

	time_t begin = time(0);
	srand(begin);
	do {
		int i = rand() % 1000 + 1;
		q.push_back(pair<bool, int>(true, i));
	} while ((time(0) - begin) < m);

	for (size_t i = 0; i < n; ++i) {
		//q.push_back(pair<bool, int>(false, 0));
		q.push_front(pair<bool, int>(false, 0));
	}

	for (auto i = ths.begin(); i != ths.end(); ++i) {
		(*i)->join();
	}

	return 0;
}

