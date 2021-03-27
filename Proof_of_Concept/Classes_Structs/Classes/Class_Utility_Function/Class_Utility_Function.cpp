// Class_Utility_Function.cpp : Initial version of this example was lifted from "How to Program" Deitel ver 4.0 Chapter 6 - // Fig. 6.11: fig06_11.cpp
// Demonstrating a utility function.  Compile this program with salesPerson.cpp
// Note that the private untility function 'totalAnnualSales' is not shown or known by the client (main code)
//
//
#include <iostream>
#include "salesPerson.h"                             // include SalesPerson class definition from salesp.h

using std::cout;								// Console output
using std::cin;									// Console input
using namespace std;							// Common practice to implement the "std" namespace as it contains multiple supporting useful functions

void exitPrgm();								// Use this function as a optional default to terminate the program

int main()
{
	SalesPerson salesEmployee;								// create SalesPerson object salesEmployee

	salesEmployee.getSalesFromUser();  // note simple sequential code; no
	salesEmployee.printAnnualSales();  // control structures in main

	exitPrgm();						// Option function member to terminate program
	system("pause");				// Some compilers do not recognize this statement
	return 0; 						// Indicates successful termination
}									// End of main



void exitPrgm()
{
	cout << "\n\n                  >>>>>>>>>>  Program has Terminated  <<<<<<<<<< " << endl;
	cout << " \n\n\n " << endl;
	exit(0);						// Terminate running program from anywhere it is called:
}