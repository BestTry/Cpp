// Class BldgStat Definiti0n File: bldgStat.cpp
// Member-function definitions for class BldgStat.
//
// Class is designed hold the current building status that are recieved from various object and held in its attributes.
// It also displays the current building status: elevator occupancy, elevator direction and floor occupancy when prompted
// Note that it is was required to prefix each function name by the class name that it is declared within
//
#include "bldgStat.h"
#include <iostream>
#include <string>										// Required when using 'cout

using namespace std;

using std::cout;
using std::endl;

BldgStat::BldgStat()									// Constructor - Utilizing the'Initialization Member List' for displaying builing status
	    : passengerID(0), floor1_Occupant(0),
		  floor2_Occupant(0) 
{
	cout << " Building status constructed " << endl;
}

BldgStat::~BldgStat()									// Destructor
{
	cout << " Building status destructed " << endl;
}


void BldgStat::setPassengerID(int passID) {				// Setter functions updated simultion attributes during sim run
	passengerID = passID;
}


void BldgStat::setfloor1_OccupantID(int flr1Persn)  {
	floor1_Occupant = flr1Persn;
}


void BldgStat::setfloor2_OccupantID(int flr2Persn) {
	floor2_Occupant = flr2Persn;
}


int BldgStat::getPassengerID() {						// These 'getter' functions of the BldgStat class object never get used
	return passengerID; 
}


int BldgStat::getfloor1_OccupantID() { 
	return floor1_Occupant; 
}


int BldgStat::getfloor2_OccupantID() { 	
	return floor2_Occupant; 
}


void BldgStat::displayBldgStatus()
{
	string noOne = "        ";
	cout << " Elevator: ";
	passengerID == 0 ? cout << noOne : cout << "Person" << passengerID << ",";
	cout << "   Floor1: ";
	floor1_Occupant == 0 ? cout << noOne : cout << "Person" << floor1_Occupant << ",";
	cout << "   Floor2: ";
	floor2_Occupant == 0 ? cout << noOne : cout << "Person" << floor2_Occupant;
	cout << endl;
}
