// ReverseDigits.cpp : This file contains the 'main' function. Program execution begins and ends there.
// From Deitel/Deitel Exercise 3.31
// Enter any interger and have its digits reversed i.e.  12345 => 54321

#include "pch.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;


int main()				// Application main routine
{
	int num;			// Original user entered integer
	int factoredNum;	// Temporary number (num/10) used in separation out digits of the original num
	int displayDgt; 	// Next digit to be displayed when reversing number digits

	do
	{
		cout << "\n\nEnter a positive interger value: ";
		cin >> num;
		cout << "\n" << endl;

		if (num <= 0)
		{
			break;
		}
		else
		{
			cout << "Here is the number entered with the digit order reversed: " << endl;
		}
		
		while (num > 0)
		{
			factoredNum = num / 10;
			displayDgt = num - (factoredNum * 10);
			cout << displayDgt;
			num = factoredNum;
		}

	} while (num >= 0);


	return 0;			// Indicates a successful termination of the routine to the main program
}

