// Fig.Class Declaration Header File: scheduler.h
// Scheduler class Declaration.

#pragma once
#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "bldgStat.h"

class Floor;								// Forward declaration

class Scheduler {

public:
	Scheduler(Floor&, Floor&, BldgStat&);	// Constructor 
	~Scheduler();							// Destructor
	void processTime(int);					// Set scheduler's time

private:
	void scheduleTime(const Floor&);		// Schedule an arrival time for a person to be placed onto a floor	
	void delayTime(const Floor&);			// Delay a person arrival to a floor (If floor is already occupied)	
	void createNewPerson(Floor&);			// Create randomly new person; Place on floor	
	void handleArrivals(Floor&, int);		// Handle person arrival on a floor

	int currentClockTime;					// Member atribute supports the processTime() function
	int floor1ArrivalTime;					// Holds the time at which next person will appear at floor 1
	int floor2ArrivalTime;					// Holds the time at which next person will appear at floor 2
	Floor& floor1Ref;
	Floor& floor2Ref;

	BldgStat& bldgStatRef;					// Reference for the 'bldgStat' object
};											// End class Scheduler

#endif										// SCHEDULER_H

