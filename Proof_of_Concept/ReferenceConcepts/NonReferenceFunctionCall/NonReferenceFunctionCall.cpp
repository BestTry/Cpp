// NonReferenceCall.cpp :  Demo this code here to show how 'Declaration' 'Prototype' function statements of variables 
// are passed to the function implementation depending on weather the funtion includes the default value or not.
//
// Description of Program .............  Boiler Plate Template  .............................
// ..........................................................................................
// ..........................................................................................
// ..........................................................................................
//
		
						// Below is what is known as the Preprocessor Directives - in this Header section
						// Under Visual Studio 17  -  replace #include "stdafx.h" with #include "pch.h" to provide same library support						
						// The Preprocessor Directives: (Header Files) 							
#include <iostream> 	// Part of the standard library  -  Used for cout, cin, cerr  ( That is the  reason for brackets < > )

#include <windows.h>	// Required to implement date and time functions - Some IDE / Complilers do not accept this header file

						// The double colons operator '::' is defined as the "Scope Resolution Operator"
using std::cout;		// Console output
using std::cin;			// Console input
using std::endl;		// End of Line - Clears output buffer and terminates with a new-line character

using namespace std;	// Common practice to implement the "std" namespace as it contains multiple supporting useful functions

						// ##### Necessary for the 'GetConsoleWindow()' function below to work! - on Windows 2000 and later
#define _win32_winnt 0x0500
#include <windows.h>	// #####

// ..............................................   Function Prototype Declaration Code   ..............................................
// Global variables, Function protoypes are placed / declared here before main .... (if the implementation code is not placed here first)

void  test(int = 2, int = 4, int = 9);		// Note that these values are initialization arguments and a function call may or may not 
											// use the default values.  If the function call uses its own arguments, the overwrite the
											// default values found here.

int main()									// Function tmain(...) begins program execution - Entry point for the program
{
	/*
											// ##############################################################
											// Modify position and size of Console Application Window
	HWND console = GetConsoleWindow();		// Get the console handle
	RECT r;									// Stores the console's current dimensions
	GetWindowRect(console, &r);				// MoveWindow(window_handle, x, y, width, height, redraw_window);
	MoveWindow(console, 1400, 500, 1600, 1500, TRUE);
											// ###############################################################
	*/

	cout << "\n\n >>>>>>>>>>>>>>>>>>>>>>>>>>   Main Code Execution   <<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	cout << "          Resident / Location -  void main() code is orchestrated here              " << endl;


	std::cout << "Hello World!\n";

	test();
	test(5);
	test(5, 10);
	test(5, 10, 20);


	system("pause");			// Some compilers do not recognize this statement
	return 0; 					// Indicates successful termination
}								// End of main

// ............................................   Function Code Definition Implementation  .............................................
//    When functional coded is declared above before the main coding section use this area for functional code implementation

void test(int first, int second, int third)
{
	first += 3;
	second += 1;
	third *= 2;
	std::cout << first << "  " << second << "  " << third << endl;
}

/*

|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|
012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
		  |         |         |         |         |         |         |         |         |         |         |         |         |         |
00		  10        20        30        40        50        60        70        80        90		00		  10        20        30        40

*/