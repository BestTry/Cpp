// Demonstration of using the various espcape sequences
//
// 					//      *** Preprocessor Directives ***
//                  // Directive #include causes another file to be included
#include <iostream>	// Account for input-output stream library functions
#include <format>
#include <string>	// Note the quotes around the 'Non-standard' class       
					// 							
using std::format;	// Option: Could have used general: 'using namespace std;'
using std::cin;     // Part of of the input-output stream library
using std::cout;	// Function definitions use 'Scope Resolution" operator 
using std::endl;	// Scope resolution operator < :: > is used to explicitly 
					// specify the scope in which an identifier is defined.
					// Identifiers: (variable, function, class, enum, etc.)
					// It helps the compiler disambiguate names when the 
					// same identifier exists in multiple scopes, and it can
					// also be used to access members without creating an object.
			

int main()
{
	int num = 0;		// Integer type variable declared and defined
	cout << "\a\a\a";	// Alarm - Causes computer to beep
	cout << "\n\n";		// Cursor to new/next line
						// Request user to enter a number - Demo "\t" & "\b" (tab & backup)
	cout << "\t Enter an number here: =>    ...\b\b\b";
	cin >> num;	
	cout << format("\t You entered the number: => {}\n", num) << endl;
	cout << "\t You entered the number: => " << num << endl;
	cout << "\t Curser left at the end of this line":
	cout << "\r\t Curser re-poitioned at the beginning of the line\r":
	cout <<  "\t More escape examples:\t \\ and \' " << endl;
	
	cout << " \t\t  ***  Goodbye!  *** \n\n";
	cout << endl << endl << endl;
	system("pause>0");
	return 0;
}

