// ASCII_Dec_Nums.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// ASCII_&_Char_Decimal_Numbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
using namespace std;   				// Avoids having to enter "std::cout" or "std::cin" every time

int main()
{
   cout << endl << endl;
   char c1, c2, c3, c4, c5;			// Define character type variables
   cout << " Enter five 'char' characters here:\n ";
   cin >> c1 >> c2 >> c3 >> c4 >> c5;
   cout << "\n The above 'char' characters converted\n" <<
      " to their equivalent ASCII numbers are:\n ";
   cout << int(c1) << " " << " " << int(c2) << " " << " " << int(c3)
      << " " << " " << int(c4) << " " << " " << int(c5);

   cout << endl << endl << " ..........................\n\n" << endl;

   int int1 = 0, int2 = 0, int3 = 0, int4 = 0, int5 = 0;
   cout << " Enter five ASCII integer mumbers here:\n ";
   cin >> int1 >> int2 >> int3 >> int4 >> int5;
   cout << "\n The decimal ASCII numbers converted\n" <<
      " to their equivalent characters are:\n ";
   cout << char(int1) << " " << char(int2) << " " << char(int3)
      << " " << char(int4) << " " << char(int5);


   cout << endl << endl;
   system("pause>0");   // Statement avoids output text upon termination of run
   return 0;            // indicate successful termination   
}
