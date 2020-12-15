// Class Declatation Header File: elevatorButton.h
// ElevatorButton class Declaration.

#pragma once
#ifndef ELEVATORBUTTON_H
#define ELEVATORBUTTON_H

class Elevator;						// Forward declaration

class ElevatorButton {

public:
	ElevatorButton(Elevator&);		// Constructor
	~ElevatorButton();				// Destructor

	void pressButton();				// Press the button
	void resetButton();				// Reset the button   

private:
	bool pressed;					// State of button	
	Elevator& elevatorRef;			// Reference to elevator containing 'this' button - Dereferencing (*this) in elevator class contructor
									// Elevator Button requires a handle to object of class Elevator - See elevator class constructor
};									// End class ElevatorButton

#endif								// ELEVATORBUTTON_H

