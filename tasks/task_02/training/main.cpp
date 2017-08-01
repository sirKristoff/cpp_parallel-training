#include <iostream>
#include <stdlib.h>
#include <vector>
#include "threading/mutex.h"
#include "threading/condition_variable.h"
#include "threading/thread.h"

using namespace std;


const unsigned nThread= 2;
const clock_t nSecGeneration= 1*CLOCKS_PER_SEC;
const unsigned kMaxLogLen= 5;
typedef int Task;

#include <queue>

// for producer
#include <ctime>
#include <cstdlib>



int main(int argc, const char *argv[])
{
	std::queue<Task> q;
	threading::thread* thProducer;
	vector<threading::thread*> poolWorker;

	// utworz pule nThread watkow workerow i startuj
	for( unsigned i= 0 ; i<nThread ; ++i )
	{
		auto funWorker = [&q, i](void) -> void {
			Task t;
			while( q.size() != 0 ) {
				if(  )
				q.front();
				q.pop();
			}
			cout << i << ": " << t << endl;
		};
		// dodaj jednego workera
		poolWorker.push_back(new threading::thread(funWorker));
	}

	// wystartuj generator taksow na nSecGeneration z konczocymi taskami dla nThread
	auto funProducer = [&q](void) -> void {
		clock_t begin = clock();
		while( (clock() - begin) < nSecGeneration ){
			q.push( Task(rand()%kMaxLogLen) );
		}
		return;
	};
	thProducer = new threading::thread( funProducer );


	// zaczekaj az watek producenta sie zakonczy
	thProducer->join();
	delete thProducer;

	// zaczekaj az wszystkie watki sie zakoncza
	for( auto thWorker : poolWorker ){
		thWorker->join();
		delete thWorker;
	}

	cout << "queue.size() : " << q.size() << endl;

	return 0;
}



