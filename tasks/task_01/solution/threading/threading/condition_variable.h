namespace threading {
	class mutex;
	struct condition_variable_pimpl;

	class condition_variable {
		condition_variable_pimpl *pimpl_;
		condition_variable(const condition_variable&);
		condition_variable& operator=(const condition_variable&);
	public:
		condition_variable();
		virtual ~condition_variable();
		void wait(mutex &);
		bool timed_wait(mutex &, int);
		void signal();
		void broadcast();
	};
}

