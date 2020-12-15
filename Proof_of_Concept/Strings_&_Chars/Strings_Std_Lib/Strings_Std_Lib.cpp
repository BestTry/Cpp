// Strings_Std_Lib.cpp - Code source: // Code Example lifted from C++ Tutorial by O'Reilly - C++ 11 Intermediate by Peter Thorsteinson 
// Video clip titled: "Standard Library Strings"
//
// Description of Program .............  Boiler Plate Template  .............................
// ..........................................................................................
// ..........................................................................................
// ..........................................................................................
//
/* See http://www.cplusplus.com/reference/string/string/ for more string library class functions, members, operators etc. */
					
						// Below is what is known as the Preprocessor Directives - in this Header section
						// Under Visual Studio 17  -  replace #include "stdafx.h" with #include "pch.h" to provide same library support						
						// The Preprocessor Directives: (Header Files) 							
#include <iostream> 	// Part of the standard library  -  Used for cout, cin, cerr  ( That is the  reason for brackets < > )
#include <string>		// Within Standard Library - 'string' class - required as a new way of using strings as opposed the old char sequence
#include <ctime>		// Required to implement date and time functions
#include <windows.h>	// Required to implement date and time functions - Some IDE / Complilers do not accept this header file
#include <typeinfo>		// Necessary for imlementing the typeid() function 
#include <memory>		// Necessary when using smart pointers. Syntax: unique_ptr<int> ptrName( new int );
#include <array>		// Necessary when using the array class i.e array<arrType, size>
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
#include <windows.h>	// #####

// ..............................................   Function Prototype Declaration Code   ..............................................


void exitPrgm();							// Use this function as a optional default to terminate the program

// Note: 'string' & 'wstring'- part of the String class were elements consist of chars - string holds 8 bit chars & wstring holds 16 bit chars
// Unicode character need 16 bit chars & so wstring would be used for unicode characters while string uses ASCII characters - 8 bit (bytes)
											
											// 'char*' type strings - Very primitive old-fashion way of dealing with text strings in memory
											// Pointer to existing chars in memory. Points to the address where the text char text string begins
void printCharStar(const char* ptrChar) {	// Assure last char in the string is null character '\0' (Does'nt know its length - prog needs find it) 
	cout << ptrChar << " at " << (int)ptrChar << endl;
}
											// String class consting of chars, A self contained object - Does'nt need null terminating character
											// The string object instantiated already has all the necessary attributes for termination, length etc.
	void printString(string strg) {			// Full copy of string to new allocated memory
	cout << strg << " at " << &strg << endl;
}

void printConstString(string const& strg) {	// Avoid copying via pass by const reference
	cout << strg << "at " << &strg << endl; 
}

