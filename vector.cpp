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

Vector::Vector(Vector&& src) noexcept
{
    moveFrom(src);
}

Vector& Vector::operator= (Vector&& src) noexcept
{
    if(this == &src)
        return *this;
    
    clean();
    moveFrom(src);
    
    return *this;
}

Vector::Vector(const Vector& src)
{
    size = src.size;
    pointer = new double [size];

    for(size_t i = 0; i < size; i++)
        pointer[i] = src.pointer[i];
}

Vector& Vector::operator=(const Vector& src)
{
    if(this == &src)
        return *this;

    Vector tmp(src);
    swap(*this, tmp);

    return *this;
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
    
    return *(pointer + index);    
}

void Vector::moveFrom(Vector& src) noexcept
{
    size = src.size;
    pointer = src.pointer;

    src.size = 0;
    src.pointer = nullptr;
}

void Vector::swap(Vector& first, Vector& second) noexcept
{
    using std::swap;
    swap(first.size, second.size);
    swap(first.pointer, second.pointer);
}








