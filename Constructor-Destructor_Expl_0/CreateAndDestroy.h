#pragma once // prevent multiple inclusions of header
// Copied from "C++20 for Programmers by Dietel - Fig. 9.13: CreateAndDestroy.h
// CreateAndDestroy class Declaration file.
// Member functions defined in CreateAndDestroy.cpp.

#include <string>
#include <string_view>

using std::string;
using std::string_view;

class CreateAndDestroy {
public:                                            // Public Class Memebers
   CreateAndDestroy(int ID, string_view message);  // Constructor
   ~CreateAndDestroy();                            // Destructor   

private:                                           // Private class members
   int m_ID;                                       // ID number for object (Interger type)
   string m_message;                               // Message describing object (string type)
};

