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

Vector& Vector::add(const Vector& operand) {
    this->x += operand.x;
    this->y += operand.y;
    return *this; 
}

Vector& Vector::add(const float x, const float y) {
    this->x += x;
    this->y += y;
    return *this; 
}

Vector& Vector::add(const float *comps) {
    this->x += comps[0];
    this->y += comps[1];

    return *this;
};