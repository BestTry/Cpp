// DateApp.cpp : This file contains the 'main' function. Program execution begins and ends here.
// Used to test the Date class which is an example of constructed classes and how they work
// Original code was from a JAVA tutorial.video lecture/  Code was then rewritten in the C++ language
//
// main.cpp : Defines the entry point for a Console Application 'DateApp'. Console applications are the simplest using text for input / output
// 
// Description of Program 
// ..........................................................................................
// ..........................................................................................
// ..........................................................................................
//
// Additonal Code Description : Steps Enumerated 
// 1 - 
// 2 - 
// 3 - 
// 4 - 
// 5 - 
// 6 -
//
						// The Preprocessor Directives: 							
#include "pch.h"		// Part of the solution file that will be compiled: Standard AFX.H; This MUST BE 1st line of any code file
#include <iostream> 	// Part of the standard library  -  Used for cout, cin, cerr
#include <string>		// Part of the standard library  ( That is the  reason for brackets < > )
#include "Date.h"		// Contains the majority of class fields and accessor, getter and mutator methods
#include <ctime>		// Required to implement date and time functions
#include <windows.h>	// Required to implement date and time functions
#include <vector>		// Support vector operations - See inputDate
						// Before compiling symbol '#' indicates a preprocessing contents of  
						// the input/output stream header file iostream.  This file must be 
						// included with any keyboard input or console screen output
						// Functions within the standard library are as follows:
						// Since classes below are part of C++ stadard library < > are placed around them
#include <cmath>		// Enables the use of the "pow" function with the math library
#include <thread>		// std::this_thread::sleep_for(std::chrono::seconds(XX) << endl;
#include <chrono>		// std::chrono::seconds(XX)
#include <iomanip>		// Required to utilize parameterized stream manipulator ie. calling setprecision(3) & fixed functions
#include <cstdlib>		// Required to implement the rand() function; Contains function prototype for the rand()  & srand() function
#include <ctime>		// Required to implement the time(0) function providing a number to seed rand() using srand(): srand( time( 0 )  << endl;
						// Arguement (0) yields an interger value of the calendar in seconds

						// The double colons is defined as the "Scope Resolution Operator"
using std::cout;		// Console output
using std::cin;			// Console input
using std::endl;		// End of Line - Clears output buffer and terminates with a new-line character
using std::fixed;		// Both 'fixed' & 'showpoint' are nonparamatized stream manipulators that Do Not require the <iomanip> header file
using std::pow;			// Standard Library Function pow(x,y) definded as x raised to the y power
using std::setw;		// Assure #include <iomanip> is included which requires a parameterized stream manipulator
using std::setprecision;// setprecision(2)indicates a double variable value should be printed with 2 digits to the right of the decimal point

using namespace std;

						// ##### Necessary for the getconsolewindow() function to work! - works for  running this program on windows 2000 or higher
#define _win32_winnt 0x0500					
#include <windows.h>    

						// ##### Funcion Prototypes supporting 'main'
string dispUserFctn(int);
bool chkUserAffrmResps();
char toLowerChar(char);
void inputDate(vector<int> &);				
int deltaDaysInput();


