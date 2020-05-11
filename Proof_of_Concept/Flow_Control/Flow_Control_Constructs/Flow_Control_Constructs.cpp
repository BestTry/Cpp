// Flow_Control_Constructs.cpp :  Pulled from O'Reilly Learnind and Training web site:  C++ Intermediate by Integrity Training - Peter Thorsteinson 
// Video clip titled: "Control Statements"
// 
// Description of Program .............  Boiler Plate Template  .............................
// ..........................................................................................
// ..........................................................................................
// ..........................................................................................
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


int main()									// Function tmain(...) begins program execution - Entry point for the program
{
	// ##############################################################
	// Modify position and size of Console Application Window
	HWND console = GetConsoleWindow();		// Get the console handle
	RECT r;									// Stores the console's current dimensions
	GetWindowRect(console, &r);				// MoveWindow(window_handle, x, y, width, height, redraw_window);
	MoveWindow(console, 1400, 500, 800, 900, true);
	// ###############################################################

	cout << "\n\n >>>>>>>>>>>>>>>>>>>>>>>>>>>>   Main Code Execution   <<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	cout << "                     Control Tools and Statements            " << endl;
	// Compound Statements inclosed within a code block encased by braces {} are block scoped
	int x = 20;   int y = 40;				// Intializing variables x and y These variables are not same as inside {}											
											// Code inside {} braces are not visible to other parts outside of braces!
	cout << " ***** Compound Statement *****   " << endl;
	{ int x = 10; int y = 100; cout << " x = " << x << ",  y = " << y << " values assigned within code block " << endl; }
	cout << " Previous x & y values were assigned previous to \n";
	cout << " and outside of the block, they can be seen here: " << endl;
	cout << " x = " << x << ",  y = " << y << " values are not modifed by code block" << endl << endl;

	// ***** Simple 'if statement'
	cout << " The 'if' Statement Topic Demo " << endl;
	if (x == 20 && y < 100) {
		cout << " x is equal to 20 and y is less than 100 " << endl << endl;
	}

	// ***** The 'if - else' statement											
	cout << "\n The 'if - else statement Topic Demo " << endl;
	if (x > 20) {
		cout << " x is greater than 20 " << endl << endl;
	}
	else {
		cout << " x is NOT greater than 20 " << endl << endl;
	}

	// ***** The 'chanined if' statement		
	cout << "\n The 'chained if' Statement Topic Demo " << endl;
	if (x < 20) {
		cout << " x is less than 20 " << endl << endl;
	}
	else if (x > 20) {
		cout << " x is greater than 20 " << endl << endl;
	}
	else {
		cout << " x is NOT greater or less than 20, ";
		cout << " therefore x must be equal to 20" << endl << endl;
	}

	// ***** The 'nested if' statement
	cout << "\n The 'nested if' Statement Topic Demo " << endl;
	if (x == 20)
	{
		cout << " x equals 20";
		if (y == 40)
		{
			cout << " and y is equal to 40" << endl << endl;
		}
		else
		{
			cout << " and y is NOT equal to 40" << endl << endl;
		}
	}
	else
	{
		cout << " x is NOT equal to 20";
		if (y == 40)
		{
			cout << " and y is equal to 40" << endl << endl;
		}
		else
		{
			cout << " and y is NOT equal to 40" << endl << endl;
		}
	}

	// ***** The 'switch' statement
	cout << "\n The 'switch' Statement Topic Demo " << endl;
	switch (x)
	{
	case 20:
		cout << " x is equal to 20 " << endl << endl;
		break;								// Important the 'break' keyword is required!!!
	case 25:								// Otherwise the next statement WILL be executed!!!
		cout << " x is equal to 25 " << endl << endl;
		break;
	default:
		cout << " x is NOT 20 or 25 " << endl << endl;
	}

	int n = 5;
	// ***** Looping Constructs  - Repeats blocks of statements
	// ***** The 'while loop' statement
	cout << " The 'while loop' statement" << endl;
	cout << " The integer variable n is: ";
	while (n > 0) {							// May execute zero to infinit amount of times
		cout << n << ",  ";
		n--;
	}
	cout << endl << endl;

	n = 7;
	// ***** The 'do-while loop' statement
	cout << " The 'do-while loop' statement" << endl;
	cout << " The integer variable n is: ";
	do {									// Always executes at least once
		cout << n << ",  ";
		n--;
	} while (n > 0);
	cout << endl << endl;

	// ***** The 'for loop' statement
	cout << " The 'for loop' statement" << endl;
	cout << " The integer variable n is: ";
	for (int n = 1; n <= 10; n++) {
		if (n % 2 == 0) {
			cout << n << ",  ";
		}
	}
	cout << endl << endl;

	// ***** The 'break' keyword
	cout << " The 'for loop' statement" << endl;
	cout << " The integer variable n is: ";
	for (int n = 1; true; n++) {			// Infinite Loop! so far: boolean condition always true
		if (n % 2 == 0) {
			cout << n << ",  ";
		}
		if (n > 10) break;
	}
	cout << endl << endl;

	// ***** The 'continue' statement
	cout << " The 'for loop' statement" << endl;
	cout << " The integer variable n is: ";
	for (int n = 1; n <= 10; n++) {
		if (n % 2 == 1) continue;			// Skip over odd intergers for display
		{
			cout << n << "  ";				// Only output even integers
		}
	}
	cout << endl << endl;

	int i;
	// ***** The 'goto keyword' in nested for loops
	cout << " The 'goto keyword' in nested for loops" << endl;
	for (i = 0; i < 5; i++)
	{
		cout << " Within outer loop: " << i << endl;
		for (int j = 0; j < 2; j++)
		{
			cout << " Within inner loop: " << j << endl;
			if (i == 3) goto theTarget;
		}
	}										// Statement below should never execute
	cout << " Loop completed normally, 'i' equals: " << i << endl << endl;
theTarget:									// Target label
	cout << " Jumped to this statement via the goto and i = " << i << endl << endl;


	// ***** The 'Range-based for loop' statement
	// Note: I tried the same statement but got a compiled error 
	// when using an array instead of a vector
	cout << " The 'Range-based For Loop' Statement" << endl;
	vector<int> intVect{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for (auto& y : intVect) {				// range-based for loop over a vector
		cout << y << ",  ";
	}
	cout << endl << endl;


	cout << " Do same but use value copy instead of reference _ Not Preffered " << endl;
	for (int y : intVect) {					// access by value using a copy declared as a specific type.  not preferred. use reference '&'
		cout << y << " ";					// access by value using a copy declared as a specific type.
	}										// not preferred.
	cout << endl;


	for (const auto& y : intVect) {			// When no modification is needed
		cout << y << ",  ";
	}
	cout << endl << endl;

	// Using Push Back to populate vector
	vector<int> newVect;					// Empty vector - Size 0 at this point
	for (int i = 0; i < 17; i++) {
		newVect.push_back(i * 2);			// Populate empty vector doubling element contents
	}

	cout << " Demonstrating Push Back (Adding content to vector) " << endl;
	for (auto& vElem : newVect) {			// Display contents of vector		
		cout << vElem << ",  ";				// In 'For-Each loop auto pre-determins 	
	}										// the size of the vector 
	cout << endl << endl;


	exitPrgm();					// Option function member to terminate program
	// system("pause");			// Some compilers do not recognize this statement
	return 0; 					// Indicates successful termination
}								// End of main

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