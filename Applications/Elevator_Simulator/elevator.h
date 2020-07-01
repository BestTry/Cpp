// Class Declaration Header File: elevator.h
// Elevator class Declaration.
//
#pragma once
#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "elevatorButton.h"					// Components of the elevator
#include "door.h"
#include "bell.h"
#include "bldgStat.h"						// BldgStat class declaration prototype

class Floor;								// Forward declaration
class Person;								// Forward declaration
class BldgStat;								// Forward declaration

class Elevator {

public:
	Elevator(Floor&, Floor&, BldgStat&); 	// Constructor
	~Elevator();							// Destructor - See Definition file as passengerPtr is removed from memory

	void summonElevator(int);				// Request to service floor
	void prepareToLeave(bool);				// Allows elevator to perform tasks before departing
	void processTime(int);					// Give current time to elevator
	void passengerEnters(Person* const);	// Board a passenger
	void passengerExits();					// Exit a passenger

	ElevatorButton elevatorButton;			// Public object accessible to person client code with access to Elevator object directly	
											// Object of class ElevBtn requires a handle to an object of class Elevator as argument of
											// the Elevator classes constructor - The handle is provide by derefencing the elevator's 
											// this pointer - See contructor in definition file

private:									// Utility functions
	void processPossibleArrival();
	void processPossibleDeparture();
	void arriveAtFloor(Floor&);
	void move();
												// Constants are initialized in deftn / implemt file 'elevator.cpp'  
	static const int ELEVATOR_TRAVEL_TIME;	// Const are static cause they are shared by all object the elevator class
	static const int UP;					// Static constants that represent time & direction required to travel 
	static const int DOWN;					// between floors and directions of the elevator

											// Data members
	int currentBuildingClockTime;			// Current time updated: Being sent every click from the building object
	bool moving;							// Elevator state
	int direction;							// Current direction
	int currentFloor;						// Current location
	int arrivalTime;						// Time to arrive at a floor
	bool floor1NeedsService;				// Floor1 service flag
	bool floor2NeedsService;				// Floor2 service flag

	BldgStat& bldgStatRef;					// Reference for the BldgStat class object 'bldgStat' constructed in the building class
	Floor& floor1Ref;						// Declares reference handle to floor1 - Reference because handle always refers same floor
	Floor& floor2Ref;						// Declares reference handle to floor2 - Reference because handle always refers same floor
	Person* passengerPtr;					// Pointer to passenger object because this pointer changes address for each new person entering or  
											// leaving the elevator while floors always remain the same, therefore floor uses references
	Door door;								// Door object
	Bell bell;								// Bell object

};											// End class Elevator

#endif										// ELEVATOR_H