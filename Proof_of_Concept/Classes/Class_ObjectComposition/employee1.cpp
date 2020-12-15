// Class Definition File: employee1.cpp
// Member-function definitions for class Employee.

/*************************************************************************
 In order for the strncopy() to work here (Its has been depreciated and 
 prevents compilatiton), I had to change properties.

 Go to the wrench icon (properties) Under the C/C++ 'General' folder options,
 select the 'SDL checks' and change to 'No'. Code should not compile but 
 issue warnings.

 ************************************************************************
*/

#include <iostream>
#include "employee1.h"                      // Employee class definition
#include "date1.h"                          // Date class definition
#include <cstring>                          // Required for strcpy and strlen prototype

using std::cout;
using std::endl;
                                            // Constructor uses member initializer list to pass initializer
                                            // values to constructors of member objects birthDate and      
                                            // hireDate [Note: This invokes the so-called "default copy    
                                            // constructor" which the C++ compiler provides implicitly.]   
Employee::Employee(const char* first, const char* last,
                   const Date& dateOfBirth, const Date& dateOfHire)
                 : birthDate(dateOfBirth),  // initialize birthDate
                   hireDate(dateOfHire)     // initialize hireDateba
{
    
    int length = strlen(first);             // Copy 'first' into firstName and be sure that it fits
    length = (length < 25 ? length : 24);
    strncpy(firstName, first, length);      // Store char string in employee object (char* array) field: firstName
    firstName[length] = '\0';               // Append null character at end of character array string

        
    length = strlen(last);                  // Copy last into lastName and be sure that it fits
    length = (length < 25 ? length : 24);
    strncpy(lastName, last, length);        // Store char string in employee object (char* array) field: lastName
    lastName[length] = '\0';                // Append null character at  end of character array string
    
    cout << " Employee object constructor " // Output Employee object to show when constructor is called
         << "called for object: "           // Variables 'firstName', 'lastName' are private atribute fields in employee object
         << firstName << ' ' << lastName << endl;

}                                           // End Employee constructor - now holding four attributes of names and dates


void Employee::print() const                // Print Employee object
{
    cout << " Employee:\n";
    cout << " " << firstName << " " << lastName << " - Hired: ";
    hireDate.print();                       // Envoking the print() within the date class
    cout << " Birth date: ";
    birthDate.print();                      // Envoking the print() within the date class
    cout << endl;

}                                           // End function print


Employee::~Employee()                       // Output Employee object to show when its destructor is called
{
    cout << " Employee object destructor: "
        << lastName << ", " << firstName << endl;

}                                           // End ~Employee destructor