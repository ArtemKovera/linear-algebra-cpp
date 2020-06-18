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
         
        //this constructor creates zero-initialized matrix
        //the first argument sets the number of rows, and the second one sets the number of columns
        //the arguments must be greater than 0
        Matrix(size_t, size_t);

        //this constructor creates a matrix whose elements are equal to the third argument
        //the first argument sets the number of rows, and the second one sets the number of columns
        //the first two arguments must be greater than 0        
        Matrix(size_t, size_t, double);

        virtual ~Matrix();

        //this method returns the dimention of the matrix
        //the first entry - number of rows, the second entry - number of columns
        std::pair<size_t, size_t> getDimension() const;

        //this method sets one element in a matrix
        //first argument - row index, second argumend - column index, third argument - value of the matrix element
        //it throws std::invalid_argument exception if one or first two arguments have inappropriate values
        void setElement(size_t, size_t, double);

        //this method returns the value of the matrix element
        //first argument - row index, second argumend - column index        
        //it throws std::invalid_argument exception if one or both the arguments have inappropriate values
        double getElement(size_t, size_t) const;

        size_t getNumberOfRaws() const;

        size_t getNumberOfColumns() const;

        //this method calculates determinent of a square matrix recursivly
        double calculateDeterminant() const;

        //this method returns the number of elements in the matrix
        size_t getNumberOfElements() const;
        
        //unary - operator
        Matrix operator-() const;
        
        //binary + operator
        //throws invalid_argument exception if the matrix taken as the argument has different dimension       
        Matrix operator+(const Matrix&) const;

        //binary - operator
        //throws invalid_argument exception if the matrix taken as the argument has different dimension
        Matrix operator-(const Matrix&) const;
        
        //scalar multiplication operator
        Matrix operator*(double) const;

        //returns true if both matrices have equal number of elements and the elements of one matrix
        //are equal to the corresponding elements of the other matrix
        //doing comparising of the elements, the method uses the fabs function from cmath header
        bool operator==(const Matrix&) const;
       

    private:
        //number of matrix rows
        size_t rows;
        
        //number of matrix columns
        size_t columns;

        //pointer pointing to double array for matrix
        double** pointer = nullptr; 

        //epsilon used for vector element comparising
        static inline const float epsilon = 0.00001;               
        
        //halper method for freeing memory
        void clean();
    };
}

#endif