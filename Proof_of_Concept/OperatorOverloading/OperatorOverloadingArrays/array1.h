// Header Declaration Prototype Code File  - // Fig. 8.4: array1.h  of Chapter 8 -  Array class for storing arrays of integers.
#pragma once
#ifndef ARRAY1_H                                               
#define ARRAY1_H                                                // Description for friend functions with Overloaded operators:

                                                                // When compiler see expression like: cout << arrayObject, 
                                                                // it invokes non-member function operator<< with the call 
#include <iostream>                                             // operator<<( cout, arrayObject )

using std::ostream;                                             // When compiler see expression like: cin >> arrayObject, 
using std::istream;                                             // it invokes non-member function operator>> with the call 
                                                                // operator>>( cin, arrayObject )

                                                                // Note must be friends because they cannot be members of the 
                                                                // class Array, because the Array is always mentioned on the
                                                                // right side of a stream-insertion or stream-extraction operator

class Array {
    friend ostream& operator<<(ostream&, const Array&);         // Overloaded stream extraction operator:  ' << '
    friend istream& operator>>(istream&, Array&);               // Overloaded stream insertion operator:  ' >> '

public:
    Array(int = 10);                                            // Default constructor - default size of array is 10 elements
    Array(const Array&);                                        // Copy constructor
    ~Array();                                                   // Destructor
    int getSize() const;                                        // Return size of array
        
    const Array& operator=(const Array&);                       // Assignment operator (Overloaded)    
    bool operator==(const Array&) const;                        // Equality operator (Overloaded) 

    bool operator!=(const Array& right) const {                 // Inequality operator; returns opposite of == operator (Overloaded)    
        return !(*this == right);                               // Invokes Array::operator== (Overloaded)
    }                                                           // End function operator!= (Overloaded)
        
    int& operator[](int);                                       // Subscript operator[] for non-const objects returns lvalue (Overloaded)    
    const int& operator[](int) const;                           // Subscript operator[] for const objects returns rvalue (Overloaded)

private:
    int size;                                                   // Array size class attribute  
    int* ptr;                                                   // Pointer to first element of array
                                                                // Dynamically allocated array of integers managed by Array object
};                                                              // End class Array

#endif