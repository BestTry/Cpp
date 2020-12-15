// Class Decalaration Header File: building.h
// Building class Declaration.

#pragma once
#ifndef BUILDING_H
#define BUILDING_H
									// Composition List of the class declaration prototype files for each building component
#include "elevator.h"				// Elevator class declaration
#include "floor.h"					// Floor class declaration
#include "clock.h"					// Clock class declaration
#include "scheduler.h"				// Scheduler class declaration
#include "bldgStat.h"				// Building Status declaration

class Building {

public:
	Building();						// Constructor
	~Building();					// Destructor
	void runSimulation(int);		// Controls simulation - runs for interger minutes - See building.cpp for details of run loop

private:							// Composition component objects of building that are created / instantiated by building object
	Floor floor1;					// Class Floor object 'floor1'
	Floor floor2;					// Class Floor object 'floor2'
	Elevator elevator;				// Class Elevator object 'elevator'
	Clock clock;					// Class Clock object 'clock'
	Scheduler scheduler;			// Class Scheduler object 'scheduler'

	BldgStat bldgStat;				// Class BldgStat object 'bldgStat' - holds, tracks person location status
									// Other classes will refetence this object by refering to 'bldgStatRef'
};									// End class Building

#endif								// BUILDING_H


