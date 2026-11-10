// Pointers and References
// 					// Any identifier outside main, functionm class is considered
//					// or has "globabal namespace scope" Such an identifier is "known"
//					// to all functions to the end of the file.  As are the identifiers 
//					// here below.				
//					//
// 					//      *** Preprocessor Directives ***
//                  // Directive #include causes another file to be included
#include <iostream>	// Account for input-output stream library functions
#include <format>
#include <string>	// Note the quotes around the 'Non-standard' class       
					// 							
//using std::format;	// Option: Could have used general: 'using namespace std;'
using std::cin;     // Part of of the input-output stream library
using std::cout;	// Function definitions use 'Scope Resolution" operator 
using std::endl;	// Scope resolution operator < :: > is used to explicitly 
					// specify the scope in which an identifier is defined.
					// Identifiers: (variable, function, class, enum, etc.)
					// It helps the compiler disambiguate names when the 
					// same identifier exists in multiple scopes, and it can
					// also be used to access members without creating an object.
/* References and Referernce Parameters
A reference parameter is an alias for its corresponding argument in a function call.
*/			


					//  Functions Declared
int squareByValue(int var);		// Function call passed by value
void squareByRef(int& var);		// Function call passed by reference

int main()
{
	cout << " Reference Concepts :" << endl;
	int x{2}; 		// Assigned values to integer variables
	int z{4};
	cout << " Variable passed by value is not modified as shown below\n";
	cout << " Value of x before function call: " << x << endl;
	cout << " Value returned by function call: " << squareByValue(x) << endl;
	cout << " Value of x after function call: " << x << endl << endl;
	
	cout << " Variable passed by reference is modified as shown below\n";
	cout << " Value of z before function call: " << z << endl;
	squareByRef(z);
	cout << " No value is returned by function call with reference argument" << endl;
	cout << " Value of z after function call by reference was modified: " << z << endl << endl;
	
	
   	cout << " \n\t\t  ***  Goodbye!  *** \n\n";
	cout << endl << endl << endl;
	//system("pause>0");
	return 0;
}

// Functions Defined

	int squareByValue(int valX) {	// Function call passed by value
		return valX = valX * valX;	// Caller argument is not modified
}

void squareByRef(int& refZ) {		// Function call passed by reference
	refZ = refZ * refZ;				// Caller argument is modified
}
// The 'squareByRef()' function squares the reference value 
// and stores the squared value back in itself modifying the original value

