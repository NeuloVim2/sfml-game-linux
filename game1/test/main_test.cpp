#include<gtest/gtest.h>
#include<gmock/gmock.h>

TEST(GoogleTestShouldWork, Main) {
  // Expect two strings not to be equal.
  EXPECT_THAT(2 + 2, testing::Eq(4));
}