// Date class declaration file: 'date.h'
#pragma once
class Date                                  // Date class
{

public:
    Date();                                 // Default constructor              
    Date(int, int, int);                    // Constuctor to take on three arguments of month day and year
    void setDate(int, int, int);
    void printDate();

private:
	int month;									// 1-12 (January-December)
	int day;									// 1-31 based on month
	int year;									// Any year

	int checkDay(int) const;					// Utility functions to test for proper day month and year
	int checkMonth(int) const;
	int checkYear(int) const;

};


