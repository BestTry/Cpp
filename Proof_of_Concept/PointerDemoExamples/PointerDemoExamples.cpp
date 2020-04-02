// PointerDemoExamples.cpp : Console Application. Console applications are the simplest using text for input / output
// Code Example lifted from C++ Tutorial by O'Reilly - C++ 11 Intermediate by Peter Thorsteinson		
//
// Description of Program .............  Pointers (Raw Pointers   ...........................
// ..........................................................................................
// ..........................................................................................
// ..........................................................................................
//
// Additonal Code Description : Steps Enumerated 
// 1 - Declare a pointer with the '*' 'indirection' operator, then use the '&' 'address of' operator to define its address
//     the '*' operator is sometimes called the 'dereferencing' operator
// 2 - Demo of using pointer arithmetic.
// 3 - Demo of using constant pointers together with constant variables
// 4 - Pointers to heap objects using the keyword 'new'
// 5 - Pointers to member operators
// 6 - Pointers to string literals (chars)
// 7 -						
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
#include <windows.h>
						// #####
// .......................................................   Function Prototype Declaration Code   ........................................................

void swapChars(char* Ptr1, char* Ptr2);	// Note there is no return parameter in this function (void)
											// Suggested practice to include in the pointer variable name 'p' or "Ptr"
int main()									// Function tmain(...) begins program execution - Entry point for the program
{
											// ##############################################################
											// Modify position and size of Console Application Window
	HWND console = GetConsoleWindow();		// Get the console handle
	RECT r;									// Stores the console's current dimensions
	GetWindowRect(console, &r);				// MoveWindow(window_handle, x, y, width, height, redraw_window);
	MoveWindow(console, 1400, 500, 830, 770, TRUE);
											// ###############################################################
	  
	cout << "\n\n >>>>>>>>>>>>>>>>>>>>>>>>>>   Example Code  <<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	cout << " 			  Swapping characters at two different addresses 				 " << endl;
	char a = 'A';
	char b = 'B';
	cout << " Contents at address1 = " << a << " Contents at address2 = " << b << endl;
	cout << " Call swap character function to exchange contents of address: " << endl;
	swapChars(&a, &b);			// Address operator '&' sends the addresses of the variables a and b
	cout << " Re-display the contents of the addresses once again after swap call" << endl;
	cout << " Contents at address1 = " << a << " Contents at address2 = " << b << endl;;

	cout << "\n *****  Example of using pointers: 'address of' operator '&' and indirection operator '*' ***** " << endl;
	int x = 5, y = 15;			// Declare, defines x and y values.
	int* PtrX, * PtrY;			// Declare x/y pointers - note syntax requires the '*' operator prefixed for both variables
	PtrX = &x; PtrY = &y;		// Assigning the addresses (pointers) for the x and y variables
	*PtrX = 10; 				// Changing the value of x using the indirection/dereferncing operator
	*PtrY = *PtrX;				// Equate y value to x value (y <- x) using the indirection/dereferncing operator '*'
	PtrX = PtrY;				// Equate pointers - Only pointer pointing to original y variable now exists (PtrY)
	*PtrX = 20;  				// This sets variable y (same address) to the value of 20
	cout << " The value of x is now: " << x << ", the value of y is now: " << y << " Is this correct? " << endl;

	cout << "\n\n >>>>>>>>>>>>>>>>>>>>>>>>>>   Example Code  <<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	cout << " 		 Pointer Arithmetic and Array Indexing				     " << endl;
	int numArry[6];				// Declare an integer type array of sizeof 6 with indexes [0] ... [5] = 4x6 -> 24 bytes
	int* PtrNumArry;			// Declare a pointer that will subsequently point to the integer type array: numArry
	PtrNumArry = numArry;       // Set pointer to the first element of the numArry
	*PtrNumArry = 11;			// Assign the first element [0] of the array 'numArry' to the integer 11
	*(PtrNumArry + 1) = 22;		// Assign the second element [1] of the array to integer 22 (address + 4 bytes)
	PtrNumArry += 2;			// Move pointer of the array to the third element of array [2] (pointer arithmetic)
	*PtrNumArry = 33;			// Assign the integer 33 to the third element [2} of the numArry.
	PtrNumArry = &numArry[3];	// Move pointer to the fourth element in the array numArry[3]
	*PtrNumArry = 44;			// Insert interger 44 into the forth element of the array, numArry[3]
	PtrNumArry = numArry + 4;	// Move pointer to the fifth element in the array, numArry[4] 
	*PtrNumArry = 55;			// Insert interger 55 into the fifth element of the array, numArry[4]
	PtrNumArry = numArry;		// Reset pointer back to first element in the array numArry[1]
	*(PtrNumArry + 5) = 66;		// Insert integer 66 into the sixth element in the numArry, numArry[5]
	cout << " Checking the contents of the number array " << endl;
	for (int i = 1; i < 6; i++)
	{
		cout << "Elem" << i << " = " << numArry[i] << ", " << endl;
	}
	cout << endl;

	cout << " Increment and decrement operators - effects of prefix vs suffix operations " << endl;
	PtrNumArry = numArry;				// Set array pointer to the first element[0] of the numArry
	cout << *(PtrNumArry++) << endl;   	// Display contents of element[0] (Suffix Mode)
	PtrNumArry = numArry;				// Set array pointer to the first element[0] of the numArry
	cout << *(++PtrNumArry) << endl;   	// Display contents of element[1] (Prefix Mode)

	cout << " Pointers, const pointers, pointers to const" << endl;
	int x1 = 1, x2 = 2;					// Address asigninments initialized to x1  Read Backwards to get definition
	int* pointer_to_int = &x1;
	int const* pointer_to_const_int = &x1;				// Variable the pointer points to is constant (Read backwards - right to left
	int* const 	const_pointer_to_int = &x1;				// Variable to pointer is constant
	int const* const const_pointer_to_const_int = &x1;	// Both pointer and pointer address content is constant

	// const_pointer_to_int = &x2; ####### No - illegal! 
	// *pointer_to_const_int = 99; ####### No - illegal!

	cout << " Pointers to heap objects - Values displayed using alternate methods of displaying its memebers:" << endl;
	class Coor							// Coordinates class (Has no constructors)
	{
	public:
		int x = 3;						// Public members (Fields/Parameters/Attributes)
		int y = 4;
	};									// This class does not have a constructor .... 
										// So pararameter are passed this way:
	Coor* PtrCoor = new Coor();			// Create new pointer of the class Coor on the heap.  Keyword 'new' creates a pointer
	PtrCoor->x = 33;					// Alternate method of accessing object's member (Field) via a pointer (altenate to dot notation)
	(*PtrCoor).y = 44;					// Alternate method accessing object's member (Field) via a pointer (Dereference first)
	cout << " PtrCoor->x = " << PtrCoor->x << ",   " << "(*PtrCoor).y = " << (*PtrCoor).y << "\n" << endl;

	cout << " Pointer to member operator - Alternate Syntax Demo" << endl;
	int Coor::*PtrMx = &Coor::x;		// Pointer declaration  /// Address declaration
	Coor coor;
	coor.x = 333;						// Direct access to the member
	cout << "coor.x -> " << coor.x << endl;
	coor.*PtrMx = 333;					// Pointer to member access
	cout << "coor.x -> " << coor.x << endl;

	cout << " Pointer to member operator alternate method" << endl;
	Coor* PtrCoor2 = new Coor();
	PtrCoor2->y = 444;
	cout << "PtrCoor2->y -> " << PtrCoor2->y << endl;
	PtrCoor2->*PtrMx = 4444;			// Pointer to member access  ??????????????
	cout << "PtrCoor2->y -> " << PtrCoor2->y << endl;

	cout << " Pointers to string literals" << endl;
	// Strings literal are arrays containg null-terminated character sequences
	const char* charSeq = "abcdef";	// charSeq[6] Ends with a '\0' null; // charSeq[0] = 'A'; ####### No - illegal!
										// Character strings in C++ are not immutable within "   quotes    "
	cout << "Character sequence is a string: " << charSeq << endl;
	cout << "charSeq type is: '" << typeid(charSeq).name() << "' using the 'typeid(charSeq).name()' syntax " << endl;
	// Keyword 'typeid' returns a reference to an object of class type_info that contains
	// the info about the type of its operand, including name of the data type
	// The member 'name' returns a string that contains the member type name

	char* charSeq2 = new char[7]{ 'a','b','c','d','e','f','\0' };	 // charSeq[0] = 'A'; Will work this time
	// charSeq[0] = 'A'; 	??????		// OK    ..... Note strings end with a null character '/0'
	charSeq2[0] = 'A';
	cout << "Character sequence is a string: " << charSeq2 << endl;
	cout << "charSeq type is: " << typeid(charSeq2).name() << endl;
	/*
	The void keyword often represents the absence of value, such as a function that returns void.
	Howerver, when used in t he declaration of a pointer, void indicates a univeral type pointer.
	Thus void pointers are flexiabile in that they point to any data type.
	But they are limited in that the data pointed at cannot be directly dereferenced.

	Of course, pointers to pointers is legal

	Invalid pointers versus null pointers  .....
	either the integer value of zero, or twith the nullptr keyword
	Do not confuse null pointers with void pointers
	A null pointer points to nowshere and has no type.
	A void pointer can point to anywhere without specifiing a target type.
	*/
	cout << endl;


	system("pause");
	return 0; 					// Indicates successful termination
}								// End of main


// .............................................   Function Prototype Declaration Code   ...........................................


void swapChars(char* char1Ptr, char* char2Ptr)
{								// Swapping character contents of pointers (addresses)
	char char0 = *char1Ptr;
	*char1Ptr = *char2Ptr;	// Exchanging contents using the indirection/dereferencing '*' operand 
	*char2Ptr = char0;
}

/* ================================================================================================================================ */
/*													*** Extra Pointer Example Information ***										*/
/*
Theoretical Example of addressing an integrated circuit chip in computer system.  IC1 address: 0x0500 Write word 0xffff to the IC1

byte IC1Address 	= 0x0500;		// IC1 is an integrated circuit designed (by engineer with gate logic) to be at this address
byte resetCmd		= 0xFFFF;		// Arbitrary made up command hex value 'FFFF'

byte* PtrIC1 = IC1Address;			// Create a pointer to the IC1 integrated circuit (Address pointer defined in bytes)
*PtrIC1		 = resetCmd;			// Address the IC and write data to it - (reset command)
*/

