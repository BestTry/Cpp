// Definition / Implementation file for the personal String class - Fig. 8.8: string1.cpp
// Member function definitions for class String.
//

#define _CRT_SECURE_NO_DEPRECATE                   // Force to add this statement to remove warings concerning the strcpy() function
#include <iostream>
#include <iomanip>
#include <new>                                      // C++ standard "new" operator
#include <cstring>                                  // strcpy and strcat prototypes
#include <cstdlib>                                  // exit prototype
#include "string1.h"                                // String class definition

using std::cout;
using std::endl;
using std::setw;

String::String(const char* s)                       // Conversion constructor converts char * to String
    : length((s != 0) ? strlen(s) : 0)              // Acquires length of string and saves it in length for the string object
{
    cout << "Conversion constructor: " << s << '\n';
    setString(s);                                   // Call utility function setString() (sets sPtr) and then calls strcpy()

}                                                   // End String conversion constructor


String::String(const String& strgTocopy)            // Copy constructor
    : length(strgTocopy.length)                     // First save the length of the source string
{
    cout << "Copy constructor: " << strgTocopy.sPtr << '\n';
    setString(strgTocopy.sPtr);                     // Calls utility function 'setString' which calls strcopy()
}                                                   // End String copy constructor


String::~String()                                   // Destructor
{
    cout << "Destructor was executed for string: " << sPtr << '\n';
    delete[] sPtr;                                  // Reclaims the memory used by the string

}                                                   // End  of ~String destructor


const String& String::operator=(const String& right)// Assignment Overloaded operator '='; - avoids self assignment
{                                                   
    cout << "operator= called\n";
    if (&right != this) {                           // Avoids self assignment and dangling pointer
        delete[] sPtr;                              // Prevents memory leak and dangling pointer
        length = right.length;                      // New String length for new string 
        setString(right.sPtr);                      // Call utility function - Copies old string into new string using strcopy
    }

    else
        cout << "Attempted assignment of a String to itself\n";

    return *this;                                   // Enables cascaded assignments
}                                                   // End function overloaded operator=


const String& String::operator+=(const String& right)// concatenate right operand to this object and
{                                                   // store in this object.  (Below: Uses pointer arithmetic to calc new length)
    size_t newLength = length + right.length;       // Calculate combined length from this string length plus new string length
    char* tempPtr = new char[newLength + 1];        // Create memory space where new concatenated string will be stored

    strcpy(tempPtr, sPtr);                          // Copy original character string from sPtr into memory beginning at tempPtr
    strcpy(tempPtr + length, right.sPtr);           // Copy new character string (right.sPtr) starting at the end of tempPtr 
                                                    // Both character are now concantenated at starting at Pointer tempPtr
    delete[] sPtr;                                  // Reclaim old memory space (housekeeping)
    sPtr = tempPtr;                                 // Assign new concantenated array to point to sPtr pointer variable
    length = newLength;                             // Assign new length to lagacy variable 'length' 

    return *this;                                   // Enables cascaded calls
}                                                   // End of function overload operator+=


bool String::operator!() const                      // String is empty (return true) if length of string is zero
{
    return length == 0;                             // Boolean test 
}                                                   // end of function overloaded operator! 


bool String::operator==(const String& right) const  // Is this String equal to right String?
{
    return strcmp(sPtr, right.sPtr) == 0;           // Function strcmp() returns zero value if both strings are eqivalent
}                                                   // End of overloaded function operator==


bool String::operator<(const String& right) const   // Determine if this String less than right String?
{                                                   // Func srtcmp(s1, s2) returns: neg if s1 < s2; zero if s1 == s2; pos if s1 > s2
    return strcmp(sPtr, right.sPtr) < 0;            // Therefore return is positve (true) if s1 < s2 and zero or negative for other two cases
}                                                   // End function overload operator<


char& String::operator[](int subscript)             // Return a reference to a character in String as a lvalue
{
    
    if (subscript < 0 || subscript >= length) {     // Test for subscript being out of range
        cout << "Error: Subscript " << subscript
             << " out of range" << endl;
        exit(1);                                    // Terminate program
    }

    return sPtr[subscript];                         // Creates a lvalue (left value variable - modifiable)
}                                                   // End of function overload operator[]


const char& String::operator[](int subscript) const // Return a reference to a character in String as a rvalue
{    
    if (subscript < 0 || subscript >= length) {     // Test for subscript being out of range
        cout << "Error: Subscript " << subscript
             << " out of range" << endl;
        exit(1);                                    // Terminate program
    }

    return sPtr[subscript];                         // Creates a rvalue (right value constant - not modifiable)
}                                                   // End of function overload operator[]



String String::operator()(int index, int subLength) // Returns a substring beginning at index and of length subLength
{                                                   // If index is out of range or substring length < 0, return an empty String object    
    if (index < 0 || index >= length || subLength < 0)
        return "";                                  // Converted to a String object automatically

    int len;                                        // Define variable 'len' to support getting length of substring
    if ((subLength == 0) || (index + subLength > length))
        len = length - index;                       // Protects against overange of substring -> gives index to end of string for substring
    else
        len = subLength;

    char* tempPtr = new char[len + 1];              // Allocate temporary array for substring and terminating null character '\0'     
    strncpy(tempPtr, &sPtr[index], len);            // Copy substring of length 'len' into char array and terminate string
    tempPtr[len] = '\0';                            // Insert trailing / terminating null character '\0'    
    String tempString(tempPtr);                     // Create temporary String object containing the substring
    delete[] tempPtr;                               // Deletes temporary array  (housekeeping - reclaim memory)

    return tempString;                              // Return copy of the temporary String which is the requested target substring
}                                                   // End function operator()


int String::getLength() const                       // Return string length - Using a getter since member variable 'length' is scoped private
{
    return length;
}                                                   // End function getLength


void String::setString(const char* string2)         // Utility function called by constructors and the overload operator=
{
    sPtr = new char[length + 1];                    // Allocate memory for new string;  The length variable value is length of string2
    if (string2 != 0)                               // If string2 is not a null pointer, copy contents 
        strcpy(sPtr, string2);                      // Copy literal to object  (New string is assigned/created)   
    else                                            // If string2 is a null pointer, make this an empty string
        sPtr[0] = '\0';                             // Create empty string
}                                                   // End function setString 


ostream& operator<<(ostream& output, const String& s)
{                                                   // Insertion output Overloaded operator (friend)
    output << s.sPtr;                               // Inserts string into 'output' starting with charactor at address sPtr

    return output;                                  // Enables cascading
}                                                   // End function operator<<


istream& operator>>(istream& input, String& s)      // Extraction input Overloaded operator (friend)
{                                                   // Input characters limited to 99 plus null character
    char temp[100];                                 // Buffer array to store input
    input >> setw(100) >> temp;                     // Input characters limited to 99 plus null character
    s = temp;                                       // Uses String class assignment operator - which uses
                                                    // the functions 'setString()' and 'strcpy()' 
    return input;                                   // Enables cascading
}                                                   // End of function operator>>
