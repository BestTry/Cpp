// Class Clock Definiti0n File: clock.cpp
// Member-function definitions for class Clock.
//
// Clock Operation: Ticks every second
//
#include <iostream>
#include "clock.h"								 // Clock class declaration
using std::cout;
using std::endl;

Clock::Clock()                                  // Constructor
	 : time(0)									// Initialize time to 0
{
	cout << " Clock constructed" << endl;
}												// End Clock constructor


Clock::~Clock()									// Destructor		
{
	cout << " Clock destructed" << endl;
}												// End ~Clock destructor


void Clock::tick()								// Increment time by 1
{
	time++;
}												// End function tick


int Clock::getTime() const						// Return current time - Funtiong geTime() is constant
{												//because it does not alter the object of class Clock
	return time;
}												// End function getTime

