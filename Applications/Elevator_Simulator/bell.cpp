// Class Bell Definition File: bell.cpp
// Member-function definitions for class Bell.
//
// Bell Operation: Non in problem statement
//
#include <stdio.h>									// Required to ring bell
#include <stdlib.h>									// Required to ring bell
#include <iostream>
#include "bell.h"									// Bell class declaration

using std::cout;
using std::endl;


Bell::Bell()										// constructor
{
	cout << " Bell constructed" << endl;
}													// End Bell constructor


Bell::~Bell()										// Destructor
{
	cout << "Bell destructed" << endl;

}													// End ~Bell destructor


void Bell::ringBell() const							// Rring bell
{
	cout << " Elevator rings its bell \a" << endl;	// Escape sequence '\a' char sounds bell under 'Windows' Op Sys
}													// End function ringBell

