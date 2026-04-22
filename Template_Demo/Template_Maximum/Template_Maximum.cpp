// Template_Maximum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Template_Maximum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// fig05_14.cpp
// Function template maximum test program.
// See the mazimum.h file for algorythm
#include <iostream>
#include "maximum.h" // Include definition of function template maximum held in the same folder *****
using namespace std;

int main() {
   // demonstrate maximum with int values
   cout << "Input three integer values: ";
   int int1, int2, int3;
   cin >> int1 >> int2 >> int3;

   // invoke int version of maximum template generic function
   cout << "The maximum integer value is: "
      << maximum(int1, int2, int3);

   // demonstrate maximum with double values
   cout << "\n\nInput three double values: ";
   double double1, double2, double3;
   cin >> double1 >> double2 >> double3;

   // invoke double version of maximum template generic function
   cout << "The maximum double value is: "
      << maximum(double1, double2, double3);

   // demonstrate maximum with char values
   cout << "\n\nInput three characters: ";
   char char1, char2, char3;
   cin >> char1 >> char2 >> char3;

   // invoke char version of maximum template generic function
   cout << "The maximum character value is: "
      << maximum(char1, char2, char3) << '\n';

   system("pause>0");
   return 0;
}   // end main
