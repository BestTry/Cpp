// Vectors_STL_Class.cpp : Testing the Vector class functions included within the Standard Template Library (STL)
// This code example was pulled from the lagacy textbook 'C++ How To Program" by Deitel $th Edition
// Chapter 21 - Standard Template Library  -  Vector Class Element-Manipulation Functions
// The following functions such as “copy’, ‘insert’, ‘begin’, ‘end’, ‘erase’, clear’ were exercised.
// Then the results of these functions were displayed on the original vector array.
//		
						// Below is what is known as the Preprocessor Directives - in this Header section
						// Under Visual Studio 17  -  replace #include "stdafx.h" with #include "pch.h" to provide same library support						
						// The Preprocessor Directives: (Header Files) 							
#include <iostream> 	// Part of the standard library  -  Used for cout, cin, cerr, printf  ( That is the  reason for brackets < > )
#include <string>		// Use the s suffix for literal strings 'string' class - required as a new way of using strings, non char sequence
#include <ctime>		// Required to implement date and time functions
#include <windows.h>	// Required to implement date and time functions - Some IDE / Complilers do not accept this header file
#include <typeinfo>		// Necessary for imlementing the typeid() function 
#include <memory>		// Necessary when using smart pointers. Syntax: unique_ptr<int> ptrName( new int );
#include <array>		// Necessary when using the array class i.e array<arrType, size>
#include <vector>		// Support vector operations - See inputDate
#include <algorithm>	// Copy algorithm - Needed to utilize Standard Template Library functions
						// Before compiling symbol '#' indicates a preprocessing contents of  
						// the input/output stream header file iostream.  This file must be 
						// included with any keyboard input or console screen output
						// Functions within the standard library are as follows:
						// Since classes below are part of C++ stadard library < > are placed around them
#include <cmath>		// Enables the use of the "pow" function with the math library and other mathematical functions
#include <functional>	// References the standard function library - std::function
#include <iomanip>		// Required to utilize parameterized stream manipulator ie. calling setprecision(3) & fixed functions
#include <thread>		// std::this_thread::sleep_for(std::chrono::seconds(XX) << endl;
#include <chrono>		// std::chrono::seconds(XX)
#include <cstdlib>		// Required to implement the rand() & srand() function.  Also, needed to execute the 'exit()' function.
#include <ctime>		// Required to implement the time(0) function providing a number to seed rand() using srand(): srand( time( 0 ) );
						// Arguement (0) yields an interger value of the calendar in seconds

						// The double colons operator '::' is defined as the "Scope Resolution Operator"
using std::cout;		// Console output
using std::cin;			// Console input
using std::endl;		// End of Line - Clears output buffer and terminates with a new-line character
using std::fixed;		// Both 'fixed' & 'showpoint' are nonparamatized stream manipulators that Do Not require the <iomanip> header file
using std::pow;			// Standard Library Function pow(x,y) definded as x raised to the y power
using std::setw;		// Assure #include <iomanip> is included which requires a parameterized stream manipulator
using std::setprecision;// setprecision(2)indicates a double variable value should be printed with 2 digits to the right of the decimal point


using namespace std;	// Common practice to implement the "std" namespace as it contains multiple supporting useful functions

						// ##### Necessary for the 'GetConsoleWindow()' function below to work! - on Windows 2000 and later
#define _win32_winnt 0x0500
#include <windows.h>
						// #####

// ..............................................   Function Prototype Declaration Code   ..............................................
// Global variables, Function protoypes, Classes are placed/declared here before 'main' .... Implementation may reside here optionally
// Implementation details of the Functions may be coded after the 'main' block 

void exitPrgm();							// Use this function as a optional default to terminate the program




