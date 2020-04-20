// StringCharFunctions.cpp : 
// Code Example lifted from Dietel "How to Program" 4th edition, Exercise / or  / Textbook Example - 
// Chapter 05 - String Manipulation Functions of the String-Handling Library - using character arrays
//
// Description of Program 
// ..........................................................................................
//			
					// Below is what is known as the Preprocessor Directives 
					// Under Visual Studio 17  -  replace #include "stdafx.h" with #include "pch.h" to provide same library support						
					// The Preprocessor Directives: 							

#include <iostream> 	// Part of the standard library  -  Used for cout, cin, cerr  ( That is the  reason for brackets < > )
#include <string>		// Part of the standard library  - 'string' class is req to be included as the new way of using strings as opposed the old char sequence
#include <cstring>		// Part of the standard library  - 'string' class is req to be included as the new way of using strings as oppossed to the latest way
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

								// .......................................................   Function Prototype Declaration Code   ........................................................
void functionExample(void);		// Function prototype - In C++ every funtion requires a prototype placed before/outside the main block or placed in the "projectName.h" file - Must then use #include "prjName.h'
								// Placing the functions in Declaration format here before 'main' satisfies both the definition & declaration requirements placed in the correspond " *.h " and " *.cpp " files


int main()									// Function tmain(...) begins program execution - Entry point for the program
{
	// ############################################################## 
	HWND console = GetConsoleWindow();		// Get the console handle
	RECT r;									// Stores the console's current dimensions
	GetWindowRect(console, &r);				// MoveWindow(window_handle, x, y, width, height, redraw_window);											
	MoveWindow(console, 1400, 500, 900, 1000, TRUE);
	// ###############################################################


	cout << "\n\n >>>>>>>>>>>>>>>>>>>>>>>>>>   Sample String Manipulation   <<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;

	// In C++, a string is an array of characters ending with the null char '\0'
	// In C++ the string is accessed via a pointer to the first character in the string
	// Therefore, - a string is a constant pointer, pointing to first char of string
	// Character array 'color' ends with the null char automatically being inserted at the end
	// The string color2[] array has to have a null char placed there manually 

	cout << " These syntax of declarations are all equivalent functionally " << endl;
	char color1[] = "Blue";
	const char* colorPtr = "Green";				// The 'char*' char pointer colorPtr is intialized with a string literal pointing to letter 'b'
	char color2[] = { 'B', 'r', 'o', 'w', 'n', '\0' };
	cout << " Strings color1, colorPtr, color2 contents follow: " << color1 << ",  " << colorPtr << ",  " << color2 << endl << endl;
	cout << " Demonstrating the standard library functions of copy " << endl;
	// A string can be stored in an array using stream extraction with cin
	char word[20];				// Limits array size to 19 plus '\0' null character at the end to signify termination
								// cin >> word;  // This will store a char array terminating on the first whitespace character or end of file char
	cout << " Type a sequence of characters (less than 19 characters) => ";
	cin >> setw(20) >> word;	// Better syntax as it protects the word array from being overrun
	cout << " Chararter sequence typed in: " << word << endl << endl;;

	// This block of code doe not work ???????????????????????????????????????????????????????????
//							// Inputing an entire line from a user an looking for user's 'enter' key action which is the delimiter
//cout << " Type an entire line of any text (less than 79 characters) and hit return => ";
//char sentence[ 80 ];		// The cin.getline function terminates when it receives the end of line char '\n'
//cin.getline( sentence, 80, '\n' ); 
//cout << "\n\n" << endl;

	char x[] = "In the Beginning";
	char y[25];					// Declaring and sizing arrays
	char z[15];					// Caution, presently array z is not terminated with the null char '\n'
								// Copying contents of array x into array y; 
								// Note the y array destination is placed first in the copy syntax sequence 
	strcpy_s(y, x);
	cout << " The contents placed into array x is: " << x << endl;
	cout << " The contents placed into array y is: " << y << '\n' << endl;

	strncpy_s(z, x, 13); 		// Copy the first 13 characters into array z 
	z[14] = '\0';  				// Necessary!  -  Append the null character '\0' at the end of the string (element [14])
	cout << " The first 13 chars of the x string char array copied into array z is: " << z << '\n' << endl;


	// Caution! string1 - going to accept string2 assure it is large enough for both strings
	cout << " Demonstrating the standard library functions of concatenating strings " << endl;
	char string1[70] = "Rejoice and be glad";
	char string2[] = "for this is the day the Lord has made";
	char string3[70] = "";		// Assure this receiving string has sufficient size to hold the concatenation event
								// Concatenating string 2 to the end of string 1
	cout << " The contents of string 1 is: " << string1 << endl;
	cout << " The contents of string 2 is: " << string2 << endl;

	strcat_s(string1, string2);
	cout << " After concatenation of string 1 with string2 with function strcat_s( string1, string2 ) " << endl;
	cout << " The contents of string 1 is: " << string1 << endl;
	cout << " The contents of string 2 is: " << string2 << endl;
	// Concatenation of the first 10 characters of string 1 into string 3
	strncat_s(string3, string1, 10);
	cout << " After concatenation of the first 10 characters of string 1 into string 3 using strncat_s() " << endl;
	cout << " The contents of string 1 is: " << string1 << endl;
	cout << " The contents of string 3 is: " << string3 << endl;

	cout << " Demonstrating the standard library functions of comparing strings " << endl;
	const char* stringAPtr = " Great is the Lord ";
	const char* stringBPtr = " Great is His Name ";
	const char* stringCPtr = " Great is the Lord ";
	// Note the use of char pointers in the above declarations as apposed to char arrays
	// Above statements are declarations of type (char *) pointers
	// In the comparison function below '0'==equal, '1'==greater than, '-1'== less than
	cout << " // Confusing I thought that cout would display an addresses not string contents since these are pointers " << endl;
	cout << " The contents of string A is: " << stringAPtr << endl;
	cout << " The contents of string B is: " << stringBPtr << endl;
	cout << " The contents of string C is: " << stringCPtr << endl;
	cout << endl;				// Demo strcmp - Compares entire string
	cout << " strcmp(stringAPtr, stringCPtr) " << setw(2) << strcmp(stringAPtr, stringCPtr) << endl;
	cout << " strcmp(stringAPtr, stringBPtr) " << setw(2) << strcmp(stringAPtr, stringBPtr) << endl;
	cout << " strcmp(stringBPtr, stringCPtr) " << setw(2) << strcmp(stringBPtr, stringCPtr) << endl;
	cout << endl;				// Demo strncmp - Compares up to designated number of characters
	cout << " strncmp(stringAPtr, stringCPtr, 10) " << setw(2) << strncmp(stringAPtr, stringCPtr, 10) << endl;
	cout << " strncmp(stringAPtr, stringBPtr) 11) " << setw(2) << strncmp(stringAPtr, stringBPtr, 11) << endl;
	cout << " strncmp(stringBPtr, stringCPtr) 11) " << setw(2) << strncmp(stringBPtr, stringCPtr, 11) << endl;

	system("pause");
	return 0; 					// Indicates successful termination
}								// End of main




/*

|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|
01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
		  |         |         |         |         |         |         |         |         |
		  10        20        30        40        50        60        70        80        90
*/