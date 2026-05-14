// notAnumFncChk.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
*            Check Floating-Point Variables (std::isnan)
* The most reliable method for checking if a float or double variable 
* is NaN using the std::isnan function defined in the <cmath> header.
*/
#include <iostream>
#include <format>
#include <cmath>                 // Required for std::isnan

using std::format;
using std::isnan;
using std::sqrt;
using std::cout;
using std::cin;
using std::endl;


int main() {
   int two = 4;
   if (isnan(two)) {
      cout << format(" Value {} is Not-a-Number (NaN)\n", two);
   }
      cout << format(" Function isnan(val) for val = {} returns a {} result\n", two, isnan(two));

   double val = sqrt(-1.0); // Generates NaN
   if (isnan(val)) {
      cout << format(" Value {} is Not-a-Number (NaN)", val);
   }
      cout << endl;
      double dbl= 4.9;
      cout << format(" Function isnan(val) for val = {} returns a {} result\n", val, isnan(dbl));
      char chr = 'z';
      cout << format(" Function isnan(val) for chr = {} returns a {} result\n", chr, isnan(val));
      int num = 77;
      cout << format(" Function isnan(val) for int = {} returns a {} result\n", num, isnan(num));
  

   cout << endl << endl;
   system("pause>0");
   return 0;
}

