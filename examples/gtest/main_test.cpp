#include "ToTest.h"
#include "Mock.h"
#include <gtest/gtest.h>

TEST(ToTestTest, TC_01) {
  Mock m;
  ToTest tt(&m);
  int b;
  int* c = 0;
  EXPECT_CALL(m, bar(0, ::testing::_, 0)\
      ).WillOnce(::testing::DoAll(::testing::SetArgReferee<1>(7)
                ,::testing::SaveArg<2>(&c),::testing::Return(0)));
  ASSERT_TRUE(c == 0);
  ASSERT_EQ(tt.foo(0), 7);
}

TEST(ToTestTest, TC_02) {
  Mock m;
  ToTest tt(&m);
  
  EXPECT_CALL(m, bar(1, ::testing::_, ::testing::Ne((int*)0))).WillOnce(::testing::Return(2));
  ASSERT_EQ(tt.foo(1), 2);
}

int main( int argc, char *argv[] ) {
    ::testing::InitGoogleMock( &argc, argv );
    return RUN_ALL_TESTS( );
}
