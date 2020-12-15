#include <iostream>  // Include iostream for the following using invocations

using std::cout;
using std::cin;
using std::endl;
using std::fixed;   // need this when used with "setprecision()" which is under the namespace <iomanip>

#include<iomanip>	// This include is needed to implement the setprecision() function as demonstrated below
using std::setprecision;

int main()
{
	long int x = 512345678;
	cout << "A demonstration of casting from an integer to a double: \n\n" << endl;
	cout << "\t The value of the integer x before casting is: " << x;

	// Casting a integer to a double using the uniary " static_cast<type>(argument) " operator
	// Invoking "fixed" means for the output to be formatted in fixed notation instead of scientific notation
	// The static_cast<argument type>(argument) is a unary operator taking on only one argument
	// The 'setprecision' is sourced from <iostream> namespace and . . . . 
	// The "fixed" keyword syntax indicates a fixed-point format unstead of scientic notation

	double y = static_cast<double>(x);

	cout << "\n\t After casting x to a double type, its value is: " << setprecision(2) << fixed << y << endl;
	cout << "\n\t See how the x value is now displayed with a precision of two decimal places. ";
	cout << "\n\t This was coded using the 'cout' member functions 'setprecision(2) and 'fixed' ";
	cout << "\n\t The code syntax used: \"cout << setprecision(2) << fixed << y << endl;\"" << endl;
	cout << endl;
	cout << "\n\t The statement: 'int x = 5123456789 will not work because the number ";
	cout << "\n\t is too large and out of bounds by a magnitude of 10 (or one digit)." << endl;;
};