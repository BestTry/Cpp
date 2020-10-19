// ArrayManipulation.cpp : // Code Example lifted from Dietel "How to Program" 4th edition, Exercise / or  / Textbook Example - Chapter 04 - Student Grades Array Manipulation 
//
// Description of Program ...................................................................
// Operations are done on a student data array to find minimum, maximum, average, values
// """"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
// ..........................................................................................
//
						// The Preprocessor Directives: (Header Files) 							
#include <iostream> 	// Standard Template Library class  -  Used for cout, cin, cerr, printf  ( That is the  reason for brackets < > )
#include <iomanip>		// Required to utilize parameterized stream manipulator ie. calling setprecision(3) & fixed functions
#include <fstream>		// Inherited from 'basic_fstream' for file I/O - Defines Data types: ofstream, ifstream, and fstream
#include <sstream>		// Used when interfacing strings by reading from and writing to files
#include <string>		// Use the s suffix for literal strings 'string' class - required as a new way of using strings, non char sequence
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
						// The double colons operator '::' is defined as the "Scope Resolution Operator"
using std::cout;		// Console output
using std::cin;			// Console input
using std::endl;		// End of Line - Clears output buffer and terminates with a new-line character
using std::fixed;		// Both 'fixed' & 'showpoint' are nonparamatized stream manipulators that Do Not require the <iomanip> header file
using std::left;
using std::setw;		// Assure #include <iomanip> is included which requires a parameterized stream manipulator
using std::setprecision;// setprecision(2)indicates a double variable value should be printed with 2 digits to the right of the decimal point


using namespace std;	// Common practice to implement the "std" namespace as it contains multiple supporting useful functions


// ..............................................   Function Prototype Declaration Code   ..............................................
void exitPrgm();							// Use this function as a optional default to terminate the program


const int students = 5;
const int exams = 10;

void prtArry(int [][exams], int, int);
int minGrade(int [][exams], int, int);
int maxGrade(int [][exams], int, int);
double averageGrade(int [], int);


int main()									// Function main() begins program execution - Entry point for the program
{
					
	cout << "\n\n >>>>>>>>>>>>>>>>>>>>>>>>>>>>   Main Code Execution   <<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	cout << "            Array Manipulation Using Student Grades Held Within An Array        \n\n" << endl;
	
											// Initialize array with all student grades: 
	int studentGrades[students][exams] =	// Each row represents grades for one student - Note ',' after each row
	{ {77, 68, 86, 73, 79, 91, 86, 81, 74, 93},
	  {96, 87, 89, 78, 83, 88, 68, 86, 73, 79},
	  {70, 90, 86, 81, 74, 93, 96, 87, 89, 78},
	  {69, 65, 83, 72, 75, 84, 77, 68, 86, 73},
	  {73, 82, 83, 76, 88, 85, 88, 91, 94, 81} };											
											// Display the array of students and their corresponding test scores
	cout << "    Student Test Results shown here: \n";
	prtArry(studentGrades, students, exams);
											// Display the minimum and maximum grade scores, Note that the array arguments [],[] not specified
	cout << "\n\n    Lowest student grade: "// Display the lowest grade
		<< minGrade(studentGrades, students, exams)
		<< "\n    Highest student grade: "		// Display the Highest grade
		<< maxGrade(studentGrades, students, exams) << "\n"<< endl;

	cout << fixed << setprecision(2);

											// Calculate the average grade for each student
	for (int person = 0; person < students; person++)
	{										// Sends only one row (person) of a double scripted array
		cout << "    Average grade for student " << person + 1 << " is: " 
			 << averageGrade( studentGrades[person], exams) << endl;
	}
	

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


int minGrade(int grades[][exams], int totalPupils, int totalTests)
{
	int lowestGrade = 100; 		// Initialize lowest grade to highest possible grade
	for (int pupil = 0; pupil < totalPupils; pupil++)
	{
		for (int exam = 0; exam < totalTests; exam++)
		{
			if (grades[pupil][exam] < lowestGrade)
			{
				lowestGrade = grades[pupil][exam];
			}
		}
	}
	return lowestGrade;
}							// End of minGrade function

int maxGrade(int grades[][exams], int totalPupils, int totalTests)
{
	int highestGrade = 0; 	// Initialize highes grade to lowest possible grade
	for (int pupil = 0; pupil < totalPupils; pupil++)
	{
		for (int exam = 0; exam < totalTests; exam++)
		{
			if (grades[pupil][exam] > highestGrade)
			{
				highestGrade = grades[pupil][exam];
			}
		}
	}
	return highestGrade;
}							// End of maxGrade function


							// Find average test score for only one student
double averageGrade(int grades[], int totalTests)
{							// Receives only one dimesion (row) of a double scripted array
	double averageGrade = 0.0; 	// Initialize average grade to zero
	int totalOfGrades = 0;

	for (int exam = 0; exam < totalTests; exam++)
	{
		totalOfGrades += grades[exam];
	}
	averageGrade = totalOfGrades / totalTests;

	return averageGrade;
}							// End of averageGrade function

void prtArry(int grades[][exams], int pupils, int totalTests)
{								// Left justify column heads
	cout << left << "    Exam Number:  [0]  [1]  [2]  [3]  [4]  [5]  [6]  [7]  [8]  [9]   ";
	for (int pupil = 0; pupil < pupils; pupil++)
	{							// output label for row
		cout << "\n    Student " << pupil + 1 << "] ->  ";
		for (int exam = 0; exam < totalTests; exam++)
		{						// Output grade3s for one student across one line				
			cout << setw(5) << grades[pupil][exam];
		}
	}
}								// End of function printArray


/*

|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|
012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
		  |         |         |         |         |         |         |         |         |         |         |         |         |         |
00		  10        20        30        40        50        60        70        80        90		00		  10        20        30        40

*/