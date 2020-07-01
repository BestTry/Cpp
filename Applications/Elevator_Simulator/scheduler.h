 // Fig.Class Declaration Header File: scheduler.h
// Scheduler class Declaration.

#pragma once
#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "bldgStat.h"

class Floor;								// Forward declaration

class Scheduler {

public:
	Scheduler(Floor&, Floor&, BldgStat&);				// Constructor 
	~Scheduler();							// Destructor
	void processTime(int);					// Set scheduler's time

private:
	void scheduleTime(const Floor&);		// Schedule arrival to a floor	
	void delayTime(const Floor&);			// Delay arrival to a floor	
	void createNewPerson(Floor&);			// Create randomly new person; Place on floor	
	void handleArrivals(Floor&, int);		// Handle person arrival on a floor

	int currentClockTime;					// Utility functions used to support the processTime() function
	Floor& floor1Ref;
	Floor& floor2Ref;

	BldgStat& bldgStatRef;					// Reference for the 'bldgStat' object
	
	int floor1ArrivalTime;					//  Holds - Keeps track of person arrival time for floor 1
	int floor2ArrivalTime;					//  Holds - Keeps track of person arrival time for floor 2

};											// End class Scheduler

#endif										// SCHEDULER_H

