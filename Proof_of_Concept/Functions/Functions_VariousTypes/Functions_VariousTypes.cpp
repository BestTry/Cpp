// Functions_VariousTypes.cpp : Code demonstrates the implementation of various typs of functions including recursive and non-recursive,
// Templated Functions, Adding cartesion coordinates, etc.
// 
//
// Description of Program .............  Boiler Plate Template  .............................
// ..........................................................................................
// ..........................................................................................
// ..........................................................................................
//
// Additonal Code Description : Steps Enumerated 
// 1 - 
// 2 - 
// 3 - 
// 4 - 
// 5 - 
// 6 -
// 7 -						
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

						// ##### Necessary for the 'GetConsoleWindow()' function below to work! - on Windows 2000 and later
#define _win32_winnt 0x0500
#include <windows.h>
						// #####

// ..............................................   Function Prototype Declaration Code   ..............................................
// There may be functions that are implemented here as well, not just declarations

double hypotenuse(double, double);			// Global function
inline void hello();						// Inline function - Compiler will decide to compile in line or call it befor run time
int factorialNonRecursive(int);				// Non-recursive implementation of finding factorials
int factorialRecursive(int);				// Recursive implementation of finding factorials
template<typename T> T plusTemplated(T, T );// Templated Function adds types of variables; This type is past @ compile time, not run time

double doCallBack(const std::function <double(double, double)>& f, double x, double y) {
	return f(x, y);
}

double processDoubles(std::vector<double>& vec, const std::function <double(double)>& f) {
	double result = 0;
	for (auto const& value : vec) {
		result += f(value);
	}
	return result;
}
											// All classes must be positioned before main or referenced from a #include						
struct Rect {								// Rectangle class that contains an area member method	
public:
	double w;
	double h;
	Rect(int width, int height) {
		w = width;
		h = height;
	}
	double area() {							// Method - Did not have to indicate within () w or h. above statements satisfied compiler
		return (w * h);
	}
};



//struct Rectangle {								// Rectangle class that contains an area member method	
//public:
//	double w;
//	double h;
//	Rectangle() : w(0), h(0) {}					// Initializes double types width and height when called without arguments
//	Rectangle(int w, int h) : w(w), h(h) {}		// Initializes int types width and height when called with arguments
//	double area() {								// Method - Did not have to indicate within () w or h. above statements satisfied compiler
//		return (w * h);
//	};
//};


class Coor {
public:
	double x;
	double y;
	double lenth() {
		return hypotenuse(x, y);
	}
	Coor() : x(), y() {}
	Coor(int x, int y) : x(x), y(y) {}

	Coor operator+ (const Coor& rhs) {			// Operator Overload method - overloading the ' + ' operator
		Coor coor;
		coor.x = this->x + rhs.x;
		coor.y = this->y + rhs.y;
		return coor;							// Returning the new object having new coordinates that are	the sums of												
	}											// the original x and y coordinates and the new x and y coordinates.
};


void exitPrgm();							// Use this function as a optional default to terminate the program

// .....................................................................................................................................

