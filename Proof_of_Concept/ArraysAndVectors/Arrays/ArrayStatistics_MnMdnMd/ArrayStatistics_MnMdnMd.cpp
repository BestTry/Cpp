// ArrayStatistics_MnMdnMd.cpp : Lifted from Dietel "How to Program" 4th edition,  - Chapter 04 - Compute Mean, Median, Mode of array
//
// Description of Program ...................................................................
// Given the populated array, find the following: mean, median and mode values of this array
// ..........................................................................................
//
//   - Program Steps Enumerated - 
// 1 - The array named 'responses' is filled with 99 responses (1-9) to a survey
// 2 - Find the average or mean values of the contents of the array
// 3 - Find the middle value from all the responses contained in the array.  The array must first be sorted.
// 4 - Find the mode which is the response value that has occurred the most frequent.
// 
						// The Preprocessor Directives: (Header Files) 							
#include <iostream> 	// Standard Template Library class  -  Used for cout, cin, cerr, printf  ( That is the  reason for brackets < > )
#include <iomanip>		// Required to utilize parameterized stream manipulator ie. calling setprecision(3) & fixed functions
#include <fstream>		// Inherited from 'basic_fstream' for file I/O - Defines Data types: ofstream, ifstream, and fstream
#include <sstream>		// Used when interfacing strings by reading from and writing to files
#include <string>		// Use the s suffix for literal strings 'string' class - required as a new way of using strings, non char sequence
#include <windows.h>	// Required to implement adjusting the Consoles window size and position - CAUSES PROBLEMS with <limits>
#include <typeinfo>		// Necessary for imlementing the typeid() function 
#include <memory>		// Necessary when using smart pointers. Syntax: unique_ptr<int> ptrName( new int );
#include <array>		// Necessary when using the array class i.e array<arrType, size>
#include <vector>		// Support vector operations - See inputDate
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
#include <chrono>		// std::chrono::seconds(XX)
#include <cstdlib>		// Required to implement the rand() & srand() function.  Also, needed to execute the 'exit()' function.
#include <ctime>		// Required to implement the time(0) function providing a number to seed rand() using srand(): srand( time( 0 ) );
						// Arguement (0) yields an interger value of the calendar in seconds

						// The double colons operator '::' is defined as the "Scope Resolution Operator"
using std::cout;		// Console output
using std::cin;			// Console input
using std::endl;		// End of Line - Clears output buffer and terminates with a new-line character
using std::fixed;		// Both 'fixed' & 'showpoint' are nonparamatized stream manipulators that Do Not require the <iomanip> header file
using std::pow;			// Standard Library Function pow(x,y) definded as x raised to the y power
using std::setw;		// Assure #include <iomanip> is included which requires a parameterized stream manipulator
using std::setprecision;// setprecision(2)indicates a double variable value should be printed with 2 digits to the right of the decimal point

using namespace std;	// Common practice to implement the "std" namespace as it contains multiple supporting useful functions

// ..............................................   Function Prototype Declaration Code   ..............................................

												// Function prototypes - In C++ every funtion requires a prototype before main
void findMean(const int[], int);
void findMedian(int[], int);
void findMode(int[], int[], int);
void arrySort(int[], int);
void displayArray(const int[], int);

void exitPrgm();							// Use this function as a optional default to terminate the program


int main()									// Function main() begins program execution - Entry point for the program
{
	cout << "\n\n >>>>>>>>>>>>>>>>>>>>>>>>>>>>   Main Code Execution   <<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	cout << "                Use Array Data to find the Mean, Mode, and Median          \n\n" << endl;


	const int arraySize = 100;				// This is the size of the constant size array named 'responsesArray'
	int occurFreq[10] = { 0 }; 			// Array will hold the frequency of each occured value from the responsesArray - all elements set to initial value 0
	int tempArray[arraySize] = { 0 };		// Array variable to hold temporay array values while computing Mean,  Midean and Mode values
								// Input array with content values of survey 
	int responseArray[arraySize] = { 6,7,8,9,8,7,8,9,8,9,
									 7,8,9,5,9,8,7,8,7,8,
									 6,7,8,9,3,9,8,7,8,7,
									 7,8,9,8,9,8,9,7,8,9,
									 6,7,8,7,8,7,9,8,9,2,
									 7,8,9,8,9,8,9,7,5,3,
									 5,6,7,2,5,3,9,4,6,4,
									 7,8,9,6,8,7,8,9,7,8,
									 7,4,4,2,5,3,8,7,5,6,
									 4,5,6,1,6,5,7,8,7,6 };

	findMean(responseArray, arraySize);	
	findMedian(responseArray, arraySize);
	findMode(occurFreq, responseArray, arraySize);

	exitPrgm();									// Option function member to terminate program
	system("pause");							// Some compilers do not recognize this statement
	return 0; 									// Indicates successful termination
}												// End of main

