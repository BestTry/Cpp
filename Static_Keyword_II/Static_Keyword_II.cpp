// Static_Keyword_II.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Static_Keyword : This file contains the 'main' function. Program execution begins and ends there.
// Demonstrate use of the keyuword static
//
/*
Static Members:
Member variable that do not belong to any instance of a class. Know as static member variables and static member functions.
When a value is stored ain a static member variable, it is not stored in an instance of the class. In instance of the class does
not even have to exist in order for values to be stored in the classs static member variable. Likewise, static memeber funcitons do
not operate on instance variables. Instead, they can operate only on statidc member functions as belonging to the class instead of
to an instance of the class.

When a member variable is declared with the key word static, there will be only one copy of the member variable in memeory, regardless
of the number of instances of the class that might exist.  A single copy of a class's static member variable is shared by all instances
of the class.  Text copied from texbook "C++ From Control Structures Through Objects" - Tony Gaddis

Local variables that are declared statitc retains it value when the function that called it returns to the calling function the value
it had when the function last completed its execution;  All static local variable variables are initialize to zero by default

Likewise an identifier declared outsite any function or class has gloabal namespace scope.  Such an identifier is known to all functions
from the point at which it is declred until the end of the file. Global variables are creatged by placing variable declarations outside
any class or function definition.  Such variables retain their values throughout a program's execution.


In the C++ programming language, the keyword static modifies the lifetime, visibility (linkage), or
class association of a variable or function. Its exact meaning depends entirely on where it is declared
in your code.The behavior of static can be broken down into four main use cases:

1. Inside a Function (Static Local Variables)When used inside a function, static changes the variable's lifetime
from automatic (stack-allocated) to static (program-lifetime).Behavior: The variable is initialized only once.
It retains its value between multiple function calls.Scope: It remains local to the function and cannot be accessed outside of it

2. Inside a Class: Variables (Static Data Members)When applied to a variable inside a class definition,
it turns the variable into a class-level variable rather than an instance-level variable behavior:
Only one copy of the variable exists, and it is shared among all objects of that class.Access:
It can be accessed using the class name directly (e.g., ClassName::variable), even if no objects of the class have been created.

3. Inside a Class: Functions (Static Member Functions)When applied to a function inside a class, it decouples the function from
any specific object instance.Behavior: The function belongs to the class itself, meaning it does not receive an implicit this pointer.
Constraints: It can only access other static variables or static functions within that class. It cannot access regular (non-static)
class members.

4. At File / Namespace Scope (Internal Linkage)When static is used outside of any function or class (at global or namespace scope),
it limits the visibility of that variable or function.Behavior: It gives the symbol internal linkage. This means the variable or
function is strictly private to the specific source file (translation unit) in which it is defined.Purpose: It prevents naming conflicts,
ensuring other files in the same project cannot see or accidentally modify it. (Note: In modern C++, unnamed namespaces are generally
preferred for this purpose).

In C++, the static keyword is heavily overloaded and changes its meaning completely depending on where it is used
*/

#include <iostream>
#include <format>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::format;
using std::string;
   
                           //      >>>    Declarations and Definiions   <<<<<
int globalVar{ 0 };			// Global variable declared outside any class or function

void countCalls() {
   static int counter = 0; // Initialized static variable only once
   counter++;              // Each time function called static 'counter' var not reset!
   cout << " The functon 'countCalls' has been called " << counter << " times\n";
}

static int totalCars;             // Static variable declared outside any class or function

class Car {
public:   
   Car() {
      totalCars++;
   }

   int getCarAmt() {
      return totalCars;
   }
};

class Calculator {
public:
   static int add(int a, int b) { // Static member function
      return a + b;
   }
};

int main()
{
   cout << endl;
   cout << format(" Initial  global variable's 'globalVar' value is: {}\n", globalVar++);
   cout << format(" The next global variable's 'globalVar' value is: {}\n", globalVar++);
   cout << format(" The last global variable's 'globalVar' value is: {}\n", globalVar++);
   cout << endl;

   countCalls();           // Output: Called 1 times
   countCalls();           // Output: Called 2 times
   countCalls();           // Output: Called 3 times
   cout << endl;
                           
   Car car1;
   cout << format(" With the first  'Car' class instaintiation, there are {} cars\n", car1.getCarAmt());   
   Car car2;
   cout << format(" With the second 'Car' class instaintiation, there are {} cars\n", car1.getCarAmt());
   Car car3;
   cout << format(" With the third  'Car' class instaintiation, there are {} cars\n", car3.getCarAmt());
   cout << endl;

   int sum = Calculator::add(5, 10);
   
   cout << endl << endl;
   system("pause>0");
   return 0;
}

