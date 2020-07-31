// Member function definitions implementations for class Array - Fig 8.5: array1.cpp - Chapter 8 of Deitel and Deitel
// Defines the code for many operator-overloads scuch as '=', '==', '!=', '[]'
// Sophisticated and complex code.  - A challenge to understand.
//
#include <iostream>                             // Required for istream and ostream
#include <iomanip>
#include <new>                                  // C++ standard "new" operator - The 'new' operator will create a ptr for array
#include <cstdlib>                              // Exit function prototype
#include "array1.h"                             // Array class declaration efinition

using std::cout;
using std::cin;
using std::endl;
using std::setw;

Array::Array(int arraySize)                     // Default constructor for class Array (default size 10)
{    
    size = (arraySize > 0 ? arraySize : 10);    // Validate arraySize
    ptr = new int[size];                        // Create space for array - Points to start addr of an array of size 'size'
    for (int i = 0; i < size; i++) {
        ptr[i] = 0;                             // Initializes array elements to all zeros
    }
}                                               // End Array default constructor


Array::Array(const Array& arrayToCopy)          // Copy an array constructor for class Array;
     : size(arrayToCopy.size)                   // It must receive a reference to prevent infinite recursion
{
    ptr = new int[size];                        // Create space for array - Points to start addr of an array of size 'size'
                                                // Can also think as 'ptr' is name of the array?
    for (int i = 0; i < size; i++)
        ptr[i] = arrayToCopy.ptr[i];            // Copy into array object starting at address 'ptr'
}                                               // End Array copy constructor


Array::~Array()                                 // Destructor for class Array
{
    delete[] ptr;                               // Reclaims array space by deleting ptr object
}                                               // End of destructor for an array object



int Array::getSize() const                      // Returns the size of the array
{
    return size;                                // The attribute 'size' is a private parameter accesible by this function
}                                               // End of function getSize()

                                                // Overloaded assignment operator= - 'const' return avoids: ( a1 = a2 ) = a3
const Array& Array::operator=(const Array& right)
{                                               // This if statement would have to call the 'operator==' (function below here) to evaluate
    if (&right != this) {                       // Check for self-assignment - Note that '&' is used to evaluate eqivalency of arrays      
        if (size != right.size) {               // For arrays of different sizes, deallocate left-side array, then allocate new left-side array
            delete[] ptr;                       // Reclaim memory space of left side array
            size = right.size;                  // Resize this left side (of assignment statement) object
            ptr = new int[size];                // Create memory space for the left-side array for the copy execution
        }                                       // End inner-if

        for (int i = 0; i < size; i++)
            ptr[i] = right.ptr[i];              // Copy right side array into left side array object
    }                                           // End outer if
                                                
    return *this;                               // Case where arrays are eqivalent in content and size; Enables x = y = z, for example
}                                               // End of function overloaded operator=


bool Array::operator==(const Array& right) const// Determine if two arrays are equal and return true, otherwise return false
{
    if (size != right.size)
        return false;                           // First check if arrays are of different sizes

    for (int i = 0; i < size; i++) {
        if (ptr[i] != right.ptr[i])             // Compare content of array on left side of '==' with array on the right side
            return false;                       // Arrays found to be not equal
    }
    return true;                                // Arrays are equal in size and content
}                                               // End function operator==



int& Array::operator[](int subscript)           // Overloaded subscript operator[] for non-const Arrays
{                                               // Reference return creates an lvalue    
    if (subscript < 0 || subscript >= size) {   // Check for subscript out of range error
        cout << "\nError: Subscript " << subscript
             << " out of range" << endl;
        exit(1);                                // Terminate program; Subscript is out of range
    }                                           // End if

    return ptr[subscript];                      // Returns a reference of the array pointing at address ptr
}                                               // End function operator[]


                                                // Overloaded subscript operator[] for const Arrays - Const reference return creates an rvalue
const int& Array::operator[](int subscript) const
{   
    if (subscript < 0 || subscript >= size) {   // check for subscript out of range error
        cout << "\nError: Subscript " << subscript
             << " out of range" << endl;
        exit(1);                                // Terminate program; Subscript is out of range
    }                                           // End if

    return ptr[subscript];                      // Returns a const reference of the array pointing at address ptr
}                                               // End function operator[]



istream& operator>>(istream& input, Array& a)           // Overloaded input operator for class Array;
{                                                       // Inputs directly values for entire array to
    for (int i = 0; i < a.size; i++)                    // which pointer points.
        input >> a.ptr[i];                              // Function has access to private member data (The're friends)

    return input;                                       // Enables cin >> x >> y;

}                                                       // End function operator>>


ostream& operator<<(ostream& output, const Array& a)    // Overloaded output operator for class Array 
{                                                       // Displays number of elem of array indicated by 'size'
    int i;                                              // from the start of the integer array starting @ pointer
    for (i = 0; i < a.size; i++) {                      // Output private ptr-based array 
        output << setw(12) << a.ptr[i];                 // Function has access to private member data (The're friends)
        if ((i + 1) % 4 == 0)                           // Four numbers per row of output
            output << endl;
    }                                                   // End for

    if (i % 4 != 0)                                     // End last line of output
        output << endl;

    return output;                                      // Enables cascading cout << x << y;

}                                                       // End function operator<<
