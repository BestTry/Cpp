// ArraysOfPtrsTofunctions.cpp : Defines the entry point for a Console Application. Console applications are the simplest using text for input / output
// Code Example lifted from Dietel "How to Program" 4th edition, Exercise / or  / Textbook Example - Chapter 05 - Arrays of Pointers to Functions
//
// Description of Program .............  
// ..........................................................................................
			
						// The Preprocessor Directives: 
#include <iostream> 	// Part of the standard library  -  Used for cout, cin, cerr  ( That is the  reason for brackets < > )
						// The double colons is defined as the "Scope Resolution Operator"
using std::cout;		// Console output
using std::cin;			// Console input
using std::endl;		// End of Line - Clears output buffer and terminates with a new-line character
using namespace std;
						// ##### Necessary for the getconsolewindow() function to work! - works for  running this program on windows 2000 or higher
#define _win32_winnt 0x0500					
#include <windows.h>    // #####

								// .............................   Function Prototypes Declaration Code   .................................
								// Three functions declared here that take an integer as an argument and do not return a value (void)
void function1( int );
void function2( int );
void function3( int );



int main()									// Function main(...) begins program execution - Entry point for the program
{
											// ##############################################################
	// Modify position and size of Console Application Window
	HWND console = GetConsoleWindow();		// Get the console handle
	RECT r;									// Stores the console's current dimensions
	GetWindowRect(console, &r);				// MoveWindow(window_handle, x, y, width, height, redraw_window);											
	MoveWindow(console, 700, 500, 900, 700, TRUE);
											// ###############################################################



// Code steps here within main block of code
// Initialize an array holding three pointers to three separate functions that each take the SAME TYPE of 
// argument (an interger) and return 'void' I think the 'void' term  preceeding the array is to indicate
// that all of these function are 'void' type functions, that is they do not return any parameters
// The 'userChoice variable is used as a subscript to the element in the arrayOfFunctions array

// *** Statement below is read as an " 'arrayOfFunctions' is an array of three pointers to functions (note the *)
// *** that each take on an interger as an argument to their function and return void" (No return)
	void (*arrayOfFunctions[3])( int ) = { function1, function2, function3 };

	int userChoice;
	cout << " Please select one of three functions to by entering a number between 1 and 3: ";
	cin >> userChoice;

	// Invoke a function at the location userChoice in the array 'arrayOfFunctions'
	// and pass as an argument the same userChoice as a the value of the function argument
	// Note the first 'userChoice' term is the function called, the second 'userChoice' term is its argument
	while (userChoice >= 1 && userChoice <= 3)
	{
		(*arrayOfFunctions[userChoice-1])(userChoice); // Array elements 0, 1, 2 correspond to functio ns 1, 2, 3

		cout << " Please select one of three functions to by entering a number between 1 and 3: ";
		cin >> userChoice;
	}


	system("pause");
	return 0; 					// Indicates successful termination
}								// End of main

								// .......................................................   Function Description Code   ................................................................


void function1(int a)
{
	cout << " You entered '1' so function #1 was called \n\n" << endl;
}

void function2(int b)
{
	cout << " You entered '2' so function #2 was called \n\n" << endl;
}

void function3(int c)
{
	cout << " You entered '3' so function #3 was called \n\n" << endl;
}

/*

|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|
01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
		  |         |         |         |         |         |         |         |         |
		  10        20        30        40        50        60        70        80        90
*/