// Fig. 6.9: salesp.h from Deitel "How to Program"  Demonstrates private untility function
// SalesPerson class Declaration -   Member functions defined in salesPerson.cpp.
//
#pragma once
#ifndef SALESP_H						// Required to prevent: 
#define SALESP_H						// Prevents multiple inclusions of header file

class SalesPerson
{

public:
	SalesPerson();						// Constructor
	void getSalesFromUser();			// Function used to input sales from keyboard
	void setSales(int, double);			// Function to set sales for a month
	void printAnnualSales();			// Function to summarize and print sales

private:
	double totalAnnualSales();			// Utility function - Pprivate => called by public printAnnualSales() function in 'salePerson.cpp'
	double sales[12];					// 12 monthly sales figures

};										// End class SalesPerson

#endif									// Completes multiple inclusions of header file statements
