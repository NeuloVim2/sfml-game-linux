#include<gtest/gtest.h>
#include<gmock/gmock.h>

#include "vector.h"


// #include "src/include/vector.h"

//TODO: add support for Vector copy assignment(Vector a = Vector b) 

//TODO: add support for Vector creation with empty constructor. Done 
//TODO: add support for Vecotor creation with cosnstructor accpepting x and y as arguments. Done 

//TODO: add vector addition support for Vector
//TODO: add method for Vecotor to add  another Vector as argument
//TODO: add method for Vecotor to add x and y components as arguments
//TODO: add support for additon of two Vectors with use of + operator

//TODO: add support for Vecotor to add x and y components as arguments
//TODO: add support for Vector for assignment x and y components as array
TEST(VectorLib, shouldAddTwoVectorsWithUseOfPlusSign) {

  // Use uniform intialisation
  Vector leftOperand {1, 2};
  Vector rightOperand {1, 2};

  Vector result = leftOperand + rightOperand;

  // Expect two strings not to be equal.
  EXPECT_THAT(result.x, testing::Eq(2));
  EXPECT_THAT(result.y, testing::Eq(4));
  // EXPECT_STREQ("some", "value");
}