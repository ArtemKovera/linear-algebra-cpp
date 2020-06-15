/*
       
        implementation of LinearAlgebra::Vector

*/

#include<iostream>
#include "vector_linear_algebra.h"

using namespace LinearAlgebra;

Vector::Vector(): size{defaultSize}, pointer{new double [size] {}} {}

Vector::Vector(size_t s): size{s}, pointer{new double [size] {}} {}

Vector::Vector(std::vector<double>& vec): size{vec.size()}, pointer{new double [size]}
{
    for(size_t i = 0; i < size; i++)
    {
        pointer[i] = vec[i];
    }
}

Vector::Vector(std::initializer_list<double> args): size{args.size()}, pointer{new double [size]}
{
    size_t i = 0;
    for(auto el : args)
    {
        pointer[i] = el;
        i++;
    }
}

Vector::~Vector()
{
    clean();
}

size_t Vector::getSize() const
{
    return size;
}

void Vector::clean() noexcept
{
    delete [] pointer;
    pointer = nullptr;
}

double& Vector::operator[] (size_t index)
{
    if(index >= size)
        throw::std::invalid_argument("Invalid index");

    return *(pointer + index);
}

double Vector::operator[] (size_t index) const
{
    if(index >= size)
        throw::std::invalid_argument("Invalid index");
    
    std::cout << "const operator [] overloading " << std::endl;
    return *(pointer + index);    
}







