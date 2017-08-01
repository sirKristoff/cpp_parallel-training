namespace threading {
	class condition_variable;
	struct mutex_pimpl;

	class mutex {
		mutex_pimpl* pimpl_;
		void *native();
		mutex(const mutex&);
		mutex& operator=(const mutex&);
	public:
		class lock {
			mutex& m_;
		public:
			lock(mutex &);
			~lock();
		};
		friend lock;
		friend condition_variable;
		mutex();
		~mutex();
	};
}

