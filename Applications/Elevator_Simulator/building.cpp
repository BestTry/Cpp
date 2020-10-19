// Class building implementation definition file: 'building.cpp'
// Member-function definitions for class Building.//
//
// The building object holds the major program while loop for continual process execution until run time expires
// Purpose of the building object is to run the simulation - See 'runSimulation' building function call below
// See Sequence Diagram on 'Buiding-Object' run for better understanding of this part of the simulation
// Bell Operation: Non in problem statement But software developer decided by design:
//
#include <iostream>
#include "building.h"                               // Building class declaration protoype
#include "bldgStat.h"                               // Building Status class declaration protoype

using std::cout;
using std::cin;
using std::endl;                                    
                                                    // Constructor creates building with floors, elevator, scheduler objects.  
Building::Building()                                // Additionaly These objects create their own objects and initialization values
        : floor1(Floor::FLOOR1, elevator, bldgStat),// Objects 'floor1' object is instantiated
          floor2(Floor::FLOOR2, elevator, bldgStat),// Objects 'floor2' object is instantiated
          elevator(floor1, floor2, bldgStat),       // Arguments / attributes are defaulted to initialization designed values.  
          scheduler(floor1, floor2, bldgStat),      // Arguments - FLOOR1 & FLOOR2 are constants defined in class Floor
          bldgStat()                                // Instantiates class object 'bldgStat' to track status of building objects
{                                                   

    cout << " Building objects constructed; Ojects listed above & below and initial values set:\n"
         << " [floors,  elevator,  buttons,  lights,  bell,  scheduler, arrival times set]" << endl;
    cout << " Building Status Tracker constucted" << endl;  
}                                                   // End Building constructor


Building::~Building()                               // Destructor
{
    cout << " Building destructed" << endl;
}                                                   // End ~Building destructor

                                                    // >>>>>>>>>>>>>>>>>>>  Main Simulation Loop  <<<<<<<<<<<<<<<<<<<
void Building::runSimulation(int totalTime)         // Function runs the simulation until 'totalTime' duration expires
{                                                   // Total time was set by user at the beginning of the program
    int currentTime = 0;                            // At the start of simulation the current time is set to zero
        
    while (currentTime < totalTime) {               // Tick event depends on user enabling time to proceed by hitting 'Enter' key 
        clock.tick();                               // Increments the clock time by one tick every time control passes through the loop
        currentTime = clock.getTime();              // Get the updated new time from the clock object
        cout << " TIME: " << currentTime << endl;   // Dislay to observer and provide this time to scheduler and elevator for processing                                            
        scheduler.processTime(currentTime);         // Update scheduler time every seccnd - Process person arrivals for currentTime        
        elevator.processTime(currentTime);          // Process elevator events for currentTime                
        bldgStat.displayBldgStatus();               // Display current status of building after every clock tick for viewer comprehension        

        cin.get();                                  // Holds up progress until observer finished viewg status then, hitting 'Enter' key resumes run  
                                                    // To run completely automatic, I would place a time delay here and remove 'cin' prompt.
    }                                               // End while

}                                                   // End function runSimulation