int main()									// Function tmain(...) begins program execution - Entry point for the program
{											// ##############################################################
											// Modify position and size of Console Application Window
	HWND console = GetConsoleWindow();		// Get the console handle
	RECT r;									// Stores the console's current dimensions
	GetWindowRect(console, &r);				// MoveWindow(window_handle, x, y, width, height, redraw_window											
	MoveWindow(console, 1400, 500, 800, 700, TRUE);
											// ###############################################################	
//
//
//
	int fnc;								// User response to which app function to invoke

	cout << "\n\t  ***** This application provides the following 'Date' functionality *****" << endl;
	cout << "\t --------------------------------------------------------------------------" << endl;
	cout << "\t 1. Provides the number of days spanning between two given dates." << endl;
	cout << "\t 2. Provides an end date spanned by a number of days from a start date." << endl;
	cout << "\t 3. Provides the number of days spanned between a given date and today." << endl;
	cout << "\t 4. Provides the weekday name from a specific date entered." << endl;
	cout << "\t --------------------------------------------------------------------------" << endl;
	cout << "\n" << endl;
		
	do
	{
		cout << "\n\t What would like this application to do?" << endl;
		cout << "\n\t Enter (1) for calculating the number of days between two given dates" << endl;
		cout << "\n\t Enter (2) for finding a date spanned by days separated from a start date" << endl;
		cout << "\n\t Enter (3) for finding days spanned from today to a future or past date" << endl;
		cout << "\n\t Enter (4) for displaying the weekday name from a date entered." << endl;
		cout << "\n\t Enter (0) for this date application to exit." << endl;


		cout << "\n\n\t Enter your intended functionality here: >>> ";  cin >> fnc;
		cout << "\n\t Ok, ";  cout << dispUserFctn(fnc) <<  endl;	

											// Prepare vector date for executing case options: Vector of integers declared
											// Declare a vector for inputing amd holding date parameters from user
		vector<int> date(3);				// Vector 'date' with size of 3 element is used for tranferring data in / out of date objects
		int newYear, newMonth, newDay, destYear, destMonth, destDay, spannedDays;
			   		 	  	  	   
		switch (fnc)
		{
			case 1:
			{
				cout << "\t Enter the Starting Date by (year month day) " << endl;
				do
				{							// InputDate function takes a reference to the date vector 
					inputDate(date);		// Acquire input date parameters (year, month, day) with local function 
					cout << "\t Is this date correct: ";
					cout << date[0] << "/" << date[1] << "/" << date[2] << "? (Enter y/n) >>> ";
				} while (!chkUserAffrmResps());
											// Instantiate the start date using parameters gained from the referenced vector date
				newYear  = date[0];		newMonth = date[1];		 newDay = date[2];
				Date startDate = Date(newYear, newMonth, newDay);
				

				cout << "\n\t Good! Now enter an Ending Date by (year month day) " << endl;
				do
				{							// InputDate function takes a reference to the date vector 
					inputDate(date);		// Acquire input date parameters (year, month, day) with local function (transfering ref vector parameters)
					cout << "\t Is this date correct: ";
					cout << date[0] << "/" << date[1] << "/" << date[2] << "? (Enter y/n) >>> ";
				} while (!chkUserAffrmResps());
											// Instantiate the end date
				newYear = date[0];		newMonth = date[1];		 newDay = date[2];
				Date endDate = Date(newYear, newMonth, newDay);
				

				spannedDays = startDate.daysBetween(endDate);

											// Note here that the display functions do not return a string, rather
											// they locally display the string to the console within their function
				cout << "\n\t There are " << spannedDays << " days between ";
				cout << startDate.getWkDayName(); cout << " ";
				startDate.displayDate();  cout << " and ";
				cout << endDate.getWkDayName(); cout << " ";
				endDate.displayDate();    cout << "\n" << endl;

				break;
			}

			case 2:
			{
				cout << "\t Enter a Starting Date by (year month day) " << endl;
				do
				{							// InputDate function takes a reference to the date vector 
					inputDate(date);		// Acquire input date parameters (year, month, day) with local function (transfering ref vector parameters)
					cout << "\t Is this date correct: ";
					cout << date[0] << "/" << date[1] << "/" << date[2] << "? (Enter y/n) >>> ";
				} while (!chkUserAffrmResps());
											// Instantiate the start date using parameters gained from the referenced vector date
				newYear = date[0];		newMonth = date[1];		 newDay = date[2];
				Date startDate = Date(newYear, newMonth, newDay);
				

				cout << "\n\t Good! Now enter the number of days spanned from your start date " << endl;
				cout << "\t Enter a negative number of days to find a past date" << endl;
				
				int spannedDays = deltaDaysInput();
				Date foundDate = startDate.spanDaysToDate(spannedDays);

				int yearInt = foundDate.getYear();
				int monthInt = foundDate.getMonth();
				int dayOfMonthInt = foundDate.getDay();
				
				string monthName = foundDate.getMonthName();
				string wkDayName = foundDate.getWkDayName();
				string suffix = foundDate.getDaySuffix();
				
			

				cout << "\n\t The date found is: \n\t ";
				cout << wkDayName << " the " << dayOfMonthInt << suffix << " of " << monthName << " in the year " << yearInt;
				cout << "   >>> ";	foundDate.displayDate(); cout << " <<<  ( YYYY/MM/DD )       \n\n" << endl;

				break;
			}

			case 3:
			{
				SYSTEMTIME X;				// Pulled this code from on-line search
				GetSystemTime(&X);

				int prsntDay   = X.wDay;
				int prsntMonth = X.wMonth;
				int prsntYear  = X.wYear;

				cout << "\t Find the number of days spanned before reaching a target date entered here " << endl;
				do
				{							// InputDate function takes a reference to the date vector 
					inputDate(date);		// Acquire input date parameters (year, month, day) with local function (transfering ref vector parameters)
					cout << "\t Is this destination / target date correct: ";
					cout << date[0] << "/" << date[1] << "/" << date[2] << "? (Enter y/n) >>> ";
				} while (!chkUserAffrmResps());

											// Instantiate the ENDING DESTINATION / TARGET date using parameters gained from the referenced vector date
				destYear = date[0];		destMonth = date[1];	 destDay = date[2];
				Date destDate = Date(destYear, destMonth, destDay);
				
											// Instantiate the present today's date 
				Date todaysDate = Date(prsntYear, prsntMonth, prsntDay);				

				spannedDays = todaysDate.daysBetween(destDate);

											// Note here that the display functions do not return a string, rather
											// they locally display the string to the console within their function
				cout << "\n\t There are " << spannedDays << " days between ";
				cout << todaysDate.getWkDayName(); cout << " ";
				todaysDate.displayDate();  cout << " and ";
				cout << destDate.getWkDayName(); cout << " ";
				destDate.displayDate();    cout << "\n" << endl;

				break;				
			}

			case 4:
			{
				cout << "\t Enter a Date by (year month day) to find its weekday name" << endl;
				do
				{							// InputDate function takes a reference to the date vector 
					inputDate(date);		// Acquire input date parameters (year, month, day) with local function (transfering ref vector parameters)
					cout << "\t Is this date correct: ";
					cout << date[0] << "/" << date[1] << "/" << date[2] << "? (Enter y/n) >>> ";
				} while (!chkUserAffrmResps());
											// Instantiate the start date using parameters gained from the referenced vector date
				newYear = date[0];		newMonth = date[1];		 newDay = date[2];
				Date targetDate = Date(newYear, newMonth, newDay);
				
				
				string weekDayName = targetDate.getWkDayName();
				cout << "\n\t The " << newDay << targetDate.getDaySuffix() << " of " << targetDate.getMonthName() << ", " << 
					        newYear << " falls on a " << weekDayName << "\n\n" << endl;

				break;							   
			}

					   			 		  		  		 	   		
			default: 
			{
				if (fnc !=0)
				cout << "\t\t Error - Allowable choices were not reconized\n" << endl;
			}

		}
		
			   		 	  	  	   	
			   		 
	} while (fnc != 0);

	
	cout << "\n\t\t Thank You  .... Have a good day!\n \t\t   Application has Terminated\n\n" << endl;	
	cout << "\n\n\n" << endl;

	system("pause");
	return 0; 											// Indicates successful termination
}														// End of main
//
//
//
// #####		#####		  #####	   	    #####		// Function Source Definitions / Implementations

