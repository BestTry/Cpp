  // Class Floor Definition Implementation file: floor.cpp - Member-function definitions for class Floor.
// The class floor has a number of ways to associate other objects with Floor class objects 
//
// Floor Operation: Resets floor button, turns off light, turns on light// 
//
#include <iostream>
#include "floor.h"                                              // Floor class declaration prototyoe
#include "person.h"                                             // Person class declaration prototyoe
#include "elevator.h"                                           // Elevator class declaration prototyoe
#include "door.h"                                               // Door class declaration prototyoe

using std::cout;
using std::endl;

const int Floor::FLOOR1 = 1;                                    // Static constants that represent the floor numbers
const int Floor::FLOOR2 = 2;

                                                                // Constructor - Using 'Initialization Member List' syntax
Floor::Floor(int number, Elevator& elevatorHandle, BldgStat& bldgStatHandle)              
     : floorButton(number, elevatorHandle),
       floorNumber(number),
       elevatorRef(elevatorHandle),
       occupantPtr(0),
       light(floorNumber),  
       bldgStatRef(bldgStatHandle)                               // Initialization Member List completed
{
    cout << " Floor " << floorNumber << " constructed" << endl;
}                                                               // End Floor constructor


Floor::~Floor()                                                 // Destructor
{
    delete occupantPtr;
    cout << " The floor " << floorNumber << " destructed" << endl;
}                                                               // End ~Floor destructor


bool Floor::isOccupied() const                                  // Determine whether floor is occupied by a person - If so, pointer is non-zero
{                                                               // Returns boolean 'true' = 1 or 'false' = 0
    return (occupantPtr != 0);                                  // If 'occupantPtr' is zero, there is no person waiting on floor
}                                                               // End function isOccupied


int Floor::getNumber() const                                    // Return this floor's number
{
    return floorNumber;
}                                                               // End function getNumber


void Floor::personArrives(Person* const personPtr)              // Person appears on floor - Scheduler set random time for person to appear on floor
{                                                               // The pointer 'occupantPtr' recieves the private member personPtr  when person  arrives on floor 
    occupantPtr = personPtr;                                    // and this function is called 1st by scheduler which calls person object which call here
    int personID = occupantPtr->getID();                        // Floor object private member 'occupantPtr' was assigned new person pointer for its floor
    floorNumber == 1 ?
        bldgStatRef.setfloor1_OccupantID(personID) :            // Update Status with building status keeper (bldgStat object)
        bldgStatRef.setfloor2_OccupantID(personID);
}                                                               // End function personArrives


Person* Floor::elevatorArrived()                                // Notify floor that elevator has arrived or is at floor
{                                                               // Called by the elevator object within / from the arriveAtFloor() function
    cout << " Floor notification: Elevator is at floor " 
         << floorNumber
         << "\n Floor has reset its floor button"               
         << "\n Floor turned floor light on" << endl;
    floorButton.resetButton();                                  // When elevator arrives, reset floor button, turn floor light on
    light.turnOn();

    return occupantPtr;                                         // Gives the elevator the person pointer to the person waiting on the floor
}                                                               // End function elevatorArrived


void Floor::elevatorLeaving()                                   // Class Elevator object sent this message that 
{                                                               // notifies this floor that the elevator is leaving 
    light.turnOff();                                            // The floor then turns off its (this) floor light
}                                                               // End function elevatorLeaving


void Floor::personBoardingElevator()                            // Notifies floor that person is leaving floor
{                                                               // Called by door.openDoor()
    occupantPtr = 0;                                            // Person no longer on floor
    floorNumber == 1 ?                                          // Update floor occupant status within
        bldgStatRef.setfloor1_OccupantID(0) :                   // Update building status keeper object for the appropriate floor
        bldgStatRef.setfloor2_OccupantID(0);                    // 
}                                                               // End function personBoardingElevator