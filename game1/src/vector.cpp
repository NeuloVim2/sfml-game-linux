#include "vector.h"
#include <iostream>
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

Vector Vector::operator+(const float scalar) {
    Vector temp;
    temp.x = x + scalar;
    temp.y = y + scalar;
    return temp;
};

Vector Vector::operator-(const Vector& vector) {
    Vector temp;
    temp.x = x - vector.x;
    temp.y = y - vector.y;
    return temp;
}

Vector Vector::operator-(const float scalar) {
    Vector temp;
    temp.x = x - scalar;
    temp.y = y - scalar;
    return temp;
};

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

Vector& Vector::add(const float scalar) {
    this->x += scalar;
    this->y += scalar;
    return *this; 
}

Vector& Vector::add(const float *comps) {
    this->x += comps[0];
    this->y += comps[1];
    return *this;
};

Vector& Vector::substract(const Vector& operand) {
    this->x = this->x - operand.x;
    this->y = this->y - operand.y; 
    return *this;
};

Vector& Vector::substract(const float scalar) {
    this->x = this->x - scalar;
    this->y = this->y - scalar; 
    return *this;
};

Vector& Vector::substract(const float *comps) {
    this->x -= comps[0];
    this->y -= comps[1]; 
    return *this;
};

Vector& Vector::substract(const float x, const float y) {
    this->x -= x;
    this->y -= y; 
    return *this;
};