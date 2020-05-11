// todoTasks.cpp : Code will generate a user input list of tasks. It will have the ability to add, remove and list tasks. Code will use some of the recently 
// assumated concepts I have been exposed to through either video lessons or tutorials.  As a minimum it will use file reading from and reading to disk file. 
// The program will store its content in several vectors.
//
//
//
// Description of Program .............  Boiler Plate Template  .............................
// ..........................................................................................
// ..........................................................................................
// ..........................................................................................
//
// Additonal Code Description : Steps Enumerated 
// 1 - 
// 2 - 
// 3 - 
// 4 - 
						// The Preprocessor Directives: (Header Files) 							
#include <iostream> 	// Standard Template Library class  -  Used for cout, cin, cerr, printf  ( That is the  reason for brackets < > )
#include <iomanip>		// Required to utilize parameterized stream manipulator ie. calling setprecision(3) & fixed functions
#include <fstream>		// Inherited from 'basic_fstream' for file I/O - Defines Data types: ofstream, ifstream, and fstream
#include <sstream>		// Used when interfacing strings by reading from and writing to files
#include <iterator>
#include <string>		// Use the s suffix for literal strings 'string' class - required as a new way of using strings, non char sequence
#include <windows.h>	// Required to implement adjusting the Consoles window size and position - CAUSES PROBLEMS with <limits>
#include <typeinfo>		// Necessary for imlementing the typeid() function 
#include <memory>		// Necessary when using smart pointers. Syntax: unique_ptr<int> ptrName( new int );
#include <array>		// Necessary when using the array class i.e array<arrType, size>
#include <vector>		// Support vector operations - See inputDate
#include <algorithm>	// Copy algorithm - Needed to utilize Standard Template Library functions
						// Before compiling symbol '#' indicates a preprocessing contents of  
						// the input/output stream header file iostream.  This file must be 
						// included with any keyboard input or console screen output
						// Functions within the standard library are as folpriLvls:
						// Since classes bepriLvl are part of C++ stadard library < > are placed around them
#include <cmath>		// Enables the use of the "pow" function with the math library and other mathematical functions
#include <functional>	// References the standard function library - std::function
#include <limits>		// Contains clasees for defining numerical data type limits on each computer platform
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

/*						// ##### Necessary for the 'GetConsoleWindow()' function bepriLvl to work! - on Windows 2000 and later
#define _win32_winnt 0x0500
#include <windows.h>
*/						// #####

// ..................................................   Function Prototype Declaration Code   ...............................................
string getFileName();
void displayCmds();                             // Declaration function to display list of user commands
void exitPrgm();							    // Use this function as a optional default to terminate the program
// ..........................................................................................................................................