// .............................................   Function Code Definition Implementation  .................................................

 												// Calculate the average of all values contained in the response array
void findMean(const int inputArray[], int arraySize)
{
	cout << " Porcessing the Mean Value of Integers in the Array " << endl;
	int avgValue = 0;							// Intialize average to zero
	int sumOfValues = 0;						// Initialize sum of value of all elements
	for (int i = 0; i < arraySize; i++)
	{
		sumOfValues += inputArray[i];
	}											// Division produces a integer?  .... then cast result to a dpuble

	double mean = static_cast<double> (sumOfValues)/ static_cast<double> (arraySize);
	cout << fixed << setprecision(4);			// Set to four decimal place accuracy
	cout << " The mean (average value of the array is: " << mean << endl;
}												// End of the findMean (average of array values) function

													
void findMedian(int  inputArray[], int arraySize)
{	
	cout << "\n Unsorted Array: " << endl;
	displayArray(inputArray, arraySize);		// Display unsorted array
	arrySort(inputArray, arraySize);
	cout << "\n Sorted Array: " << endl;
	displayArray(inputArray, arraySize);		// Display --sorted array
	cout << "\n Median Value: \n";
	int median = inputArray[arraySize / 2];		// Returns middle value of array element (arraySize / 2)
}
	

												// Find the mode value (most frequently occurred value) 
void findMode(int occurFreq[], int inputArray[], int arraySize)
{
	int numOccurred;
	occurFreq[arraySize] = { 0 };				// Set all element in the frequency array to zero value

	for (int i = 0; i < arraySize; i++)			// Accumulate occurances of all elements in the input array
	{
		numOccurred = inputArray[i];			// Summing up the number of times an interger occured in the array
		occurFreq[numOccurred]++;						
	}

	int frequency = 0;								// Display the the number of times each value occurred with values between 0 and 9
	int modeValue = 0;							// Maximum occurrances
	int maxOccurNum = 99;

	for (int i = 0; i < 10; i++)
	{		
		frequency = occurFreq[i];				// Retrieve the number of times each value between 0-9 occurred in the inputArray
		cout << " " << i << " occurred " << right 
			 << setw(2) << frequency << " times |";

		if (frequency > modeValue) {			// Keep track the largest occuring number and its frequency of occurrance
			modeValue = frequency;
			maxOccurNum = i;
		}

		while (frequency != 0)					// Print out bar graph reflecting number of times each value occurred in the inputArray
		{
			cout << "*";
			frequency--;
		}		
		cout << endl;							// Do a next line carriage return to show frequency of occurrence of next number
	}
	cout << "\n\n Mode Value: " << maxOccurNum << endl;
	cout << " Most frequent occurring value is " << maxOccurNum << " occurring " << modeValue << " times." <<endl;
}

void arrySort(int arrayInput[], int arraySize)
{
	int tempHold;								// Temporary location holding elemens values while swapping values of arrays locations
	bool swapped = false;
	do
	{
		swapped = false;
		// The value of 'i' will range from the index of '0' to the index of '(arraySize-1)'
		for (int i = 0; i < (arraySize-1); i++)
		{
			if (arrayInput[i] > arrayInput[i + 1])
			{									// Bubble sorting 
				tempHold = arrayInput[i];
				arrayInput[i] = arrayInput[i + 1];
				arrayInput[i + 1] = tempHold;
				swapped = true;					// Keep going through entire array til no longer a single swap occuring 
			}					// End of 'if' block
		}
	} while (swapped == true);
}

void displayArray(const int arrayInput[], int arraySize)
{
	cout << "{ "; 				
	for (int i = 0; i < arraySize; i++)
	{
		if ((i) % 20 == 0) { cout << endl; }		// Insert a Cr (a new line) every 20 values
		cout << setw(2) << " " << arrayInput[i];
	}											// End of 'for loop'	
	cout << " }" << endl << endl;							// Terminate array contents with bracket
}

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