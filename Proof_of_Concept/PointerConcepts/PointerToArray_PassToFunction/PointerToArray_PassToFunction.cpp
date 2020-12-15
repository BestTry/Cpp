// PointerToArray_PassToFunction.cpp : Defines the entry point for a Console Application. Console applications are the simplest using text for input / output
// Code Example lifted from C++ From Control Structure Through Objects" - Tony Gaddis Chapter 9 
//
// Description of Program .............  Boiler Plate Template  ..............................
// ..........................................................................................
// ..........................................................................................
// ..........................................................................................
//
					
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


#define _win32_winnt 0x0500	    // ##### Necessary for the getconsolewindow() function to work! - works for  running this program on windows 2000 or higher			
#include <windows.h>    		// #####

								// .......................................................   Function Prototype Declaration Code   ........................................................

void getSales(double*, int); 	// Declaration of arguement types for array of doubles and array size
double totalSales(double*, int);


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

	cout << "\n\n >>>>>>>>>>>>>>>>>>>>>>>>>>   Example Code  <<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	cout << " Code demonstrates how a pointer to an array can be used as a parameter when passing it to a function" << endl;

	const int QTRS = 4;						// Array size representing that there are 4 quarters in a year
	double sales[QTRS];						// Array of doubles in array sales with the size of 4

	getSales(sales, QTRS);					// Get sales data for all quarters of the year

											// Set output for 2 decimal places in double and display											
	cout << fixed << showpoint << setprecision(2);
	cout << "\n The total sales for the year is: $: ";
	cout << totalSales(sales, QTRS) << "\n\n" << endl;




	system("pause");
	return 0; 					// Indicates successful termination
}								// End of main

								// ..................................   Function Description Code   .......................................
								// These functions use a pointer of an array to accept the address of an array as their arguments
void getSales(double* salesArray, int quarters)
{
	double quarterSales;
	for (int i = 0; i < quarters; i++)
	{
		cout << "\n Please enter the sales figure for quarter " << (i + 1) << ":  ";
		cin >> quarterSales;	// Array is populated wiht user provided double values 
		salesArray[i] = quarterSales;
	}
}

double totalSales(double* salesArray, int quarters)
{
	double totalSalesAmount = 0.0;
	for (int i = 0; i < quarters; i++)
	{
		totalSalesAmount += salesArray[i];
	}
	return totalSalesAmount;
}

