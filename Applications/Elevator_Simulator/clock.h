// Class Declaration Header file: clock.h
// Clock class Declaration.

#pragma once
#ifndef CLOCK_H
#define CLOCK_H

class Clock {

public:
	Clock();					// Constructor
	~Clock();                   // Destructor
	void tick();				// Increment clock by one second
	int getTime() const;		// Returns clock's current time

private:
	int time;					// Clock's time

};								// End class Clock

#endif							// CLOCK_H