int main()									// Function tmain(...) begins program execution - Entry point for the program
{

											// ##############################################################
											// Modify position and size of Console Application Window
	HWND console = GetConsoleWindow();		// Get the console handle
	RECT r;									// Stores the console's current dimensions
	GetWindowRect(console, &r);				// MoveWindow(window_handle, x, y, width, height, redraw_window);
	MoveWindow(console, 1400, 500, 1100, 1500, true);
											// ###############################################################	

	cout << "\n\n >>>>>>>>>>>>>>>>>>>>>>>>>>>>   Main Code Execution   <<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	cout << "	            ......  Standard Library Strings  ......							\n" << endl;
											// Following Code *** Calls the three functions declared and defined above exterior to 'main'
	auto ptrChar = "Hello World";			// const char* (no s suffix);  Keyword 'auto' implicently/automatically determines type of variable
	cout << typeid(ptrChar).name() << "\n";	// Above const* means the contents of the string can not be changed
	cout << ptrChar << " at " << (int)ptrChar << "\n";
	printCharStar(ptrChar);

	auto strg1 = "Hello World"s;			// 's' suffix indicates the string is literal std::string type
	cout << typeid(strg1).name() << "\n";
	cout << strg1 << " at " << &strg1 << "\n";
	printString(strg1);
	printConstString(strg1);
											// Escape characters placed middle of strings; std type strings do'nt interpret '\0' as end of string
	string strg2 = "abc\0def";				// Literal string - char style type string - sees the null it interpretes as end of string
	string strg3 = "abc\0def"s;				// Object type string because of 's' - Allow an embedded null in middle of string (Will not terminate)
	cout << "Size of strg2: " << strg2.size() << " \"" << strg2 << "\"\n";
	cout << "Size of strg3: " << strg3.size() << " \"" << strg3 << "\"\n";

	/* --------------------------------------------------------------------------------------------------------------------------------------- */
	cout << "	          ......  More Standard Library Strings  ......							\n" << endl;

											// Regular string literal (Escaped with '\') Seen here 'quote' and tab
	auto strg4 = "\"Hello\tWorld\""s;		// The 's' indicates that the string is a regular string literal
	cout << typeid(strg4).name() << "\n";	// In the regular string each '\' means special charcter follows
	cout << strg4 << "\n";
											// Raw string literal (Unescaped -> raw '\' ) 
	auto strg5 = R"("Hello\tWorld")";		// Can contain characters without any escapement happening
	cout << typeid(strg5).name() << "\n";	// The 'R' indicate that the string is a 'raw' string
	cout << strg5 << "\n";					// Here '\' are not escape character but are really backslash
											// Parenthesis require to distiquish content & delimiters of string

	{
		string strg6("Mellow");				// String strg6 contains the text 'Mellow'
		*strg6.begin() = 'Y';				// Returns pointer to 1stt elem in string 'M', then replaces it with 'Y'
		cout << strg6 << "\n";				// Prints out 'Yellow'

		for (string::iterator it = strg6.begin(); it != strg6.end(); ++it)
		{									// Above ++it increments the iterator in the sequence by 1
			(*it)++;						// Increase contents of each char in string by 1 (i.e. ('Y' + 1) -> 'Z'
		}									// That is increase the contents of what the iterator is pointing to
			cout << strg6 << '\n';	
			cout << " The next line should be blank as the string was cleared of its contents" << endl;
			strg6.clear();					// Clear contents
			cout << strg6 << '\n';			// Displays an empty string
	}

	{
		auto* ptrToConstChar = "Flexible";	// ptrToConst is pointer to constant char ???
		cout << "'ptrToConstChar' is a <" << typeid(ptrToConstChar).name() << 
			  "> pointer to a Char type string" << "\n";
		cout << ptrToConstChar << " <-- Contents of the char string" << '\n';
		cout << ptrToConstChar[3] << " <-- This char is ptrToConstChar[3]: element [3]" << '\n' << endl;

		auto strg7 = "miH esiarP"s;			// String strg7 is a literal std::string because of the 's'
		cout << strg7 << " <-- Contents of the std::string strg7 " << '\n';
		cout << strg7[3] << " <-- This char is strg7[3]: indexing element [3]" << '\n';
		reverse(strg7.begin(), strg7.end());// This reverse keyward is a funtion
		cout << strg7 << " <-- Contents of the std::string strg7 now reversed" << '\n';
		strg7.insert(7, "To "); cout << "Inserting 'To' " << endl;
		cout << strg7 << " <-- Contents of the std::string strg7 now with insertion" << '\n';
		strg7.append(" always!"); cout << "Appending 'always' " << endl;
		cout << strg7 << " <-- Contents of the std::string strg7 has been appended" << '\n' << endl;		
	}

	{
		string strg8("yin");
		string strg9("yang");
		cout << strg8 + strg9 << " Exhibiting concatenation \n";
		strg8.swap(strg9);
		cout << strg8 + strg9 << " Exhibiting swap \n";
	}


	//{								Code produces error - does not work
	//	char *ptrchar1 = "hello";
	//	char *ptrchar2 = "hello";	// literal char* strings share address
	//	if (ptrchar1 == ptrchar1) {
	//	cout << "(Yes) - The addresses of ptrchar1 and ptrchar2 are equal " << '\n'
	//	}
	//	else {
	//		cout << "The addresses of ptrchar1 and ptrchar2 are not equal " << '\n'
	//	}
	//}

	{
		int* ptrchar3 = new int[7]{ 'M', 'I', 'G', 'H', 'T', 'Y', 0 };
		int* ptrchar4 = new int[7]{ 'M', 'I', 'G', 'H', 'T', 'Y', 0 };
		if (ptrchar3 == ptrchar4) { // non-literal char* strings are distinct address
			cout << "The addresses of ptrchar3 & ptrchar3 are equal" << endl;
		}
		else {
			cout << "(Yes) - The addresses of ptrchar3 & ptrchar3 are NOT equal" << endl;
		}
	}


	{
		string strgA = "hello";
		string strgB = "hello";
		if (strgA == strgB) {		// std::string different from char* (compare contents)
			cout << "(Yes) - The contents of strgA and strgB are equal " << '\n'; }
		else { cout << "The contents of strgA and strgB are NOT equal "  << '\n'; }
	}


	{								// Conversions
		string strgC = "42";
		int intOne = stoi(strgC);	// String to Interger function
		cout << " stoi(\"" << strgC << "\" is " << intOne << '\n';

		string strgD = "3.141592653589793";
		int intTwo = stoi(strgD);	// String to Interger function
		cout << " stoi(\"" << strgD << "\" is " << intTwo << '\n';
		double dblOne = stod(strgD);// String to Double function
		cout << " stod(\"" << strgD << "\" is " << dblOne << '\n';
									// Below function tries it best -> 13 is displayed
		string strgE = "13 and some text";
		int intSix = stoi(strgE);	// String to Interger function
		cout << " stoi(\"" << strgE << "\" is " << intSix << '\n';

		string strgF = "some text and then a 2";
		// int intTen = stoi(strgF);  // runtime error: std::invalid argument
		// cout << " stoi(\"" << strgF << "\" is " << intTen << '\n';


	}

	// TODO:  To find TODOs ...  Go to >   View  >   Task List      TODO:TODO:TODO:TODO:TODO:TODO:TODO:TODO:TODO:TODO:TODO:TODO:

	exitPrgm();					// Option function member to terminate program
	system("pause");			// Some compilers do not recognize this statement
	return 0; 					// Indicates successful termination
}								// End of main



// .............................................   Function Code Definition Implementation  .................................................
//    When functional coded is declared above before the main coding section use this area for functional code implementation

void exitPrgm()
{
	cout << "\n                  >>>>>>>>>>  Program has Terminated  <<<<<<<<<< " << endl;
	cout << " \n\n\n " << endl;
	exit(0);					// Terminate running program from anywhere it is called:
}

/*

|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|
012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
		  |         |         |         |         |         |         |         |         |         |         |         |         |         |
00		  10        20        30        40        50        60        70        80        90		00		  10        20        30        40

*/

/* See http://www.cplusplus.com/reference/string/string/ for more string library class functions, members, operators etc. */