// Argument _Priority.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


int main()
{
   std::cout << " Demo of operand presedence \n" << std::endl;
   double a = 48, b = 3, c = 4;
   double product1 = a / b * c * 2;      // Is this 2.0 or 128.0 ?
   double product2 = a / (b * c * 2);    // Is this 2.0 or 128.0 ?

   cout << " Are the products equal to the value 2.0 or 128.0 ?" << endl;
   std::cout << " Product1 Value: " << product1 << " <= [ a / b * c * 2 ]" << endl;
   std::cout << " Product2 Value:   " << product2 << " <= [ a / (b * c * 2) ]" << endl;

   cout << "\n Where the double variables equal:  a = 48.0, b = 3.0, c = 4.0" << endl;

   system("pause>0");
   return 0;
}
