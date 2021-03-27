// Class_Time-Date_LocalSystem.cpp : Pulled the function to acquire the system current time and date from the internet; 
// Retrieved code that is similar to what is presented here from the textbook "How to Program" by Deitel version four
//
						// The Preprocessor Directives: (Header Files) 							
#include <iostream> 	// Used for cout, cin, cerr, printf  ( Brackets < > indicate function in Standard Librart) istream, ostream
#include <iomanip>		// Required to utilize parameterized stream manipulator ie. calling setprecision(3) & fixed functions
#include <windows.h>    // Needed for time delay function 'Sleep' and .... ?????
#include <ctime>		// Convert time_t value to stringL Interprets value pointed by timer as a calendar time and converts it to a 
						// C - string containing a human - readable version of the corresponding time and date, in terms of local time.
						// The double colons operator '::' is defined as the "Scope Resolution Operator"

using std::cout;		// Console output
using std::cin;			// Console input
using std::endl;		// End of Line - Clears output buffer and terminates with a new-line character
using std::setfill;		// Fills output with leading characters between the sign and value when a number is displayed: from <iomannip> 
using std::setw;		// Assure #include <iomanip> is included which requires a parameterized stream manipulator
using std::setprecision;// setprecision(2)indicates a double variable value should be printed with 2 digits to the right of the decimal point
using std::istream;		// These libraries must be a subset of the included iostream 
using std::ostream;		// Probably not necessary if 'using namespace std;' is stated

using namespace std;	// Common practice to implement the "std" namespace as it contains multiple supporting useful functions

// ............................................................................................................................................... //
#define _win32_winnt 0x0500	// Necessary for 'GetConsoleWindow()' function below to work! - on Windows 2000 and later	                           //																											   //
#include <windows.h>		// Provides position of Console Window on the desktop PC screen	                                                       //
// ................................................................................................................................................//


// ...............................................................................................................................................

class PC_DateTime 
{
public:  
	PC_DateTime()							// Constructor initializes each data member to zero and
	{										// Ensures all PC_DateTime objects start in a consistent state
		year = month = day = hour = min = sec = 0;
	}										// Initializing attributes in header is prohibited

											// Class Functions
	void GetCurrentDateTime();				// Acquire date and time of the local PC system 
	void DisplayDateTime();					// Display date and time of the local PC system 
	void PrintUniversal();
	void PrintStandard();
											// Following Attributes must be public get and display functions must have direct access
	int year;
	int month;
	int day;
	int hour;
	int min;
	int sec;
};											// End of class DateTime

void exitPrgm();							// Use this function as an optional default to terminate the program

// ...............................................................................................................................................

int main()									// Function main() begins program execution - Entry point for the program
{
	// ---------------------------------------------------------------------------------------------------------------------------------------------	
	HWND console = GetConsoleWindow();		// Modify position and size of Console Application Window
	RECT r;									// Get the console handle	
	GetWindowRect(console, &r);				// Stores the console's current dimensions
	MoveWindow(console,		 				// MoveWindow(window_handle, x, y, width, height, redraw_window);
	1910, 270, 470, 1600, true);
	// ----------------------------------------------------------------------------------------------------------------------------------------------

	
	cout << "\n <<<<<<<<<<<<<   PC System Local Time   >>>>>>>>>>>>>" << endl;	

	PC_DateTime timeObj;					// Instantiate an object of class PC_DateTime 
	
	for (int dsp = 0; dsp != 9; dsp++)
	{
		cout << " \n\n " << endl;
		PC_DateTime DT_Object;				// Instantiate a Date Time object	
		DT_Object.GetCurrentDateTime();		// Acquire date and time of object
		DT_Object.DisplayDateTime();		// Display date and time of object
		
		cout << " Universal Time: ";
		DT_Object.PrintUniversal();			// Display time in universal format
		cout << " - Standard Time: ";
		DT_Object.PrintStandard();			// Display time in standard format

		Sleep(7000);						// Sleep for designated milliseconds
	}
	
	cout << endl << endl;

	exitPrgm();								// Option function member to terminate program
	system("pause");						// Some compilers do not recognize this statement
	return 0; 								// Zero '0' indicates successful termination
}											// End of main



// .............................................   Code Functions Definitions Implementations  ................................................... //
//    When functional coded is declared above before the main coding section use this area for functional code definitions and implementation      //
// ............................................................................................................................................... //
//
/*	<ctime> Functions:  C++ time(): The time() function in C++ returns the current calendar time as an object of type time_t.
	The time() function in C++ returns the current calendar time as an object of type time_t. The time() function is defined in <ctime> header file. 
	The time() function takes a pointer to time_t object as its argument and returns the current calendar time as a value of type time_t.
*/


void PC_DateTime::GetCurrentDateTime()		// FUNCTION of class PC_DateTime
{
	time_t current_time;					// The parameter values are returned to the class object's attributes 
	struct tm local_time;

	time(&current_time);					// The time() function returns the current calendar time as value type of an object of type time_t.
	localtime_s(&local_time, &current_time);

											// Following parameters where defined in the pc_datetime class as a type integer 'int' 
	 year  = local_time.tm_year + 1900;		// and were made public to allow access outside of this function
	 month = local_time.tm_mon + 1;
	 day   = local_time.tm_mday;

	 hour  = local_time.tm_hour;
	 min   = local_time.tm_min;
	 sec   = local_time.tm_sec;
}											// End of function 


void PC_DateTime::DisplayDateTime()			// FUNCTION of class PC_DateTime
{
	cout << " >>>  Current PC System Date and Time Attribute   <<<" << endl;
	cout << " Date in years  : " << year  << " \t\t " << " Dime in hours  : " << hour << endl;
	cout << " Date in months : " << month << " \t\t " << " Dime in minutes: " << min  << endl;
	cout << " Date in days   : " << day   << " \t\t " << " Dime in seconds: " << sec  << endl;
}											// End of function 


void PC_DateTime::PrintUniversal()			// FUNCTION of class PC_DateTime: Print time in universal-time format
{
	cout << setfill('0') << setw(2) << hour << ":"
		 << setw(2) << min << ":"
		 << setw(2) << sec;
}											// End function PrintStandard



void PC_DateTime::PrintStandard()			// FUNCTION of class PC_DateTime: Print time in standard-time format
{
	cout << ((hour == 0 || hour == 12) ?	// Display 12 or modulus of <13 ... 23> 
		12 : hour % 12) << ":" << setfill('0')		
		<< setw(2) << min << ":"			// Obove statement strips '12' from the output
		<< setw(2) << sec
		<< (hour < 12 ? " AM" : " PM");
}											// End function printStandard


void exitPrgm()
{
	cout << "\n >>>>>>>>>>>>  Program Has Terminated   <<<<<<<<<<<<<" << endl;
	cout << " \n\n\n\n " << endl;
	exit(0);								// Terminate running program from anywhere it is called:
}

