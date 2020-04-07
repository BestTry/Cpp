// Typedefs.cpp :  Code Example lifted from O'Reilly Tutorial on Type Definitions - Subject Matter TypeDefs
//
// Description of Program Code demonstrates various examples of Typedef assignments
// Typedefs are used as replacements for long key words and to make the code more readible
// typedef keyword stands for type definition create synonyms or aliases for existing / new types
// ..............................................................................................
//
						// Below is what is known as the Preprocessor Directives 
						// Under Visual Studio 17  -  replace #include "stdafx.h" with #include "pch.h" to provide same library support						
						// The Preprocessor Directives: 							

#include <iostream> 	// Part of the standard library  -  Used for cout, cin, cerr  ( That is the  reason for brackets < > )
#include <string>		// Part of the standard library  - 'string' class is req to be included as the new way of using strings as opposed the old char sequence
#include <ctime>		// Required to implement date and time functions
#include <windows.h>	// Required to implement date and time functions
#include <vector>		// Support vector operations - See inputDate
#include <typeinfo>		// Use to facilitate the typeid()function and corresponding *.name() function and execution
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
#include <windows.h>    // #####

								// .......................................................   Function Prototype Declaration Code   ........................................................
void functionExample(void);		// Function prototype - In C++ every funtion requires a prototype placed before/outside the main block or placed in the "projectName.h" file 
								//  Must then use #include "prjName.h'  Placing the functions in Declaration format here and then defining them with implementation before 'main' 
								//satisfies both the definition & declaration requirements placed in the correspond " *.h " and " *.cpp " files


int main()									// Function tmain(...) begins program execution - Entry point for the program
{
											// ##############################################################
											// Modify position and size of Console Application Window
	HWND console = GetConsoleWindow();		// Get the console handle
	RECT r;									// Stores the console's current dimensions
	GetWindowRect(console, &r);				// MoveWindow(window_handle, x, y, width, height, redraw_window);											
	MoveWindow(console, 1400, 500, 500, 500, true);
											// ###############################################################

											// Simple typedef:  typedef keyword, data type, and alias name or synonym name
	typedef unsigned long ulong;			// Defined the type definition of a unsigned long interger named -> "ulong"
	cout << " The type definition ulong is a type of: " << typeid(ulong).name() <<  endl << endl;											
	unsigned long td1;						// td1 and td2 have the same type (unsigned long)
	ulong td2;								// Used the previosly created type definition of 'ulong' to declare 'td2'
	cout << " The type definition td1 is a type of: " << typeid(td1).name() <<  endl << endl;
	cout << " The type definition td2 is a type of; " << typeid(td2).name() <<  endl << endl;
		

											// Complicated typedefs
	typedef int intTyp, * intPtr, arrTyp[4];// Three separate variable types defined by integer 'int'
	intTyp x = 42;							// Longer definition than original 'int' but more readable
	intTyp *xPtr = &x;

	cout << " The type definition intTyp is a type of: " << typeid(intTyp).name() <<  endl;
	cout << " The intTyp variable x has a value of: " << x << endl << endl;

	cout << " The type definition xPtr is a type of: " << typeid(xPtr).name() <<  endl ;
	cout << " The intTyp pointer xPtr's content has a value of: " << *xPtr << endl << endl;

	/*  ?????  I do not understand the following code  ?????  */  // "    for (auto& el : arr1)   " ??????

	int arr1[] = { 1, 2, 4, 8 };			// An array of size 4 of interger types
	cout << " The type definition arr1 is an array type of " << typeid(arr1).name() <<  endl;
		for (auto& el : arr1)
		{
			cout << arr1 << endl;
		}
	cout << endl;

	arrTyp arr2 = { 3, 5, 7, 9 };			// An array of size 4 of interger types defined typeDef 'arrTyp'
	cout << " The type definition arr2 is an array type of " << typeid(arr2).name() <<  endl;
		for (auto& el : arr2)
		{
			cout << arr2 << endl;
		}
	cout << endl;

	system("pause");
	return 0; 					// Indicates successful termination
}								// End of main

								// .......................................................   Function Description Code   ................................................................


void functionExample(void)		// Function place holder outside of the main() included in this template
{
	cout << "Could 'return 0' if 'int' was inserted above as return type instead of 'void' " << endl;
}



// TODO:  To find TODOs ...  Go to >   View  >   Task List      TODO:TODO:TODO:TODO:TODO:TODO:TODO:TODO:TODO:TODO:TODO:TODO:





/*

|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|
01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
		  |         |         |         |         |         |         |         |         |
		  10        20        30        40        50        60        70        80        90
*/