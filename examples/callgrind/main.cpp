#include <iostream>

using namespace std;

void bar()
{
	static char c = 'a';
	cout << c++ << endl;
}

void foo()
{
	for (int i = 0; i < 10000; ++i)
		bar();
}

int main(int c, char** v) {
	foo();
	return 0;
}