int main()									// Function main() begins program execution - Entry point for the program
{
	/*											// ##############################################################
												// Modify position and size of Console Application Window
		HWND console = GetConsoleWindow();		// Get the console handle
		RECT r;									// Stores the console's current dimensions
		GetWindowRect(console, &r);				// MoveWindow(window_handle, x, y, width, height, redraw_window);
		MoveWindow(console, 1300, 0600, 1100, 1400, true);
	*/											// ###############################################################


	cout << "\n\n >>>>>>>>>>>>>>>>>>>>>>>>>>>>   TODO Task List   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	cout << "             ......................................................         \n\n" << endl;

	int tskNum, index;
	int priLvl;
	string tskDefStr;
	vector<int> tskPriVec;						// Vector contains the task priority 1 - 10
	vector<string> tskDefVec;					// Vector contains the line descriptions of each task


	string fileName = 	getFileName();
	string listTitle;
	
	ofstream outputFile;						// Create file output stream object using the 'fstream::ofstream' class for writing to files
	ifstream inputFile;							// Create file input stream object using the 'fstream::ifstream class' for reading from files
												// First - populate vectors w/historical data, If file non existent prompt user to add data 
	inputFile.open(fileName);					// Open an input file object having a name contained in variable 'fileName' 
	if (inputFile) {							// Boolean test is file was opened successfully in previos statement
		while ( (inputFile >> priLvl ) &&       // Assuming boolean test statement will be 'true' as long as there is data in the file to read 
		( getline(inputFile, tskDefStr) ) )
		{										// Once the last item in the input file is read the test becomes false and fpriLvl drops from loop	
			tskPriVec.push_back(priLvl);		// Take next item priority number and add it to end of 'tskPriVec vector array'
			tskDefVec.push_back(tskDefStr);		// Take next item description string and add it to end of 'tskDefVec' vector array'
		}
		inputFile.close();						// End of data in file must have been reached - Close the file input stream object
	}											
	else {										// Either the file code not be found or there is no data in the file to be read
		cout << "\n Unable to open this file: \n" 
			 << " Recommend adding data item which creates a file with item \n" << endl;
	}											// Adding items to the file will automatically create a new file with the name defined in fileName
												// User has the option of addig items which will create a file 
	//if (!(cin >> listTitle)) {
	//	cout << " Enter the title assigned to this tem list? ->>> ";
	//	getline(cin, listTitle);
	//}

	displayCmds();                                  // Continue program fpriLvl by displaying commands to user

												// ***** Central Program Continuous Command Loop *****
	char command = 'v';                         // Initialize variable command to anything prior to the next while boolean test
	while (command != 'x') {                    // Get command from user - Check for 'Terminate Program' - 'x' command
		if (command != 's') {					// Skip requesting user for next command if there is a save command pending
			cout << endl;
			cout << "Command: ";                    // Repeat solicitation for action until terminate command is recognized
			cin >> command;
		}										// These vector contents and sizes may change each time through the loop
		int tskPriVecSz = tskPriVec.size();     // Compute vector sizes to be placed in the for-loops
		int tskDefVecSz = tskDefVec.size();     // Using initializing within for loops gave warning messages


		switch (command) {                      // Select and execute appropriate user command
		case 'v':
			cout << "   ... >>>  To Do Task List  <<< ... \n\n"                
				<< left << setw(5) << " Task"	// Column definition format
				<<left << setw(11) << "   Priority" << left << setw(19) << "   Task Description" << endl
				<< " ----   --------   -----------------" << endl;
			                           
			cout << fixed << setprecision(0);	// Not necessart with integers but kept here for edification (Sets decimal places )
			tskNum = 1;							// Continue thru loop til last vector elem is reached
			for (int i = 0; i < tskPriVecSz; ++i) {  
				priLvl = tskPriVec[i];			// Pull priority (integer) of each task from the task piority vector array		
				tskDefStr = tskDefVec[i];		// Pull definition (string) of each task from the task definition vector array	
				cout << "  " << right <<  setw(2) << tskNum << setw(8) << "       " 
					 << setw(2) << priLvl << setw(5) << "     " 
					 << left << setw(74) << tskDefStr << '\n';
				++tskNum;
			}
			break;                              // Return to 'while' loop beginning

												// TODO User input must be protected from type input error
		case 'a':			
			cout << "\n Enter a description of the task: " << endl;;
			cin.ignore();						// Important! For 'getline' to work it must come before 'cin'
			getline(cin, tskDefStr);			// Or before envoking it, use 'cin.ignore()' as was done here
			cout << " Assign a priority level of the task that entered. \n"
				<< " Enter 1 for the highest to 5 for the lowest priority. \n"
				<< " Enter the priority level of the task: ";
			cin >> priLvl;

			tskPriVec.push_back(priLvl);        // Adding priority level values (integer) to end of vector arrays        
			tskDefVec.push_back(tskDefStr);     // Adding task description text (string) to end of vector arrays            
			break;                              // Return to 'while' loop beginning

		case 'r':
			cout << "Enter a task to remove: ";
			cin >> tskNum; 

			index = tskNum - 1;					// Element index is one less than task number displayed
			if (index >= 0 && index < tskPriVecSz) {
				tskDefVec.erase(tskDefVec.begin() + index);
				tskPriVec.erase(tskPriVec.begin() + index);
			}

			cout << "Task number " << tskNum << " has been removed.\n";
			break;								// Return to 'while' loop beginning

		case 's':                               // If file does not exist, it will be created here
			outputFile.open(fileName);          // Open ofstream in preparation for writing data
			for (int i = 0; i < tskPriVecSz; ++i) {
				priLvl = tskPriVec[i];
				tskDefStr = tskDefVec[i];
				outputFile << priLvl << tskDefStr << '\n';
			}
			outputFile.close();
			cout << "Your changes have been saved.\n";
			command = 'v';						// Return to top of loop and enter User command prompt
			break;                              // Return to 'while' loop beginning

		case 'c':
			displayCmds();
			break;

		case 'x':
			char keyEntry;
			cout << " Have your remembered to save your work? \n"
				 << " If you did, hit the 'x' key once again \n"
				 << " Otherwise hit the 's' key to save --> ";
			cin >> keyEntry;
			if (keyEntry != 'x') {
				command = 's';
				continue;
			}
			else {
				cout << "\n     Good Bye! - Program has ended \n\n";
				break;

			default:                                    // Any char beside the chars not identified in the switch list 
			cout << "Invalid command has been entered - Try again.\n";
			break;
			}
		}
	}




	exitPrgm();					// Option function member to terminate program
	system("pause");			// Some compilers do not recognize this statement
	return 0; 					// Indicates successful termination
}								// End of main

