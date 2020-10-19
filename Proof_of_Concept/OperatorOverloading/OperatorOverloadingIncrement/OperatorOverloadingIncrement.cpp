// OperatorOverloadingIncrement.cpp : Pulled this code from chapter 8 of 'How to Program' - Deitel and Deitel - Fig. 8.12: fig08_12.cpp
// Code demonstrates Operator Overloading of the increment operator ++
// Code uses the Date class and incrementing dates to demonstrate the 'operator++' overloaded operator
//
// Date class test program.
#include <iostream>

using std::cout;
using std::endl;

#include "date1.h"                                      // Date class definition

int main()
{
    Date d1;                                            // Defaults to January 1, 1900 as declared/defined in the 'date1.h' file
    Date d2(12, 27, 1992);
    Date d3(0, 99, 8045);                               // Invalid date will be displayed as 1/1/1900

    cout << "d1 is " << d1 << "\nd2 is " << d2
         << "\nd3 is " << d3;

    cout << "\n\nd2 += 7 is " << (d2 += 7);

    d3.setDate(2, 28, 1992);
    cout << "\n\n  d3 is " << d3;
    cout << "\n++d3 is " << ++d3;

    Date d4(7, 13, 2002);

    cout << "\n\nTesting the preincrement operator:\n"
         << "  d4 is " << d4 << '\n';
    cout << "++d4 is " << ++d4 << '\n';
    cout << "  d4 is " << d4;

    cout << "\n\nTesting the postincrement operator:\n"
         << "  d4 is " << d4 << '\n';
    cout << "d4++ is " << d4++ << '\n';
    cout << "  d4 is " << d4 << endl;

    return 0;

}                                                           // End of main test code