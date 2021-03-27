// Employee Class Declaration File: 'employee2.h'
#pragma once
#ifndef EMPLOYEE2_H
#define EMPLOYEE2_H
class Employee {

public:
	Employee(const char*, const char*);				// Constructor - Taking pointers to character constant - (These are strings)
	~Employee();									// Destructor
	const char* getFirstName() const;				// Returns first name character string
	const char* getLastName() const;				// Returns last name character string

													// Static member function - Class employee objects can use this function (Not all class global)
	static int getCount();							// Returns # objects instantiated
													// Each static member must be initialized.  Must be accessed thu public member funtions or friends
private:
	char* firstName;
	char* lastName;

	// Static data member
	static int count;								// Number of objects instantiated

};													// End class Employee

#endif

