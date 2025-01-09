#include<gtest/gtest.h>
#include<gmock/gmock.h>

#include "vector.h"

TEST(VectorLibAddition, AddTwoVectorsWithUseOfPlusSign) {

  // Use uniform intialisation
  Vector leftOperand {1.0f, 2.0f};
  Vector rightOperand {1.0f, 2.0f};

  Vector result = leftOperand + rightOperand;

  // Expect two strings not to be equal.
  EXPECT_THAT(result.x, testing::Eq(2.0f));
  EXPECT_THAT(result.y, testing::Eq(4.0f));
}

TEST(VectorLibAddition, AddTwoVectorsWithUseOfAddMethod) {

  // Use uniform intialisation
  Vector leftOperand {2.0f, 5.0f};
  Vector rightOperand {0.0f, 4.0f};

  Vector result = leftOperand.add(rightOperand);

  // Expect two strings not to be equal.
  EXPECT_THAT(result.x, testing::Eq(2.0f));
  EXPECT_THAT(result.y, testing::Eq(9.0f));
}

TEST(VectorLibAddition, AddToVectorXYComponentsWithUseOfAddMethod) {

  // Use uniform intialisation
  Vector leftOperand {2.0f, 5.0f};

  Vector result = leftOperand.add(2.0f, 4.0f);

  // Expect two strings not to be equal.
  EXPECT_THAT(result.x, testing::Eq(4.0f));
  EXPECT_THAT(result.y, testing::Eq(9.0f));
}

TEST(VectorLibAddition, AddToVectorXYComponentsAsArrayWithUseOfAddMethod) {

  // Use uniform intialisation
  Vector leftOperand {2.0f, 5.0f};
  float components [2] = {2.3f, 9.1f};

  Vector result = leftOperand.add(components);

  // Expect two strings not to be equal.
  EXPECT_THAT(result.x, testing::Eq(4.3f));
  EXPECT_THAT(result.y, testing::Eq(14.1f));
}

TEST(VectorLibAddition, AddScalarToVectorWithUseOfAddMethod) {
  // Use uniform intialisation
  Vector vector {2.0f, 5.0f};
  float scalar = 3.2f;

  Vector result = vector.add(scalar);

  // Expect two strings not to be equal.
  EXPECT_THAT(result.x, testing::Eq(5.2f));
  EXPECT_THAT(result.y, testing::Eq(8.2f));
}

TEST(VectorLibAddition, AddScalarToVectorWithUseOfPlusSign) {
  // Use uniform intialisation
  Vector vector {2.0f, 5.0f};
  float scalar = 3.2f;

  Vector result = vector + scalar;

  // Expect two strings not to be equal.
  EXPECT_THAT(result.x, testing::FloatEq(5.2f));
  EXPECT_THAT(result.y, testing::FloatEq(8.2f));
}