// Class Door Definition File: door.cpp
// Member-function definitions for class Door.
//
// Door Operation: Opens door, signals person to exit elevator, signals person to enter elevator
//
//
#include <iostream>
#include "door.h"                                   // Door class definition
#include "person.h"                                 // Person class definition
#include "floor.h"                                  // Floor class definition
#include "elevator.h"                               // Elevator class definition

using std::cout;
using std::endl;


Door::Door() : open(false)                          // Constructor - Initializes door bool var 'open' to false (closed)
{                                                   // Initialized using the Member Initialer List syntax
    cout << " Door constructed" << endl;
}                                                   // End Door constructor


Door::~Door()                                       // Destructor
{
    cout << " Door destructed" << endl;
}                                                   // End ~Door destructor

                                                    // Called by the elevator's arriveAtFloor() function
void Door::openDoor(Person* const passengerPtr,     // Open the door function needs notify passenger within the elevator to exit,
    Person* const nextPassengerPtr,                 // person waiting on the floor to enter and current floor to notify elevator 
    Floor& currentFloor,                            // should be preparing to leave this current floor on this elevator
    Elevator& elevator)
{
    if (!open) {                                    // If door is not open, toggle bool variable 'open' to true - meaning door is now open
        open = true;
        cout << " Elevator opens its door on floor "
            << currentFloor.getNumber() << endl;
                                                    // If passenger is in elevator, have person leave
        if (passengerPtr != 0) {                    // Function 'exitElevator' resides in person class which calls 'elevator.passengerExits()'
            passengerPtr->exitElevator(currentFloor, elevator); 
            delete passengerPtr;                    // Passenger leaves simulation - This will also call the person destructor
        }                                           // End inner if

        if (nextPassengerPtr != 0)                  // If passenger is waiting to enter elevator, have passenger enter elevator
            nextPassengerPtr->enterElevator(        // Function 'entertElevator' resides in person class
                elevator, currentFloor);
    }                                               // End outer if

}                                                   // End function openDoor


void Door::closeDoor(const Floor& currentFloor)     // Close the door
{
    if (open) {                                     // If door is open, close door
        open = false;
        cout << " Elevator closes its door on floor "
            << currentFloor.getNumber() << endl;
    }                                               // End if
}                                                   // End function closeDoor

/*  
    Example of 'path' / 'message communication' complexity - 
    Described here is the path taken if there is a passenger waiting to board elevator:
    elevator.arrivedAtFloor() >> door.OpenDoor() >> personPtr.entersElevator() >>
    floor.personBoardingElevator() >> elevator.passengerEnters()

    (Floor deletes personPtr during the floor.personBoardingElevator() function) [ occupantPtr = 0; ]
    (Elevator receives personPtr during the elevator.passengerEnters() function) [ passengerPtr = personPtr;   ]    
     
*/