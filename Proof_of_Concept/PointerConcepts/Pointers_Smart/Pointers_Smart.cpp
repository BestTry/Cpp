// Pointers_Smart.cpp : Console Application. Console applications are the simplest using text for input / output
// Code Example lifted from Tutorial by O'Reilly - C++ 11 Intermediate by Peter Thorsteinson
//
// Description of Program .... Smart Pointers (Safer than raw pointers) ...Automatically deleted..............
// Smart Pointer manage the pointers of objects within the 'Heap'  - Three types:
// Unique Pointers - Only one owner of an object. (Best Choice) Can be moved to another owner (Change ownership) ..
// Shared Pointers - More than 1 variable pointing to same object (Reference Pointer) - There is a control pointer in play
// Weak Pointers - Part of Shared pointers: Observer type pointer
// Smart Pointers manage objects in the 'Heap'
// Only use smart pointers: protects memory leaks through failing to delete an object or deleting pointer to that object.


					// Below is what is known as the Preprocessor Directives 
					// Under Visual Studio 17  -  replace #include "stdafx.h" with #include "pch.h" to provide same library support						
					// The Preprocessor Directives: 							
#include <iostream> 	// Part of the standard library  -  Used for cout, cin, cerr  ( That is the  reason for brackets < > )
#include <string>		// Part of the standard library  - 'string' class is req to be included as the new way of using strings as opposed the old char sequence
#include <ctime>		// Required to implement date and time functions
#include <windows.h>	// Required to implement date and time functions
#include <typeinfo>		// Necessary header file for implementing the typeid() function 
#include <memory>		// Necessary header file when using smart pointers 
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
#include <windows.h>	// #####
						
// ..........................................   Function Prototype Declaration and Implementatin Code   .............................................
class Coor							// Class Coordinates defined here as 'Coor'
{
public:
	Coor(int x, int Y) : x(x), y(y) { Coor::count++; }   	// Constructor increments static count when an object is instantiated
	~Coor() { Coor::count--; }								// Destructor decrements the static count global variable before distruction
	int x;
	int y;
	static long count;										// count in the class Coor should not be is initialized within the class
};															// Before it is even instantiated/initiated
long Coor::count = 0;										// count is initialized outside the class and in global scope!
									

void  UseRawPointer()					// If raw pointers used make sure object pointer and object is deleted
										// Confirm variables that used the object/pointer were deleted or set to null
{  										// The 'new' keyword creates an object & in this case a pointer to a object of class Coor
	Coor* PtrCoor = new Coor(1, 2);		// Create raw pointer (This is NOT recommended)
	cout << " Using object, Coor::count " << Coor::count << endl;
	// ^^^^^^^^^^^^^^^ Use raw pointers here  ^^^^^^^^^^^^^^^^^^^^
	delete PtrCoor;						// Delete raw pointer after its use ???? What if you forget this ?????
										// ^^^^^^^^^^^^^^^ Delete the raw pointer here  ^^^^^^^^^^^^^^^^^^^^
										// Delete ONLY once - if more than once huge problems will launch
}
// ...................................................................................................................................................
// ...................................................................................................................................................

										// A Better Pointer - Better way - Use only smart pointers! (Recommended)
void UseSmartPointer()					// Purpose of smart pointers is to automatically manage objects in the heap
{										// Create Smart Pointer (Recommended)
										// The 'new' keyword creates a pointer to a object of class Coor
										// Here 'PtrCoorSmart' - a smart pointer rapper object to the raw pointer
										// Which is the raw pointer instantiated with 'new Coor(3,4)'
										// Appears the <syntax> creates the smart pointer PtrCoorSmart
										// Or ??? is 'unique_ptr' a keyword that makes is a smart unique pointer?
										// Keyword 'unique_ptr' is a generic type class that automatically deletes pointer/object
										// The PtrCoorSmart object intelligently wraps the dumb raw pointer in the Coor class
	unique_ptr<Coor> PtrCoorSmart(new Coor(3, 4));
										//     >>>>>   Using the smart pointer here    <<<<<<  
	cout << " Using object, Coor::count " << Coor::count << endl;
										// ^^^^^^^^^^^^^^^^^^^ Using Smart Pointer Here  ^^^^^^^^^^^^^^^^^^^^^^^
										// Do not explicitly delete raw pointer!	
}										// Smart pointer is deleted automatically here at this curly brace .... 



