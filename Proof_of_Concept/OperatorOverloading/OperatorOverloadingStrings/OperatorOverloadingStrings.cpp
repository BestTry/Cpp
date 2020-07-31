// OperatorOverloadingStrings.cpp : Code was pulled from textbook ' to Program' - Deitel and Deitel - 
// Chapter  - Fig. 8.9: fig08_09.cpp
// Athours of the textbook produced this code to demostrate operator overloading - 
// Use C++ approved String class for future code.
// This code was only developed for demostrating the operator overloading concept.
//      
// String class test program.

#include <iostream>

using std::cout;
using std::endl;

#include "string1.h"

int main()
{
    String s1("happy");
    String s2(" birthday");
    String s3;
        
    cout << "s1 is \"" << s1 << "\"; s2 is \"" << s2         // Test overloaded equality and relational operators
        << "\"; s3 is \"" << s3 << '\"'
        << "\n\nThe results of comparing s2 and s1:"
        << "\ns2 == s1 yields "
        << (s2 == s1 ? "true" : "false")
        << "\ns2 != s1 yields "
        << (s2 != s1 ? "true" : "false")
        << "\ns2 >  s1 yields "
        << (s2 > s1 ? "true" : "false")
        << "\ns2 <  s1 yields "
        << (s2 < s1 ? "true" : "false")
        << "\ns2 >= s1 yields "
        << (s2 >= s1 ? "true" : "false")
        << "\ns2 <= s1 yields "
        << (s2 <= s1 ? "true" : "false");
    
    cout << "\n\nTesting !s3:\n";                           // Test overloaded String empty (!) operator

    if (!s3) {
        cout << "s3 is empty; assigning s1 to s3;\n";
        s3 = s1;                                            // Test overloaded assignment
        cout << "s3 is \"" << s3 << "\"";
    }

    cout << "\n\ns1 += s2 yields s1 = ";                    // Test overloaded String concatenation operator
    s1 += s2;                                               // Test overloaded concatenation
    cout << s1;

    cout << "\n\ns1 += \" to you\" yields\n";               // Test conversion constructor
    s1 += " to you";                                        // Test conversion constructor
    cout << "s1 = " << s1 << "\n\n";
        
    cout << "The substring of s1 starting at\n"             // Test overloaded function call operator () for substring
        << "location 0 for 14 characters, s1(0, 14), is:\n"
        << s1(0, 14) << "\n\n";
                                    
    cout << "The substring of s1 starting at\n"             // Test substring "to-end-of-String" option
        << "location 15, s1(15, 0), is: "
        << s1(15, 0) << "\n\n";                             // Value '0' is inserted "to end of string"

    String* s4Ptr = new String(s1);                         // Test copy constructor
    cout << "\n*s4Ptr = " << *s4Ptr << "\n\n";
    
    cout << "Asigning *s4Ptr to *s4Ptr\n";                  // Test assignment (=) operator with self-assignment
    *s4Ptr = *s4Ptr;                                        // Test overloaded assignment
    cout << "*s4Ptr = " << *s4Ptr << '\n';

    
    delete s4Ptr;                                           // Test destructor

    s1[0] = 'H';                                            // Test using subscript operator to create lvalue
    s1[6] = 'B';
    cout << "\ns1 after s1[0] = 'H' and s1[6] = 'B' is: "
         << s1 << "\n\n";

   
    cout << "Attempt to assign 'd' to "                     // Test subscript out of range
         << "s1[30] yields:" << endl;  
    s1[30] = 'd';                                           // ERROR: subscript out of range

    return 0;

    }                                                       // End of main
