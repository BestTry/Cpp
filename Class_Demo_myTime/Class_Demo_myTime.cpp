// Class_Demo_myTime.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Code was retrieved from "C++20 for Programmers" textbook - Deitel and related video from "O'Reilly Leaning" web site
// fig09_09.cpp -  TimeTestmObj_0.cpp of textbook - Assure Version C++20 compiler version is implemented
// *** Activate *** C++20 version of compiler by right-clicking on project name and drilling down on 'Properties"
// Select Configuration Properties > C/C++ > Language > C/C++ Language Standard 
// 
// Program to test class Time.  
// ***** Separating interface from implementation with separate files *****                  
// Separate files for main(), declaration and definition files
// NOTE: This main() file must be linked with declaration.h and definition.cpp
// The "declaration.h" file is organized and can be seen under the "Header Files" "folder
// The "definition.cpp" file is organized and can be seen under the "Source Files" "folder
// 
// In this version, I copied the original declaration code that was sitting over this main block. 
// I then placed the declaration file with its declaration type code within the  'Header Files' section.  
// The definition code is held under and remains under the 'Source Files' section.
// 

#include <format>
#include <iostream>
#include <stdexcept>                            // Require for Invalid_argument exception class
#include <string>
#include <string_view>                          // Required for long strings with spaces #include 
#include "declaration.h"                        // Declaration class Time in Declaration.h;   

using namespace std;
using std::format;
using std::cout;
using std::endl;

int main() {
   string const msg0{ " Testing a new custom 'myTime' class under the 'cpp20' compiler version\n" };
   cout << format("\n Code Purpose: {}", msg0) << endl;

   myTime tmObj_0{};                            // Instantiate object tmObj_0 of class myTime
                                                // Display tmObj_0's initial default value < 00:00:00 >
   tmObj_0.displayTime(" Initial default 'tmObj_0 time:");

   tmObj_0.setTime(13, 27, 6);                  // Change the time from the initial default values
   tmObj_0.displayTime(" Change to tmObj_0:");  // display tmObj_0's new value

   tmObj_0.setTime(8, 17, 11);                  // Change time for the tmObj_0 object
   tmObj_0.displayTime(" Change to tmObj_0:");  // display tmObj_0's new value

   cout << " Set an invalid time: 99:99:99\n";  // Attempt to set the time with invalid values
                                                // In this case all three parameters are out-of-range

   try {                                        // Try / Catch statements
      tmObj_0.setTime(99, 99, 99);              // Values out of range - Will cause an exception to occur
   }                                            // If 'try' fails, terminate it immediately fall thru to catch
   catch (const std::invalid_argument& e) {
      cout << format(" Exception: {}\n\n", e.what());
   }
                                                // Display tmObj_0's value after attempting to set an invalid time
   tmObj_0.setTime(18, 45, 41);                 // Change time to valid entry values
   tmObj_0.displayTime(" After setting an invalid time, ... A new valid time for object 'tmObj_0' was entered: ");

   tmObj_0.setTime(21, 28, 03);                 // Enter another valid entry values; display object tmObj_0's new value
   tmObj_0.displayTime(" Another new valid time was entered:");
                                                // Demo of assigning one class to another using class assignment operator ' = '
   string const msg1{ " Next: Demonstrating the class assignment operator '='" };
   string const msg2{ " Assigning one class to another: (tmObj_1 = tmObj_0)" };
   cout << format("{}\n{}\n", msg1, msg2) << endl;
                                                // Instantiating another myTime class object
   cout << (" Instantiating a new 'mytime' class object: 'tmObj_1'\n");
   myTime tmObj_1{};                            // Instantiate object tmObj_1 of class Time
   tmObj_1.displayTime(" Display instantiated myTime object's 'tmObj_1' initial time:");
                                                // Above ^ Displayed tmObj_1's initial value
   cout << " After re-assigning tmObj_1 = tmObj_0,";
   tmObj_1 = tmObj_0;
   tmObj_1.displayTime("\n Object 'tmObj_1 time values are now:");

   cout << "\t    Press the \"Push the 'Enter' keyboard key to exit program\"" << endl;
   cout << endl << endl;
   system("pause>0");
   cout << " \t\t\t     *** GoodBye! ***\n\n\n\n" << endl;
   return 0;
}
