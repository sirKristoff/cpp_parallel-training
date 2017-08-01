
namespace threading {
	class function {
	public:
		virtual void operator()() = 0;
	};
	class thread {
		void* tid;
		static void* th_f(void *f);
		thread(const thread&);
		thread& operator=(const thread&);
	public:
		thread(function &);
		~thread();
		void join();
	};
};
