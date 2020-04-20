// Enums_StronglyTyped.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Description of Program: Shows the way to code enums in accordance with the latest C++ standards using "class" as enum type

					// Below is what is known as the Preprocessor Directives 
					// Under Visual Studio 17  -  replace #include "stdafx.h" with #include "pch.h" to provide same library support						
					// The Preprocessor Directives: 							
					// #include "pch.h"		// Part of the solution file that will be compiled: Standard AFX.H; This MUST BE 1st line of any code file
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
#include <windows.h>    // #####

						// 'Strongly Typed enums' declarations Or an 'enum class' - In S.T. enums, class apprears after the word enum
						// Strongly Typed enums may have types other than intergers i.e. enum class : Day char { Monday, Tuesday, Wednesdaa ... }
enum class Dogs { Collie, Dashound, Border_Collie, BullDog, Shepherd, Labador_Retreiver, Golden_Retreiver };
enum class Autos { Dodge, Buick, Subaro, Chevy, Toyota, VW };



int main()									// Function tmain(...) begins program execution - Entry point for the program
{											// ##############################################################
											// Modify position and size of Console Application Window
	HWND console = GetConsoleWindow();		// Get the console handle
	RECT r;									// Stores the console's current dimensions
	GetWindowRect(console, &r);				// MoveWindow(window_handle, x, y, width, height, redraw_window);											
	MoveWindow(console, 1400, 500, 400, 500, true);
											// ###############################################################

// Code steps here within main block of code
// Using strongly type enums - must prefix enumerator with name of the enum, followed by the '::' operator
	Dogs myPet = Dogs::Shepherd;			// The variable 'myPet' is a enum with a value of Shepherd
	Autos myCar = Autos::Toyota;			// The variable 'myCar' is a enum with a value of Toyota







	system("pause");
	return 0; 					// Indicates successful termination
};								// End of main

