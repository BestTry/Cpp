// Vectors_File_I-O.cpp : Code was copied from Marach's 'C++ Programming' by Mary Delamater - Code is tiltled 'The Temperature Manager Program'
// 
// Description of Program 
// Demonstrate the use of vectors.  Followed by reading and writing to an external file
// ....................................................................................................................................

						// Below is what is known as the Preprocessor Directives - in this Header File section
						// Under Visual Studio 17  -  replace #include "stdafx.h" with #include "pch.h" to provide same library support						
						// The Preprocessor Directives: (Header Files) 							
#include <iostream> 	// Standard Template Library class  -  Used for cout, cin, cerr, printf  ( That is the  reason for brackets < > )
#include <fstream>		// Template Specialization inherited from 'basic_fstream' for file input / output prototype functions - Enables char I/O
#include <string>		// Use the s suffix for literal strings 'string' class - required as a new way of using strings, non char sequence
#include <ctime>		// Required to implement date and time functions
#include <windows.h>	// Required to implement date and time functions - Some IDE / Complilers do not accept this header file
#include <typeinfo>		// Necessary for imlementing the typeid() function 
#include <memory>		// Necessary when using smart pointers. Syntax: unique_ptr<int> ptrName( new int );
#include <array>		// Necessary when using the array class i.e array<arrType, size>
#include <vector>		// Support vector operations - See inputDate
#include <algorithm>	// Copy algorithm - Needed to utilize Standard Template Library functions
						// Before compiling symbol '#' indicates a preprocessing contents of  
						// the input/output stream header file iostream.  This file must be 
						// included with any keyboard input or console screen output
						// Functions within the standard library are as follows:
						// Since classes below are part of C++ stadard library < > are placed around them
#include <cmath>		// Enables the use of the "pow" function with the math library and other mathematical functions
#include <functional>	// References the standard function library - std::function
#include <limits>		// Contains clasees for defining numerical data type limits on each computer platform
#include <iomanip>		// Required to utilize parameterized stream manipulator ie. calling setprecision(3) & fixed functions
#include <thread>		// std::this_thread::sleep_for(std::chrono::seconds(XX) << endl;
#include <chrono>		// std::chrono::seconds(XX)
#include <cstdlib>		// Required to implement the rand() & srand() function.  Also, needed to execute the 'exit()' function.
#include <ctime>		// Required to implement the time(0) function providing a number to seed rand() using srand(): srand( time( 0 ) );
						// Arguement (0) yields an interger value of the calendar in seconds

						// The double colons operator '::' is defined as the "Scope Resolution Operator"
using std::cout;		// Console output
using std::cin;			// Console input
using std::endl;		// End of Line - Clears output buffer and terminates with a new-line character
using std::fixed;		// Both 'fixed' & 'showpoint' are nonparamatized stream manipulators that Do Not require the <iomanip> header file
using std::pow;			// Standard Library Function pow(x,y) definded as x raised to the y power
using std::setw;		// Assure #include <iomanip> is included which requires a parameterized stream manipulator
using std::setprecision;// setprecision(2)indicates a double variable value should be printed with 2 digits to the right of the decimal point


using namespace std;	// Common practice to implement the "std" namespace as it contains multiple supporting useful functions

					// ##### Necessary for the 'GetConsoleWindow()' function below to work! - on Windows 2000 and later
#define _win32_winnt 0x0500
#include <windows.h>
						// #####

// ..............................................   Function Prototype Declaration Code   ..............................................

void displayCmds();                             // Declaration function to display list of user commands
void exitPrgm();							    // Use this function as a optional default to terminate the program


