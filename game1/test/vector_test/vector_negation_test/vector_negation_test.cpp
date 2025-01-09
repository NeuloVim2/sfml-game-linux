#include<gtest/gtest.h>
#include<gmock/gmock.h>
#include<iostream>

#include "vector.h"

TEST(VectorLibCompare, NegateVectorWithPositiveComponents) {

  // Use uniform intialisation
  Vector v = {2.3f, 4.1f};
  Vector result = -v;

  EXPECT_THAT(result.x, testing::FloatEq(-2.3f));
  EXPECT_THAT(result.y, testing::FloatEq(-4.1));
}