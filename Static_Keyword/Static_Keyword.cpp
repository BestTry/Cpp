// Static_Keyword : This file contains the 'main' function. Program execution begins and ends there.
// Demonstrate use of the keyuword static
//
/*
In the C++ programming language, the keyword static modifies the lifetime, visibility (linkage), or 
class association of a variable or function. Its exact meaning depends entirely on where it is declared 
in your code.The behavior of static can be broken down into four main use cases:

1. Inside a Function (Static Local Variables)When used inside a function, static changes the variable's lifetime 
from automatic (stack-allocated) to static (program-lifetime).Behavior: The variable is initialized only once. 
It retains its value between multiple function calls.Scope: It remains local to the function and cannot be accessed outside of it

2. Inside a Class: Variables (Static Data Members)When applied to a variable inside a class definition, 
it turns the variable into a class-level variable rather than an instance-level variable.Behavior: 
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

void countCalls() {
    static int counter = 0; // Initialized only once
    counter++;
    std::cout << "Called " << counter << " times\n";
}

class Car {
public:
    static int totalCars; // Declared inside the class
    Car() { totalCars++; }
};

class Calculator {
public:
    static int add(int a, int b) { // Static member function
        return a + b;
    }
};


int main()
{
   countCalls(); // Output: Called 1 times
    countCalls(); // Output: Called 2 times
  
  int Car::totalCars = 0; // Definition and initialization outside the class


    Car car1;
    Car car2;
    std::cout << Car::totalCars; // Output: 2
	
	 int sum = Calculator::add(5, 10); 
	
	// Inside helper.cpp
static int localSecret = 42; // Other .cpp files cannot access this via 'extern'

static void localHelper() {
    // Only callable within helper.cpp
}
	
  
	
   cout << endl << endl;
   system("pause>0");
   return 0;
}


AI Overview
In C++, the static keyword is heavily overloaded and changes its meaning completely depending on where it is used. 

Reddit
 +1
The behavior of static can be divided into four distinct contexts:
1. Inside a Function (Static Local Variables)
When applied to a local variable inside a function, static extends the variable's lifetime to the entire duration of the program. 

GeeksforGeeks
 +1
Behavior: It is initialized only once (the first time the function is called). It retains its value between successive function calls.
Common Use: Counting how many times a function is called, or caching data (memoization). 

Reddit
 +2
cpp
#include <iostream>

void countCalls() {
    static int counter = 0; // Initialized once, persists in memory
    counter++;
    std::cout << "Called " << counter << " times\n";
}

int main() {
    countCalls(); // Output: Called 1 times
    countCalls(); // Output: Called 2 times
}
Use code with caution.
2. Inside a Class (Static Data Members)
When a variable inside a class is declared static, it becomes a class-level variable rather than an instance-level variable. 

W3Schools
 +1
Behavior: All objects of that class share the exact same variable. It does not increase the size of individual class objects. It must be defined outside of the class declaration (usually in a .cpp file).
Common Use: Keeping track of the total number of active objects, or sharing a global configuration among instances. 

YouTube
·enigma tutorials
 +2
cpp
class Player {
public:
    static int totalPlayers; // Declaration
    Player() { totalPlayers++; }
};

int Player::totalPlayers = 0; // Definition outside class

int main() {
    Player p1;
    Player p2;
    std::cout << Player::totalPlayers; // Output: 2 (Accessed via class name)
}
Use code with caution.
3. Inside a Class (Static Member Functions)
A static member function belongs to the class itself, not to any specific object. 

GeeksforGeeks
 +1
Behavior: It can be invoked directly using the class name (e.g., ClassName::FunctionName()) without instantiating an object. Because it is not tied to an instance, it does not have a this pointer and can only access other static variables or static functions.
Common Use: Helper functions, factory methods, or API patterns like Singletons. 

Wikipedia
 +3
cpp
class MathUtils {
public:
    static int square(int x) { return x * x; }
};

int main() {
    int result = MathUtils::square(5); // No object creation needed
}
Use code with caution.
4. At File / Namespace Scope (Global Static)
When used outside of any function or class (at the global level), static alters the linkage of the variable or function. 

YouTube
·The Cherno
 +1
Behavior: It gives the symbol internal linkage. This means the variable or function is strictly hidden and isolated within the single translation unit (the specific .cpp file) where it is defined. Other files cannot access it, even with an extern declaration. 

Medium
 +4
Common Use: Preventing name collisions across different source files. (Note: In modern C++, unnamed namespaces namespace { ... } are often preferred for this purpose). 

GeeksforGeeks
cpp
// Inside helper.cpp
static void internalLog() { 
    // This function cannot be seen or called from main.cpp
}