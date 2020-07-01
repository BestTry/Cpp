// Class Elevator Definition Implementaton File: elevator.cpp
// Member-function definitions for class Elevator.
//
// Elevator Operations: 
// Moves, arrives at a floor, resets elevator-button, sounds elevator bell, signals its arrival at a floor, opens its door
//
#include <iostream>
#include "elevator.h"  // Elevator class declaration prototype
#include "person.h"    // Person class declaration prototype
#include "floor.h"     // Floor class declaration prototype
#include "bldgStat.h"  // BldgStat class declaration prototype
#include "building.h"

using std::cout;
using std::endl;

const int Elevator::ELEVATOR_TRAVEL_TIME = 5;                   // Constants that represent time required to travel 
const int Elevator::UP = 0;                                     // between floors and directions of the elevator
const int Elevator::DOWN = 1;

                                                                // Constructor - Exhibiting an extensive 'Initializer Member List' 
Elevator::Elevator(Floor& firstFloor, Floor& secondFloor,       // The (*this) deferences the 'this' pointer for the elevatorButton
                    BldgStat& bldgStatHandle)
        : elevatorButton(*this),                                // ElevBtn requires a handle to object of class Elevator: Derefernce (*this)
          currentBuildingClockTime(0),                          // Current time updated: Being sent every click from the building object
          moving(false),
          direction(UP),
          currentFloor(Floor::FLOOR1),
          arrivalTime(0),
          floor1NeedsService(false),
          floor2NeedsService(false),
          floor1Ref(firstFloor),
          floor2Ref(secondFloor),
          passengerPtr(0),
          bldgStatRef(bldgStatHandle)
{
    cout << " Elevator constructed" << endl;
}                                                               // End Elevator constructor


Elevator::~Elevator()                                           // Destructor - Good practice to remove an object (passengerPtr) from
{                                                               // memory that was created with the operator 'new'
    delete passengerPtr;
    cout << " Elevator destructed" << endl;
}                                                               // End ~Elevator destructor


void Elevator::processTime(int time)                            // Give time to elevator - Function called by building within bldg 'while loop'
{
    currentBuildingClockTime = time;                            // Update CBCTime from simulation time

    if (moving) {                                               // Check if elevator is moving - if it is check utility function PPA()
        processPossibleArrival();                               // Elevator is moving
    }
    else {                                                      // Elevator is not moving
        processPossibleDeparture();                             // Recall - Function called by building within bldg 'while loop'
    }
    if (!moving)                                                // Display status of elevator motion to view
        cout << " Elevator is at rest on floor "
             << currentFloor << endl;                           // End function processTime
}                                                               // ----------------------------------------------------


void Elevator::processPossibleArrival()                         // When elevator is moving, determine if it should stop by 
{                                                               // comparing the present building time to the arrival time
    if (currentBuildingClockTime == arrivalTime) {              // Check arrival time - if elevator arrived at destination floor 
        currentFloor =                                          // Update current floor - Toggle floor number by knowing source of last floor 
       (currentFloor == Floor::FLOOR1 ?
        Floor::FLOOR2 : Floor::FLOOR1);                    
        direction =                                             // Update direction - Toggle direction by knowing current floor arrived
       (currentFloor == Floor::FLOOR1 ? UP : DOWN);

        cout << " Elevator arrives on floor "
             << currentFloor << endl;
                arriveAtFloor(currentFloor == Floor::FLOOR1 ?   // Process arrival tasks at currentFloor: Bell, Reset botton, Open door
                floor1Ref : floor2Ref);                             // Transfer reference to arrived floor number
        
        return;
    }                                                           // End if                                                                
    cout << " Elevator is moving "                              // Elevator is still moving: Present time NOT EQUAL Arrival Time
         << (direction == UP ? "up" : "down") << endl;          // End function processPossibleArrival
}                                                               // ----------------------------------------------------


