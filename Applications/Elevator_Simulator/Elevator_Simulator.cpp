// Elevator_Simulator.cpp : Code files pulled from Deitel - 'How to Program'[ Chapters 7 - Elevator Simulation Implementation pg 510
// Demonstration and example of analyzing and developing a project from ground up using 'Object-Oriented Design Analysis' (OOAD) approach.
//
//
// Description of Program ...........................  Code Example Multiple Object Interaction   ........................................
// This code represent a excellent example of object-oriented design and implementation.  There are numerous classes which construct their
// corresponding object with appropriate initialization.  The program demonstrates the interaction between objects via message communication. 
// Objects perform their appropriate behavior responding to their environment dictated by random time events (Persons arriving at a floor 
// with the intention of taking the elevator to a adjecent floor.                          ...............................................
// .......................................................................................................................................
//
// Additonal Code Description : The building object controls the simulation using the sceduler object. The building clock object controls the 
// simulation time in seconds.  The building clock increments the clock once every second.  The scheduler object is responsible for creating
// a person randomly and placing the person on a floor.  
//  

						// The Preprocessor Directives: (Header Files) 	
#include "building.h"	// Building class Declaration file 
#include <iostream> 	// Standard Template Library class  -  Used for cout, cin, cerr, printf  ( That is the  reason for brackets < > )
#include <iomanip>		// Required to utilize parameterized stream manipulator ie. calling setprecision(3) & fixed functions
#include <fstream>		// Inherited from 'basic_fstream' for file I/O - Defines Data types: ofstream, ifstream, and fstream
#include <sstream>		// Used when interfacing strings by reading from and writing to files
#include <string>		// Use the s suffix for literal strings 'string' class - required as a new way of using strings, non char sequence
#include <new>			// Required for creating pointer to new object - C++ stamdard mew operator
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


void exitPrgm();							// Use this function as a optional default to terminate the program


int main()									// Function main() begins program execution - Entry point for the program
{
	cout << "\n\n >>>>>>>>>>>>>>>>>>>>>>>>>>>   Main Code Execution   <<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	cout << "                   >>>>>   Elevator Simulation Program   <<<<<      \n\n" << endl;

	int duration;							// Length of simulation in seconds
											// Request from user how long simulation is to run (Number of steps)
	cout << " Enter run time (Time-Steps): ";
	cin >> duration;  
	cin.ignore();							// Function 'ignore' returns user input but ignoring last 'CR' character

	Building building;						// Create the building object and initialize passenger floor arrival times
	cout << endl << " Building & components have been constructed - Press 'Enter' to advance 'Time-Steps'" << endl <<endl;

	cout << endl << "			*** ELEVATOR SIMULATION BEGINS ***" << endl << endl;
	building.runSimulation(duration);		// Run simulation providing building with maximum run time - duration
	cout << "		*** ELEVATOR SIMULATION ENDS ***" << endl;
											// Building's 'While Loop' terminated and program flow passed back here
											// End Simulation message display when duration is expended.


	exitPrgm();								// Option function member to terminate program
	system("pause");						// Some compilers do not recognize this statement
	return 0; 								// Indicates successful termination
}											// End of main

// .............................................   Function Code Definition Implementation  ...................................... 

void exitPrgm()
{
	cout << "\n\n                  >>>>>>>>>>  Program has Terminated  <<<<<<<<<< " << endl;
	cout << " \n\n\n " << endl;
	exit(0);								// Terminate running program from anywhere it is called:
}

/*

|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|
012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
		  |         |         |         |         |         |         |         |         |         |         |         |         |         |
00		  10        20        30        40        50        60        70        80        90		00		  10        20        30        40

*/














