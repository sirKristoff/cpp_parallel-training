#include <iostream>
#include <stdlib.h>
#include "threading/mutex.h"
#include "threading/condition_variable.h"
#include "threading/thread.h"

using namespace std;

int CNT = 0;
bool IS_PING = true;
threading::mutex MTX;
threading::condition_variable COND;

void ping();
void pong();

int main(int argc, const char *argv[])
{
	if (argc != 2) {
		cout << "invalid argument count" << endl;
		return 1;
	}

	CNT = atoi(argv[1]);

	threading::thread th_ping(ping);
	threading::thread th_pong(pong);
	th_ping.join();
	th_pong.join();
	return 0;
}

void ping()
{
	for (int i = 0; i < CNT;) {
		threading::mutex::lock l(MTX);
		if (!IS_PING) {
			COND.wait(MTX);
		}
		else {
			cout << "ping" << endl;
			IS_PING = !IS_PING;
			COND.signal();
			++i;
		}
	}
}

void pong()
{
	for (int i = 0; i < CNT; ++i) {
		threading::mutex::lock l(MTX);
		while (IS_PING) {
			COND.wait(MTX);
		}
		cout << "\tpong" << endl;
		IS_PING = !IS_PING;
		COND.signal();
	}
}
