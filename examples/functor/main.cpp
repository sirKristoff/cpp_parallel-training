#include <iostream>
#include <stdlib.h>
#include "threading/mutex.h"
#include "threading/condition_variable.h"
#include "threading/thread.h"

using namespace std;

class hello: public threading::function {
public:
	void operator()() {
		cout << "hello world" << endl;
	}
};

int main(int argc, const char *argv[])
{
	hello h;
	threading::thread th(h);
	th.join();
	return 0;
}

