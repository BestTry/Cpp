// Classes_PointerAllocated.cpp : Code example was pulled from textbook: "C++ Control Structure Though Objects" - Tony Gaddis
// Description of Program: In this code pointers were instantiated pointing to objects.  Object names were not created only
// their pointer names were created.
// ......................................................................................................................................

						// Below is what is known as the Preprocessor Directives - in this Header section
						// Under Visual Studio 17  -  replace #include "stdafx.h" with #include "pch.h" to provide same library support						
						// The Preprocessor Directives: (Header Files) 							
#include <iostream> 	// Part of the standard library  -  Used for cout, cin, cerr, printf  ( That is the  reason for brackets < > )
#include <string>		// Use the s suffix for literal strings 'string' class - required as a new way of using strings, non char sequence
#include <ctime>		// Required to implement date and time functions
#include <windows.h>	// Required to implement date and time functions - Some IDE / Complilers do not accept this header file
#include <typeinfo>		// Necessary for imlementing the typeid() function 
#include <memory>		// Necessary when using smart pointers. Syntax: unique_ptr<int> ptrName( new int );
#include <array>		// Necessary when using the array class i.e array<arrType, size>
#include <vector>		// Support vector operations - See inputDate
						// Before compiling symbol '#' indicates a preprocessing contents of  
						// the input/output stream header file iostream.  This file must be 
						// included with any keyboard input or console screen output
						// Functions within the standard library are as follows:
						// Since classes below are part of C++ stadard library < > are placed around them
#include <cmath>		// Enables the use of the "pow" function with the math library and other mathematical functions
#include <functional>	// References the standard function library - std::function
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
						//
						// ##### Necessary for the 'GetConsoleWindow()' function below to work! - on Windows 2000 and later
#define _win32_winnt 0x0500
#include <windows.h>
						// #####

// ..............................................   Function Prototype Declaration Code   ..............................................

class Rectngl								// Rectangle class declaration 
{
private:									// Attributes/Fields/Parameters
	double length;
	double width;
	double area = 0.0;

public:										// Constructors - Note constructors are in Declaration block - See Definition block
	Rectngl(); 								// Default Constructor Declaration
	Rectngl(double len, double wth);		// Alternate Constructor syntax unitializing object attributes thru parametrs
	
	void setLength(double);
	void setWidth(double);
	double getLength() const;				// see block below for class definitions / method implementations using this syntax
	double getWidth() const;
	double getArea() const;


	// Intialization constructor !!! This is the PREFFERED constructor syntax !!!
/*Rectngl(int len, int wth) : length(len), width(wth)
{
	area = 0.0;
	cout << "Rectangle Object has be instantiated \n ";
	cout << "Lenth: " << length << "\n";
	cout << "Width: " << width << "\n" << endl; area = length * width;
	cout << "Area: " << area << endl;
}*/
};											// End Rectangle class declaration 


// .............................................   Member Function Declaration    .....................................................
	//  >>>>>>>> declarations below must be followed up by a block of member function implementation <<<<<<<<
void exitPrgm();							// Use this function as a optional default to terminate the program


// ....................................................................................................................................

