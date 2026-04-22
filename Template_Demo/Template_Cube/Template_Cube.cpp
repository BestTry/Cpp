// Template_Cube.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// // Modified the template concept presented in textbook shown
// below to demonstrate a template with a cube function instead
//
// Lifted from Deitel and Deitel ' C++20 For Programmers ' page 137
// Fig. 5.13: maximum.h file
// Function template maximum header.
// Function code was contained in this separate header file to simplify readability of main()
// fig05_14.cpp
// Function template maximum test program.
// See the mazimum.h file for algorythm
#include <iostream>
#include <iomanip>
#include <format>

using std::format;


#include "cube.h"   // Include definition of function template maximum held in the same folder *****
using namespace std;

int main() {
   cout << " Demonstrating a template by usign a cube function \n\n";
   // demonstrate the cube of a integer number
   cout << " Input a integer number: ";
   int intNum;
   cin >> intNum;

   // invoke int version of cubed template generic function
   cout << format(" The cubed value of the integer number {} is: {}",
           intNum, (cube(intNum)));

   // demonstrate maximum with double values
   cout << "\n\n Input a double number: ";
   double dblNum;
   cin >> dblNum;

   // invoke double version of cube template generic function
   cout << format(" The cubed value of the double number {} is: {:<20.2f}",
           dblNum, (cube(dblNum)));
   // Format syntax {:<20.2f}??? - Meaning: Left justified, 2 significant figures
   // Enter 3.3 to see limit of significant figures to two places

   cout << endl << endl;
   system("pause>0");
   return 0;
}   // end main
