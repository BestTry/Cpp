// Class Declaration Header file: bldgStat.h
// BldgStat class Declaration.

#pragma once
#ifndef BLDGSTAT_H
#define BLDGSTAT_H

class BldgStat 
{
public:
	
	BldgStat();								// Constructor
	~BldgStat();							// Destructor

	void setPassengerID(int);
	void setfloor1_OccupantID(int);
	void setfloor2_OccupantID(int);

	int getPassengerID();
	int getfloor1_OccupantID();
	int getfloor2_OccupantID();
	
	void displayBldgStatus();				// Display simulation parameters 

 private:
	int passengerID;
	int floor1_Occupant;
	int floor2_Occupant;
	
};											// End class BldgStat

#endif										// BLDGSTAT_H
