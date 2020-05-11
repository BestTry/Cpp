// FileInput_ErrorChecking.cpp :  Code was adopted and enhanced from Marach's 'C++ Programming' by Mary Delamater - Introduction to Streams and Buffers
//
// ......................................................................................................................................................
// ......................................................................................................................................................
//
			// Below is what is known as the Preprocessor Directives - in this Header File section
						// Under Visual Studio 17  -  replace #include "stdafx.h" with #include "pch.h" to provide same library support						
						// The Preprocessor Directives: (Header Files) 							
#include <iostream> 	// Standard Template Library class  -  Used for cout, cin, cerr, printf  ( That is the  reason for brackets < > )
#include <iomanip>		// Required to utilize parameterized stream manipulator ie. calling setprecision(3) & fixed functions
#include <fstream>		// Template Specialization inherited from 'basic_fstream' for file input / output prototype functions - Enables char I/O
#include <string>		// Use the s suffix for literal strings 'string' class - r#include <ctime>		// Required to implement date and time functions
#include <limits>		// Contains clasees for defining numerical data type limits on each computer platform

						// The double colons operator '::' is defined as the "Scope Resolution Operator"
using std::cout;		// Console output
using std::cin;			// Console input
using std::endl;		// End of Line - Clears output buffer and terminates with a new-line character
using std::fixed;		// Both 'fixed' & 'showpoint' are nonparamatized stream manipulators that Do Not require the <iomanip> header file
using std::pow;			// Standard Library Function pow(x,y) definded as x raised to the y power
using std::setw;		// Assure #include <iomanip> is included which requires a parameterized stream manipulator
using std::setprecision;// setprecision(2)indicates a double variable value should be printed with 2 digits to the right of the decimal point


using namespace std;	// Common practice to implement the "std" namespace as it contains multiple supporting useful functions


// ..............................................   Function Prototype Declaration Code   ..............................................
// Global variables, Function protoypes, Classes are placed/declared here before 'main' .... Implementation may reside here optionally
// Implementation details of the Functions may be coded after the 'main' block 

void exitPrgm();							// Use this function as a optional default to terminate the program


int main()									// Function main() begins program execution - Entry point for the program
{
	cout << "\n\n >>>>>>>>>>>>>>>>>>>>>>>>>>>>   Main Code Execution   <<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	cout << "                   File Data Input Error Checking            \n\n" << endl;

	cout << " Extracting file data without error checking ...." << endl;
	ifstream input_file;						// Open / Create stream input object
	input_file.open("info.txt");				// Target path with file name to be in home directory
	if (input_file) {							// If file opened successfully .....
		int intNum;
		while (input_file >> intNum) {			// Extract file data while no errors ... 
			cout << intNum << '|';				// Display the data in the file - - - Caution leave no spaces inside '|'
		}
		input_file.close();
	}
	cout << "\n Attempted to read an  interger and encouter text: \n " 
		 << " Flow broke from while loop in attempt to read integer\n\n" << endl;

	cout << " Next handle data conversion errors ...." << endl;
	input_file.open("info.txt");				// Target path with file name to be in home directory
	if (input_file) {							// If file opened successfully .....
		int intNum;
		while (true) {							// Infinite Loop pending a break ..... 
			if (input_file >> intNum) {
				cout << intNum << '|';			// Display the data in the file - - - Caution leave no spaces inside '|'
			}
			else if (input_file.eof()) {		// Check End of File reached:  End of File also sets 'fail' bit 
				break;							// Exit While Loop  - Make sure (*.eof) preceeds (*.fail)
			}
			else if (input_file.fail()) {			// Encountered a non - interger or other reason
				input_file.clear();
				input_file.ignore(numeric_limits<streamsize>::max(), '\n'); 
			}			
		}
		input_file.close();
	}

	exitPrgm();					// Option function member to terminate program
	system("pause");			// Some compilers do not recognize this statement
	return 0; 					// Indicates successful termination
}								// End of main

// .............................................   Function Code Definition Implementation  .................................................

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