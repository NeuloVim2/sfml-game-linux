#include<gtest/gtest.h>
#include<gmock/gmock.h>

#include ""

TEST(Test, shouldWorkByDefault) {
  // Expect two strings not to be equal.
  EXPECT_THAT(2 + 2, testing::Eq(3));
  // EXPECT_STREQ("some", "value");
}