// ArrayBinarySearch.cpp : Code Example lifted from Dietel "How to Program" 4th edition, Exercise / or  / Textbook Example - Chapter 04 - Binary Search Example
//
// Description of Program ...................................................................................................................................
/* Focused on learning about and exercising a code example surrounding binary search algorithm: The algorithm is very efficient with high performance gains -
   but it requires an array that has previously been sorted. It works well for large previously sorted arrays. The binary search algorithm eliminates one-half
   of the elements in the array being searched after each comparison. The algorithm locates the middle element of the array and compares it against the search
   key. If they are equal, the key is found and the subscript of the array element is returned.  Otherwise, the problem is reduced to searching one half of the
   array.  If the search key is less than the middle element value, the first half of the array is searched.  If it is greater the second half of the array is
   searched. If the key is not in the middle of the subarray searched, (piece of the original array) the search is repeated with the same criteria in now a new
   subarray (a quarter of the original array). The search continues in like manner until the key is found in the middle of the ever-smaller divided subarrays.
   Or once the last subarray only consist of one element and that element does not hold the key value, the key was not found and does not exist in the array.
   The maximum number of comparison (subarray searches) is finding the first power of 2 greater than the number of elements in the array.
*/
// The Preprocessor Directives: (Header Files) 							
#include <iostream> 	// Standard Template Library class  -  Used for cout, cin, cerr, printf  ( That is the  reason for brackets < > )
#include <iomanip>		// Required to utilize parameterized stream manipulator ie. calling setprecision(3) & fixed functions
#include <fstream>		// Inherited from 'basic_fstream' for file I/O - Defines Data types: ofstream, ifstream, and fstream
#include <sstream>		// Used when interfacing strings by reading from and writing to files
#include <string>		// Use the s suffix for literal strings 'string' class - required as a new way of using strings, non char sequence
#include <typeinfo>		// Necessary for imlementing the typeid() function 
#include <memory>		// Necessary when using smart pointers. Syntax: unique_ptr<int> ptrName( new int );
#include <array>		// Necessary when using the array class i.e array<arrType, size>
#include <algorithm>	// Copy algorithm - Needed to utilize Standard Template Library functions
						// Before compiling symbol '#' indicates a preprocessing contents of  
						// the input/output stream header file iostream.  This file must be 
						// included with any keyboard input or console screen output
						// Functions within the standard library are as follows:
						// Since classes below are part of C++ stadard library < > are placed around them
#include <cmath>		// Enables the use of the "pow" function with the math library and other mathematical functions
#include <functional>	// References the standard function library - std::function
#include <limits>		// Contains clasees for defining numerical data type limits on each computer platform
#include <thread>		// std::this_thread::sleep_for(std::chrono::seconds(XX) << endl;

						// The double colons operator '::' is defined as the "Scope Resolution Operator"
using std::cout;		// Console output
using std::cin;			// Console input
using std::endl;		// End of Line - Clears output buffer and terminates with a new-line character
using std::fixed;		// Both 'fixed' & 'showpoint' are nonparamatized stream manipulators that Do Not require the <iomanip> header file
using std::pow;			// Standard Library Function pow(x,y) definded as x raised to the y power
using std::setw;		// Assure #include <iomanip> is included which requires a parameterized stream manipulator
using std::setprecision;// setprecision(2)indicates a double variable value should be printed with 2 digits to the right of the decimal point


using namespace std;	// Common practice to implement the "std" namespace as it contains multiple supporting useful functions

// .........................................   Function Prototype Declaration Header References   ............................................
// Global variables, Function protoypes, Classes are placed/declared here before 'main' .... Optionally, function implementation may reside here 

void printHeader(int);									// Array size as argument
void printArrayRow(const int[], int, int, int, int); 	// (Target Array, Low Index, Middle Index, High Index, Array size)
int  binarySearch (const int[], int, int, int, int);	// (Target Array, Search Key, Low Index, High Index, Array size)
// void populateArray(const int );						// Create data by populating array