int main()									    // Function main() begins program execution - Entry point for the program
{
											    // ##############################################################
												// Modify position and size of Console Application Window
		HWND console = GetConsoleWindow();		// Get the console handle
		RECT r;									// Stores the console's current dimensions
		GetWindowRect(console, &r);				// MoveWindow(window_handle, x, y, width, height, redraw_window);
		MoveWindow(console, 1300, 0600, 800, 1100, true);
												// ###############################################################


	cout << "\n\n >>>>>>>>>>>>>>>>>>>>>>>>>>>>   Main Code Execution   <<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	cout << "          Experimenting with vectors while reading and writing to files            " << endl;

    // string filename = "temps.txt";
    //// set a full path to the correct file
    //const char* home = getenv("HOME");
    //string user_home = "";
    //if (home) {
    //    user_home = home;
    //}
    //else {
    //    // if home isn't found, edit 'username' so it's correct for your system
    //    user_home = "/Users/username";
    //}
    //string file_path = "/Documents/murach/cpp/files/temp_manager/";
    //filename = user_home + file_path + filename;

    // Above code did not work and I do not know how to make it work. 
    // So I found were the 'temps.txt' resided on my PC and copied the path and placed it here:
    // Using the following path the program was able to find the file and execute the program        
    // filename = "C:/murach/cpp/xcode/book_apps/ch06c_temperature_manager/temperature_manager/temps.txt";
    // Avoiding the above path I just set filename to that shown below and the code works with 
    // the filename in the main project folder where the *.cpp source file resides

    string filename = "temps.txt";
    filename = "temps.txt";
    cout << "\n\n The Temperature Manager program\n\n";
 
                                                    // Moved these 3 lines from inside while loop just before vector sizing statements
                                                    // Read the history low and high temps from file and store them in vectors
    int dayNum, index;                              // Used within while loop for viewing temperature table    
    double low, high;                               // Used to hold the double type low and high temperature 
    vector<double> low_temps, high_temps;           // Instiate two vector array objects containing temperatures
    ofstream output_file;                           // Initialize file stream object for writing to files using the ofstream class
    ifstream input_file;                            // Create (instantiate) a file input stream object using the ifstream class

    displayCmds();
        
    input_file.open(filename);                      // Open an input file object having a name contained in variable 'filename'
    if (input_file) {                               // if file opened successfully...This must be boolean 'true' - 
        while (input_file >> low >> high) {         // Assuming test will be 'true' as long as there is data in the file to read
            low_temps.push_back(low);               // Once the last of the data is read the while test becomes 'false'
            high_temps.push_back(high);             // Build low and high temperature vector arrays from data in file temps.txt        
        }                                           // While test fails at this point meaning there is no longer andy data to be read
        input_file.close();                         // End of file data reached: Close the file I/O object which terminates any further xfr
    }
    else {                                          // Either the file code not be found or there is no data in the file to be read
        cout << "\nUnable to open file. You may need to add temperatures to view temperature list.\n";
    }                                               // Therefore user has an option of adding temperature date which will create a file

    
    char command = 'v';                             // Initialize variable command to anything prior to the next while boolean test
    while (command != 'x') {                        // Get command from user - Check for 'Terminate Program' - 'x' command
        cout << endl;
        cout << "Command: ";                        // Repeat solicitation for action until terminate command is recognized
        cin >> command;       
                                                    // These vector contents and sizes may change each time through the loop
        int loTmpVecSz = low_temps.size();          // Compute vector sizes to be placed in the for-loops
        int hiTmpVecSz = high_temps.size();         // Using initializing within for loops gave warning messages

        
        switch (command) {                          // Select and execute appropriate user command
        case 'v':
            cout << "TEMPERATURES\n"                // Column definition format
                << left << setw(4) << "Day"
                << right << setw(6) << "Low" << setw(6) << "High" << endl
                << "---   ----  ----" << endl;

            cout << fixed << setprecision(1);
            dayNum = 1;   
            for (int i = 0; i < loTmpVecSz; ++i) {  // Continue thru loop til last vector elem is reached
                low = low_temps[i];
                high = high_temps[i];
                cout << " "<< left << setw(3) << dayNum
                    << right << setw(6) << low << setw(6) << high << '\n';
                ++dayNum;
            }
            break;                                  // Return to 'while' loop beginning

            // TODO // This user input must be protected from type input error
        case 'a':                                    
            cout << "Enter day low temp: ";
            cin >> low;

            cout << "Enter day high temp: ";
            cin >> high;

            low_temps.push_back(low);               // Adding temperature values to end of vector arrays        
            high_temps.push_back(high);             // Adding temperature values to end of vector arrays            
            break;                                  // Return to 'while' loop beginning

        case 'r':
            int day;
            cout << "Enter day to remove: ";
            cin >> day;

            index = day - 1;
            if (index >= 0 && index < hiTmpVecSz) {
                high_temps.erase(high_temps.begin() + index);
                low_temps.erase(low_temps.begin() + index);
            }

            cout << "Temps for day " << day << " have been removed.\n";
            break;                                  // Return to 'while' loop beginning

        case 's':                                   // If file does not exist, it will be created here
            output_file.open(filename);             // Open ofstream in preparation for writing data
            for (int i = 0; i < loTmpVecSz; ++i) {
                low = low_temps[i];
                high = high_temps[i];
                output_file << low << '\t' << high << '\n';
            }
            output_file.close();
            cout << "Your changes have been saved.\n";
            break;                                  // Return to 'while' loop beginning

        case 'c':
            displayCmds();
            break;

        case 'x':
            cout << "Good Bye! - Program has ended \n\n";
            break;

        default:                                    // Any char beside the chars not identified in the switch list 
            cout << "Invalid command has been entered - Try again.\n";
            break;
        }
    }                                               // Receive the 'Terminate Program' command

	
	exitPrgm();					// Option function member to terminate program
	system("pause");			// Some compilers do not recognize this statement
	return 0; 					// Indicates successful termination
}								// End of main

// .............................................   Function Code Definition Implementation  .................................................
//    When functional coded is declared above before the main coding section use this area for functional code implementation

void displayCmds() {
    cout << "COMMANDS\n"
         << "v - View temperatures\n"
         << "a - Add temperatures\n"
         << "r - Remove temperatures\n"
         << "s - Save changes to file\n"
         << "c - Display command list\n"
         << "x - Exit program\n";
}

void exitPrgm()
{
	cout << "\n\n                  >>>>>>>>>>  Program has Terminated  <<<<<<<<<< " << endl;
	cout << " \n\n\n " << endl;
	exit(0);					// Terminate running program from anywhere it is called:
}

/*

|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|
012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
		  |         |         |         |         |         |         |         |         |         |         |         |         |         |
00		  10        20        30        40        50        60        70        80        90		00		  10        20        30        40

*/