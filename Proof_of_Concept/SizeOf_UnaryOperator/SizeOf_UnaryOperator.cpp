// SizeOfUnaryOperator.cpp  Unary operator to return the size of data types, mostly used to determine size of an array
//	
						// Below is what is known as the Preprocessor Directives 
						// Under Visual Studio 17  -  replace #include "stdafx.h" with #include "pch.h" to provide same library support						
						// The Preprocessor Directives: 							

#include <iostream> 	// Part of the standard library  -  Used for cout, cin, cerr  ( That is the  reason for brackets < > )
#include <string>		// Part of the standard library  - 'string' class is req to be included as the new way of using strings as opposed the old char sequence
#include <ctime>		// Required to implement date and time functions
#include <windows.h>	// Required to implement date and time functions
#include <iomanip>
#include <vector>		// Support vector operations - See inputDate
						// Before compiling symbol '#' indicates a preprocessing contents of  
						// the input/output stream header file iostream.  This file must be 
						// included with any keyboard input or console screen output

						// The double colons is defined as the "Scope Resolution Operator"
using std::cout;		// Console output
using std::cin;			// Console input
using std::endl;		// End of Line - Clears output buffer and terminates with a new-line character
using std::fixed;		// Both 'fixed' & 'showpoint' are nonparamatized stream manipulators that Do Not require the <iomanip> header file
using std::pow;			// Standard Library Function pow(x,y) definded as x raised to the y power
using std::setw;		// Assure #include <iomanip> is included which requires a parameterized stream manipulator
using std::setprecision;// setprecision(2)indicates a double variable value should be printed with 2 digits to the right of the decimal point

using namespace std;

// ##### Necessary for the getconsolewindow() function to work! - works for  running this program on windows 2000 or higher
#define _win32_winnt 0x0500					
#include <windows.h>    		// #####

											// Declaring the sizeOfTyp function (Prototype)
double getSize(double *);					// Prototype -  Function takes a pointer as an argument

int main()									// Function tmain(...) begins program execution - Entry point for the program
{											// ##############################################################
											// Modify position and size of Console Application Window
	HWND console = GetConsoleWindow();		// Get the console handle
	RECT r;									// Stores the console's current dimensions
	GetWindowRect(console, &r);				// MoveWindow(window_handle, x, y, width, height, redraw_window);											
	MoveWindow(console, 1400, 500, 900, 300, true);
	// ###############################################################

	// Code steps here within main block of code
	//
	//
	char c;
	short s;
	int i;
	long l;
	float f;
	double d;
	long double ld;
	int array[20];
	int* ptr = array;						// Do not use '&array' syntax because array variable is already a pointer by default
		
	cout << " The 'sizeOf()' operator returns the size of the object in bytes!" << endl;
	cout									// I like the way I formated this list of rows to the display using 'cout'
		<< "\n\t  The size of c is: " << sizeof(c)
		<< "\n\t  The size of s is: " << sizeof(s)
		<< "\n\t  The size of i is: " << sizeof(i)
		<< "\n\t  The size of l is: " << sizeof(l)
		<< "\n\t  The size of f is: " << sizeof(f)
		<< "\n\t  The size of d is: " << sizeof(d)
		<< "\n\t  The size of ld is: " << sizeof(ld)
		<< "\n\t  The size of array is: " << sizeof(array)
		<< "\n\t  The size of ptr is: " << sizeof(ptr) 
		<< endl;

	double arrayOf30[30];					// Notice that the name arrayOf30 standing alone is a Pointer to the first element[0]
	cout << "\n The size of the array 'arrayOf30' is: " << getSize(arrayOf30) << " Since it is the name of the array or pointer to it" << endl;

	system("pause");
	return 0; 					// Indicates successful termination
}								// End of main
								//



								// Function Definition
double getSize(double *ptr)		// Return size of contents of pointer
{
	return sizeof(ptr);
}


/*

|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|
01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
		  |         |         |         |         |         |         |         |         |
		  10        20        30        40        50        60        70        80        90
*/