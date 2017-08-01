#include "ToTest.h"
#include "IDependency.h"

ToTest::ToTest(IDependency* d): d(d) {}

ToTest::~ToTest() {}

int ToTest::foo(int a) {
  if (a == 0) {
    int b = 0;
    d->bar(a, b, 0);
    return b;
  } else {
    int b;
    int c;
    return d->bar(a, b, &c);
  }
}
