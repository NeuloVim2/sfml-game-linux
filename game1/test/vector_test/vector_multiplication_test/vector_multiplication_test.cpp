#include<gtest/gtest.h>
#include<gmock/gmock.h>
#include<iostream>

#include "vector.h"

TEST(VectorLibMultiplication, MultiplyVectorByScalar) {

  // Use uniform intialisation
  Vector vector {1.0f, 2.4f};
  float scalar = 3.3f;

  Vector result = vector * scalar;

  // Expect two strings not to be equal.
  EXPECT_THAT(result.x, testing::FloatEq(3.3f));
  EXPECT_THAT(result.y, testing::FloatEq(7.92f));
}