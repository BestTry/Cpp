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
   int a = 0;
   int aMod = 0;
   cout << endl << endl;
   string status{ "" };    // Declaring, defining and initializing the variable string
                           // Note the "ternary" operator format shown below
   cout << "\n Demonstration and format of the 'Ternary if' operator\n" << endl;
   cout << " If the entered number is less than zero, it is doubled, otherwise tripled\n\n";
   cout << " Please enter a positive or negative number here => "; cin >> a;

   if (a < 0 ? aMod = (a * 2) : aMod = (a * 3));
      
   if (a < 0) {
      status = "doubled";
   } 
   else {
      status = "0 or tripled";
   }
   // The 'Ternary if' does not appear to work with string assignments
   // if (a < 0 ? status = "doubled" : status = "0 or tripled");  ERROR DOES NOT COMPILE WITH STRING ASSIGNMENTS
   cout << format(" The orginial value of the variable 'a' {} is now {}, {} ", a, aMod, status);
   
  
   cout << endl << endl;
   system("pause>0");
   return 0;
}

