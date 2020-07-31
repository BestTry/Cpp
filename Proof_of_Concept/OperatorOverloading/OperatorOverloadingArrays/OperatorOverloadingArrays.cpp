// OperatorOverloadingArrays.cpp : Code was pulled from textbook Deitel & Deitel - 'How to Program' - Chapter 8 - Overloading
// Fig. 8.6: fig08_06.cpp -  Array class test program.
//
// Description of Program .............   Overloading Operators for Arrays .............................
// Arrays have a great potential for errors and are limited in functionality.  By using Overloaded 
// Operators with arrays. Safegaurds are implemented as well as functionality is instilled.
// ..........................................................................................

//
//						// The Preprocessor Directives: (Header Files) 	
#include "array1.h"		// Included header file for array with overloaded operators
#include <iostream> 	// Standard Template Library class  -  Used for cout, cin, cerr, printf  ( That is the  reason for brackets < > )
#include <iomanip>		// Required to utilize parameterized stream manipulator ie. calling setprecision(3) & fixed functions
#include <fstream>		// Inherited from 'basic_fstream' for file I/O - Defines Data types: ofstream, ifstream, and fstream

						// The double colons operator '::' is defined as the "Scope Resolution Operator"
using std::cout;		// Console output
using std::cin;			// Console input
using std::endl;		// End of Line - Clears output buffer and terminates with a new-line character
using std::fixed;		// Both 'fixed' & 'showpoint' are nonparamatized stream manipulators that Do Not require the <iomanip> header file
using std::setw;		// Assure #include <iomanip> is included which requires a parameterized stream manipulator

using std::istream;		// These libraries must be a subset on the included iostream ?
using std::ostream;		// Probably not necessary if 'using namespace std;' is stated

using namespace std;	// Common practice to implement the "std" namespace as it contains multiple supporting useful functions


// .........................................   Function Prototype Declaration Header References   ............................................

void exitPrgm();							// Use this function as a optional default to terminate the program


int main()									// Function main() begins program execution - Entry point for the program
{
	cout << "\n\n >>>>>>>>>>>>>>>>>>>>>>>>>>>   Main Code Execution   <<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	cout << "                 Operator Overloading with Arrays        \n\n" << endl;

	Array integers1(7);										// Seven-element Array
	Array integers2;										// 10-element Array by default
		
	cout << "Size of array integers1 is "					// Print integers1 size and contents
		 << integers1.getSize()
		 << "\nArray after initialization:\n" << integers1;	// Initialization of array renders all elements to zero

	
	cout << "\nSize of array integers2 is "					// Print integers2 size and contents
		<< integers2.getSize()
		<< "\nArray after initialization:\n" << integers2;

															// Input and print integers1 and integers2
	cout << "\nOn a single line just separated with spaces - Input 17 integers:\n";
	cin >> integers1 >> integers2;

	cout << "\nAfter input, the arrays contain:\n"
		<< "integers1:\n" << integers1
		<< "integers2:\n" << integers2;
		
	cout << "\nEvaluating: integers1 != integers2\n";		// Uses overloaded-operator inequality (!=) operator

	if (integers1 != integers2)
		cout << "integers1 and integers2 are not equal\n";
															// Create array integers3 using integers1 as initializer - print size & contents
	Array integers3(integers1);								// Calls copy constructor

	cout << "\nSize of array integers3 is "
		<< integers3.getSize()
		<< "\nArray after initialization:\n" << integers3;

	cout << "\nAssigning integers2 to integers1:\n";		// Uses overloaded assignment (=) operator
	integers1 = integers2;									// Note target is smaller

	cout << "integers1:\n" << integers1
		 << "integers2:\n" << integers2;

	cout << "\nEvaluating: integers1 == integers2\n";		// Uses overloaded equality (==) operator

	if (integers1 == integers2)
		cout << "integers1 and integers2 are equal\n";
	
	cout << "\nintegers1[5] is " << integers1[5];			// Uses overloaded subscript operator to create rvalue

	
	cout << "\n\nAssigning 1000 to integers1[5]\n";			// Uses overloaded subscript operator to create lvalue
	integers1[5] = 1000;
	cout << "integers1:\n" << integers1;

															// Attempt to use out-of-range subscript
	cout << "\nAttempt to assign 1000 to integers1[15]" << endl;
	integers1[15] = 1000;									// ERROR: out of range


	exitPrgm();												// Option function member to terminate program
	system("pause");										// Some compilers do not recognize this statement
	return 0; 												// Indicates successful termination
}															// End of main

// .............................................   Function Code Definition Implementation  .................................................


void exitPrgm()
{
	cout << "\n\n                  >>>>>>>>>>  Program has Terminated  <<<<<<<<<< " << endl;
	cout << " \n\n\n " << endl;
	exit(0);					// Terminate running program from anywhere it is called:
}

/*

|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|
012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
		  |         |         |         |         |         |         |         |         |         |         |         |         |         |
00		  10        20        30        40        50        60        70        80        90		00		  10        20        30        40

*/