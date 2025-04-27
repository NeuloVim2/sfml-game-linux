#include<gtest/gtest.h>
#include<gmock/gmock.h>
#include<iostream>

#include "Vector2f.h"

TEST(VectorLibCompare, NegateVectorWithPositiveComponents) {

  // Use uniform intialisation
  Vector2f v = {2.3f, 4.1f};
  Vector2f result = -v;

  EXPECT_THAT(result.x, testing::FloatEq(-2.3f));
  EXPECT_THAT(result.y, testing::FloatEq(-4.1));
}