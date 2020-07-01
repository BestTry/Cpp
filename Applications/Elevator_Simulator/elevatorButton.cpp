// Class Definition Implementation File: elevatorButton.cpp: 
// Member-function definitions for class ElevatorButton.
// 
// ElevatorButton Operation: Signals elevator to move, resets elevator button
//
#include <iostream>
#include "elevatorButton.h"  // ElevatorButton class definition
#include "elevator.h"        // Elevator class definition

using std::cout;
using std::endl;


ElevatorButton::ElevatorButton(Elevator& elevatorHandle)    // Constructor - Initializes 'pressed' to false
    : pressed(false), elevatorRef(elevatorHandle)
{
    cout << " Elevator-button constructed" << endl;
}                                                           // End ElevatorButton constructor


ElevatorButton::~ElevatorButton()                           // Destructor
{
    cout << " Elevator-button destructed" << endl;
}                                                           // End ~ElevatorButton destructor


void ElevatorButton::pressButton()                          // Press button and signal elevator 
{                                                           // to prepare to leave floor
    pressed = true;
    cout << " Elevator-button notifies elevator to prepare to leave" << endl;
    elevatorRef.prepareToLeave(true);
}                                                           // End function pressButton


void ElevatorButton::resetButton()                          // Reset button
{
    pressed = false;
}                                                           // End function resetButton

