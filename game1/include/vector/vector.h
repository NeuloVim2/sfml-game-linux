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

// const int * ptr // pointer to const int
// int const * ptr // pointer to const int
// int * const ptr // const pointer to int
// const int * const ptr // const pointer to const int
};

#endif