// ArrayStatic.cpp : Code Example lifted from Dietel "How to Program" 4th edition, Exercise / or  / Textbook Example - Chapter 04 - Subject Matter 
//
// Description of Program ...................................................................
// Program demonstrates the differences betweed a regular standard array and a static array
// Static array remembers its values once execution leaves the function. So that the next 
// time the function is entered modification is based on the last values that it contained
// ..........................................................................................
//
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

void staticArrayInit(void);					// The static array will retain its values when exiting the funciton call
void automaticArrayInit(void);				// The standard array will be initialized each time its function is called

void exitPrgm();							// Use this function as a optional default to terminate the program


int main()									// Function main() begins program execution - Entry point for the program
{
	cout << "\n\n >>>>>>>>>>>>>>>>>>>>>>>>>>>>   Main Code Execution   <<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	cout << "                  Demontrating a Static Local Array      \n\n" << endl;

	cout << "First call to each funtion:\n";
	staticArrayInit();
	automaticArrayInit();

	cout << "\n\n Second call to each function:\n";
	staticArrayInit();
	automaticArrayInit();
	cout << endl;


	
	exitPrgm();							// Option function member to terminate program
	system("pause");					// Some compilers do not recognize this statement
	return 0; 							// Indicates successful termination
}										// End of main

// .............................................   Function Code Definition Implementation  .................................................
//   

							
void staticArrayInit(void)				// Function to demostrate a static local array
{
										// Initialize elements to 0 first time function is called
	static int arrayOne[3];
	cout << "\n Values on entering staticArrayInit:\n";

										// Output contents of arrayOne which should be all zeros upon intialization
	for (int i = 0; i < 3; i++)
		cout << "arrayOne[" << i << "] = " << arrayOne[i] << " ";

	cout << "\nValues on exiting staticArrayInit:\n";

										// Modify and output contents of arrayOne all in one statement
	for (int j = 0; j < 3; j++)
		cout << "arrayOne[" << j << "] = " << (arrayOne[j] += 5) << " ";

}										// end function staticArrayInit


										// Function to demostrate an automatic local array
void automaticArrayInit(void)
{
										// Initialize elements each time function is called
	int arrayTwo[3] = { 1, 2, 3 };
	cout << "\nValues on entering automaticArrayInit:\n";

										// Output contents of arrayTwo
	for (int i = 0; i < 3; i++)
		cout << "arrayTwo[" << i << "] = " << arrayTwo[i] << " ";

	cout << "\nValues on exiting automaticArrayInit:\n";

										// M odify and output contents of arrayOne all in one statement
	for (int j = 0; j < 3; j++)
		cout << "arrayTwo[" << j << "] = " << (arrayTwo[j] += 5) << " ";

}							// end function automaticArrayInit




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
