// ReferenceTypeArguments.cpp :
// Example and introduction to References and Reference Parameters  -  Retreived form C++ How to program textbook by Deitel 4th edition - Chapter 3
// Code compares pass by value parameter function with similar pass by reference parameter
// Think of a reference name as an alias name for the same variable content


#include <iostream>  						// Include iostream for the following using invocations
#include<iomanip>							// This include is needed to impliment the setprecision() function as demonstrated below

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::fixed;   						// need this when used with "setprecision()" which is under the namespace <iomanip>
using std::setprecision;

#define _win32_winnt 0x0500					// necessary for the getconsolewindow() function to work! - works for  running this program on windows 2000 or higher
#include <windows.h>



int sqrByVal(int);							// Function prototype - Declaration of function taking a int value as an argument
void sqrByRef(int&);						// Function prototype - Declaration of function taking a reference as an argument 


int main()
{

	// Modify position and size of Console Application Window
	HWND console = GetConsoleWindow();		// Get the console handle
	RECT r;									// Stores the console's current dimensions
	GetWindowRect(console, &r);				// MoveWindow(window_handle, x, y, width, height, redraw_window);											
	MoveWindow(console, 1400, 500, 600, 500, true);

	int x = 2;								// Value of x 
	int y = 4;								// Value of y


	cout << "\n\n\n" << endl;

	// Demonstrate square by value
	cout << "   x = " << x << " before invoking the squareByValue function" << endl;
	int sqrValue = sqrByVal(x);
	cout << "   Value returned by squareByValue(x) is: " << sqrValue << endl;
	cout << "   Notice that x = " << x << " remains same after invoking the \n   squareByValue function \n\n" << endl;

	cout << "   x = " << x << " before invoking the squareByRef function" << endl;
	sqrByRef(x);
	cout << "   Value within the reference of x is: " << endl;
	cout << "   x = " << x << " has changed after invoking the squareByRef function\n\n" << endl;

	cout << "   Another example demonstration of references " << endl;
	int s = 11;								// Value of r 
	int& refS = s;							// The variable refS becomes an alias of s or a reference to s

	cout << "   After assigning s=11 and & refS = s" << endl;
	cout << "   s = " << s << " and refS = " << refS << endl;
	refS = 0;
	cout << "   After re-assigning refS=0" << endl;
	cout << "   s = " << s << " and refS = " << refS << endl;
	refS = y;								// From above the value of y is equal to 4
	cout << "   After re-assigning refS=y with y=4, refS = " << refS << endl;

	cout << "\n\n\n" << endl;

	return 0;								// Indicates successful termination

};											// End of main

// ..........................................................   Function Code   ........................................................................

int sqrByVal(int paramX)				// squareByValue multiplies the number by itself, stores the result and returns it
{										// Compound operator is used here x *= x which is equivalent of (x = x * x) 
	return (paramX *= paramX);			// Caller parameter int x is not modified
}

// squareByReference multiplies the reference number by itself and 
// Stores the result in the variable to which the reference number 
// refers in the function main  The '&' symbol specfies paramX is a reference
void sqrByRef(int& paramX)
{										// Compound operator is used here x *= x which is equivalent of (x = x * x) 
	paramX *= paramX;					// Caller parameter int &x is modified
}


