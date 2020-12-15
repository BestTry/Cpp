// Poiinters_Smart_Unique.cpp : Demonstation of using the Smart Pointer 'unique_ptr'
// Pulled this example code from 'C++ From Control Structures through Objects' - by Tony Gaddis Ninth Edition
// 
					
						// Below is what is known as the Preprocessor Directives - in this Header section
						// Under Visual Studio 17  -  replace #include "stdafx.h" with #include "pch.h" to provide same library support						
						// The Preprocessor Directives: (Header Files) 							
#include <iostream> 	// Part of the standard library  -  Used for cout, cin, cerr  ( That is the  reason for brackets < > )
#include <string>		// Within Standard Library - 'string' class - required as a new way of using strings as opposed the old char sequence
#include <ctime>		// Required to implement date and time functions
#include <windows.h>	// Required to implement date and time functions - Some IDE / Complilers do not accept this header file
#include <typeinfo>		// Necessary for imlementing the typeid() function 
#include <memory>		// Necessary when using smart pointers. Syntax: unique_ptr<int> ptrName( new int );
#include <array>		// Necessary when using the array class i.e array<arrType, size>
#include <vector>		// Support vector operations - See inputDate
						// Before compiling symbol '#' indicates a preprocessing contents of  
						// the input/output stream header file iostream.  This file must be 
						// included with any keyboard input or console screen output
						// Functions within the standard library are as follows:
						// Since classes below are part of C++ stadard library < > are placed around them
#include <cmath>		// Enables the use of the "pow" function with the math library
#include <thread>		// std::this_thread::sleep_for(std::chrono::seconds(XX) << endl;
#include <chrono>		// std::chrono::seconds(XX)
#include <iomanip>		// Required to utilize parameterized stream manipulator ie. calling setprecision(3) & fixed functions
#include <cstdlib>		// Required to implement the rand() & srand() function.  Also, needed to execute the 'exit()' function.
#include <ctime>		// Required to implement the time(0) function providing a number to seed rand() using srand(): srand( time( 0 )  << endl;
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
#include <windows.h>	// #####

// ..............................................   Function Prototype Declaration Code   ..............................................
// Global variables, Function protoypes are placed / declared here before main .... (if the implementation code is not placed here first)

void exitPrgm();								// Use this function as a optional default to terminate the program


int main()									// Function tmain(...) begins program execution - Entry point for the program
{
											// ##############################################################
											// Modify position and size of Console Application Window
	HWND console = GetConsoleWindow();		// Get the console handle
	RECT r;									// Stores the console's current dimensions
	GetWindowRect(console, &r);				// MoveWindow(window_handle, x, y, width, height, redraw_window);
	MoveWindow(console, 1400, 500, 900, 500, true);
											// ###############################################################

	cout << "\n\n >>>>>>>>>>>>>>>>>>>>>>>>>>>>   Main Code Execution   <<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	cout << "            Resident / Location -  void main() code is orchestrated here              " << endl;

											// Define the unique smart pointer to be dynamically pointing to int
	unique_ptr<int> ptrToInt(new int);		// Both 'int' syntaxes determin the type of pointer contents
	*ptrToInt = 999;						// Assign 999 to dynamically allocated int
	cout << "\n\n\n                  This code demonstrates the unique_ptr" << endl;
	cout << "\n The value (999) contained in the pointer 'prtToInt is: " << *ptrToInt << endl << endl;
											// No statement to free up mememory because it is down automatically.

	cout << "\n\n                 This code demonstrates using the 'unique_ptr to dynamically allocate array of integers "<< endl;
	int max;								// Maximum size of the array to be created
	cout << " How many numbers do you want to enter ?  Enter the number here: ";
	cin >> max;								// Maximum size of the array about to be created
											// unique_ptr 'ptrToArray' is created pointing to array of intergers to be filled
	unique_ptr<int[]> ptrToArray( new int[max] ); 
	for (int index = 0; index < max; index++)
	{
		cout << "Enter an interger: "; \
		cin >> ptrToArray[index];			// Tried the syntax;  *(ptrToArray + index); and compiler objects
	}

	cout << "\n  The numbers you entered are listed here: " << endl;
	for (int index = 0; index < max; index++)
	{
		cout << "  Number " << (index + 1) << " -> ";
		cout << ptrToArray[index] << endl;			// Tried the syntax;  *(ptrToArray + index); and compiler objects
	}
	cout << endl << endl;






	exitPrgm();					// Option function member to terminate program
	system("pause");			// Some compilers do not recognize this statement
	return 0; 					// Indicates successful termination
}								// End of main

// .............................................   Function Code Definition Implementation  .................................................
//    When functional coded is declared above before the main coding section use this area for functional code implementation

void exitPrgm()
{
	cout << "\n                  >>>>>>>>>>  Program has Terminated  <<<<<<<<<< " << endl;
	cout << " \n\n\n " << endl;
	exit(0);					// Terminate running program from anywhere it is called:
}

/*

|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|
012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
		  |         |         |         |         |         |         |         |         |         |         |         |         |         |
00		  10        20        30        40        50        60        70        80        90		00		  10        20        30        40

*/