#ifndef _VECTOR_LINEAR_ALGEBRA_H_
#define _VECTOR_LINEAR_ALGEBRA_H_

#include<vector>
#include<exception>
#include<initializer_list>
#include<utility>
#include<cmath>

namespace LinearAlgebra
{

    class Vector
    {
    public:
        //default constructor creates a vector with default size
        //vector elements are zero initialized        
        Vector();
        
        //this constructor creates a vector whose size equals to the argument
        //vector elements are zero initialized
        Vector(size_t);

        //this constructor creates a vector whose size and values are equal to the ones of the stl vector taken as the argument
        Vector(std::vector<double>&);

        //initializer-list constructor
        Vector(std::initializer_list<double>);

        //copy constructor
        Vector (const Vector&); 

        //exception-safe copy assignment operator
        Vector& operator = (const Vector&); 

        //move constructor
        Vector (Vector&&) noexcept;

        //move assignment operator
        Vector& operator = (Vector&&) noexcept; 

        virtual ~Vector();

        //this method returns the size of the vector
        size_t getSize() const;

        //overloading [] operator; it's zero based
        //it throws invalid_argument exception if the argument is greater or equal to the size of the vector
        double& operator[](size_t);

        //read-only variant of [] operator
        //it throws invalid_argument exception if the argument is greater or equal to the size of the vector       
        double operator[](size_t) const;

        //unary + operator
        //just returns the exact copy of the vector 
        Vector operator+() const;

        //unary - operator
        //returns copy of the vector with inverse sign of the elements 
        Vector operator-() const;

        //binary + operator
        //throws invalid_argument exception if the vector taken as the argument has different size
        Vector operator+(const Vector&) const;
        
        //binary - operator
        //throws invalid_argument exception if the vector taken as the argument has different size
        Vector operator-(const Vector&) const; 

        //scalar multiplication
        Vector operator*(double) const;
        
        //returns true if both vectors have equal number of elements and the elements of one vector
        //are equal to the corresponding elements of the other vector
        //doing comparising of the elements, method uses the fabs function from cmath header
        bool operator==(const Vector&) const;

    private:
        //size of the vector
        size_t size;

        //pointer pointing to the vector elements
        double* pointer = nullptr;

        //size of the vector used in the default constructor
        static const size_t defaultSize = 10;

        //epsilon used for vector element comparising
        static inline const float epsilon = 0.00001;

        //helper method for freeing memory
        void clean() noexcept;

        //helper method used in move constructor and assignment operator
        void moveFrom(Vector&) noexcept;

        //helper method used in copy assignment operator
        void swap(Vector&, Vector&) noexcept;
    };
}


#endif