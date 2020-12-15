// ReferenceArgumentSwap.cpp : 
// Pointers_Examples.cpp : Console Application. Console applications are the simplest using text for input / output
// Code Example lifted from C++ Tutorial by O'Reilly - C++ 11 Intermediate by Peter Thorsteinson			?????????
//
					// Below is what is known as the Preprocessor Directives 
					// Under Visual Studio 17  -  replace #include "stdafx.h" with #include "pch.h" to provide same library support						
					// The Preprocessor Directives: 							
#include <iostream> 	// Part of the standard library  -  Used for cout, cin, cerr  ( That is the  reason for brackets < > )
#include <string>		// Part of the standard library  - 'string' class is req to be included as the new way of using strings as opposed the old char sequence
#include <ctime>		// Required to implement date and time functions
#include <windows.h>	// Required to implement date and time functions
#include <typeinfo>		// Necessary for imlementing the typeid() function   
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
#include <windows.h>	// #####

// .......................................................   Function Prototype Declaration Code   ........................................................
/*
	References are similar to Pointers    Differences between references (alias) and pointers:
	1.	References cannot be NULL or invalid. A reference ALWAYS refers to an object in memory (alias).
		Once a reference is initialized (required) to an object, it cannot be changed to or refered to another object.
	2. 	Pointers can be assigned to point to another object addresss at any time.
	3. 	A reference must be initialized when it is created, but pointers can re-assigned at any time.
	4.  There is no reference_to_member in C++
	5. 	There is pointer_to_member in C++
	6.  A reference refers to another variable.  So you can consider it a alias to the original variable
*/
// Generic version of the swap function below
// The '&' declares that the variable a and b are references of type T
/*	template <class T> void swap(T& a, T& b)// 'T' signafies a generic type & takes references of a and b to type T
	{										// Variables a & b are references they are not  to be dereferenced
		T c(a);								// References do not to be deferenced; They are already deferenced
		a = b;								// References are aliases of another variable at the same address
		b = c;
	}
*/
																
	void swap(char& a, char& b)				// Simplier alternate version - Easier to understand - straight forward
	{										// Here a & b are references to char type variables
		char c(a);							// Here variables 'a' and 'b' are aliases to the original variables 
		a = b;								// of the calling function. Any change to these alias variables
		b = c;								// will reflect the change to the values of the origina variables
	}										// Do not dereference as it is already dereferenced.  They are aliases
											// They are not addresses that need 'indirection' or 'dereferencing'

	int& badFunc()							// This badFunc is returning a reference to a integer int
	{										// No - Risky
		int x = 10;							// Compiler give Warning Message! " returning address of local variable or temporary x "
		return x;							
	}
	
	void func(int param)
	{}

int main()									// Function main(...) begins program execution - Entry point for the program
{
											// ##############################################################
											// Modify position and size of Console Application Window
	HWND console = GetConsoleWindow();		// Get the console handle
	RECT r;									// Stores the console's current dimensions
	GetWindowRect(console, &r);				// MoveWindow(window_handle, x, y, width, height, redraw_window);											
	MoveWindow(console, 1400, 500, 900, 300, TRUE);
											// ###############################################################

	
	char a = 'A'; 
	char b = 'B';							// The '::' is the global scope resolution operator
	cout << " Before the function swap call, values of a and b are shown here: " << endl;
	cout << " a = " << a << "  b = " << b << endl;
	:: swap(a, b);							// '::' refers to swap in THIS code & not in 'std::namespace', namespace has a swap() func
	cout << " After the function swap call, values of a and b are shown here: " << endl;
	cout << " a = " << a << "  b = " << b << endl;

	int& result = badFunc();				// Bad function because x is place on the stack and not heap and is collobbered
	cout << result << endl;					// The result variable is a reference to a local variable 'x' in the badFunc()
	func(0);								// So the x a local variable may get clobbared and then 'result' has a erroneous value
	cout << result << endl;					// Function func(0) clobarred the x ++ result variables!
	cout << " The variable 'result' which is a reference to a local variable x in the badFunc() was clobberd " << endl << endl;

	cout << " Assigning References " << endl;
											// Any time a reference is declared, It must be assigned or initialized
	int x = 5, y = 15; 						// Declaring x and y values
	int & refX = x; 						// Declaring reference refX which is the reference to x (refX must be assigned when declared!)
	cout << " x = " << x << "  y = " << y << "  refX = " << refX << endl;
	refX = y; 								// Assigns value in y to value in x (Does not change the reference) (Does'nt change to a ref to y)
	cout << " x = " << x << "  y = " << y << "  refX = " << refX << endl;
	
	cout << " References and references to constants " << endl;
	int x1 = 1, x2 = 2;
	int & reference_to_int = x1;
	int const & reference_to_const_int = x1;
											// reference_to_const_int = 22; No! Illegal
											// reference_to_int = 22;		Ok (Non constant reference)
	cout << endl;
	
	
	system("pause");
	return 0; 					// Indicates successful termination
}								// End of main



