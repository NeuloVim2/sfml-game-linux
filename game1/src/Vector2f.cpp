#include <iostream>

#include "Vector2f.h"
// Vector2f & Vector2f::operator=(const float *arr){
//     return this*;
//     // TODO: insert return statement here
// }

Vector2f Vector2f::operator+(const Vector2f& vector) {
    Vector2f temp;
    temp.x = x + vector.x;
    temp.y = y + vector.y;

    return temp;
}

Vector2f Vector2f::operator+(const float scalar) {
    Vector2f temp;
    temp.x = x + scalar;
    temp.y = y + scalar;
    return temp;
};

Vector2f Vector2f::operator-(const Vector2f& vector) {
    Vector2f temp;
    temp.x = x - vector.x;
    temp.y = y - vector.y;
    return temp;
}

Vector2f Vector2f::operator-(const float scalar) {
    Vector2f temp;
    temp.x = x - scalar;
    temp.y = y - scalar;
    return temp;
};

Vector2f Vector2f::operator*(const float scalar) {
    Vector2f temp;
    temp.x = x * scalar;
    temp.y = y * scalar;
    std::cout << "temp.x: " << temp.x << ", temp.y: " << temp.y << std::endl;
    return temp;
};

Vector2f Vector2f::operator-() {
  return Vector2f(-x, -y);
};

bool Vector2f::operator==(const Vector2f& vector) const {
    return x == vector.x && y == vector.y;
};

bool Vector2f::operator!=(const Vector2f& vector) const {
    return x != vector.x || y != vector.y;
};

Vector2f& Vector2f::add(const Vector2f& operand) {
    this->x += operand.x;
    this->y += operand.y;
    return *this; 
}

Vector2f& Vector2f::add(const float x, const float y) {
    this->x += x;
    this->y += y;
    return *this; 
}

Vector2f& Vector2f::add(const float scalar) {
    this->x += scalar;
    this->y += scalar;
    return *this; 
}

Vector2f& Vector2f::add(const float *comps) {
    this->x += comps[0];
    this->y += comps[1];
    return *this;
};

Vector2f& Vector2f::substract(const Vector2f& operand) {
    this->x = this->x - operand.x;
    this->y = this->y - operand.y; 
    return *this;
};

Vector2f& Vector2f::substract(const float scalar) {
    this->x = this->x - scalar;
    this->y = this->y - scalar; 
    return *this;
};

Vector2f& Vector2f::substract(const float *comps) {
    this->x -= comps[0];
    this->y -= comps[1]; 
    return *this;
};

Vector2f& Vector2f::substract(const float x, const float y) {
    this->x -= x;
    this->y -= y; 
    return *this;
};