// Class Declaration Header File: employee1.h
// Employee class Declaration.
// Member functions defined in employee1.cpp.

#pragma once
#ifndef EMPLY1_H
#define EMPLY1_H
                                        
#include "date1.h"              // Include Date class definition from date1.h

class Employee {

public:                         // Constructor declaration - See employee1.cpp file for constructor dedfinition detail
                                // First date in constructor params is birth date, last is hire date
                                // Both dates variable receive references to the date objects
    Employee(const char*, const char*, const Date&, const Date&);

    void print() const;
    ~Employee();                // Provided to confirm destruction order

private:
    char firstName[25];
    char lastName[25];
    const Date birthDate;       // Composition: member object created from the Date class
    const Date hireDate;        // Composition: member object created from the Date class

};                              // End class Employee

#endif