int main()									// Function main() begins program execution - Entry point for the program
{
												// ##############################################################
												// Modify position and size of Console Application Window
		HWND console = GetConsoleWindow();		// Get the console handle
		RECT r;									// Stores the console's current dimensions
		GetWindowRect(console, &r);				// MoveWindow(window_handle, x, y, width, height, redraw_window);
		MoveWindow(console, 1300, 0600, 700, 1100, true);
												// ###############################################################


	cout << "\n\n >>>>>>>>>>>>>>>>>>>>>>>>>>>>   Main Code Execution   <<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	cout << "    Standard Template Library  -  Vector Class Element-Manipulation Functions        " << endl;
												// Note 'vector' 'copy', ostream, sytax could  been written like std::copy 
												// Since all of these functional classes are part of the STL i.e. std::vector
	const int SIZE = 6;							// Assign vector container size to 6 elements;  The ' = ' operator is optional
	int rawArray[SIZE] = { 1, 2, 3, 4, 5, 6 };	// Regular raw array   -  Then, ... Instantiate a vector array -
												// Using raw array & overloaded vector constructor from its class
	vector< int > vecIntArry(rawArray, rawArray + SIZE);
												// Constructor takes two iterator arguments - Recall pointers to an array
												// can be used as iterators.  And an array name is by default a pointer.
												// The vector vecIntArry is initialized with the contents of rawArray from location
												// 'rawArray' to ((rawArray + SIZE) - 1)  because first elem[0] address is rawArray
	ostream_iterator < int > outStrm(cout, " ");// STL function 'ostream_iterator' used to output contents of the vector 'vecIntArry:
												// Outputs integers separated by single spaces via 'cout'. "ostream_iterator < int >' is 
												// type-safe output mechanism that outputs only type int: First arg specifies output stream
												// Second arg aspecifies string separator characters - space character. 
												// The variable 'outStrm' is the name given to the outStream object that is used by 'copy'
	cout << " Here is the contents of the vector array: " << endl;
	copy(vecIntArry.begin(), vecIntArry.end(), outStrm);
												// The STL uses 'copy' to output entire contents of the vector array 'vecIntArry. The algorithm
												// copy copies each element from location *.begin() to (*.end()-1)

	cout << "\n First element of the vector array: " << vecIntArry.front();
	cout << "\n Last  element of the vector array: " << vecIntArry.back() << endl << endl;

	cout << " Manipulating elements in the vector array --> " << endl;
	vecIntArry[0] = 7;							// set element [0] to 7		Subscripting vector array  
	vecIntArry.at(2) = 9;						// Set element at position 2 [2] to the value 9
	vecIntArry.insert(vecIntArry.begin() + 3, 99);
												// Inserted 99 at [3]
	cout << " After changes, the contents of the vector array: " << endl;
	copy(vecIntArry.begin(), vecIntArry.end(), outStrm);
	cout << "\n" << endl;


	try {
		vecIntArry.at(100) = 888;				// Access out-of-range elelment
	}											// End try
						
	catch (std::out_of_range outOfRange) {		// Catch out_of_range exception
		cout << "\n\nException: " << outOfRange.what();
	}											// End catch


	vecIntArry.erase(vecIntArry.begin());		// Erases first element in the vector array 
	cout << "\n After changes, the first element is erased: " << endl;
	copy(vecIntArry.begin(), vecIntArry.end(), outStrm);
	cout << "\n" << endl;

												// Erases first element in the vector array 
	vecIntArry.erase(vecIntArry.begin(), vecIntArry.end());		
	cout << "\n Remaining elements in the vector array are erased: ";
	cout << "\n After erasing all elements in vecIntArry, the vector array"
		 << ( vecIntArry.empty()  ? " is " : " is not " ) << "empty" << endl << endl;

												// Inserts up to, but not including the rawArray + 1 pointer
	cout << " Inserting the raw array 'rawArray' bact into the vector array vecINtArry" << endl;
	vecIntArry.insert(vecIntArry.begin(), rawArray, rawArray + SIZE);
	cout << " Contents of the vector array vecIntArry before invoking the 'clear' function:" << endl;
	copy(vecIntArry.begin(), vecIntArry.end(), outStrm);
	cout << "\n" << endl;

	cout << " Calling the 'clear' function on the vector array 'vecIntArry' " << endl;
	vecIntArry.clear();
	cout << " After invoking the 'clear' function on the vecIntArry, the vector array"
		<< (vecIntArry.empty() ? " is " : " is not ") << "empty" << endl << endl;




	exitPrgm();									// Option function member to terminate program
	system("pause");							// Some compilers do not recognize this statement
	return 0; 									// Indicates successful termination
}												// End of main

// .............................................   Function Code Definition Implementation  .................................................
//    When functional coded is declared above before the main coding section use this area for functional code implementation

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