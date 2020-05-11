// FileInput_BadStringData.cpp :  Code was adopted and enhanced from Marach's 'C++ Programming' by Mary Delamater - Introduction to Streams and Buffers
//
// ..........................................................................................
// ..........................................................................................
								
						// The Preprocessor Directives: (Header Files) 							
#include <iostream> 	// Standard Template Library class  -  Used for cout, cin, cerr, printf  ( That is the  reason for brackets < > )
#include <iomanip>		// Required to utilize parameterized stream manipulator ie. calling setprecision(3) & fixed functions
#include <fstream>		// Template Specialization inherited from 'basic_fstream' for file input / output prototype functions - Enables char I/O
#include <sstream>		// Used when interfacing strings by reading from and writing to files
#include <string>		// Use the s suffix for literal strings 'string' class - required as a new way of using strings, non char sequence
#include <windows.h>	// Required to implement date and time functions - Some IDE / Complilers do not accept this header file


						// The double colons operator '::' is defined as the "Scope Resolution Operator"
using std::cout;		// Console output
using std::cin;			// Console input
using std::endl;		// End of Line - Clears output buffer and terminates with a new-line character
using std::fixed;		// Both 'fixed' & 'showpoint' are nonparamatized stream manipulators that Do Not require the <iomanip> header file
using std::setw;		// Assure #include <iomanip> is included which requires a parameterized stream manipulator
using std::setprecision;// setprecision(2)indicates a double variable value should be printed with 2 digits to the right of the decimal point


using namespace std;	// Common practice to implement the "std" namespace as it contains multiple supporting useful functions

						// ##### Necessary for the 'GetConsoleWindow()' function below to work! - on Windows 2000 and later
#define _win32_winnt 0x0500
#include <windows.h>
						// #####

// ..............................................   Function Prototype Declaration Code   ..............................................
// Global variables, Function protoypes, Classes are placed/declared here before 'main' .... Implementation may reside here optionally
// Implementation details of the Functions may be coded after the 'main' block 

void exitPrgm();							// Use this function as a optional default to terminate the program


int main()									// Function main() begins program execution - Entry point for the program
{
												// ##############################################################
												// Modify position and size of Console Application Window
		HWND console = GetConsoleWindow();		// Get the console handle
		RECT r;									// Stores the console's current dimensions
		GetWindowRect(console, &r);				// MoveWindow(window_handle, x, y, width, height, redraw_window);
		MoveWindow(console, 1300, 0600, 705, 600, true);
												// ###############################################################


	cout << "\n\n >>>>>>>>>>>>>>>>>>>>>>>>>>>>   Main Code Execution   <<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	cout << "                  Use String Stream to Handle Unexpected Data         \n\n" << endl;

	/*
		>>> Three Classes of the sstrem header file - All create a string buffer for input <<<
	istringstream	Creats an input stream object that reads characters from a string
	ostringstream	Creats an output stream object that writes characters to a string
	stringstream    Create a stream object that can read characters from and write characters to a string
	str()			Returns a string object that's a copy of the contents of the buffer: That is . . .
					Retrieve a string from the buffer or replaces a string existing in the buffer
	str(string)		Replaces the contents of the buffer with the specified string
	*/
	
								
	ifstream inpStrFile("temps.txt");			// Open / Create stream input file object with name: temps.txt
	if (inpStrFile) {							// Check if file stream object has opened  . . . .
		string strLine;							// String variable defined for receiving string stored in the file
		stringstream strStreamObj;				// Create an object to store string retreive from the file and  // Used it to handle bad strings in file
		double low, high;						// Used it to handle bad strings in file
		cout << fixed << setprecision(1);		// Any floating point number will default to one decimal point
		while (getline(inpStrFile, strLine)) {	// Acquire the next line of strings in the file and store it variable strLine
			strStreamObj.str(strLine);			// Place string in stream buffer with current line retreived from file
			strStreamObj.clear();				// Reset string stream error bits (in case of error)
			if (strStreamObj >> low >> high) {	// Display legal correct types (ddouble) and continue until no more lines in file
				cout << setw(8) << low << setw(8) << high << '\n';
			}
		}
		inpStrFile.close();
	}
	
	cout << "\n\n Inspect the source file 'temps.txt' to see how code handled the bad data " << endl;
	
	
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