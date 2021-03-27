// A_BoilerePlateTemplate.cpp : 
// A_BoilerPlateTemplate.cpp : Use this source file for all initial coding examples/files
// Contains majority of the '#included' header files. Delete any unnecessary information 
// or files if not used. Begin with this layout and header files; Then edit to preference
//
// Description of Program .............  Boiler Plate Template  .............................
// ..........................................................................................
// ..........................................................................................
// ..........................................................................................
//
// Additonal Code Description : Steps Enumerated Use Dark Theme:
// 1 - Open your Notepad++, and select “Settings” on the menu bar, and choose “Style configurator”.
// 2 - Select theme “Obsidian” (you can choose other dark themes)
// 3 - Go to “Global Styles” -> “Global override”, click the “background color”
// 4 - 
//
						// The Preprocessor Directives: (Header Files) 							
#include <iostream> 	// Used for cout, cin, cerr, printf  ( Brackets < > indicate function in Standard Librart) istream, ostream
#include <iomanip>		// Required to utilize parameterized stream manipulator ie. calling setprecision(3) & fixed functions
#include <fstream>		// Inherited from 'basic_fstream' for file I/O - Defines Data types: ofstream, ifstream, and fstream
#include <sstream>		// Used when interfacing strings by reading from and writing to files
#include <string>		// Use the s suffix for literal strings 'string' class - required as a new way of using strings, non char sequence
#include <new>			// Required for creating pointer to new object - C++ stamdard new operator
#include <typeinfo>		// Necessary for imlementing the typeid() function 
#include <memory>		// Necessary when using smart pointers. Syntax: unique_ptr<int> ptrName( new int );
#include <array>		// Necessary when using the array class i.e array<arrType, size>
#include <vector>		// Support vector operations - See inputDate
#include <algorithm>	//  Needed to utilize Standard Template Library functions such as sort()
						// Before compiling symbol '#' indicates a preprocessing contents of  
						// the input/output stream header file iostream.  This file must be 
						// included with any keyboard input or console screen output
						// Functions within the standard library are as follows:
						// Since classes below are part of C++ stadard library < > are placed around them
#include <cmath>		// Enables the use of the "pow" function with the math library and other mathematical functions
#include <functional>	// References the standard function library - std::function
#include <limits>		// Contains clasees for defining numerical data type limits on each computer platform
#include <thread>		// std::this_thread::sleep_for(std::chrono::seconds(XX) << endl;
#include <chrono>		// std::chrono::seconds(XX)
#include <cstdlib>		// Required to implement the rand() & srand() function.  Also, needed to execute the 'exit()' function.
#include <windows.h>    // Needed for time delay function 'Sleep' and .... ?????
#include <ctime>		// Required to implement the time(0) function providing a number to seed rand() using srand(): srand( time( 0 ) );
						// Arguement (0) yields an interger value of the calendar in seconds

						// The double colons operator '::' is defined as the "Scope Resolution Operator"
using std::cout;		// Console output
using std::cin;			// Console input
using std::endl;		// End of Line - Clears output buffer and terminates with a new-line character
using std::fixed;		// Both 'fixed' & 'showpoint' are nonparamatized stream manipulators that Do Not require the <iomanip> header file
using std::pow;			// Standard Library Function pow(x,y) definded as x raised to the y power
using std::setfill;		// Fills output with leading characters between the sign and value when a number is displayed: from <iomannip> 
using std::setw;		// Assure #include <iomanip> is included which requires a parameterized stream manipulator
using std::setprecision;// setprecision(2)indicates a double variable value should be printed with 2 digits to the right of the decimal point


using std::istream;		// These libraries must be a subset of the included iostream 
using std::ostream;		// Probably not necessary if 'using namespace std;' is stated

using namespace std;	// Common practice to implement the "std" namespace as it contains multiple supporting useful functions

// ............................................................................................................................................... //
#define _win32_winnt 0x0500	// Necessary for 'GetConsoleWindow()' function below to work! - on Windows 2000 and later	                           //																											   //
#include <windows.h>		// Provides position of Console Window on the desktop PC screen	                                                       //
// ................................................................................................................................................//


// .........................................   Function Prototype Declaration Header References   .................................................
// Global variables, Function protoypes, Classes are placed/declared here before 'main' --- Optionally, function implementation may reside here 
//				 Implementation details of the Functions may be coded usually here located below the 'main' block 
// ................................................................................................................................................


void exitPrgm();							// Use this function as a optional default to terminate the program


int main()									// Function main() begins program execution - Entry point for the program
{
	// ---------------------------------------------------------------------------------------------------------------------------------------------	
	HWND console = GetConsoleWindow();		// Modify position and size of Console Application Window
	RECT r;									// Get the console handle	
	GetWindowRect(console, &r);				// Stores the console's current dimensions
	MoveWindow(console,		 				// MoveWindow(window_handle, x, y, width, height, redraw_window);
	1700, 500, 700, 1000, true);
	// ----------------------------------------------------------------------------------------------------------------------------------------------
	

	cout << "\n\n  <<<<<<<<<<<<<<<<<<<<<<<<<<<   Main Code Execution   >>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	cout << "           Resident / Location -  int main() block code is placed here         \n\n" << endl;

	// '''''''''''''''''''''''''''''
	// . . . . . Code Here . . . . .
	// ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,

	// TODO:  To find TODOs ...  Go to >   View  >   Task List      TODO:TODO:TODO:TODO:TODO:TODO:TODO:TODO:TODO:TODO:TODO:TODO:

	exitPrgm();						// Option function member to terminate program
	system("pause");				// Some compilers do not recognize this statement
	return 0; 						// Indicates successful termination
}									// End of main

// .............................................   Code Functions Definitions Implementations  ................................................... //
//    When functional coded is declared above before the main coding section use this area for functional code definitions and implementation      //
// ............................................................................................................................................... //



void exitPrgm()
{
	cout << "\n\n   		   <<<<<<<<<<  Program has Terminated  >>>>>>>>>> " << endl;
	cout << " \n\n\n " << endl;
	exit(0);						// Terminate running program from anywhere it is called:
}									// End of the exitPrgrm() function

/*

// >>>>>>>>>>>>>>>>>>>>>>>>>   		   Header and Source File Requirement Statements"
//		( When the header declarations and source definitions are placed in separate files instead in the code body )
//
// #ifndef CLASSNAME_H				// Place thes statements within header file: Required to prevent multiple inclusions of header file
// #define CLASSNAME_H				// Use this format with *_H following class name
//   ....  Header code resides here ...
// #endif							// Completes the prevention inclusion statements
//
//  >>>>>>>>>>>>>>>>>>>>>>>>		// Source file className.cpp must include reference to header file: #include "className.h"


|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|
012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
		  |         |         |         |         |         |         |         |         |         |         |         |         |         |
00		  10        20        30        40        50        60        70        80        90		00		  10        20        30        40

*/