// ArrayBubbleSort.cpp : Code Example lifted from Dietel "How to Program" 4th edition, Exercise / or  / Textbook Example - Chapter 04 - Sorting Arrays
//
//
// Description of Program .............  Boiler Plate Template  .............................
// ..........................................................................................
// ..........................................................................................
// ..........................................................................................
//
// Additonal Code Description : Steps Enumerated 
// 1 - 
// 2 - 
// 3 - 
// 4 - 
						// The Preprocessor Directives: (Header Files) 							
#include <iostream> 	// Standard Template Library class  -  Used for cout, cin, cerr, printf  ( That is the  reason for brackets < > )
#include <iomanip>		// Required to utilize parameterized stream manipulator ie. calling setprecision(3) & fixed functions
#include <fstream>		// Inherited from 'basic_fstream' for file I/O - Defines Data types: ofstream, ifstream, and fstream
#include <sstream>		// Used when interfacing strings by reading from and writing to files
#include <string>		// Use the s suffix for literal strings 'string' class - required as a new way of using strings, non char sequence
#include <windows.h>	// Required to implement adjusting the Consoles window size and position - CAUSES PROBLEMS with <limits>
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
#include <limits>		// Contains clasees for defining numerical data type limits on each computer platform
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

// ..............................................   Function Prototype Declaration Code   ..............................................

void exitPrgm();								// Use this function as a optional default to terminate the program


int main()										// Function main() begins program execution - Entry point for the program
{
	
	cout << "\n\n >>>>>>>>>>>>>>>>>>>>>>>>>>>>   Main Code Execution   <<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	cout << "                    Simple Inefficient Bubble Sort of an Array        \n\n" << endl;

	const int arraySize = 10;					// Initialize the size of the array and then its content
	int arrayOne[arraySize] = { 45, 6, 4, 8, 10, 12, 89, 68, 2, 37 };
	int tempHold;								// Temporary location holds element value while swapping values of two arrays indexed locations

	cout << "\ Contents of the array before sorting: ";
	cout << "{ ";
	for (int i = 0; i < arraySize-1; i++)
	{
		cout << arrayOne[i] << ", ";
	}
	cout << arrayOne[arraySize-1]
		 << " }" << endl;

	cout << " Sorting array by bubble sort technique in progress . . . . . " << endl;
	int pass = 0;								// Loop to control the number of passes
	do {										// Make array (size-1) passes for bubble to rise to top (begginning of array)
		for (int i = 0; i < (arraySize - 1); i++)
		{
			if (arrayOne[i] > arrayOne[i + 1])
			{
				tempHold = arrayOne[i];
				arrayOne[i] = arrayOne[i + 1];
				arrayOne[i + 1] = tempHold;
			}
		}
		pass++;
	} while (pass != arraySize - 1);


	cout << "\ Contents of the array after sorting:  ";
	cout << "{ ";
	for (int i = 0; i < arraySize - 1; i++)
	{
		cout << arrayOne[i] << ", ";
	}
	cout << arrayOne[arraySize - 1]
		 << " }" << endl;
	
	exitPrgm();					// Option function member to terminate program
	system("pause");			// Some compilers do not recognize this statement
	return 0; 					// Indicates successful termination
}								// End of main

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