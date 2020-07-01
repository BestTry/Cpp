// Class Declaration Header File: door.h
// Door class Declaration.

#pragma once
#ifndef DOOR_H
#define DOOR_H                              // Forward declations are used to avoid circular 'includes' 
                                            // avoing classes referencing one another  
                                            // Placed here to reference class prototypes, declarations and definitions 
                                            // needed for the door class to function properly

class Person;                               // Forward declaration
class Floor;                                // Forward declaration
class Elevator;                             // Forward declaration

class Door {

public:
    Door();                                 // Constructor
    ~Door();                                // Destructor
                                            // Opens door
    void openDoor(Person* const, Person* const, Floor&, Elevator&);
    void closeDoor(const Floor&);           // Closes door

private:
    bool open;                              // Open or closed status 'Open' = 'true'

};

#endif                                      // DOOR_H


