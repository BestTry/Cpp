 // Class Person Definition Implementation file: person.cpp
// Member-function definitions for class Person.
// Person Operation: 
// Appears (steps) onto floor, presses floor button, presses elevator button, enters elevator, exits elevator
//
#include <iostream>
#include "person.h"    // Person class definition
#include "floor.h"     // Floor class definition
#include "elevator.h"  // Elevator class definition

using std::cout;
using std::endl;

int Person::personCount = 0;                                    // Initialize static member personCount (How d0es this work outside the constructor?) 
                                                                // Must be a global initialization event
Person::Person(int destFloor)                                   // Constructor - Appears for each person born, 
      : ID(++personCount),                                      // this constructor keeps track of total persons generated
        destinationFloor(destFloor)                             // Variable name destFloor is alternate from floor where person was created
{
    cout << " Person " << ID << " constructed" << endl;
}                                                               // End Person constructor


Person::~Person()                                               // Destructor
{
    cout << " Person " << ID << " destructed" << endl;
}                                                               // End ~Person destructor


int Person::getID() const                                       // Returns person's ID number for the person object instantiated
{
    return ID;
}                                                               // End function getID


void Person::stepOntoFloor(Floor& floor)                        // Person walks onto a floor
{
    cout << " Person " << ID                                    // Notify that a person has arrived at a floor (created)
         << " appears at floor "
         << floor.getNumber() << endl;
    floor.personArrives(this);                                  // Function delivers the pointer to the person created 
                                                                // and feeds it the occupantPtr on the floor object

    cout << " Person " << ID                                    // After the person appears on the floor, 
        << " presses floor-button on floor "                    // the person presses the floor-button on floor summoning elevator
        << floor.getNumber() << endl;
    floor.floorButton.pressButton();                            // Pressing the floor button summons the elevator       
                                                                // End function stepOntoFloor
}                                                               // ----------------------------------------------------


void Person::enterElevator(Elevator& elevator, Floor& floor)    // Person enters elevator (Notify floor: leaving floor, entering elevator)
{
    floor.personBoardingElevator();                             // Person enters elevator and leaves floor - Notify floor
    elevator.passengerEnters(this);                             // Person enters elevator - Notify elevator    
    cout << " Person " << ID                                    // Press button on elevator
        << " presses elevator button" << endl;
    elevator.elevatorButton.pressButton();                      // Notify elevator to move to other floor
                                                                // End function enterElevator
}                                                               // ----------------------------------------------------


void Person::exitElevator(                                      // Person exits elevator - called by door class -
    const Floor& floor, Elevator& elevator) const               // using the passengerPtr for this person
{
    cout << " Person " << ID << " exits the elevator at floor "
         << floor.getNumber() << endl;
    elevator.passengerExits();                                  // Notify elevator passenger person is exiting elevator  

}                                                               // End function exitElevator
