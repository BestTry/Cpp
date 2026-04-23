// Global_Variable.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Demonstrating the use of and differences between Global and Local Variables  - Retrieved form C++ How to program textbook by Deitel 4th edition - Chapter 3
// The unary scope resolution operator is ( :: ) is optional when the only variable with that name is of global type 
// But is good programming practice to use ( :: ) when the variable is of global scope See the 'cout' syntax in code below	

//#include "pch.h"
#include <iostream>						// Include iostream for the following using invocations
#include <iomanip>						// This include is needed to impliment the setprecision() function as demonstrated below

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::fixed;   						// need this when used with "setprecision()" which is under the namespace <iomanip>
using std::setprecision;

const double PI = 3.141592653589793;// Defining the Global variable PI in type double


int main()
{												// Define a local variable PI by taking the global variable PI and casting it to a float
	const float PI = static_cast<double> (::PI);
	cout << setprecision(9) << "Value of float type variable PI local  = " << PI << "\n"
		<< "Value of double type variable PI global = " << (::PI) << endl;

	cout << endl << endl;
	system("pause0");
	return 0;								// Indicates successful termination

}												// End of main
