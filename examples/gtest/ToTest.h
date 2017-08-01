class IDependency;

class ToTest {
  IDependency* d;
public:
  ToTest(IDependency* d);
  ~ToTest();
  int foo(int a);
};
