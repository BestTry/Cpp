// Class Header Declaration File: floor.h
// Floor class Declaration.

#pragma once
#ifndef FLOOR_H
#define FLOOR_H

#include "floorButton.h"
#include "light.h"
#include "bldgStat.h"

class Elevator;								// Forward declaration
class Person;								// Forward declaration

class Floor {

public:
	Floor(int, Elevator&, BldgStat&);		// Constructor - Both of the arguments are references since they never change
	~Floor();								// Destructor

	bool isOccupied() const;				// Return true if floor occupied
	int getNumber() const;					// Return floor's number

	void personArrives(Person* const);		// Pass a handle to new person coming on floor	
	Person* elevatorArrived();				// Notify floor that elevator has arrived	
	void elevatorLeaving();					// Notify floor that elevator is leaving	
	void personBoardingElevator();			// Notify floor that person is leaving floor
		
	static const int FLOOR1;				// Static constants representing floor numbers
	static const int FLOOR2;				// Used in place of actual numbers for better comprehension

	FloorButton floorButton;				// Public FloorButton object accessible to 
											// any client code with access to a Floor
private:
	const int floorNumber;					// The floor's number
	Elevator& elevatorRef;					// Reference to elevator object - (One elevator - always refers to same elevator)
	Person* occupantPtr;					// Pointer to person on floor - (Handle changes each time a new person walks onto or leaves floor)
	Light light;							// Light object - (used for turning floor light on and off, when elevator arrives and leaves
	BldgStat& bldgStatRef;					// Reference for the BldgStat class object 'bldgStat', constructed in the building class	

};											// End class Floor

#endif										// FLOOR_H
