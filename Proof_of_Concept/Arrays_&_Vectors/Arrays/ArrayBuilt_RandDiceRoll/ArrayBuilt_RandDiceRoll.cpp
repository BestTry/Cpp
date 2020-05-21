// ArrayBuilt_RandDiceRoll.cpp : 
// Description of Program ...................................................................
// Program provides the number of times a roll of the dice comes up with values of 2 through 12
// over the course of multiple rolls such as 60000 rolls 
// ..........................................................................................
//
						// The Preprocessor Directives: (Header Files) 							
#include <iostream> 	// Standard Template Library class  -  Used for cout, cin, cerr, printf  ( That is the  reason for brackets < > )
#include <iomanip>		// Required to utilize parameterized stream manipulator ie. calling setprecision(3) & fixed functions
#include <array>		// Necessary when using the array class i.e array<arrType, size>
#include <cmath>		// Enables the use of the "pow" function with the math library and other mathematical functions
#include <limits>		// Contains clasees for defining numerical data type limits on each computer platform
#include <thread>		// std::this_thread::sleep_for(std::chrono::seconds(XX) << endl;
#include <chrono>		// std::chrono::seconds(XX)
#include <cstdlib>		// Required to implement the rand() & srand() function.  Also, needed to execute the 'exit()' function.
#include <ctime>		// Required to implement the time(0) function providing a number to seed rand() using srand():  srand( time( 0 ) );
						// Arguement (0) yields a interger value of the calendar in seconds


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

void exitPrgm();							// Use this function as a optional default to terminate the program


int main()									// Function main() begins program execution - Entry point for the program
{
	
	cout << "\n\n >>>>>>>>>>>>>>>>>>>>>>>>>>>>   Main Code Execution   <<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	cout << "       Filling contents of array by saving results of the random function         \n\n" << endl;

	const int arraySize = 14;				// Define constant value once and use it multiple times if necessary - intialize all elements to content of zero
	int rollValue[arraySize] = { 0 };		// Init array size: 14 (12+2); Roll index 0 & 1 ignored using only indexes [2] thru [12] accountg for actual dice rolls
	int maxRoll = 60000; 					// Maximum number of rolls
	srand(time(0));							// Seed randum-number function so results are not duplicated each time program executes but relies on present time value

											// Populate the array from the dice rolls using the random-number generator
	for (int roll = 1; roll <= maxRoll; roll++)
	{										// Each die capable of showing values between 2 to 12 which increments the contents of the array indexes 2 to 12
		++rollValue[(1 + rand() % 6) + (1 + rand() % 6)];
	}
											// Display the results of the dice rolls and Ignore indexes 0 and 1	
	cout << "     Dice Roll " << endl;
	cout << "  Value" << setw(10) << "Occurred" << endl;
	cout << "  -----" << setw(10) << "--------" << endl;
	for (int rollTotal = 2; rollTotal <= 12; rollTotal++)
	{
		cout << setw(3) << "   " << setw(2) << rollTotal 
			 << setw(10) << rollValue[rollTotal] << endl;
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