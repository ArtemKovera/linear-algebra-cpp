/*

    Implementation of LinearAlgebra::Matrix

    it should be compiled using C++17 standard or higher

*/

#include"matrix_linear_algebra.h"
#include<cassert>

using namespace LinearAlgebra;

Matrix::Matrix(size_t row, size_t col): rows{row}, columns{col}, pointer{new double* [rows]}
{
    assert(rows > 0);
    assert(columns > 0);

    for(size_t i = 0; i < rows; i++)
    {
        pointer[i] = new double [columns] {};
    } 
}

Matrix::Matrix(size_t row, size_t col, double value): Matrix(row, col)
{
    for(size_t i = 0; i < rows; i++)
    {
        for(size_t j = 0; j < columns; j++)
        {
            pointer[i][j] = value;
        }
    }
}

Matrix::~Matrix()
{
    clean();
}

void Matrix::setElement(size_t row, size_t col, double value)
{
    if(row >= rows || col >=columns)
        throw std::invalid_argument("");

    pointer[row][col] = value;
}

double Matrix::getElement(size_t row, size_t col) const
{
    if(row >= rows || col >=columns)
        throw std::invalid_argument("");    
    
    return pointer[row][col];
}

std::pair<size_t, size_t> Matrix::getDimension() const
{
    std::pair<size_t, size_t> pair;
    pair.first = rows;
    pair.second = columns;

    return pair;
}

size_t Matrix::getNumberOfRaws() const
{
    return rows;
}

size_t Matrix::getNumberOfColumns() const
{
    return columns;
}

double Matrix::calculateDeterminant() const
{
    assert(rows == columns);
    double determinant = 0.0;  
    
    if (rows == 1)
    {
        determinant = pointer[0][0];        
    }
    else
    {
        
        for (size_t i_outer=0; i_outer<rows; i_outer++)
        {
            Matrix sub_matrix(rows-1, rows-1);
            for (size_t i=0; i<rows-1; i++)
            {
                for (size_t j=0; j<i_outer; j++)
                {
                    sub_matrix.setElement(i+1, j+1, pointer[i+1][j]);
                }

                size_t num = getNumberOfElements();

                for (size_t j=i_outer; j < num-1; j++)
                {
                    sub_matrix.setElement(i+1, j+1, pointer[i+1][j+1]);
                }
            }

            double sub_matrix_determinant = sub_matrix.calculateDeterminant();
            determinant += pow(-1.0, i_outer)* pointer[0][i_outer]*sub_matrix_determinant;
        }
    }

    return determinant;
}

size_t Matrix::getNumberOfElements() const
{
    return rows * columns;
}

void Matrix::clean()
{
    for(size_t i = 0; i < rows; i++)
    {
        delete [] pointer [i];
    }
    delete [] pointer;
    pointer = nullptr;     
}


