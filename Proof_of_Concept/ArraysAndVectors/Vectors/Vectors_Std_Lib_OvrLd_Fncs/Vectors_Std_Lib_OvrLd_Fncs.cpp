// Vectors_Std_Lib_OvrLd_Fncs.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Code was pulled form textbook: 'How to Program' by Deitle and Deitel - Chapter 8.  Fig. 8.14: 
// This code is almost an exact implementation of previously generated code demostrating a personal 'Vectorg' class using overloaded operators.
// This code instead of using the personal vector class, it uses the String class provided in the C++ standard library. This was done to demonstrate the 
// equivalency of the two pieces of code while showing was is really hidden or behind the implementation of the the standard class Vector code.
// So it is recommended that one compare this code with the code implementing the same functionality but using the personally developed Vector class.
//
// Demonstrating standard library class vector.
#include <iostream>
#include <iomanip>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::vector;


void outputVector(const vector< int >&);                        // Function Declarations / Headers / Prototypes
void inputVector(vector< int >&);

int main()
{
    vector< int > integers1(7);                                 // 7-element vector< int >  (Elements initializes to zero)
    vector< int > integers2(10);                                // 10-element vector< int > (Elements initializes to zero)

    
    cout << "Size of vector integers1 is "                      // Print integers1 size and contents
         << integers1.size()
         << "\nvector content after initialization:\n";
    outputVector(integers1);

    
    cout << "\nSize of vector integers2 is "                    // Print integers2 size and contents
         << integers2.size()
         << "\nvector content after initialization:\n";
    outputVector(integers2);

    
    cout << "\nInput 17 integers:\n";                           // input and print integers1 and integers2
    inputVector(integers1);                                     // Integer numbers first seven in integers1
    inputVector(integers2);                                     // Next ten integers will be save ininters2 arrray
                                                                // User is unaware numbers are being saved in two arrays
    cout << "\nAfter input, the vectors contain:\n"
         << "integers1:\n";
    outputVector(integers1);
    cout << "integers2:\n";
    outputVector(integers2);

    
    cout << "\nEvaluating: integers1 != integers2\n";           // use overloaded inequality (!=) operator
    if (integers1 != integers2)
        cout << "integers1 and integers2 are not equal\n";

        vector< int > integers3(integers1);                     // Copy constructor - create vector integers3 using integers1 
                                                                // as an initializer; print sizeand contents
    cout << "\nSize of vector integers3 is "
         << integers3.size()
         << "\nvector contents after initialization:\n";
    outputVector(integers3);

        
    cout << "\nAssigning integers2 to integers1:\n";            // Use overloaded assignment (=) operator
    integers1 = integers2;

    cout << "integers1:\n";
    outputVector(integers1);
    cout << "integers2:\n";
    outputVector(integers1);

    
    cout << "\nEvaluating: integers1 == integers2\n";           // Use overloaded equality (==) operator

    if (integers1 == integers2)
        cout << "integers1 and integers2 are equal\n";

    
    cout << "\nintegers1[5] is " << integers1[5];               


    cout << "\n\nAssigning 1000 to integers1[5]\n";             // Use overloaded subscript operator to create rvalue
    integers1[5] = 1000;
    cout << "integers1:\n";
    outputVector(integers1);

  
    cout << "\nAttempt to assign 1000 to integers1.at( 15 )\n"  // Attempt to use out of range subscript
         << "will cause an 'Exception Unhandled' to occur"
         << endl;
    integers1.at(15) = 1000;                                    // ERROR: out of range

    return 0;

}                                                               // End main

// .....................................................   Function Implementations / Definitions   .........................................................

void outputVector(const vector< int >& array)                   // Output vector contents
{
    int arrySize = array.size();
    for (int  i = 0; i < arrySize; i++) {
        cout << setw(12) << array[i];
                                                                // Formatting four numbers per row
        if ((i + 1) % 4 == 0)                                   // 4 numbers per row of output
            cout << endl;
    }                                                           // End for
                                          
        cout << endl;                                           // End last line of output

}                                                               // End function outputVector


void inputVector(vector< int >& array)                          // Input vector contents
{                                                               // Store interger numbers from users
    int arrySize = array.size();                                // Save in array reference '&'
    for (int i = 0; i < arrySize; i++)
        cin >> array[i];

}                                                               // End function inputVector
