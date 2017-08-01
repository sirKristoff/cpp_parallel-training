#include "IDependency.h"
#include <gmock/gmock.h>

class Mock: public IDependency {
public:
  MOCK_METHOD3(bar, int(int a, int& b, int* c));
};
