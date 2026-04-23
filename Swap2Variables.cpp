// Swap2Variables.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Repeating algorithm from the on-line "Code Beauty" Tutorial about the 2.0 hour mark of C++ Tutorial in 10 Hours
// 

#include <iostream>
using namespace std;


int main()
{

   cout << " This algorithm demonstrates swapping two \n"
        << " variables without using a temporary variable\n" << endl;

   int x = 20, y = 40;

   cout << " Before swapping, the values of variables x and y are:" << endl;
   cout << " x = " << x << " and  y = " << y << endl << endl;

   x = x + y;           // 60
   y = x - y;           // 20
   x = x - y;           // 40

   cout << " After swapping, the values of variables x and y are:" << endl;
   cout << " x = " << x << " and  y = " << y << endl;

   system("pause>0");
}