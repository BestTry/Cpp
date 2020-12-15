// Strings_Std_Lib_OvrLd_Fncs.cpp : Code was pulled form textbook: 'How to Program' by Deitle and Deitel - Chapter 8.  Fig. 8.13: fig08_13.cpp
// This code is almost an exact implementation of previously gerated code demostrating a personal 'String' class using overloaded operators.
// This code instead of using the personal string class using the String class provided in the C++ standard library. This was done to demonstrate the 
// equivalency of the two pieces of code while showing was is really hidden or behind the implementation of the the standard class String code.
// So it is recommended that one compare this code with the code implementing the same functionality but using the personally developed String class.
//
// 
// Standard library string class test program.
#include <iostream>

using std::cout;
using std::endl;

#include <string>

using std::string;

int main()
{
    string s1("happy");
    string s2(" birthday");
    string s3;
                                                                    // Test SDL Class overloaded equality and relational operators
    cout << "s1 is \"" << s1 << "\"; s2 is \"" << s2
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

    
    cout << "\n\nTesting s3.empty():\n";                            // Test SDL Class string member function empty 

    if (s3.empty()) {
        cout << "s3 is empty; assigning s1 to s3;\n";
        s3 = s1;                                                    // Assign s1 to s3 - SDL Class - Overloaded operator '='
        cout << "s3 is \"" << s3 << "\"";
    }

    
    cout << "\n\ns1 += s2 yields s1 = ";                            // Test SDL Class overloaded string concatenation operator
    s1 += s2;                                                       // Test SDL Class overloaded concatenation
    cout << s1;

    cout << "\n\ns1 += \" to you\" yields\n";                       // Test SDL Class overloaded string concatenation operator with C-style string
    s1 += " to you";
    cout << "s1 = " << s1 << "\n\n";

    
    cout << "The substring of s1 starting at location 0 for\n"      // Test SDL Class string member function substr
        << "14 characters, s1.substr(0, 14), is:\n"
        << s1.substr(0, 14) << "\n\n";

                                                                    
    cout << "The substring of s1 starting at\n"                     // Test SDL Class substr "to-end-of-string" option
        << "location 15, s1.substr(15), is:\n"
        << s1.substr(15) << '\n';

                                                                    
    string* s4Ptr = new string(s1);                                 // Test SDL Class copy constructor
    cout << "\n*s4Ptr = " << *s4Ptr << "\n\n";

                                                                    
    cout << "Assigning *s4Ptr to *s4Ptr\n";                         // Test SDL Class assignment (=) operator with self-assignment
    *s4Ptr = *s4Ptr;
    cout << "*s4Ptr = " << *s4Ptr << '\n';

                                                                    // Test SDL Class destructor
    delete s4Ptr;

                                                                   
    s1[0] = 'H';                                                     // Test SDL Class using subscript operator to create lvalue
    s1[6] = 'B';
    cout << "\ns1 after s1[0] = 'H' and s1[6] = 'B' is: "
        << s1 << "\n\n";

                                                                    
    cout << "Attempt to assign 'd' to s1.at( 30 ) yields:" << endl; // Test SDL Class subscript out of range with string member function "at"
    s1.at(30) = 'd';                                                // ERROR: subscript out of range test SDL Class

    return 0;

}                                                                   // End main
