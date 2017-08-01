
namespace threading {
	typedef void (*thread_function)(void);
	class thread {
		void* tid;
		static void* th_f(void *f);
		thread(const thread&);
		thread& operator=(const thread&);
	public:
		thread(thread_function);
		~thread();
		void join();
	};
};
