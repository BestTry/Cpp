// Class FloorButton Definition Implementation File: floorButton.cpp
// Member-function definitions for class FloorButton.
//
// FloorButton Operation: Summons elevator
//
#include <iostream>
#include "floorButton.h"
#include "elevator.h"

using std::cout;
using std::endl;


FloorButton::FloorButton(int floor, Elevator& elevatorHandle)   // Constructor using the 'Initialization Member List' syntax
    : floorNumber(floor),
      pressed(false),
      elevatorRef(elevatorHandle)
{
    cout << " Floor " << floorNumber
        << " floor-button constructed" << endl;                  // Floor button created / instantiated
}                                                               // End FloorButton constructor


FloorButton::~FloorButton()                                     // FloorButton Destructor
{
    cout << " Floor " << floorNumber
        << " floor-button destructed" << endl;
}                                                               // End ~FloorButton destructor


void FloorButton::pressButton()                                 // Press the floor button
{
    pressed = true;
    cout << " Floor " << floorNumber
         << " button pressed: Summons elevator" << endl;
    elevatorRef.summonElevator(floorNumber);                    // Call elevator to this floor (floorNumber)
}                                                               // End function pressButton


void FloorButton::resetButton()                                 // Reset button
{
    pressed = false;
}                                                               // End function resetButton
