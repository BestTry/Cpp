// OperatorOverloadingStreams.cpp : Pulled this code example from Deitel and Deitel - "How to Program' Chapter 8
// Fig. 8.3: fig08_03.cpp
// Overloading the stream-insertion and stream-extraction operators.
//
// Description of Program .............  Boiler Plate Template  .............................
// ..........................................................................................
// ..........................................................................................

						// The Preprocessor Directives: (Header Files) 							
#include <iostream> 	// Standard Template Library class  -  Used for cout, cin, cerr, printf  ( That is the  reason for brackets < > )
#include <iomanip>		// Required to utilize parameterized stream manipulator ie. calling setprecision(3) & fixed functions
#include <fstream>		// Inherited from 'basic_fstream' for file I/O - Defines Data types: ofstream, ifstream, and fstream

						// The double colons operator '::' is defined as the "Scope Resolution Operator"
using std::cout;		// Console output
using std::cin;			// Console input
using std::endl;		// End of Line - Clears output buffer and terminates with a new-line character
using std::fixed;		// Both 'fixed' & 'showpoint' are nonparamatized stream manipulators that Do Not require the <iomanip> header file
using std::setw;		// Assure #include <iomanip> is included which requires a parameterized stream manipulator

using std::istream;		// These libraries must be a subset on the included iostream ?
using std::ostream;

using namespace std;	// Common practice to implement the "std" namespace as it contains multiple supporting useful functions


// ........................   PhoneNumber class declaration - Demonstration stream-extraction and stream-insertion  ...........................
																// Code assumes phone numbers will be entered correctly format: (800) 555-1234
																// Class PhoneNumber appears as right opreand of operator and therefore these 
																// operators must be non-members and therefore must be declared friends
class PhoneNumber {												 
	friend ostream& operator<<(ostream&, const PhoneNumber&);	// Returns ostream reference 
	friend istream& operator>>(istream&, PhoneNumber&);			// Returns istream reference from reference input and reference num arguments
																// Operator function 'operator>>' inputs phone numberss
																// When compiler see statement: [ cin >> phone ] it generates 
private:			   // char arrays for ea part of num		// non - member function call operator >> (cin, phone ); >	
	char areaCode[4];  // 3-digit area code and null			// When this call executes, ref parameter 'input' becomes an alias for 'cin'
	char exchange[4];  // 3-digit exchange and null				// And refernce parameter num becomes an alias for phone
	char line[5];      // 4-digit line and null

};																// End class PhoneNumber
// ............................................................................................................................................

// ........................   PhoneNumber class definition - Demonstration stream-extraction and stream-insertion  ............................
//                        These two overloaded functions are defined OUTSIDE their class and are friends of the class 
//
																// overloaded stream-insertion operator; cannot be 
																// a member function if it is to be invoked it with
																// cout << somePhoneNumber;
ostream& operator<<(ostream& output, const PhoneNumber& num)	// Stream insertion 'operator<<' takes an ostream reference (output) and a  
{																// constant PhoneNumber ref (num) as arguments and returns an ostream reference
	output << "(" << num.areaCode << ") "						// Function 'operator<<' displays objects of type PhoneNumber.  - When the compiler
		   << num.exchange << "-" << num.line;					// see the expression  cout << phone  the compiler generates the non-member function
																// call operator << ( cout, phone );
	return output;												// Enables cascading  -  cout << a << b << c;

}																// End function operator<< 

																// overloaded stream-extraction operator; cannot be 
																// a member function if it is to be invoked it with
																// cin >> somePhoneNumber;
istream& operator>>(istream& input, PhoneNumber& num)			// When this call executes, ref parameter 'input' becomes an alias for 'cin'
{																// And refernce parameter num becomes an alias for phone
	input.ignore();						// skip '('				// The operator function reads as strings three parts of the phone number
	input >> setw(4) >> num.areaCode;	// input area code		// The setw() function limits the number of chars read into each char array
	input.ignore(2);					// skip ')' and space	
										// Allows 3 chars & reserves one char position for terminating 'null' char
	input >> setw(4) >> num.exchange;	// input exchange
	input.ignore();						// skip dash (-)
	input >> setw(5) >> num.line;		// input line

	return input;						// enables cin >> a >> b >> c;

}										// end function operator>> 
// ..........................   End of PhoneNumber class definition / implementation .........................................................
//
void exitPrgm();						// Use this function as a optional default to terminate the program


int main()								// Function main() begins program execution - Entry point for the program
{
	cout << "\n\n >>>>>>>>>>>>>>>>>>>>>>>>>>>   Main Code Execution   <<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	cout << "         Overloading Stream-Insertion and Stream-Extraction         \n\n" << endl;


	PhoneNumber phone;					// create object 'phone'

	cout << "Enter phone number in the form (123) 456-7890:\n";
	cin >> phone;						// cin >> phone invokes operator>> by implicitly issuing
										// the non-member function call operator>>( cin, phone )	
	cout << "The phone number entered was: ";
										// cout << phone invokes operator<< by implicitly issuing 
	cout << phone << endl;				// the non-member function call operator<<( cout, phone )

	exitPrgm();							// Option function member to terminate program
	system("pause");					// Some compilers do not recognize this statement
	return 0; 							// Indicates successful termination
}										// End of main

// .............................................   Function Code Definition Implementation  ...............................................//    When functional coded is declared above before the main coding section use this area for functional code implementation

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
