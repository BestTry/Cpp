// salesPrsn.h
// SalesPerson class Declaration.    >>> Header File <<<
// Member functions defined in salesp.cpp.

#pragma once

#ifndef SALESPrsn_H
#define SALESPrsn_H

class SalesPerson {

public:
	SalesPerson();					// Constructor
	void getSalesFromUser();		// Function handles input sales from user keyboard
	void setSales(int, double);		// Sets sales for a month, using public functin 'getSalesFromUser' function
	void printAnnualSales();		// Public function invoking a PRIVATE fucntion summarizes and print sales

private:							// Monthly Sales figures are PRIVATE
	double totalAnnualSales();		// Utility function that provides private sales data to public printAnnualSales() function
	double sales[12];				// Array holds private 12 monthly sales figures

};									// End class SalesPerson Decalaration

#endif