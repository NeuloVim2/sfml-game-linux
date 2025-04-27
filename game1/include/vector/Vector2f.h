#pragma once
#ifndef VECTOR2F_H 
#define VECTOR2F_H

class Vector2f {
public:
    float x{};
    float y{};
    
    Vector2f() = default;

    Vector2f(float xArg, float yArg):x(xArg), y(yArg){};


    bool operator==(const Vector2f& vector) const;
    bool operator!=(const Vector2f& vector) const;

    // Vector2f operator=(const float* arr);
    Vector2f operator+(const Vector2f& operand);
    Vector2f operator+(const float scalar);
    Vector2f operator-(const Vector2f& operand);
    Vector2f operator-(const float scalar);
    Vector2f operator*(const float scalar);

    Vector2f operator-();

    Vector2f& add(const Vector2f& operand);
    Vector2f& add(const float scalar);
    Vector2f& add(const float x,  const float y);
    Vector2f& add(const float *comps);

    Vector2f& substract(const Vector2f& operand);
    Vector2f& substract(const float scalar);
    Vector2f& substract(const float *comps);
    Vector2f& substract(const float x, const float y);
};

#endif