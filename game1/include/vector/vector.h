#pragma once
#ifndef VECTOR_H 
#define VECTOR_H

class Vector {
public:
    float x;
    float y;
    
    Vector(){};

    // Member initialisation of constructor
    Vector(float xArg, float yArg):x(xArg), y(yArg){};

    // Vector operator=(const float* arr);
    Vector operator+(const Vector& operand);
    Vector operator+(const float scalar);
    Vector operator-(const Vector& operand);
    Vector operator-(const float scalar);

    Vector& add(const Vector& operand);
    Vector& add(const float scalar);
    Vector& add(const float x,  const float y);
    Vector& add(const float *comps);

    Vector& substract(const Vector& operand);
    Vector& substract(const float scalar);
    Vector& substract(const float *comps);
    Vector& substract(const float x, const float y);

    // Vector& substract(const Vector& operand);
    // Vector& substract(const float x,  const float y);
    // Vector& substract(const float *comps);
// const int * ptr // pointer to const int
// int const * ptr // pointer to const int
// int * const ptr // const pointer to int
// const int * const ptr // const pointer to const int
};

#endif