int main()									// Function tmain(...) begins program execution - Entry point for the program
{
											// ##############################################################
											// Modify position and size of Console Application Window
	HWND console = GetConsoleWindow();		// Get the console handle
	RECT r;									// Stores the console's current dimensions
	GetWindowRect(console, &r);				// MoveWindow(window_handle, x, y, width, height, redraw_window);
	MoveWindow(console, 1400, 500, 1600, 1500, TRUE);
											// ###############################################################
	
	cout << "\n\n >>>>>>>>>>>>>>>>>>>>>>>>>>   Example Code  <<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;

	// Raw Pointers
	{
		cout << " Raw Pointrs ...  " << endl;
		cout << " About to create object using raw pointer, Coor::count " << UseRawPointer();
		cout << " Finished with raw pointer, Coor::count " << Coor::count << endl;
	}
	// Smart Pointers ...
	{
		cout << " Smart pinters ... \n";
		cout << " About to create object using smart pointer, Coor::count " << UseSmartPointer();
		cout << " Finished with smart pointer, Coor::count " << Coor::count << endl;
	}
	// Unique Smart Pointers ...  !!! If possible only use unique pointers
	{
		cout << " Unique Smart Pointers... \n";
		cout << " About to create object using make_unique, Coor::count " << endl;
		// make_unjique is implemented for exception safety
		// use make_unique instead of calling unique_ptr ctor directly (make_unique: a wrapper)
		unique_ptr<Coor> Ptr1 = make_unique<Coor>(5, 6);

		cout << " About to move unique pointer using std::move, Coor::count" << endl;

		// Move raw pointer from one unique_Ptr to another (Change ownership to pointers)
			unique_ptr<Coor> Ptr2 = std::move(Ptr1);
		cout << " Finished with moving unique pointer using std::move, Coor::count " << endl;
	}
	cout << " Finished with unique pointers scope, Coor::cont " << Coor::count << endl;

	// Shared Smart Pointers ...
	{
		cout << " Shared Smart Pointers ... \n" << endl;
		cout << " About to create object using make_shared, Coor::count" << endl;
		auto ShrPtr1 = make_shared<Coor>(7, 8);
		cout << " Shared pointer use count for ShrPtr1 " << ShrPtr1.use_count() << endl;
		auto ShrPtr2 = shared_ptr<Coor>(nullptr);
		cout << " Shared pointer use count for ShrPtr2 " << ShrPtr2.use_count() << endl;
		cout << " About to assign ShrPtr2 = ShrPtr1, Coor::count " << Coor::count << endl;
		ShrPtr2 = ShrPtr1;
		cout << " Finished assignment ShrPtr2 = ShrPtr1, Coor::count " << Coor::count << endl;
		cout << " Shared pointer use count for ShrPtr1 " << ShrPtr1.use_count() << endl;
		cout << " Shared pointer use count for ShrPtr2 " << ShrPtr2.use_count() << endl;
	}

	// Weak Smart Pointers ...
	{										// Weak pointer are observers and will get destroyed
		cout << " Weak Smart Pointers ... \n" << endl;
		cout << " About to create object using make_shared, Coor::count " << endl;
		auto ShrPtr1 = make_shared<Coor>(9, 10);
		cout << " Shared pointer use count for ShrPtr1 " << ShrPtr1.use_count() << endl;
		weak_ptr<Coor> ShrPtr2;				// Weak pointers DO NOT contribute to the use counter of an object
		cout << " Shared pointer use count for ShrPtr1 " << ShrPtr2.use_count() << endl;
		cout << " About to assign ShrPtr2 = ShrPtr1, Coor::count " << Coor::count << endl;
		ShrPtr2 = ShrPtr1;
		cout << " Finished assignment ShrPtr2 = ShrPtr1, Coor::count " << Coor::count << endl;
		cout << " Shared pointer use count for ShrPtr1 " << ShrPtr1.use_count() << endl;
		cout << " Shared pointer use count for ShrPtr2 " << ShrPtr2.use_count() << endl;
	}

	cout << " Finished with entire program, Coor::count " << Coor::coor << endl;

	system("pause");
	return 0; 					// Indicates successful termination
}								// End of main

// .............................................   Function Code Implementation  .............................................

