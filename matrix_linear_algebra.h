#ifndef _MATRIX_LINEAR_ALGEBRA_H_
#define _MATRIX_LINEAR_ALGEBRA_H_

#include<vector>
#include<exception>
#include<initializer_list>
#include<utility>
#include<cmath>
#include<tuple>

namespace LinearAlgebra
{
    class Matrix
    {
    public:

        Matrix();

        Matrix(size_t, size_t);

        ~Matrix();

        std::pair<size_t, size_t> getDimension() const;

        void setElement(size_t, size_t);

        double getElement(size_t, size_t) const;

        size_t getNumberOfRaws() const;

        size_t getNumberOfColumns() const;

        double calculateDeterminant() const;
        
        Matrix operator+() const;
        
        Matrix operator-() const;
        
        Matrix operator+(const Matrix&) const;

        Matrix operator-(const Matrix&) const;
        
        Matrix operator*(double) const;

        bool operator==(const Matrix&) const;
       

    private:
        double* pointer = nullptr;

        size_t rows;

        size_t columns;

        void clean();

    };


}

#endif