string dispUserFctn(int function) 						// Function elected from typing in 0,1,2,3 
{														// Provides a string for displaying description of user request  
	switch (function)
	{
	case 1:
		return "Lets find the number of days between two given dates.";

	case 2:
		return "Lets find a date spanned by a number of days from a start date.";

	case 3:
		return "Lets find the number of days spanned to reach the date you enter.";

	case 4:
		return "Lets find the weekday name for any given date you enter.";

	case 0:
		return "This 'Date' apllication is now terminated.";

														// case 0x001B:
														// ("\n\t\t Escape!");   
														// break;
	default:
		return "\n\t\t Error - This is not a legal option - Enter a legal option.";
	}
}

														// Check user response for a affirmative indication
bool chkUserAffrmResps()								// Checks if first character of user response from keyboard is a 'y'
{
	string response;
	cin >> response;									// // Read entire line of text until first space into string variable response	
	char firstChar = response[0];						// Extract first character of string which is an equivalent char array							
	firstChar = toLowerChar(firstChar);					// Assure first character is of the lower case sequence of characters
	return (firstChar == 'y');							// Return with a resonse of boolean affirmative true if first chaaracter is a 'y' 
}


char toLowerChar(char c)								// Returns lower case character if character is of upper case sequence
{
	if (c >= 'A' && c <= 'Z')
		return c + 32;

	return c;
}


void inputDate(vector<int>& dateRef)					// Input date parameters from user using a vector reference  
{														
	int newYear, newMonth, newDay;					
														
	cout << "\t Enter the date (year month day) using the following format: YYYY MM DD \n" <<
		    "\t Separate the year, month, and day by a space: >>> ";
	cin >> newYear >> newMonth >> newDay;				// Receive a new date from user keying in YYYY MM DD parameters

	
	dateRef[0] = newYear;								// Correct method to replace vector contents unlike 'bug' method below
	dateRef[1] = newMonth;
	dateRef[2] = newDay;

	return;												// Returning the populated vector with date values
 }


int deltaDaysInput()
{
	int daysFromPresent;
	cout << "\t Enter the number of days spanned from the start date: >>> ";
	cin >> daysFromPresent;

	return daysFromPresent;								// Returns num of days to be spanned from date object
}