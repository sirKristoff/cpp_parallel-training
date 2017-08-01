#include <functional>

namespace threading {
//	typedef void (*thread_function)(void);
	typedef std::function<void(void)> thread_function;
	class thread {
		void* tid;
		static void* th_f(void *f);
		thread(const thread&);
		thread& operator=(const thread&);
	public:
		explicit thread(const thread_function&);
		~thread();
		void join();
	};
};
