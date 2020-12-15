//Enums_Demos_C++.cpp : Example code retreived from textbook: C++ Control Structures through Objects
// Various emum examples

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

					// Enums   -    Defined as scoped or unscoped  { content in brackets are optional syntax)
					//              Compiles sees them as integers.  Requires enum keyword plus enum-list
					//
					// 				unscoped enum:
					//
					// 				enum [identifier] [: type]		// Type - default 32-bit integer 
					// 				{enum-list};
					// 
					//				scoped enum:
					//
					//				enum [class|struct]
					//				[identifier] [: type]
					// 				{enum-list};
					//

						// Double colons: "Scope Resolution Operator"  ::function means function defined here not extrnl library
						// Otherwise it shows that library/class is a host to the fucnion i.e.  class::function
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

enum weekDayName { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };
string dayName[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
int const NumOfDays = 7;// Number of days in a week
double sales[NumOfDays];// Array holding the sales amount for each day of the week
double total = 0.0;		// Keep accumalator of total sales
int index;				// Loop counter - Could have been place inside <  for (int index = Monday; index <= Friday; index++)  > instead 


int main()									// Function tmain(...) begins program execution - Entry point for the program
{											// ##############################################################
											// Modify position and size of Console Application Window
	HWND console = GetConsoleWindow();		// Get the console handle
	RECT r;									// Stores the console's current dimensions
	GetWindowRect(console, &r);				// MoveWindow(window_handle, x, y, width, height, redraw_window);											
	MoveWindow(console, 1400, 500, 900, 700, true);
											// ###############################################################

											// Code steps here within main block of code
											// Acquire sale amount from  user by implementing an enum usage
											// for an index for an array instead of just using a interger
											// The index was declare previously as a integer as all enums are
											// Notice loop excludes Saturday and Sunday indexes
											// The array is populated with elements [2] thru [6] (Monday thru Friday)
	for (index = Monday; index <= Friday; index++)
	{
		cout << "\n Enter the sales for weekday: " << index << " here: ";
		cin >> sales[index];
	}
	cout << endl;

	for (index = Monday; index <= Friday; index++)
	{
		cout << "\n Enter the sales for weekday: " << dayName[index] << " here: ";
		cin >> sales[index];
	}
	cout << endl;
											// Accumulate the total sales for the week from the sales array populated
	for (index = Monday; index <= Friday; index++)
	{
		total += sales[index];
	}
	// Display the total amount of sales
	cout << "\n Total sales for the week: $" << setprecision(2) << fixed << total << endl;
	//
	// Nice to Know:
	// weekDayName workday; asigns workday as a enum of WeekDayName type
	// workDay = 3  .... this is an ERROR!
	// weekDayName = static_cast<weekDayName> = 3; ..... This is legal
	// workDay = Wednesday;   ..... Equivalent to above, which is also legal
	// int x = Friday  ..... May assign an enum variable to an integer variable
	// cout << "\n Work day is: " << x << endl;  ..... Will display ' 5 '
	// cout << "\n Work day is: " << x << endl;  ..... Will display ' 5 '
	// if (Monday == 1) if (Friday > Monday)  ..... Comparisons are also legal

	system("pause");
	return 0; 					// Indicates successful termination
}								// End of main





// TODO:  To find TODOs ...  Go to >   View  >   Task List      TODO:TODO:TODO:TODO:TODO:TODO:TODO:TODO:TODO:TODO:TODO:TODO:


/* Another example of simple code
// Function main(...) begins program execution /  Entry point for the program

int main()
{
	cout << "\n\n >>>>>>>>>>>>>>>>>>>>>>>>>>   Sample Program   <<<<<<<<<<<<<<<<<<<<<<<<<<<<";
	cout << "\n\n\n\n\n      This source code serves as a template for starting any new code\n";
							 Under Tools > Options > General > Chk Line Numbers Box << endl;
	int x;					// Keeps the console window open in order to see the display
	cin >> x;				// when executed with debugging: "Start Debugging"	- Uses Console Output call

	return 0;				// Required as the last statement placed at the end of each program
}
*/

/*

|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|
01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
		  |         |         |         |         |         |         |         |         |
		  10        20        30        40        50        60        70        80        90
*/