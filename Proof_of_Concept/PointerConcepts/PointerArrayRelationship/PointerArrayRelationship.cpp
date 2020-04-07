// PointersArrayRelation.cpp : Code Example lifted from Dietel "How to Program" 4th edition, Exercise / or  / Textbook Example - Chapter 05# - Relationship betwen Pointers and Arrays 
// Code demonstrates pointer - array relationships, pointer array arithmetic as well as showing alternative syntax

						// Below is what is known as the Preprocessor Directives 
						// Under Visual Studio 17  -  replace #include "stdafx.h" with #include "pch.h" to provide same library support						
						// The Preprocessor Directives: 							

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
#include <windows.h>  	// #####



// ..............................................   Function Prototype Declaration Code   ........................................................
void copy1(char*, const char*);		// Prototypes with arguments, pointer to a character,  pointer to a character constant (i.e.  - a constant string)
void copy2(char*, const char*);


int main()									// Function tmain(...) begins program execution - Entry point for the program
{
	// ##############################################################
	// Modify position and size of Console Application Window
	HWND console = GetConsoleWindow();		// Get the console handle
	RECT r;									// Stores the console's current dimensions
	GetWindowRect(console, &r);				// MoveWindow(window_handle, x, y, width, height, redraw_window);											
	MoveWindow(console, 1400, 500, 800, 700, true);
	// ###############################################################

							// Notation examples below:
	// int arrayA[5]; 			// Array declared with size of 5
							// Intializing arrayA with content
	int arrayA[5] = { 0, 10, 20, 30, 40 };
	int* arrayAPtr; 		// arrayAPtr is declared as a pointer
	arrayAPtr = arrayA;		// Here arrayAPt is declared as a pointer to the array arrayA. arayAPtr contains the address to the first element [0]
	*arrayAPtr = arrayA[0]; // Contents of first element of array and the array pointer are equivalent
							// Statements below are true because arrayA[3] and *(arrayA + 3) (pointer offset notation) are equivilent expressions
							// And &arrayA[3] == arrayAPtr + 3 are equivilent refering to the contenst of the 4th element in the array
							// Since this is an integer array, each location takes 4 bytes so index 3 is 4x4 bytes away from index 0
	arrayA[3] = *(arrayA + 3);	
	*(arrayA + 3) = arrayA[3]; 

	int arraySize = size(arrayA);													// Function size() is a library function for arrays
	cout << " Contents of Array arrayA[3] is: " << arrayA[3] << endl;

	cout << "\n\n >>>>>>>>>>>>>>>>>>>>>>>>>>   Pointers and Array Relationships  <<<<<<<<<<<<<<<<<<<<<<<<<<" << endl << endl;
	cout << " Display array content using array subscript notation " << endl;
	for (int i = 0; i < sizeof(arrayA)/4; i++)
	{
		cout << " arrayA[" << i << "] = " << arrayA[i] << endl;
	}
	
	cout << " Display array content using array name (which is a pointer) and pointer offset notation " << endl;
	for (int offset = 0; offset < arraySize; offset++)								
	{
		cout << " *(arrayAPtr + " << offset << ") = " << *(arrayA + offset) << endl;
	}

	cout << " Display array content using array pointer and array subscript notation " << endl;
	for (int j = 0; j < arraySize; j++)
	{
		cout << " (arrayAPtr[" << j << "] = " << arrayAPtr[j] << endl;
	}

	cout << " Display array content using array pointer and pointer offset notation " << endl;
	for (int offset = 0; offset < arraySize; offset++)
	{
		cout << " *(arrayAPtr + " << offset << ") = " << *(arrayAPtr + offset) << endl;
	}

	// Demonstrating copy functions using array element index, and pointer indirection/dereferencing notation
	char string1[10];
	char string2[] = "Hello";
	char string3[10];
	char string4[] = "Good Bye";

	cout << endl << endl;

	copy1(string1, string2);
	cout << "string1 = string2 => " << string1 << " = " << string2 << endl;

	copy2(string3, string4);
	cout << "string3 = string4 => " << string3 << " = " << string4 << endl;


	system("pause");
	return 0; 					// Indicates successful termination
}								// End of main

								// .......................................................   Function Definition / Description Code   ................................................................

							
void copy1(char* string1, const char* string2)
{									// Copy using array element index notation:  incrementing the index
	for (int i = 0; (string1[i] = string2[i]) != '\0'; i++)
		; // Do Nothing in body }	// Look at this - Doing computation in the middle of the 'if' (Loop Controller)
}

void copy2(char* string1, const char* string2)
{								// Copy array2 to array1 using pointer dereferencing or indirection notation
	for (; (*string1 = *string2) != '\0'; string1++, string2++)
		; // Do Nothing in body }	// Look at this - Doing computation in the middle of the 'if' (Loop Controller)
}

		/*

		|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|
		01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
				  |         |         |         |         |         |         |         |         |
				  10        20        30        40        50        60        70        80        90
		*/