// Class Decalaration Header File: person.h
// Person class Declaration.

#pragma once
#ifndef PERSON_H
#define PERSON_H

#include "bldgStat.h"

class Floor;							// Forward declaration
class Elevator;							// Forward declaration

class Person {

public:
	Person(int);						// Constructor
	~Person();							// Destructor
	int getID() const;					// Returns person's ID

	void stepOntoFloor(Floor&);
	void enterElevator(Elevator&, Floor&);
	void exitElevator(const Floor&, Elevator&) const;
	
private:								// Total person count is necessary to assign the next person ID number
	static int personCount;				// Totalof person- passengers created - Incremented each person creation, than assigned to ID
	const int ID;						// Person's unique ID # - assigned from the tolal person variable 'personCount'
	const int destinationFloor;			// Destination floor #   
};										// End class Person

#endif									// PERSON_H
