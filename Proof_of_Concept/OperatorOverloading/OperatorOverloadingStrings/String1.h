// String class Declaration Header Prototype file -  Fig. 8.7: string1.h of textbook
#pragma once
//
#ifndef STRING1_H
#define STRING1_H

#include <iostream>

using std::ostream;
using std::istream;

class String {                                              // Declared as friends as they are used on the right hand side of the stream operators
    friend ostream& operator<<(ostream&, const String&);    // Declares insertion overload operator '<<' for outputting a string
    friend istream& operator>>(istream&, String&);          // Declares extraction overload operator '>>' for inputting a string

public:
    String(const char* = "");                               // Conversion / Default constructor - Defaults empty string - Can covert to string object
    String(const String&);                                  // Copy constructor - Copies the reference to the string
    ~String();                                              // Destructor

    const String& operator=(const String&);                 // Assignment overload operator
    const String& operator+=(const String&);                // Concatenation overload operator

    bool operator!() const;                                 // Determines if string is empty with a bool (checks lenght) value String empty?
    bool operator==(const String&) const;                   // Determines is string 's1' is equivalent size and content to string 's2'
    bool operator<(const String&) const;                    // Determines is string 's1' is less than in ???? size and content to string 's2'

    
    bool operator!=(const String& right) const              // Determine if  s1 != s2 - Declaration and Definition here 
    {
        return !(*this == right);                           // Takes advantage of the overloaded operator== function defined within class
    }                                                       // End of overloaded function operator!=

                                                            // Declaration & Definition - Note logic inversion: (*this) is on the right hand side!
    bool operator>(const String& right) const               // Test if s1 > s2 Works because the function uses the overloaded operator< function
    {                                                       // which in turn uses the strcmp() funtion which only returns a positive value if
        return right < *this;                               // si < s2; Otherwise it returns a negative num if greater than > or 0 if equal ==
    }                                                       // End function overloaded operator>

    
    bool operator<=(const String& right) const              // Test s1 <= s2 by taking advantage of existing functions and performing a negate
    {
        return !(right < *this);                            // Note that (* this) is on the right-hand side of the equation for the logic to work
    }                                                       // End of function overloaded operator<=

    
    bool operator>=(const String& right) const              // Test boolean:  s1 >= s2; For this logic to work (*this) is on the left 
    {                                                       // As above this function takes advantage of existing functionality of the class
        return !(*this < right);
    }                                                       // End function operator>=

    char& operator[](int);                                  // Subscript overload operator for non-constant Strings
    const char& operator[](int) const;                      // Subscript overload operator for     constant Strings

    String operator()(int, int);                            // Returns a substring

    int getLength() const;                                  // Returns string length

private:                                                    // Private members of the String class
    int length;                                             // String length (Not cluding the endng null charcter '0')
    char* sPtr;                                             // Pointer to start of string (Character Array) - Dynamically allocated memory

    void setString(const char*);                            // Utility function (Internal class usage)

};                                                          // End of class String

#endif
