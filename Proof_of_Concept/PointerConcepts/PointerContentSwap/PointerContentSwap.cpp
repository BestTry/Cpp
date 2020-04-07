// PointerContentSwap.cpp: Main() is a thread on the stack that defines the entry point for this code
// Code Example copied from O'Reilly - Introduction to Pointers within the course C++ Intermediate taught by Integrity Training - Through Safari Books on Line
//
// Description of Program ...... Swap the contents of two memory locations using reference/pointers
// ..........................................................................................
// 
						// Below is what is known as the Preprocessor Directives 
						// Under Visual Studio 17  -  replace #include "stdafx.h" with #include "pch.h" to provide same library support						
						// The Preprocessor Directives: 	
//
#include <iostream> 	// Part of the standard library  -  Used for cout, cin, cerr  ( That is the  reason for brackets < > )
#include <string>		// Part of the standard library  - 'string' class is req to be included as the new way of using strings as opposed the old char sequence
#include <ctime>		// Required to implement date and time functions
#include <windows.h>	// Required to implement date and time functions
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
#include <cstdlib>		// Required to implement the rand() function; Contains function prototype for the rand()  & srand() function
#include <ctime>		// Required to implement the time(0) function providing a number to seed rand() using srand(): srand( time( 0 )  << endl;
						// Arguement (0) yields an interger value of the calendar in seconds

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

								// .......................................................   Function Prototype Declaration Code   ........................................................

void swap(char*, char*);		// Function takes pointers to character values
int* badFunctionCode();
void functionAny();


int main()									// Function tmain(...) begins program execution - Entry point for the program
{
	// ##############################################################
	// Modify position and size of Console Application Window
	HWND console = GetConsoleWindow();		// Get the console handle
	RECT r;									// Stores the console's current dimensions
	GetWindowRect(console, &r);				// MoveWindow(window_handle, x, y, width, height, redraw_window);											
	MoveWindow(console, 1400, 500, 1600, 1500, TRUE);
	// ###############################################################



// Code steps here within main block of code
	cout << "\n\n >>>>>>>>>>>>>>>>>>>>>>>>>>   Sample Program   <<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;

	char a = 'A';
	char b = 'B';
	cout << "character a = " << a << " and " << "character b = " << b << endl;
	swap(&a, &b);				// Use the addresses of variables a and b to swap their contents
	cout << " After calling the 'swap() function, variables a and b values are: " << endl;
	cout << "character a = " << a << " and " << "character b = " << b << endl;

	int* ptrResult = badFunctionCode();
	cout << " Pointer contents is: " << *ptrResult << endl;	// Address of variable is returned .... but it is on the stack
	functionAny(); cout << " Bad function called " << endl;	// Calling functionAny() will clobber addr contents placed on thread stack by badFunctionCode
	cout << " Pointer contents is: " << *ptrResult << endl;	// The address contents has been collebber by the previous function: functionAny() call 
	cout << " The address contents has been clobbered by the previous bad function call \n" << endl;



	system("pause");
	return 0; 					// Indicates successful termination
}								// End of main

								// .......................................................   Function Description Code   ................................................................


	// The following code is the proper way that a Swap function should be coded using generic functions;  'T' is a place holder for a type
	// But the code following this proper way is used to better understand the concept of pointers:

	// template <class T> void swap(T* ptrA, T* ptrB)
	// { T c(*ptrA);
	//   *ptrA = *ptrB;
	//   *ptrB = c;
	// }

						// The following simpler code is shown for purpose of understanding pointers and references concept 
						// Swapping the characters of the contents of pointers ptrA and ptrB using their addresses to do so
void swap(char* ptrA, char* ptrB)
{
	cout << " Swap function swaps the contents of two pointers of characters " << endl;
	char c(*ptrA);  	// Equivalent of char c = *ptrA;
	*ptrA = *ptrB;		// Using the dereference operator '*' to swap the contents at those pointer addresses
	*ptrB = c;
}

// The following example is Dangerous code and should not be used as the address 
// returned is on the stack and it will be colobbered by a subsequent function calling

int* badFunctionCode()	// Returning a function of a local variable is risky because
{						// this address will probably overwritten when the next function is called
	int x = 10;			// Address will only be on the thread stack for a limited unknown time 
	return &x;			// No! - The returned address contents will be clobbered with a subsequent function call	
}						// Warning message from Visual Studio: Returning address of local variable or temprary x
						// The x variable is a temporary variable place on the stack not the heap

void functionAny()
{	}


/*

|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|
01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
		  |         |         |         |         |         |         |         |         |
		  10        20        30        40        50        60        70        80        90
*/