// .............................................   Function Code Definition Implementation  .................................................
//    
void exitPrgm()
{
	cout << "\n\n                  >>>>>>>>>>  Program has Terminated  <<<<<<<<<< " << endl;
	cout << " \n\n\n " << endl;
	exit(0);					// Terminate running program from anywhere it is called:
}

string getFileName()
{								
	string listFileName = "todoList";			// Default file name for file holding historical list items
	cout << " Enter a file name that holds or will hold an item list " << endl;				
	cout << " Enter name here ->>>  Default (todo): ";
	getline(cin, listFileName);					// Acquire the file name for file I/O interfacing
	if ( listFileName == "todo" || listFileName == "" ) {
		listFileName = "todolist";
	}
	else {							
		vector<char> flNameVec;					// Instantiate an empty vector of type character
		int strLen = listFileName.length();		// Acquire user provide file name string length
		int strIndx = 0;
		int vecIndx = 0;

		while (strIndx < strLen) {
			if (listFileName[strIndx] == ' ') { // Removing the spaces ' ' from the user provided file name
				strIndx++;						// Advance to checking for spaces in the next element	
				continue;						// without transferring the character to the vector build
			}
			else {								// Build vector with characters from user provide file name minus spaces
				flNameVec.push_back(tolower(listFileName[strIndx]));
				strIndx++;						// Advance vector's element index in preparation for next insertion
			}
		}

		/*										// Used for troubleshooting during development
		cout << " Here is the contents of the character vector:" << endl;
			for (auto vecChr : flNameVec) {		// Statement char vecChr is not required using recommended 'auto'
				cout << vecChr;
			}
		cout << endl;
		*/
												// URL: https://www.techiedelight.com/convert-vector-chars-std-string/
												// Range constructor used - "Techie Delight" - Converting vector of char to string	
		
		string strFromVec(flNameVec.begin(), flNameVec.end());
		listFileName = strFromVec;

		/*										// Used for troubleshooting during development
		cout << "Here is the vector converted to a string: " << endl;
		cout << strFromVec << endl;
		*/		
	}
	listFileName = listFileName + ".txt";
	cout << " The file \"" << listFileName << "\" will be found in the project directory" << endl;
	return listFileName;
}

void displayCmds() {
	cout << "\n COMMANDS\n"
		 << " v - View list items\n"
		 << " a - Add item to list\n"
		 << " r - Remove item from list\n"
		 << " s - Save changes to list file\n"
		 << " c - Display command list\n"
		 << " x - Exit program\n";
}


/*

|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|
012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
		  |         |         |         |         |         |         |         |         |         |         |         |         |         |
00		  10        20        30        40        50        60        70        80        90		00		  10        20        30        40

*/