#include<gtest/gtest.h>
#include<gmock/gmock.h>

#include "vector.h"

//TODO: add support for Vector copy assignment(Vector a = Vector b) 

//TODO: add support for Vector creation with empty constructor. Done 
//TODO: add support for Vecotor creation with cosnstructor accpepting x and y as arguments. Done 

//TODO: add vector addition support for Vector. Done
//TODO: add method for Vecotor to add  another Vector as argument. Done
//TODO: add method for Vecotor to add x and y components as arguments. Done
//TODO: add support for additon of two Vectors with use of + operator. Done

//TODO: add support for Vecotor to add x and y components as arguments. Done
//TODO: add support for Vector for assignment x and y components as array. Done
TEST(VectorLib, shouldAddTwoVectorsWithUseOfPlusSign) {

  // Use uniform intialisation
  Vector leftOperand {1.0f, 2.0f};
  Vector rightOperand {1.0f, 2.0f};

  Vector result = leftOperand + rightOperand;

  // Expect two strings not to be equal.
  EXPECT_THAT(result.x, testing::Eq(2.0f));
  EXPECT_THAT(result.y, testing::Eq(4.0f));
  // EXPECT_STREQ("some", "value");
}

TEST(VectorLib, shouldAddTwoVectorsWithUseOfAddMethod) {

  // Use uniform intialisation
  Vector leftOperand {2.0f, 5.0f};
  Vector rightOperand {0.0f, 4.0f};

  Vector result = leftOperand.add(rightOperand);

  // Expect two strings not to be equal.
  EXPECT_THAT(result.x, testing::Eq(2.0f));
  EXPECT_THAT(result.y, testing::Eq(9.0f));
  // EXPECT_STREQ("some", "value");
}

TEST(VectorLib, shouldAddToVectorXYComponentsWithUseOfAddMethod) {

  // Use uniform intialisation
  Vector leftOperand {2.0f, 5.0f};

  Vector result = leftOperand.add(2.0f, 4.0f);

  // Expect two strings not to be equal.
  EXPECT_THAT(result.x, testing::Eq(4.0f));
  EXPECT_THAT(result.y, testing::Eq(9.0f));
  // EXPECT_STREQ("some", "value");
}

TEST(VectorLib, shouldAddToVectorXYComponentsAsArrayWithUseOfAddMethod) {

  // Use uniform intialisation
  Vector leftOperand {2.0f, 5.0f};
  float components [2] = {2.3f, 9.1f};

  Vector result = leftOperand.add(components);

  // Expect two strings not to be equal.
  EXPECT_THAT(result.x, testing::Eq(4.3f));
  EXPECT_THAT(result.y, testing::Eq(14.1f));
  // EXPECT_STREQ("some", "value");
}