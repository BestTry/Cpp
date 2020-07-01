// Class Declaration Header File: light.h
// Light class Declaration

#pragma once
#ifndef LIGHT_H
#define LIGHT_H

class Light {

public:
	Light(int);							// Constructor - Tacks argument interger to indicate floor number
	~Light();							// Destructor

	void turnOn();						// Turns light on
	void turnOff();						// Turns light off

private:
	bool on;							// State: 'true' if on; 'false' if off
	const int floorNumber;				// Floor number that contains light

};										// End class Light

#endif									// LIGHT_H
