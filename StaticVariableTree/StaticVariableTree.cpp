// Static class example - Pulled from "C++ From Control Structures to Objects"  - Tony Daddis
// 
// The following coded should be placed in a seperate header file titled: 'tree.h'
//

// Tree class
class Tree {
	
private:
	int static objectCount; // Static member variable
public:
		Tree(){				// Constructor without any initializing parameters
			objectCount++;
		}
		
		int getCount() {	// Accessor function for retrieving object count/
		return objectCount;	
		}
};

int Tree:: objectCount = 0; Definition of static variable defined outside of class

// ........................................................................................................


// ........................................................................................................
// Code demostrates the static member variable

#include <iostream>
#include <format>
#include "Tree.h"
using std::format;
using std::endl;
using std::cout;
using std::cin;

int main()
{
		Tree maple;
		Tree hicory;
		Tree oak;
		Tree elm;
		Tree pine;
							// Acquire the total number of tree objects created
		numOfTrees = pine.getCount();
		
	cout << format( "There has been {} 'Tree' objects insatiated", numOfTrees); 
	
	cout << endl << endl << endl;
    cout << "           >>>>> Hit the 'enter' key (2x) to exit <<<<<" << endl;
    system("pause>0");
    return 0;
}	
	
	
	
