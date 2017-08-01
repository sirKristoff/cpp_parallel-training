#include <vector>
#include <thread>

using namespace std;

vector<int> v;

void prod() {
	while (1) {
		v.push_back(1);
	}
}

void cons() {
	while (1) {
		if (!v.empty()) {
			int i = v.back();
			v.pop_back();
		}
	}
}

int main(int argc, const char *argv[])
{
	thread p1(prod);
	thread c1(cons);
	thread c2(cons);
	thread c3(cons);

	p1.join();

	return 0;
}
