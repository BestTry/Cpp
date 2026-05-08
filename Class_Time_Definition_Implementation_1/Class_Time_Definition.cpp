// Class_Time_Definition.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Code was retrieved from "C++20 for Programmers" textbook - Deitel and related video from "O'Reilly Leaning" web site
// fig09_09.cpp -  TimeTestmObj_0.cpp of textbook - Assure Version C++20 compiler version is implemented
// *** Activate *** C++20 version of compiler by right-clicking on project name and drilling down on 'Properties"
// Select Configuration Properties > C/C++ > Language > C/C++ Language Standard 
// 
// Program to test class Time.  
// ***** Separating interface from implementation with separate files *****                  
// Separate files for main(), myTime() declaration and myTime() definition
// NOTE: This main() file must be linked with myTime.cpp and myTime.hS
// The "myTime.cpp" file is organized and can be seen under the "Source Files" "folder
// // The "myTime.h" file is organized and can be seen under the "Header Files" "folder
//
// Once Time class is defined, it can be used  as a type 
//    * Time sunset{};                          // An object of type time with default members set to '0'
//    * std::array<Time, 5> arrayOftimes>{};    // Standard array of 5 Time objects
//    * Time& dinnerTimeRef{sunset};            // Reference to a Time object
//    * timePtr{&sunset};                       // Pointer to a Time object

#include <format>
#include <iostream>
#include <stdexcept>                            // Invalid_argument exception class
#include <string>
#include <string_view>                          // Required for long strings with spaces #include 
#include "myTime.h"                             // Declaration class Time in myTime.h; // Orig name chgd from "Time.h" to rmove err  
                                                
using namespace std;
using std::format;
using std::cout;
using std::endl; 
                                                // *** See "Class_Time_Definition_Alternate_Implementation_2***
                                                // *** Alternate_Implementation_2 places function within header file and Source Files ***
                                                // ** This implementation has the function definition just outside of the Main() section
                                                // Displays a Time in 24-hour and 12-hour formats
                                                // A reference address to a myTime constant is passed to the function
                                                // Function displayTime() takes two arguments: Text message & an object reference both passed
void  displayTime(string_view message, const myTime& myTime) {
      cout << format("{}\n 24-hour time: {}\n 12-hour time: {}\n\n",
      message, myTime.to24HourString(), myTime.to12HourString());
}

int main() {
   string const msg0{ " Testing a new custom 'myTime' class under the 'cpp20' compiler version\n" };
   cout << format("\n Code Purpose: {}", msg0) << endl;

   myTime tmObj_0{};                            // Instantiate object tmObj_0 of class Time

   displayTime(" Initial time:", tmObj_0);      // Display tmObj_0's initial value

   tmObj_0.setTime(13, 27, 6);                  // Change time
   displayTime(" After setTime1:", tmObj_0);    // display tmObj_0's new value

   tmObj_0.setTime(8, 17, 11);                  // Change time
   displayTime(" After setTime2:", tmObj_0);    // display tmObj_0's new value

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
   displayTime(" After setting an invalid time, ... A valid time was entered: ", tmObj_0);

   tmObj_0.setTime(21, 28, 03);                 // Enter another valid entry values; display object tmObj_0's new value
   displayTime(" Another new valid time was entered:", tmObj_0);
                                                // display tmObj_0's new value
                                                // Demo of assigning one class to another using class assignment operator ' = '
   string const msg1{ " Next: Demonstrating the class assignment operator '='" };
   string const msg2{ " Assigning one class to another: (tmObj_1 = tmObj_0)" };
   cout << format("{}\n{}\n", msg1, msg2) << endl;
                                                // Instantiating another myTime class object
   cout << (" Instantiating a new 'mytime' class object: 'tmObj_1'\n");
   myTime tmObj_1{};                            // Instantiate object tmObj_1 of class Time
   displayTime(" Display instantiated myTime object's 'tmObj_1' initial time:", tmObj_1);
                                                // Above ^ Displayed tmObj_1's initial value
   cout << " After reassigning tmObj_1 = tmObj_0,";
   tmObj_1 = tmObj_0;
   displayTime("\n Object 'tmObj_1 time values are now:", tmObj_1);

   cout << endl << endl;
   system("pause>0");
   return 0;

}
















