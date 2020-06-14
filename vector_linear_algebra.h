#ifndef _VECTOR_LINEAR_ALGEBRA_H_
#define _VECTOR_LINEAR_ALGEBRA_H_

namespace LinearAlgebra
{

    class Vector
    {
    public:
        //default constructor creates a vector with default size
        Vector();
        
        //this constructor creates a vector whose size equals to the argument
        //vector elements are zero initialized
        Vector(size_t);

        //this constructor creates a vector whose size and values are equal to the ones of the stl vector taken as the argument
        Vector(std::vector<double>);

        ~Vector();

        //this method returns the size of the vector
        size_t getSize() const;

        //overloading [] operator; it's zero based
        double operator[](size_t);

        //read-only variant of [] operator
        const double operator[](size_t) const;

        //unary + operator
        Vector operator+() const;

        //unary - operator
        Vector operator-() const;

        // binary + operator
        Vector operator+(const Vector&) const;
        
        // binary - operator
        Vector operator-(const Vector&) const; 

        //scalar multiplication
        Vector operator*(double) const;
        


    private:
        size_t size;
        double* pointer = nullptr;
        static const size_t defaultSize = 10;
    };

}


#endif