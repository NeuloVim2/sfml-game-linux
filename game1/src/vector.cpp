#include "vector.h"

// Vector & Vector::operator=(const float *arr){
//     return this*;
//     // TODO: insert return statement here
// }

Vector Vector::operator+(const Vector& vector) {
    Vector temp;
    temp.x = x + vector.x;
    temp.y = y + vector.y;

    return temp;
}