int main()									// Function main(...) begins program execution - Entry point for the program
{
	// ##############################################################
	// Modify position and size of Console Application Window
	HWND console = GetConsoleWindow();		// Get the console handle
	RECT r;									// Stores the console's current dimensions
	GetWindowRect(console, &r);				// MoveWindow(window_handle, x, y, width, height, redraw_window);
	MoveWindow(console, 1400, 500, 600, 900, true);
	// ###############################################################


	cout << "\n\n   >>>>>>>>>>>>>>>>>>>>   Main Code Execution   <<<<<<<<<<<<<<<<<<" << endl;
	cout << "     Class - Object Instantiation/Implementation Using Pointers \n\n" << endl;


	// Preparation for instantiation of rectangle objects i.e room of house
	double dimLgth;							// Use and re-use variables for constructions of rectangle objects
	double dimWdth;

	Rectngl* PtrBedRoom = nullptr;			// Pointers created to rooms
	Rectngl* PtrGamRoom = nullptr;
	Rectngl* PtrDenRoom = nullptr;

	PtrBedRoom = new Rectngl;				// Dynamically allocate objects:- Creates pointers to the objects
	PtrGamRoom = new Rectngl;				// Using pointers to the object 
	PtrDenRoom = new Rectngl;				// instead of using object names - As in syntax: Rectngl bedRoom;

	dimLgth = 20.5;							// Length dimension		Bedroom
	dimWdth = 15.0;							// Width dimension		Bedroom
	PtrBedRoom->setLength(dimLgth);			// When pointers are used for object use  
	PtrBedRoom->setWidth(dimWdth);			// the -> operator to assign attributes	

	dimLgth = 30.3;							// Length dimension		Game Room
	dimWdth = 25.0;							// Width dimension		Game Room
	PtrGamRoom->setLength(dimLgth);			// When pointers are used for object use  
	PtrGamRoom->setWidth(dimWdth);			// the -> operator to assign attributes	

	dimLgth = 12.2;							// Length dimension		Den Room
	dimWdth = 14.4;							// Width dimension		Den Room
	PtrDenRoom->setLength(dimLgth);			// When pointers are used for object use  
	PtrDenRoom->setWidth(dimWdth);			// the -> operator to assign attributes	

	cout << " Total area of three rooms: Bedroom, Game & Den:" << endl;
	cout << " Total area of all three rooms:    -->  " <<
		PtrBedRoom->getArea() +
		PtrGamRoom->getArea() +
		PtrDenRoom->getArea() << "  <-- " << endl;

	cout << "\n\n Standard way of instantiating objects using initializing paramemters " << endl;
	cout << " Method intantiates object using an object name. Does not use pointers " << endl;
	Rectngl framePicture(1.1, 0.7);			// Instantiating the object with name: 'framePicture'
	cout << " Using alternate syntax of instantiating object, Check object area: " << endl;
	cout << " Area of picture frame is: " << framePicture.getArea() << " feet \n" << endl;

	exitPrgm();								// Option function member to terminate program
	system("pause");						// Some compilers do not recognize this statement
	return 0; 								// Indicates successful termination
}											// End of main

// .............................................   Function Code Definition Implementation  .................................................
//    When functional coded is declared above before the main coding section use this area for functional code implementation

Rectngl::Rectngl() {						// Default Constructor
	area = length = width = 0.0;			// Terminated with ' ; ' after ending brace - ' }; '
};

Rectngl::Rectngl(double len, double wth) {	// Alternate Constructor syntax unitializing object attributes thru parametrs
	length = len;							// Terminated with ' ; ' after ending brace - ' }; '
	width = wth;
	area = (length * width);
	cout << " A Rectangle 'Rectngl' class object has be instantiated " << endl;
};


// Compiloer message states "Constuctor already has a body' so I cannot adopt this block
// Rectngl::Rectngl(double len, double wth) : length(len), width(wth) {
//	area = (length * width);
//	cout << " a rectangle 'rectngl' class object has be instantiated " << endl;
//	cout << " instantiated was accomplishe using prefferred constructor syntax " << endl;
//};

void Rectngl::setLength(double len) {		// Member Methods - Includes bothe Declarations and Definitions - 
	length = len;							// Definitions should be separated outside class for good Engineering
}											

void Rectngl::setWidth(double wth) {		// Scope resolution operator ' :: ' identifies function/method as a memeber of Rectngl class	
	width = wth;
}

double Rectngl::getLength() const {			// Keyword 'const' is used here to guarantee no data will be modified in the calling object
	return length;
}

double Rectngl::getWidth() const {			// Keyword 'const' is used here to guarantee no data will be modified in the calling object
	return width;
}
// setArea member method is not establisehed as it might lead to stale data: 
double Rectngl::getArea() const {			// That is, - lenght & width initialize but no area value was computed
	return (length * width);
}
//

void exitPrgm()
{
	cout << "\n\n           >>>>>>>>>>  Program has Terminated  <<<<<<<<<< " << endl;
	cout << " \n\n\n " << endl;
	exit(0);					// Terminate running program from anywhere it is called:
}

// .............................................   Function Code Definition Implementation  .................................................
/*

|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|
012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
		  |         |         |         |         |         |         |         |         |         |         |         |         |         |
00		  10        20        30        40        50        60        70        80        90		00		  10        20        30        40

*/