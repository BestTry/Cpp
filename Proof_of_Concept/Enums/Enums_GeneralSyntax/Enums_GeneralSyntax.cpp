// Enums_GeneralSyntax.cpp :  Sourced from O'Reilly On Line Learning: Course Title:  "C++ Intermediate" - Integrity Learning with Peter Thorsteinson
//				
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

						// The double colons is defined as the "Scope Resolution Operator"
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
#include <windows.h>    		// #####

								// .......................................................   Function PrototypeCode   ........................................................
void functionExample(void);		// Function prototype - In C++ every funtion requires a prototype placed before/outside the main block or placed in the 
								// "projectName.h" file - Must then use #include "prjName.h'  Placing the functions in Declaration format here before 'main' 
								// satisfies both the definition & declaration requirements placed in the correspond " *.h " and " *.cpp " files
								// Examples: Day of the week, Months of the year, Colors of rainbow 

// Enums - Defined:Syntax and Details
// Enumeration 'Enums'are a user defined type that consist of a set of named integral constants there are known as enumerators.
// Enumerators define a type.  Then that type can be used to declare variables, classes, data members of classes etc.

	/*										
	// Syntax:  anything in square brackets is optional syntax
	// The [identifier] defines the user defined type name given to the enumeration
	// The [: type] difines the type of integer, The default is 32 bit interger (four byte)
	// The enum list must be unique but they can have the same (duplicate) interger value 

		// *** Unscoped enum
		enum [identifier] [:type]				
		{enum-list};

		// *** Scoped enum (Also called Strongly Typed Enums) - The presense of class||struct makes it scoped enum
		enum [class|struct] [identifier] [:type]  // Less likely of having a collision if the enum is scope with a class/struct 
		{enum-list};
	*/

										// This is a Strongly Typed class enum.  
										// Here the data type is defined as a 'Planet' data type
enum class Planet : std::uint8_t		// Eight bit unsigned interger as data type										
{										// enum values are 0 ... 8 by default (Optionally could assign any any values)
	Mercury=1, Venus, Earth, Mars, Jupiter, Saturn, Uranus, Neptune, Pluto
};

string getName(Planet);
void flyTo(Planet);

int main()									// Function tmain(...) begins program execution - Entry point for the program
{											// ##############################################################
											// Modify position and size of Console Application Window
	HWND console = GetConsoleWindow();		// Get the console handle
	RECT r;									// Stores the console's current dimensions
	GetWindowRect(console, &r);				// MoveWindow(window_handle, x, y, width, height, redraw_window);											
	MoveWindow(console, 1400, 500, 500, 400, true);
											// ###############################################################

	flyTo(Planet::Earth);
	flyTo(Planet::Saturn);
	flyTo((Planet)20);						// Casting an integer to be a Planet type: Integer 20 was casted to a Planet type, 
											// but there is no Planet number 20 in the list, sSo the program display a mystery planet
	cout << endl << endl;
	system("pause");
	return 0; 					// Indicates successful termination
}								// End of main

								// ............................................   Function Definition Code   .............................................................

string getName(Planet planet)
{
	switch (planet)				// Because the enum 'Planet' is scoped the planet names must be prefixed by ' Planet:: '
	{
	case Planet::Mercury: 	return "Mercury";
	case Planet::Venus: 	return "Venus";
	case Planet::Earth: 	return "Earth";
	case Planet::Mars: 		return "Mars";
	case Planet::Jupiter: 	return "Jupiter";
	case Planet::Saturn: 	return "Saturn";
	case Planet::Uranus: 	return "Uranus";
	case Planet::Neptune: 	return "Neptune";
	case Planet::Pluto: 	return "Pluto";
	default: 				return "Mystery";
	}
}

void flyTo(Planet planet)
{
	cout << "Destination: " << getName(planet) << "... ";
	if (planet == Planet::Earth)	// Enumerator must be qualified
	{
		cout << "Already here!" << endl;
	}
	else
	{						// Casting the Planet type enum to be an integer
		cout << "going to planet # " <<
			std::to_string((int)planet) << "..." <<  endl; 
	}
}

