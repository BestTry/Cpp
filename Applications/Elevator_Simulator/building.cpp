// Class building implementation definition file: 'building.cpp'
// Member-function definitions for class Building.//
//
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
                                                    // Constructor creates building with floor, elevator scheduler objects.  
Building::Building()                                // Additionaly These objects create their own objects and initialization values
        : floor1(Floor::FLOOR1, elevator, bldgStat),// Objects 'floor1' object is instantiated
          floor2(Floor::FLOOR2, elevator, bldgStat),// Objects 'floor2' object is instantiated
          elevator(floor1, floor2, bldgStat),       // Arguments / attributes are defaulted to initialization designed values.  
          scheduler(floor1, floor2, bldgStat),      // Arguments - FLOOR1 & FLOOR2 are constants defined in class Floor
          bldgStat()                                // Building Status - Instantiates BldgStat class object 'bldgStat'
{                                                   

    cout << " Building constructed with objects listed above & below and values initialized:\n"
         << " [floors,  elevator,  buttons,  lights,  bell,  scheduler, arrival times set]" << endl;

    cout << " Building Status Keeper constucted" << endl;  
}                                                   // End Building constructor


Building::~Building()                               // Destructor
{
    cout << " Building destructed" << endl;
}                                                   // End ~Building destructor


void Building::runSimulation(int totalTime)         // Function to run simulation until 'totalTime' duration occurs
{
    int currentTime = 0;    
        
    while (currentTime < totalTime) {               // Tick event depends on user enabling time to proceed by hitting 'Enter' key 
        clock.tick();                               // Increments the clock time by one tick every time throught the while loop
        currentTime = clock.getTime();              // Get the updated new time  
        cout << " TIME: " << currentTime << endl;   // Dislay and provide this time to scheduler and elevator for processing                                            
        scheduler.processTime(currentTime);         // Update scheduler time every seccnd - Process person arrivals for currentTime        
        elevator.processTime(currentTime);          // Process elevator events for currentTime                
        bldgStat.displayBldgStatus();               // Display current status of building after every clock tick for viewer        

        cin.get();                                  // Hold time progress so observer may view status: Hits 'Enter' key  resume run  
                                                    // To run completely automatic, I could place a time delay here
    }                                               // End while

}                                                   // End function runSimulation
