// Detect_Data_Input_Errors.cpp : Code was copied from Marach's 'C++ Programming' by Mary Delamater - Code: Introduction to Streams and Buffers
					
						// The Preprocessor Directives: (Header Files) 							
#include <iostream> 	// Standard Template Library class  -  Used for cout, cin, cerr, printf  ( That is the  reason for brackets < > )
#include <fstream>		// Template Specialization inherited from 'basic_fstream' for file input / output prototype functions - Enables char I/O
#include <string>		// Use the s suffix for literal strings 'string' class - required as a new way of using strings, non char sequence
#include <limits>
						// The double colons operator '::' is defined as the "Scope Resolution Operator"
using std::cout;		// Console output
using std::cin;			// Console input
using std::endl;		// End of Line - Clears output buffer and terminates with a new-line character

using namespace std;	// Common practice to implement the "std" namespace as it contains multiple supporting useful functions


// ..............................................   Function Prototype Declaration Code   ..............................................

void exitPrgm();							// Use this function as a optional default to terminate the program


int main()									// Function main() begins program execution - Entry point for the program
{
												

	cout << "\n\n >>>>>>>>>>>>>>>>>>>>>>>>>>>>   Main Code Execution   <<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	cout << "                  Detecting Data Input Errors          " << endl;

	cout << " Following is three different methods of detecting input errors " << endl;
	cout << " The input class function 'cin' is expecting a double. \n" 
		 << " By entering alternate type should produce an error " 
		 << " Exit program by entering zero '0' at Check 3 " << endl;

	// In order to test each section I have to comment out the other two - Do not know why this is the case
	
	double dblNum;
	double newVar;
		cout << "\n Check 1: - Enter a number: ";	// Method One
		cin >> dblNum;
		/*if (cin) {    // #####????????? Do not know why ... Once this is tested it carries over to the other tests
			cout << " The number entered is: " << dblNum; cout << endl;
		}*/
		//else {
			cout << " That is not a valid number!" << endl;
			cout << " Enter double again: " << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> newVar;
			cin.clear();
			// cin >> dblNum;			// ## ???? ## Why is the code not pausing here to take the input from user ???????
			dblNum = 0.0;
			cin.clear();
			cout << " The number entered is: " << dblNum << endl;
			cout << " The number entered is: " << newVar << endl;
		// } 


		cout << "\n Check 2: - Enter a number: "; // Method Two
		if (cin >> dblNum) {
			cout << " The number entered is: " << dblNum << endl;
		}
		else {
			cout << " That is not a valid number!" << endl;
		}
		cin.clear();

		
	
		cout << "\n Check 3: - Enter a number: ";	// Method Three
		cin >> dblNum;
		if (cin.good()) {
			cout << " The number entered is: " << dblNum << endl;
		}
		else if (cin.fail()) {
			cout << " That is not a valid number! Try again \n" << endl;
 		}
		else if (cin.bad()) {
			cout << " An unrecoverable error has occurred.  bye! \n";
		}
		cin.clear();
	

	exitPrgm();					// Option function member to terminate program
	system("pause");			// Some compilers do not recognize this statement
	return 0; 					// Indicates successful termination
}								// End of main

// .............................................   Function Code Definition Implementation  .................................................

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