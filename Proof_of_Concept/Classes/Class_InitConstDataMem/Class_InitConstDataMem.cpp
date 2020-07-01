// Class_InitConstDataMem.cpp: Pulled from Deitel - 'How to Program' - chapter 6  _ "Initializing a const Data Member with
// Data "Member Initializer List" syntax
//

						// The Preprocessor Directives: (Header Files) 							
#include <iostream> 	// Standard Template Library class  -  Used for cout, cin, cerr, printf  ( That is the  reason for brackets < > )
#include <iomanip>		// Required to utilize parameterized stream manipulator ie. calling setprecision(3) & fixed functions
#include <fstream>		// Inherited from 'basic_fstream' for file I/O - Defines Data types: ofstream, ifstream, and fstream
#include <sstream>		// Used when interfacing strings by reading from and writing to files
#include <string>		// Use the s suffix for literal strings 'string' class - required as a new way of using strings, non char sequence
#include <windows.h>	// Required to implement adjusting the Consoles window size and position - CAUSES PROBLEMS with <limits>
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
using std::setfill;		// Fills output with leading characters between the sign and value when a number is displayed: from <iomannip> 
using std::setw;		// Assure #include <iomanip> is included which requires a parameterized stream manipulator
using std::setprecision;// setprecision(2)indicates a double variable value should be printed with 2 digits to the right of the decimal point


using namespace std;	// Common practice to implement the "std" namespace as it contains multiple supporting useful functions


// .........................................   Function Prototype Declaration Header References   ............................................
// 

class Increment {
public:
	Increment(int c = 0, int i = 1);				// Default constructor

	void addIncrement()								// Class 'Increment' contains the 'addIncrement' memeber function
	{
		count += increment;
	}												// End function addIncrement

	void print() const;								// Constant Function - prints count and increment

private:
	int count;
	const int increment;							// Const data member
};													// End class Increment

// .............. Definitions of class functions ( 'Increment', 'print' ) and declaration of function ( 'exitPrgm' )  ......
Increment::Increment(int c, int i)					// Constructor taking parameters/ arguments
	: count(c), increment(i)						// initializer syntax for non-const member
													// required initializer for const member     
{
	// Empty constuctor body 
	// Above shows initializer syntax: Increment(int c, int i) : count(c), increment(i) { }
	// These will NOT work: count = c; and increment = i;
}													// End constructor Increment


void Increment::print() const						// Print count function: Displays increment values
{
	cout << "count = " << count
		<< ", increment = " << increment << endl;
}													// End function print


void exitPrgm();									// Use this function as a optional default to terminate the program


int main()											// Function main() begins program execution - Entry point for the program
{
	cout << "\n\n >>>>>>>>>>>>>>>>>>>>>>>>>>>   Main Code Execution   <<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	cout << "       Initializing a const Data Member with Data Member Initializer Syntax      \n\n" << endl;

	Increment valueObj(10, 5);							// Instantiate Increment object 'valueObj' with count (10), increment (5)

	cout << "Before incrementing object 'valueObj', attributes 'count' & 'increment':\n";
	valueObj.print(); cout << endl;

	for (int j = 0; j < 3; j++) {
		valueObj.addIncrement();
		cout << "After increment at time " << j + 1 << ": ";
		valueObj.print();
	}



	exitPrgm();										// Option function member to terminate program
	system("pause");								// Some compilers do not recognize this statement
	return 0; 										// Indicates successful termination
}													// End of main

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
