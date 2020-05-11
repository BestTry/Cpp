// ReadWrite_DelimitedData.cpp :   Code was adopted and enhanced from Marach's 'C++ Programming' by Mary Delamater - Introduction to Streams and Buffers
// The ifstream and ofstream are part of the fstream class.  
// In order to read or write to the files, objects are instantiated from the ofstream clsas or the ifstream class as shown in this example code.
// ..........................................................................................
// ..........................................................................................

//
// Additonal Code Description : Steps Enumerated 
// 1 - 
// 2 - 
// 3 - 
// 4 - 
				
						// Below is what is known as the Preprocessor Directives - in this Header File section
						// Under Visual Studio 17  -  replace #include "stdafx.h" with #include "pch.h" to provide same library support						
						// The Preprocessor Directives: (Header Files) 							
#include <iostream> 	// Standard Template Library class  -  Used for cout, cin, cerr, printf  ( That is the  reason for brackets < > )
#include <fstream>		// Template Specialization inherited from 'basic_fstream' for file input / output prototype functions - Enables char I/O
#include <string>		// Use the s suffix for literal strings 'string' class - required as a new way of using strings, non char sequence
#include <ctime>		// Required to implement date and time functions
#include <windows.h>	// Required to implement date and time functions - Some IDE / Complilers do not accept this header file
#include <typeinfo>		// Necessary for imlementing the typeid() function 
#include <memory>		// Necessary when using smart pointers. Syntax: unique_ptr<int> ptrName( new int );
#include <array>		// Necessary when using the array class i.e array<arrType, size>
#include <vector>		// Support vector operations - See inputDate
#include <algorithm>	// Copy algorithm - Needed to utilize Standard Template Library functions
						// Before compiling symbol '#' indicates a preprocessing contents of  
						// the input/output stream header file iostream.  This file must be 
						// included with any keyboard input or console screen output
						// Functions within the standard library are as follows:
						// Since classes below are part of C++ stadard library < > are placed around them
#include <cmath>		// Enables the use of the "pow" function with the math library and other mathematical functions
#include <functional>	// References the standard function library - std::function
#include <limits>		// Contains clasees for defining numerical data type limits on each computer platform
#include <iomanip>		// Required to utilize parameterized stream manipulator ie. calling setprecision(3) & fixed functions
#include <thread>		// std::this_thread::sleep_for(std::chrono::seconds(XX) << endl;
#include <chrono>		// std::chrono::seconds(XX)
#include <cstdlib>		// Required to implement the rand() & srand() function.  Also, needed to execute the 'exit()' function.
#include <ctime>		// Required to implement the time(0) function providing a number to seed rand() using srand(): srand( time( 0 ) );
						// Arguement (0) yields an interger value of the calendar in seconds

						// The double colons operator '::' is defined as the "Scope Resolution Operator"
using std::cout;		// Console output
using std::cin;			// Console input
using std::endl;		// End of Line - Clears output buffer and terminates with a new-line character
using std::fixed;		// Both 'fixed' & 'showpoint' are nonparamatized stream manipulators that Do Not require the <iomanip> header file
using std::pow;			// Standard Library Function pow(x,y) definded as x raised to the y power
using std::setw;		// Assure #include <iomanip> is included which requires a parameterized stream manipulator
using std::setprecision;// setprecision(2)indicates a double variable value should be printed with 2 digits to the right of the decimal point


using namespace std;	// Common practice to implement the "std" namespace as it contains multiple supporting useful functions

/*						// ##### Necessary for the 'GetConsoleWindow()' function below to work! - on Windows 2000 and later
#define _win32_winnt 0x0500
#include <windows.h>
*/						// #####

// ..............................................   Function Prototype Declaration Code   ..............................................
// Global variables, Function protoypes, Classes are placed/declared here before 'main' .... Implementation may reside here optionally
// Implementation details of the Functions may be coded after the 'main' block 

void exitPrgm();							// Use this function as a optional default to terminate the program


int main()									// Function main() begins program execution - Entry point for the program
{
	/*											// ##############################################################
												// Modify position and size of Console Application Window
		HWND console = GetConsoleWindow();		// Get the console handle
		RECT r;									// Stores the console's current dimensions
		GetWindowRect(console, &r);				// MoveWindow(window_handle, x, y, width, height, redraw_window);
		MoveWindow(console, 1300, 0600, 1100, 1400, true);
	*/											// ###############################################################


	cout << "\n\n >>>>>>>>>>>>>>>>>>>>>>>>>>>>   Main Code Execution   <<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	cout << "            Writing and Reading Delimited Data to a File        \n\n" << endl;

	string fileName = "temps.txt";

	ofstream output_file;						// Create output file stream object
	output_file.open(fileName);					// Give file stream object name of the file to open and open the file
	output_file << fixed << setprecision(1);	// Default to one decimal point suffix
	output_file << "\t" << 1 << "\t" << "One"   << "\t" << 1.0 << '\n';
	output_file << "\t" << 2 << "\t" << "Two"   << "\t" << 22.22 << '\n';
	output_file << "\t" << 3 << "\t" << "Three" << "\t" << 333.333 << '\n';
	output_file << "\t" << 4 << "\t" << "Four"  << "\t" << 4444.4444 << '\n';
	output_file << "\t" << 5 << "\t" << "Five"  << "\t" << 55555.55555 << '\n';
	output_file.close();

	cout << "Check file the 'temps.txt' content in local directory for the results \n\n" << endl;
	cout << " Now read from the file that was populated and display its content \n" << endl;

	string numName;
	int intNum;
	double decNum;
	ifstream input_file;						// Create input file stream object
	input_file.open(fileName);					// Open the file stream object with file name 
	if (input_file) {
		output_file << fixed << setprecision(1);	// Default to one decimal point suffix
		while (input_file >> intNum >> numName >> decNum) {
			cout << right << setw(1) << intNum << left << "  " 
				 << numName << right << "  \t" << setw(8) << decNum << endl;
		}
		input_file.close();
	}



	exitPrgm();					// Option function member to terminate program
	system("pause");			// Some compilers do not recognize this statement
	return 0; 					// Indicates successful termination
}								// End of main

// .............................................   Function Code Definition Implementation  .................................................
//    When functional coded is declared above before the main coding section use this area for functional code implementation

void exitPrgm()
{
	cout << "\n\n                  >>>>>>>>>>  Program has Terminated  <<<<<<<<<< " << endl;
	cout << " \n\n\n " << endl;
	exit(0);					// Terminate running program from anywhere it is called:
}

/*

|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|
012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
		  |         |         |         |         |         |         |         |         |         |         |         |         |         |
00		  10        20        30        40        50        60        70        80        90		00		  10        20        30        40

*/