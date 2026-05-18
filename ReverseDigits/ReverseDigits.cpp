// ReverseDigits.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Code does not handle leading or traing digits of zero ('0')
// Reverse the digits of a integer type number
#include <iostream>
using namespace std;

int main()
{
	int num = 0, rmdr = 0, newNum = 0;
	cout << " With no leading or trailing zeros and less than nine places" << endl;
	cout << " Enter a integer type number you wish its digits reversed. \n => ";
	cin >> num;  		// 123 - Integer example
						// Veriable values at each loop pass
	while (num > 0)		//  123 > 12  >  1
	{
		rmdr = num % 10;//	3 >  2 > 1  - Using the 'Remainder' operator
		newNum = (newNum * 10) + rmdr; // 3 >  32  > 321 
		num = num / 10;	// 12 >  1  > 0	 
	}

	cout <<  endl;
	cout << " => " << newNum 
		 << " is the original number with digits reversed" << endl; 

	cout << endl << endl;
	system("pause>0");
	return 0;
}