void exitPrgm();										// Use this function as a optional default to terminate the program


int main()												// Function main() begins program execution - Entry point for the program
{
	cout << "\n\n >>>>>>>>>>>>>>>>>>>>>>>>>>>   Main Code Execution   <<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	cout << "            Resident / Location -  void main() block code is placed here         \n\n" << endl;

	const int arraySize = 17;							// Size of an array used during creation Must be a constant and a ODD number!
	int srchArray[arraySize];							// Declare and create data for searching in an array
	int srchKey;
	int lowInx = 0;
	int hiInx = arraySize - 1;

	for (int i = 0; i < arraySize; i++) {				// Populate the array with even integers of size (arraySize/2)*2
		srchArray[i] = 2 * i;							// Integers: 0 -> (2 * arraySize - 1)
	}

	cout << " Please enter a even number between 0 and " << ((arraySize/2)*4) << ": ";
	cin >> srchKey;

	int arryElem;										// Element of array srchKey was found
	printHeader(arraySize);								// Prepare array data with a header for graphic display
	arryElem = binarySearch(srchArray, srchKey, lowInx, hiInx, arraySize);

	// Display the search results
	if (arryElem != -1)
	{
		cout << "\n The searched key " << srchKey << " was found in the array element " << arryElem;
	}
	else
	{
		cout << "\n The searched key " << srchKey << " was not found in the array";
	}

	

	exitPrgm();					// Option function member to terminate program
	system("pause");			// Some compilers do not recognize this statement
	return 0; 					// Indicates successful termination
}								// End of main

// .............................................   Function Code Definition Implementation  .................................................
//    When functional coded is declared above before the main coding section use this area for functional code implementation

int binarySearch(const int subArray[], int searchKey, int lowIndex, int hiIndex, int arraySize)
{
	int midIndex;
	while (lowIndex <= hiIndex)						// Boolean expression fails when array has reached a single element 
	{												// and the search key was not found
		int midIndex = (lowIndex + hiIndex) / 2;	// Determine the middle index of subArray being searched
													// Display subArray used in this loop iteration
		printArrayRow(subArray, lowIndex, midIndex, hiIndex, arraySize);
		if (subArray[midIndex] == searchKey)
		{
			return midIndex;						// Search key was found!  - Return array index
		}
		else
		{
			if (searchKey < subArray[midIndex])
			{
				hiIndex = midIndex - 1;				// Change search into lower half of present subArray
			}
			else
			{
				lowIndex = midIndex + 1;			// Change search into higher half of present subArray
			}
		}

	}
	return -1;										// Search Key was never found and lowIndex > hiIndex at this point												
}													// End of binarySearch Function

void printHeader(int const arraySize)
{
	int arrSize4 = arraySize * 4;
	cout << "\n  Array Index / Subscript:" << endl;
	for (int p = 0; p < arraySize; p++)
	{
		cout << setw(3) << p << ' ';			// Prints indexes / subscripts across row
	}
	cout << endl;								// Start a new line	

	for (int p = 0; p <= arrSize4; p++)
	{
		cout << "-";
	}
	cout << endl;								// Start a new line for displaying the rows
}												// End of function printHeader

void printArrayRow(const int dispArrayRow[], int lowIndex, int midIndex, int hiIndex, int arraySize)
{												// Code places spaces before and after the midpoint '*'
	for (int m = 0; m < arraySize; m++)
	{
		if (m < lowIndex || m > hiIndex)
		{
			cout << "    ";
		}
		else
		{
			if (m == midIndex)
			{
				cout << setw(3) << dispArrayRow[m] << '*';
			}
			else
			{
				cout << setw(3) << dispArrayRow[m] << ' ';
			}
		}
	}
	cout << endl;								// Start a new  line of output
}												// End of printArrayFunction




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