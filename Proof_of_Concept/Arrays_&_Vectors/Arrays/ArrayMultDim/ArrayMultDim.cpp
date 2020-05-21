// ArrayMultDim.cpp : Code Example lifted from Dietel "How to Program" 4th edition, - Chapter 04 - Multi Dimensional Arrays
// Description of Program ...................................................................
// Introduction to using multi dimensional arrays by giving examples of syntax and usage 
// """"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
						// The Preprocessor Directives: (Header Files) 							
#include <iostream> 	// Standard Template Library class  -  Used for cout, cin, cerr, printf  ( That is the  reason for brackets < > )
#include <array>		// Necessary when using the array class i.e array<arrType, size>

using namespace std;	// Common practice to implement the "std" namespace as it contains multiple supporting useful functions

// .........................................   Function Prototype Declaration Header References   ............................................
void printArray(int[][4]);		// Function to print array - In C++ every funtion requires a prototype placed before/outside the main block
void exitPrgm();							// Use this function as a optional default to terminate the program


int main()						// Function main() begins program execution - Entry point for the program
{
	cout << "\n\n >>>>>>>>>>>>>>>>>>>>>>>>>>>   Main Code Execution   <<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	cout << "                       Examples of Multidimensional Arrays        \n" << endl;

	int array1[3][4] = { { 1,2,3}, {4,5,6}, {7,8,9,0} };	// Zeros are displayed in elements [0][3] and [1][3]
	int array2[3][4] = { 1,2,3,4,5,6,7,8 };					// Two rows are display with volumn content [2], rows are all zeros	
	int array3[3][4] = { {1,2}, {4} };						// Zeros are placed in [0][2] and [0][3], Zeros in [1][1], [1][2], [1][3]
															// Zeros are placed in all of row 3 [2][]
	cout << "\nValues in array1 by row are:  " << endl;
		printArray(array1);

	cout << "\nValues in array2 by row are:  " << endl;
		printArray(array2);

	cout << "\nValues in array3 by row are:  " << endl;
		printArray(array3);


	exitPrgm();					// Option function member to terminate program
	system("pause");			// Some compilers do not recognize this statement
	return 0; 					// Indicates successful termination
}								// End of main

// .............................................   Function Code Definition Implementation  .................................................

								// Function to output a (2 x 3) array
								// One does not have to specify the first dimension, compiler figures it out
void printArray(int inputArray[][4])
{
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			cout << inputArray[row][col] << " ";
		}
		cout << "\n";
	}
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