#include<gtest/gtest.h>
#include<gmock/gmock.h>
#include<iostream>

#include "vector.h"

TEST(VectorLibCompare, VectorsWithSameValuesComparisonWithEqualToOperator) {

  // Use uniform intialisation
  Vector vector1 {1.0f, 2.4f};
  Vector vector2 {1.0f, 2.4f};

  EXPECT_TRUE(vector1 == vector2);
}

TEST(VectorLibCompare, VectorsWithDifferenValuesComparisonWithEqualToOperator) {

  // Use uniform intialisation
  Vector vector1 {1.0f, 2.4f};
  Vector vector3 {2.0f, 2.4f};

  EXPECT_FALSE(vector1 == vector3);
}

TEST(VectorLibCompare, VectorsWithSameValuesComparisonWithNotEqualToOperator) {

  // Use uniform intialisation
  Vector vector1 {1.0f, 2.4f};
  Vector vector2 {1.0f, 2.4f};

  EXPECT_FALSE(vector1 != vector2);
}

TEST(VectorLibCompare, VectorsWithDiffernetValuesComparisonWithNotEqualToOperator) {

  // Use uniform intialisation
  Vector vector1 {1.0f, 2.4f};
  Vector vector2 {5.3f, 2.4f};

  EXPECT_TRUE(vector1 != vector2);
}