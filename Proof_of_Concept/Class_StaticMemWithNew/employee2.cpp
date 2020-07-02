// Class Definition File 'employee2.cpp' Member-function definitions for class Employee.
#include <iostream>
#include "employee2.h"                                      // Employee class definition 

using std::cout;
using std::endl;

#include <new>                                              // C++ standard new operator - required to use the 'new' operator
#include <cstring>                                          // strcpy and strlen prototypes - Must turn off "SDL Checks' for this to work

int Employee::count = 0;                                    // Define and initialize static data member (Static members must be initialized) 

int Employee::getCount()                                    // Define static member function that returns number of 
{                                                           // Employee objects instantiated
    return count;
}                                                           // End static function getCount

Employee::Employee(const char* first, const char* last)     // Constructor dynamically allocates space for
{                                                           // first and last name and uses strcpy to copy
    firstName = new char[strlen(first) + 1];                // first and last names into the object    
    strcpy_s(firstName, 20, first);
    lastName = new char[strlen(last) + 1];
    strcpy_s(lastName, 20, last);

    ++count;                                                // Each time an employee is created, increment static count of employees

    cout << "Employee constructor for " << firstName
        << ' ' << lastName << " called." << endl;

}                                                           // End Employee constructor


Employee::~Employee()                                       // Destructor deallocates dynamically allocated memory
{
    cout << "~Employee() called for " << firstName
        << ' ' << lastName << endl;

    delete[] firstName;                                     // Recaptures memory - Must include the [ ] or only the first elem will be deleted
    delete[] lastName;                                      // recaptures memory - Must include the [ ] or only the first elem will be deleted

    --count;                                                // Dcrement static count of employees

}                                                           // End ~Employee destructor


const char* Employee::getFirstName() const                  // return first name of employee
{
    return firstName;                                       // const before return type prevents client from modifying
                                                            // private data; client should copy returned string before
                                                            // destructor deletes storage to prevent undefined pointer
}                                                           // End function getFirstName


const char* Employee::getLastName() const                  // return lirst name of employee
{
    return lastName;                                       // const before return type prevents client from modifying
                                                            // private data; client should copy returned string before
                                                            // destructor deletes storage to prevent undefined pointer
}                                                           // End function getLastName

