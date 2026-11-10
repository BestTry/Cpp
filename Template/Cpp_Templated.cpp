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
   	cout << " \t\t  ***  Goodbye!  *** \n\n";
	cout << endl << endl << endl;
	system("pause>0");
	return 0;
}
+