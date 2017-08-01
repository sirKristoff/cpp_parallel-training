#include <thread>
#include <mutex>
#include <iostream>

using namespace std;

mutex m1;
mutex m2;

void f0();
void f2();
void f3();
void f4();

void th1() {
	while (1) {
		f0();
	}
}

void th2() {
	while (1) {
		f3();
	}
}

int main(int argc, const char *argv[])
{
	thread t1(th1);
	thread t2(th2);
	t1.join();
	return 0;
}

void f0() {
	unique_lock<mutex> l(m1);
	f2();
}

void f2() {
	unique_lock<mutex> l(m2);
	cout << "f2" << endl;
}

void f3() {
	unique_lock<mutex> l(m2);
	f4();
}

void f4() {
	unique_lock<mutex> l(m1);
	cout << "f4" << endl;
}

