// TernaryOperator_IfStatement.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Demostrate and show the format of the "if statement" using the "Ternary" operator
//

#include <iostream>
#include <format>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::format;
using std::string;

int main()
{
   int a, b, c;
  
   string status{ "" };
   cout << "\n Demonstration and format of the 'Ternary' operator\n" << endl;
   cout << " Please enter a positive or negative number here => "; cin >> a;
      
   if (a < 0 ? a = a * 2 : a = a * 3)
   cout << " If entered number is less than zero, it is doubled, otherwise tripled\n";
   cout << format(" The modified value of variable 'a' is now: {}\n\n", a) << endl;
   cout << " Value of variable 'a' is "; {}  	
   status = a < 0 ? "less" : "zero or greater";
   cout << status;
   
	// Error in Compilation - Statement below does not compile even thought it is same
	// syntax as that above using integer variables
	// if (a < 0 ? status = "less" : status = "zero or greater"); //  ???? Format does NOT work ?????
	// cout << ((a < 0) ? "less" : "equal or greater") " than zero" << endl; //

   cout << endl << endl;
   system("pause>0");
   return 0;
}

