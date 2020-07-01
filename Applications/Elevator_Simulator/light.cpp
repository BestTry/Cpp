// Class Light Definition File: light.cpp
// Member-function definitions for class Light.
//
// Light Operation: None in problem statement
//
#include <iostream>
#include "light.h"  // Light class definition

using std::cout;
using std::endl;


Light::Light(int number)                                    // Constructor - Using the "Initialization Member List" syntax 
     : on(false), floorNumber(number)                       // Note that is takes an interger to intialize the light 
{                                                           // that is specifying the floor location (floor 1 or floor 2)
    cout << " Floor " << floorNumber << " light constructed"
         << endl;
}                                                           // End Light constructor


Light::~Light() {                                           // Destuctor
    cout << " Floor " << floorNumber
         << " light destructed" << endl;
}                                                           // End ~Light destructor


void Light::turnOn()                                        // Turn light on
{
    if (!on) {                                              // Check light status: if light is off, turn it on
        on = true;
        cout << " Floor " << floorNumber
            << " light turns on" << endl;
    }                                                       // End if
}                                                           // End function turnOn


void Light::turnOff() {                                     // Turn light off
    if (on) {                                               // Check light status: if light is on, turn it off
        on = false;
        cout << " Floor " << floorNumber
            << " light turns off" << endl;
    }                                                       // End if
}                                                           // End function turnOff