void Elevator::processPossibleDeparture()                       // Should elevator move? - If current floor need service, call arriveAtFloor()
{                                                               // If other floor needs service, call prepareToLeave() and move to this floor
    bool currentFloorNeedsService =                             // Check if this 'current' floor needs service?
         currentFloor == Floor::FLOOR1 ?
         floor1NeedsService : floor2NeedsService;

    bool otherFloorNeedsService =                               // Check if 'other' floor needs service?
         currentFloor == Floor::FLOOR1 ?
         floor2NeedsService : floor1NeedsService;

    if (currentFloorNeedsService) {                             // Service this floor (if needed)
        arriveAtFloor(currentFloor == Floor::FLOOR1 ?
        floor1Ref : floor2Ref);

        return;
    }

    if (otherFloorNeedsService)                                 // Service other floor (if needed)
        prepareToLeave(true);                                   // End function processPossibleDeparture
}                                                               // ----------------------------------------------------

                                                                
void Elevator::arriveAtFloor(Floor& arrivalFloor)               // Elevator arrived at arrival reference floor - Performs arrival tasks       
{                                                           
    moving = false;                                             // Stop the elevator: Reset moving state to false
    cout << " Elevator has reset its button" << endl;           // Reset elevator button
    elevatorButton.resetButton();
    bell.ringBell();
                                                                // Declare a temporary pointer to a Person class type object which stores a handle 
    Person* floorPersonPtr = arrivalFloor.elevatorArrived();    // to a person that might be waiting on the floor. This pointer than recieves the 
                                                                // personPtr of person waiting on floor from the floor's 'elevatorArrived()' member function
    door.openDoor(
         passengerPtr, floorPersonPtr, arrivalFloor, *this);    // Opens this elevator door using the door class object openDoor() member function
                                                                // And exits or enters passenger after the door opens (function of door class objec)
    bool currentFloorNeedsService =                             // Check if this current floor needs service
         currentFloor == Floor::FLOOR1 ?                        // Bools set by the summonElevator() function
         floor1NeedsService : floor2NeedsService;

    bool otherFloorNeedsService =                               // Check if other floor needs service
         currentFloor == Floor::FLOOR1 ?
         floor2NeedsService : floor1NeedsService;

    if (!currentFloorNeedsService) {                            // If this floor does not need service
         prepareToLeave(otherFloorNeedsService);                // prepare to leave to the other floor
    }
    else {                                                      // otherwise, reset service flag for the current floor
        currentFloor == Floor::FLOOR1 ?
        floor1NeedsService = false : floor2NeedsService = false;
    }                                                           // End function arriveAtFloor
}                                                               // ----------------------------------------------------


                                                                // Within the FloorButton class, function pressButton() will call the summonElevator() function
                                                                // Additional scenario:  Summon elevator service - Starts with elevator.processTime() >>> 
                                                                // processPossibleDeparture() >>> scheduler creating a person - >>> 
void Elevator::summonElevator(int floor)                        // createNewPerson() >>> (newPersonPtr->stepOntoFloor()) >>> floor.personArrives(this) >>>
{                                                               // floor.floorButton.pressButton() >> elevatorRef.summonElevator() 
    floor == Floor::FLOOR1 ?                                    // Set appropriate (floor1/floor2) service flag: Check (floor == FLOOR#)
    floor1NeedsService = true : floor2NeedsService = true;      // If FLOOR1 did not summons, then FLOOR2 must have (Set 'true')
}                                                               // End function summonElevator


void Elevator::passengerEnters(Person* const personPtr)         // Accepts a passenger - Takes person pointer argument from person object which called it
{                                                               // and updates the elevater's passengerPtr handle to point to the new passenger
    passengerPtr = personPtr;                                   // Board passenger
    int personID = passengerPtr->getID();
    cout << " Person " << personID
         << " enters elevator from floor "
         << currentFloor << endl;                               
    bldgStatRef.setPassengerID(personID);                       // Notify building status keeper - Person with ID 'personID' has entered elevator
                                                                // End function passengerEnters
}                                                               // ----------------------------------------------------


void Elevator::passengerExits()                                 // Notify elevator that passenger is exiting - Called from 'person.exitElevator()'
{
    passengerPtr = 0;                                           // Sets pointer to a null and this will destructs the person object as well
    bldgStatRef.setPassengerID(0);
}                                                               // End function passengerExits


void Elevator::prepareToLeave(bool leaving)                     // Called by elevator button press within elevator . . . Or . . . ???
{
    Floor& thisFloor =                                          // Get reference to current floor
        currentFloor == Floor::FLOOR1 ? floor1Ref : floor2Ref;
    thisFloor.elevatorLeaving();                                // Notify the referenced floor that elevator may be leaving - reults in 
    door.closeDoor(thisFloor);                                  // turning off this floor's light  The close thisFloor's (ref floor) door

    if (leaving)                                                // Leave, if necessary (Var 'leaving' is bool type passed as argument)
        move();                                                 // End function prepareToLeave
}                                                               // ----------------------------------------------------


void Elevator::move()                                           // Travell to alternate floor
{
    moving = true;                                              // Change moving state to 'true' and schedule arrival time 
    arrivalTime = currentBuildingClockTime + ELEVATOR_TRAVEL_TIME;
    cout << " Elevator begins moving "
         << (direction == DOWN ? "down " : "up ")
         << "to floor "
         << (direction == DOWN ? '1' : '2')                     // If direction is down it is going to floor 1, otherwise floor2         
         << " (arrives at time " << arrivalTime << ')'
         << endl;                                               // End function move
}                                                               // ----------------------------------------------------