int main()									// Function tmain(...) begins program execution - Entry point for the program
{
											// ##############################################################
											// Modify position and size of Console Application Window
	HWND console = GetConsoleWindow();		// Get the console handle
	RECT r;									// Stores the console's current dimensions
	GetWindowRect(console, &r);				// MoveWindow(window_handle, x, y, width, height, redraw_window);
	MoveWindow(console, 1400, 500, 700, 1000, true);
											// ###############################################################
	

	cout << "\n\n >>>>>>>>>>>>>>>>>>>>>>>>>>>>   Main Code Execution   <<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	cout << "            Examples of Various Types of Functions            " << endl;

	{											// ***** Library function call *****
		double param, result;
		param = 256.10;
		result = sqrt(param);					// Library function calling from math.h
		std::printf("sqrt(%f) = %f\n", param, result);
	}											// printf is a formating function

	{											// ***** Global function call *****
		cout << "hypotenuse: " << hypotenuse(3, 4) << endl;
	}	

	{											// ***** Class Member Method Call *****
		Rect newRect(10, 20);					// Insantiate a rectangle then call on its area method
		cout << "Rectangle area: " << newRect.area() << endl;;
	}

	{											// ***** Inline functions *****
		hello();								// Call inline function like any normal function
		hello();								// Call inline function like any normal function
	}

	int factNum = 7;							// ***** Recursive Functions *****
	cout << " Non - Recursive: Factorial of number " << factNum << " is: " << factorialNonRecursive(factNum) << endl;
	cout << " Yes - Recursive: Factorial of number " << factNum << " is: " << factorialRecursive(factNum) << endl;

	{											// ***** Templated Functions *****
		cout << "Using Templated Functions (TF) add: " << endl;
		cout << "Using (TF) add (3 + 4): " << plusTemplated(3, 4) << endl;				// Add integers
		cout << "Using (TF) add (3.3 + 4.4): " << plusTemplated(3.3, 4.4) << endl;		// Add doubles
	 // cout << "Using (TF) add (\"3\" + \"4\"): " << plusTemplated("3", "4") << endl;	// No! can't add two chars 'pointers'
																						// Concatenate strings - Yes!
		cout << "Using (TF) add (\"3\"s + \"4\"s): " << plusTemplated("3"s, "4"s) << endl; 
		
		Coor coor = plusTemplated(Coor(3, 4), Coor(5, 6));								// Add custom coordinates
		cout << "Using (TF) add (Coor(3, 4) + Coor(5, 6)): " <<							// Vector addition results
			"coor x: " << coor.x << " " << "coor y:" << coor.y << endl;

	// Rect rect2 = plusTemplated(Rect(3, 4), Rect(5, 6));								// No! 	Did not overload the 'Rect'
	// cout << rect2.w << ", " << rect2.h << endl;										// core type with the 'operator+'
	}																					// But the Coor type does see code

	{											// ***** Lambda Functions *****
												// Function called without a function name, just a variable name (anoymous function)
												// Right hand side of the function is the implementation of the lamda function
		auto lamdaFnct = []() { return 42; };	// Square bracket intoduce the lambda syntax, Contents within brackets called 'closure'
		cout << "lamdaFnct() = " << lamdaFnct() << std::endl;

		double result = doCallBack([](double a, double b) { return (a + b); }, 3, 4);
		cout << "DdoCallBack() Lamda result: " << result << endl;
												// Below sum of squares implemented: 1 + 4 + 9 + 16 = 30
		std::vector<double> vecV = { 1.0, 2.0, 3.0, 4.0 };
		cout << "processDoubles Lamda result: " <<
		processDoubles(vecV, [](double value) { return value * value; }) << endl;

	}

	// TODO:  To find TODOs ...  Go to >   View  >   Task List      TODO:TODO:TODO:TODO:TODO:TODO:TODO:TODO:TODO:TODO:TODO:TODO:

	exitPrgm();					// Option function member to terminate program
	system("pause");			// Some compilers do not recognize this statement
	return 0; 					// Indicates successful termination
}								// End of main

// .............................................   Function Code Definition Implementation  .................................................
//    When functional coded is declared above before the main coding section use this area for functional code implementation

double hypotenuse(double x, double y)			// Global function
{
	return sqrt((x * x) + (y * y));				// Function sqrt hosted by the header include 'funtional'
}

inline void hello() {							// Keyline is a hint to compiler (Not a directive to compiler) Compiler makes decision
	cout << "Hello from Inline Funtion" << endl;
}

int factorialNonRecursive(int num){				// Non-recursive implementation of finding factorials
	int fact = num;
	while (num !=1){
		fact *= (--num);
	}
	return fact;
}

int factorialRecursive(int num) {				// Recursive implementation of finding factorials
	while (num > 1)								// Next Line: (num--) or (--num) below does NOT work; I think  
	{											// case 1 result infinit loop; case 2 it modifies first num factor too
		return ((num * factorialRecursive(num-1)));
	}
	return 1;
}												// Compile time oriented
												// Generic Function - compiler produces different versions of function for diff types
template<typename T> T plusTemplated(T param1, T param2) {
	return (param1 + param2);					// Compiler figures out what type is appropriate at compile time
}												// Takes parameters of 'T's and returns results of type 'T's
												// The 'T's are place holders for actual types which compiler will determine
void exitPrgm()
{
	cout << "\n                  >>>>>>>>>>  Program has Terminated  <<<<<<<<<< " << endl;
	cout << " \n\n\n " << endl;
	exit(0);									// Terminate running program from anywhere it is called:
}


/*

|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|
012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
		  |         |         |         |         |         |         |         |         |         |         |         |         |         |
00		  10        20        30        40        50        60        70        80        90		00		  10        20        30        40

*/