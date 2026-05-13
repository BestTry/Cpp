// notNumChk.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Code was adapted by a tutorial by "Code Beauty" tutorial
//
#include <iostream>
#include <format>
using std::format;
using std::endl;
using std::cout;
using std::cin;

int main()
{	//		*****		// Code to verify input is an interger type    *****
	double num1, num2;
	bool isNum1Int, isNum2Int;
	cout << "Enter your parameters for number 1 and number 2:" << endl;
	cout << (" Number 1: => "); (cin >> num1);
	cout << (" Number 2: => "); (cin >> num2);

	isNum1Int = (num1 == (int)num1);	// Test num1 for integer type
	isNum2Int = (num2 == (int)num2);	// Test num2 for integer type

	cout << " Number 1 is an integer: " << (isNum1Int == 1 ? "True" : "False") << endl;
	cout << " Number 2 is an integer: " << (isNum2Int == 1 ? "True" : "False") << endl;
	cout << endl;
	// If number 1 or number 2 are not integers, 
	// the 'while' condition fails
	while ((!(isNum1Int) || !(isNum2Int) || cin.get() != '\n'))
	{
		cout << " Enter your parameters for number 1 and number 2:" << endl;
		cout << (" Number 1: => "); (cin >> num1);
		cout << (" Number 2: => "); (cin >> num2);

		isNum1Int = (num1 == (int)num1);	// Test num1 for integer type
		isNum2Int = (num2 == (int)num2);	// Test num2 for integer type

		cout << " Number 1 is an integer: " << (isNum1Int == 1 ? "True" : "False") << endl;
		cout << " Number 2 is an integer: " << (isNum2Int == 1 ? "True" : "False") << endl;
		cout << endl;

		cout << format(" number 1 = {}\n number 2 = {} \n", num1, num2);
		if (!(isNum1Int) || !(isNum2Int) || cin.get() != '\n')
		{
			cout << " Error. One of numbers is not numeric.\n Please enter legal numeric types:" << endl;
			cout << " Try Again: Enter two numbers." << endl;
		}

		cin.clear();					// Clears the error condtion in cin but input is still left there
		while (cin.get() != '\n');		// Reads and discards the input until the newline character is encountered.
										// After a successful check for non integers
										// Read / Refresh input and cin to a good state to allow future input	
	}
	cout << "................................................." << endl;
	cout << format(" Entered number values are:\n"
		" number 1 = {} and number 2 = {}\n", num1, num2);
}

