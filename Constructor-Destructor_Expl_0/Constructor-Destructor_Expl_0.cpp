// Constructor-Destructor_Expl_0.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Code was pulled from fig 9.15 of Textbook "C++ for Programmers" by Detiel
// Code shows order in which constructors and Destructors are called for global, local and static objects.
//
// Constructors and normally called implicitly when objects are created (Instantiated) and when they are about to go 
// out of scope.  Generally, destructor calls are made in reverse order of corresponding constuctor calls. 
// Global and static objects alter the normal sequence 
// 
// 
// 
// 
// 
// 					               *** Preprocessor Directives ***
//                            // Directive #include causes another file to be included
#include <iostream>	         // Account for input-output stream library functions
#include <format>
#include <string>	            // Note the quotes around the 'Non-standard' class 
#include "CreateAndDestroy.h" // Include CreateAndDestroy class definition (Constructor / Destructor example
// 							
using std::format;	         // Option: Could have used general: 'using namespace std;'
using std::cin;               // Part of of the input-output stream library
using std::cout;	            // Function definitions use 'Scope Resolution" operator 
using std::endl;	            // Scope resolution operator < :: > is used to explicitly 
                              // specify the scope in which an identifier is defined.
                              // Identifiers: (variable, function, class, enum, etc.)
                              // It helps the compiler disambiguate names when the 
                              // same identifier exists in multiple scopes, and it can
                              // also be used to access members without creating an object.

void create(); 					// Prototype / Declaration within main() section

const CreateAndDestroy first{ 1, " (Global before main)" }; // Global object 'first' is instiated

int main() {
   cout << endl;
   cout << "\n Main function execution begins\n";
   const CreateAndDestroy second{ 2, " ( Local object in main instantiated)" };
   static const CreateAndDestroy third{ 3, " ( Local static object in main instantiated)" };

   create(); 					   // Call function to create objects

   std::cout << "\n The main function execution resumes\n";
                              // CreateAndDestroy declared with the header file
   const CreateAndDestroy fourth{ 4, " (local in main)" };
   std::cout << "\n The main function execution terminates \n";

   cout << endl << endl;
   system("pause>0");
   return 0;
   }

                               // Function definition to create objects
void create() {
   std::cout << "\n The create() function execution is triggered\n";
   const CreateAndDestroy fifth{ 5, " ( Local object is instantiated from cll by the create function)" };
   static const CreateAndDestroy sixth{ 6, " ( Local static object instantiation is called from the create function)" };
   const CreateAndDestroy seventh{ 7, " ( Local objected is instantiated from call by the create funtion)" };
   std::cout << "\n The create function execution terminates \n";
}
