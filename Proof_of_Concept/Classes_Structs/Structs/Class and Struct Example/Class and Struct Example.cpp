// CodeExampleName.cpp : Console Application. Console applications are the simplest using text for input / output
// Code Example lifted from C++ 	....  Example lifted from O'Reilly 'C++ Intermediate' tutorial by Peter Thorsteinson Subtopic Classes and Structs
// Recommendation - With any new code, start with these header files and format layout
//
// Description of Program .............  Boiler Plate Template  .............................
// ..........................................................................................
// ..........................................................................................
				
					// Below is what is known as the Preprocessor Directives - in this Header section
					// Under Visual Studio 17  -  replace #include "stdafx.h" with #include "pch.h" to provide same library support						
					// The Preprocessor Directives: (Header Files) 							
#include <iostream> 	// Part of the standard library  -  Used for cout, cin, cerr  ( That is the  reason for brackets < > )
#include <string>		// Part of the standard library  - 'string' class is req to be included as new way of using strings as opposed the old char sequence
#include <ctime>		// Required to implement date and time functions
#include <windows.h>	// Required to implement date and time functions - Some IDE / Complilers do not accept this header file
#include <typeinfo>		// Necessary for imlementing the typeid() function 
#include <memory>		// Necessary when using smart pointers  
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


using namespace std;	// Common practice to implement the "std" namespace as it contains multiple supporting useful functions
/*
						// ##### Necessary for the getconsolewindow() function to work! - works for  running this program on windows 2000 or higher
#define _win32_winnt 0x0500
#include <windows.h>
						// #####
*/
// .............................................   Function Prototype Declaration Code   .............................................
//          Global variables, Function protoypes are place here before main .... if the implementation code is not placed here first

							// Declaring method prototypes in type declaratin is allowed
							// Then they can be defined or implemented in global scope
							// See the statement Car::Car(string make, string model, int year) :
							// for implementation of the struct fields

class Person				// Class or a Struct define a type of object
{							// Class always defaults to private member access
public:
	string firstName;		// Usually these members / parameters / attributes/ fields   . . . are given a private scope
	string lastName;		// Data members have nouns to represent status of the object
	int age = 0;			// Not recommend to not utilize a constructor in a class
};

struct Car					// Structs always defaults to public member access scope
{							// Note here that public does not have to be designates as all structs are public 
	string make;			// Data members are nouns, represent state of the object 
	string model;			// Also known as fields that can be read from or written to
	int year;
							// Constructor for the 'Car' struct shown below here.  
							// Its purpose is to initialize the object when it is instantiated (created)
							// Looks like not having a body here is OK as it is defined below with Car::Car  ???
	Car(string make, string model, int year);
	void displayMembers();	// Methods are the verbs of an object - Actions or operations that the object can perform
};							// Methods are callable, they can be invoked 
							
Car::Car(string make, string model, int year) :
	make(make), model(model), year(year) {}
void Car::displayMembers()
{
	cout <<
		" Make: " + make + ", Model: " + model + ", " + " Year: " + to_string(year) << endl;
}


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


	cout << "\n\n >>>>>>>>>>>>>>>>>>>>>>>>>>   Main Code Execution   <<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	cout << "          Resident / Location -  void main() code is orchestrated here              " << endl;
											// Object person1 created, allocated on a stack frame - No constructor with Person which is unusual
	Person person1;							// Instaintiated person object 'person1' Instances of variables are called objects
	person1.firstName = "Thomas";			// Assign parameters/fields to object person1 (This works because 'Person' class has no constructor
	person1.lastName  = "Ricci";			
	person1.age = 72;
	cout << "\n" << endl;
	cout << " Person Attributes: " << person1.firstName << " " << person1.lastName << " " << person1.age << endl; 
								// Class Car does have a constructor - so alternate syntax from above is used
								//Original initialization syntax: >>> Car car1 = { "Toyota", "4-Runner", 1997 };  <<<
	cout << "\n" << endl;
	Car car1("Toyota", "4-Runner", 1997);
	cout << " Car attributes: ";
	car1.displayMembers();
	cout << "\n" << endl;

	system("pause");			// Some compilers do not recognize this statement
	return 0; 					// Indicates successful termination
}								// End of main

// .................................................   Function Code Implementation  .............................................
//    When functional coded is declared above before the main coding section use this area for functional code implementation

/*

|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|
01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
		  |         |         |         |         |         |         |         |         |
		  10        20        30        40        50        60        70        80        90
*/