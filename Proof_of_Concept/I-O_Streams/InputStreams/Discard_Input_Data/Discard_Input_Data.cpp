// Discard_Input_Data.cpp : 
// Input_Problems.cpp :  Code was copied from Marach's 'C++ Programming' by Mary Delamater - Code: Introduction to Streams and Buffers
// Demonstrating how to use the numeric_limits class to discard all remaining data in an input stream
//
						// The Preprocessor Directives: (Header Files) 							
#include <iostream> 	// Standard Template Library class  -  Used for cout, cin, cerr, printf  ( That is the  reason for brackets < > )
#include <limits>		// Used for discarding remainig data in an input stream.  All data in the input buffer is discarded
#include <string>		// Use the s suffix for literal strings 'string' class - required as a new way of using strings, non char sequence

						// The double colons operator '::' is defined as the "Scope Resolution Operator"
using std::cout;		// Console output
using std::cin;			// Console input
using std::endl;		// End of Line - Clears output buffer and terminates with a new-line character

using namespace std;	// Common practice to implement the "std" namespace as it contains multiple supporting useful functions


// ..............................................   Function Prototype Declaration Code   ..............................................

void exitPrgm();							// Use this function as a optional default to terminate the program

int main()									// Function main() begins program execution - Entry point for the program
{
	
	cout << "\n\n >>>>>>>>>>>>>>>>>>>>>>>>>>>>   Main Code Execution   <<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	cout << "                         Discarding Unwanted Input Data        " << endl;

	/* To use the numeric_limits class, you include the limits header file.  Then, you can use the max() function of the numeric_limits
	   class to get the maximum size of the stream.  Next, you can pass this value to the ignore() member funciton of the cin object as its
	   first argument, and you can supply a newline character (\n) as the second argument.  This way C++ discards the rest of the data in 
	   the stream buffer.  Discarding all data except the first entered by the user assures extra data will not cause problems with the code.
	*/

	int intNum;
	double dblNum;
	char chrChar;
	string strg;									
													// Discards all remaining data in the buffer
													// cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << " Streaming to and from the 'Console'- Enter the requested data followed by a carriage return: " << endl;	
	cout << " Enter a interger: ";  cin >> intNum;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << " Enter a double: "; cin >> dblNum;	
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << " Enter a character: "; cin >> chrChar;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << " Enter a string: "; cin >> strg;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << endl << "The folowing was entered: " << endl;
	cout << intNum << ' ' << dblNum << ' ' << chrChar << ' ' << strg << endl << endl;


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
