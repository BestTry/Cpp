// Global_Variable_Demo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Demonstrating the use of and differences between Global and Local Variables  
// Retrieved form C++ How to program textbook by Deitel 4th edition - Chapter 3
// The unary scope resolution operator is ( :: ) is optional when the only variable with that name is of global type 
// But is good programming practice to use ( :: ) when the variable is of global scope See the 'cout' syntax in code below	

//#include "pch.h"
#include <iostream>						// Include iostream for the following using invocations
#include <iomanip>						// This include is needed to impliment the setprecision() function as demonstrated below
#include <format>

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::fixed;   						// need this when used with "setprecision()" which is under the namespace <iomanip>
using std::setprecision;
using std::format;						// Must invoke both 'include<format> and using std::format"

const double PI = 3.141592653589793;// Defining the Global variable PI in type double


int main()
{												// Define a local variable PI by taking the global variable PI and casting it to a float
	const float PI = static_cast<double> (::PI);
	cout << setprecision(11) << "Value of float type variable PI local  = " << PI << "\n"
		<< "Value of double type variable PI global = " << (::PI) << endl;
	// Example below from 'C++ From Control Structures ...' - Tony Gaddis
	float distance;						// Variable 'distance' defined as a float type
	double mass;							// Variable 'mass' defined as a double type

	distance = 1.495979E11;				// The output is adding erroneously addtional precision ???
	mass = 1.988E30;

	cout << format("\n The Sun is {} meters from the earth", distance);
	cout << format("\n The Sun's mass is {} kilograms", mass);


	cout << endl << endl;
	system("pause>0");
	return 0;								// Indicates successful termination

}												// End of main
