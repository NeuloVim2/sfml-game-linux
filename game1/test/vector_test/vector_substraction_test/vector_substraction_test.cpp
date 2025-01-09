#include<gtest/gtest.h>
#include<gmock/gmock.h>
#include<iostream>

#include "vector.h"

TEST(VectorLibSubstraction, SubstractTwoVectorsWithUseOfMinusSign) {

  // Use uniform intialisation
  Vector leftOperand {1.0f, 2.0f};
  Vector rightOperand {1.0f, 2.0f};

  Vector result = leftOperand - rightOperand;

  // Expect two strings not to be equal.
  EXPECT_THAT(result.x, testing::Eq(0.0f));
  EXPECT_THAT(result.y, testing::Eq(0.0f));
}

TEST(VectorLibSubstraction, SubstractScalarFromVectorWithUseOfMinusSign) {

  // Use uniform intialisation
  Vector vector {4.0f, 2.0f};
  float scalar = 2.0f;

  Vector result = vector - scalar;

  // Expect two strings not to be equal.
  EXPECT_THAT(result.x, testing::Eq(2.0f));
  EXPECT_THAT(result.y, testing::Eq(0.0f));
}

TEST(VectorLibSubstraction, SubstractOneVectorFromAnotherWithUseOfMethod) {

  // Use uniform intialisation
  Vector vectorA {5.0f, 8.3f};
  Vector vectorB {5.0f, 8.3f};
  Vector vectorC {2.0f, 2.2f};
  Vector vectorD {3.0f, 8.1f};

  Vector result1 = vectorA.substract(vectorC);

  // Expect two strings not to be equal.
  EXPECT_THAT(result1.x, testing::FloatEq(3.0f));
  EXPECT_THAT(result1.y, testing::FloatEq(6.1f));

  Vector result2 = vectorB.substract(vectorD);

  // Expect two strings not to be equal.
  EXPECT_THAT(result2.x, testing::FloatEq(2.0f));
  EXPECT_THAT(result2.y, testing::FloatNear(0.2f, 0.001));
}

TEST(VectorLibSubstraction, SubstractScalarFromVectorWithUseOfMethod) {

  // Use uniform intialisation
  Vector vector {4.0f, 2.0f};
  float scalar = 2.0f;

  Vector result = vector.substract(scalar);

  // Expect two strings not to be equal.
  EXPECT_THAT(result.x, testing::FloatEq(2.0f));
  EXPECT_THAT(result.y, testing::FloatEq(0.0f));
}

TEST(VectorLibSubstraction, SubstractArrayOfComponentsFromVectorWithUseOfMethod) {
  Vector vector {4.0f, 2.0f};
  const float arrComponents [2]  = {2.3f, 1.2f};

  Vector result = vector.substract(arrComponents);
  
  // Expect two strings not to be equal.
  EXPECT_THAT(result.x, testing::FloatEq(1.7f));
  EXPECT_THAT(result.y, testing::FloatEq(0.8f));
}

TEST(VectorLibSubstraction, SubstractXYComponentsFromVectorWithUseOfMethod) {
  Vector vector {4.0f, 2.0f};

  Vector result = vector.substract(2.3f, 1.2f);
  
  // Expect two strings not to be equal.
  EXPECT_THAT(result.x, testing::FloatEq(1.7f));
  EXPECT_THAT(result.y, testing::FloatEq(0.8f));
}