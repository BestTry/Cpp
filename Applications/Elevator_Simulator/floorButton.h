// Class Declaration Header File: floorButton.h
// FloorButton class Declaration.

#pragma once
#ifndef FLOORBUTTON_H
#define FLOORBUTTON_H

class Elevator;                         // Forward declaration

class FloorButton {

public:
    FloorButton(int, Elevator&);        // Constructor
    ~FloorButton();                     // Destructor

    void pressButton();                 // Press the button
    void resetButton();                 // Reset the button

private:
    const int floorNumber;              // Button's floor number
    bool pressed;                       // Button state 
    Elevator& elevatorRef;              // Reference to elevator used to summon elevator to floor                                        
};                                      // End class FloorButton

#endif                                  // FLOORBUTTON_H

