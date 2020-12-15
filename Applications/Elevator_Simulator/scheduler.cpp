// Class Scheduler Definition File: scheduler.cpp
// Member-function definitions for class Scheduler.
// Scheduler Operation: Randomly schedules times, creates a person, verifies a floor is unoccupied, delays creating a person by one second
// The Scheduler hanles time and randomly creates people to appear on floors 
// 
#include <iostream>
#include <new>
#include <cstdlib>
#include <ctime>

#include "scheduler.h"                                  // Scheduler class Declaration
#include "floor.h"                                      // Floor class Declaration
#include "person.h"                                     // Person class Declaration

#include "bldgStat.h"

using std::cout;
using std::endl;


// Constructor - with Member Initialization List syntax
Scheduler::Scheduler(Floor& firstFloor, Floor& secondFloor, BldgStat& bldgStatHandle)  
    : currentClockTime(0),                              // Object 'scheduler' instantiated with clock initialized to zero seconds
    floor1Ref(firstFloor),
    floor2Ref(secondFloor), 
    bldgStatRef(bldgStatHandle)
{                                                       // Constructor initializing arrival times and display status
    cout << " Scheduler orchestrator constructed" << endl;
    srand(time(0));                                     // Seeds random num generator so each run has different arrival times   
    scheduleTime(floor1Ref);                            // Constructor randomly schedules time for first person appearance on floor 1 
    scheduleTime(floor2Ref);                            // Constructor randomly schedules time for first person appearance on floor 2 
}                                                       // End Scheduler constructor


Scheduler::~Scheduler()                                 // Destructor of Scheduler
{
    cout << " Scheduler destructed" << endl;
}                                                       // End Scheduler destructor


void Scheduler::scheduleTime(const Floor& floor)        // Random - Schedule person arrival time on a single floor
{                                                       // Random arrival times are generated between 5-20 seconds into future
    int floorNumber = floor.getNumber();                // Future time current time plus five to twenty additional seconds
    int arrivalTime = currentClockTime + (5 + rand() % 16);
                                                        // Random arrival time is generated from current time plus 5 to 20 click ticks
    floorNumber == Floor::FLOOR1 ?                      // Current time is updated by building the function processTime() at every clock tick
        floor1ArrivalTime = arrivalTime :               // Arrival times refers to the time a person first appears on a floor
        floor2ArrivalTime = arrivalTime;

    cout << " Scheduler schedules next person for floor "
         << floorNumber << " at time " << arrivalTime
         << endl;                                       // End function scheduleTime
}                                                       // ------------------------------                                          


void Scheduler::delayTime(const Floor& floor)           // Reschedule arrival on a floor
{                                                       
    int floorNumber = floor.getNumber();

    int arrivalTime = (floorNumber == Floor::FLOOR1) ?  // Increment (delay) person arrival time on floor 
        ++floor1ArrivalTime : ++floor2ArrivalTime;      // And thus next person creation time is delayed

    cout << " Scheduler delays next person arrival on floor "
         << floorNumber << " until time " 
         << arrivalTime << " ###!###!###!###" << endl;  // End function delayTime
}                                                       // ------------------------------                                        


void Scheduler::processTime(int time)                   // Building updates schedular's time every second with current time
{                                                       // Scheduler has current time to make decisions
    currentClockTime = time;                            // Record current / present time: Scheduler now has updated current clock time
                                                        // Scheduler needs this time in function 'scheduleTime()' shown above
    handleArrivals(floor1Ref, currentClockTime);        // Handle person arrivals on to floor 1
    handleArrivals(floor2Ref, currentClockTime);        // Handle person arrivals on to floor 2
                                                        // End function processTime
}                                                       // -----------------------------


void Scheduler::createNewPerson(Floor& floor)           // Create new person and place it on  floor
{
    int destinationFloor =
        floor.getNumber() == Floor::FLOOR1 ?
        Floor::FLOOR2 : Floor::FLOOR1;

    Person* newPersonPtr = new Person(destinationFloor);// Create new person with unique ID, The person class assigns person ID 
    cout << " Scheduler creates a person with an ID of "
         << newPersonPtr->getID() << endl;              // During person construction, an incremented ID was assigned to this new person
    newPersonPtr->stepOntoFloor(floor);                 // Place person on designated floor (floor is referenced floor object)
    scheduleTime(floor);                                // Schedule the future time for next person random arrival 
                                                        // End function createNewPerson
}                                                       // ----------------------------


void Scheduler::handleArrivals(Floor& floor, int time)  // Handle arrivals for a specified floor
{
    int floorNumber = floor.getNumber();                
    int arrivalTime = (floorNumber == Floor::FLOOR1) ?  
        floor1ArrivalTime : floor2ArrivalTime;

    if (arrivalTime == time) {
        if (floor.isOccupied()) {                       // Check if floor is occupied,
            delayTime(floor);                           // Delay person arrival on floor by 1 if person is waiting on floor
        }                                               // May only have on person waiting on floor at this time (version)
        else {                                          // Otherwise, if floor is not occupied,
            createNewPerson(floor);                     // Create new person at this 'arrivalTime' and no sooner
        }                                               // End inner if
    }                                                   // End outer if
                                                        // End function handleArrivals
}                                                       // ------------------------------                                                   

