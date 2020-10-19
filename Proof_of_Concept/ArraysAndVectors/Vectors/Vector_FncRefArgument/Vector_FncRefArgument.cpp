// Vector_FncRefArgument.cpp : 
// Passing a vector in a function by value and by reference
// The code populates the vector "number" three different times using three different methods of populations
// Passing a vector both by value and by reference demo See tutorial:  //https://www.youtube.com/watch?v=LBbERXYa7Uo      
// Vectors are arrays with more functioanlity / capability / functionality. Vectors can expand in size


#include <iostream>
#include <vector>							// Necessary in using the funtionality of vectors

using namespace std;

#define _win32_winnt 0x0500					// ##### Necessary for the 'GetConsoleWindow()' function below to work! - on Windows 2000 and later
#include <windows.h>						// #####

// ..............................................   Function Prototype Declaration Code   ..............................................

void xfrByVal(vector<int>);					// Prototype Function
void xfrByRef(vector<int>&);				// Prototype Function - Note the ampersand & added for the call by reference execution


int main()
{											// ##############################################################
											// Modify position and size of Console Application Window
HWND console = GetConsoleWindow();		// Get the console handle
RECT r;										// Stores the console's current dimensions
GetWindowRect(console, &r);					// MoveWindow(window_handle, x, y, width, height, redraw_window);
MoveWindow(console, 1400, 500, 700, 1000, true);
											// ###############################################################

	cout << " Part One - Declare a vector and populate it within 'main'" << endl;
	cout << " The contents of the vector 'numbers' populated within 'main' is shown below:" << endl;
	vector<int> numbers;					// Vector of integers declared haveing a vector name of "numbers"

	for (int i = 1; i <= 10; i++) {
		numbers.push_back(i);				// add intergers to vector the mumbers with a name of 'numbers'
	}

	for (int j = 0; j < 10; j++) {			// display then remove intergers from the vector mumbers
		cout << " " << numbers[j] << ",";
	}
	cout << endl;

	numbers.clear();						// Before continuing empty the vector
	cout << " The vector was just emptied with the 'number.clear' statement" << endl;
	cout << " Finished Part One \n" << endl;
	system("pause");						// The system("pause") statement pause execution and awaits key press

	cout <<	"\n Part Two - Transfer the vector 'numbers' by 'value' to a " <<
			"\n function outside 'main' to perform the work of populating it" <<
			"\n The vector was emptied within main:'numbers' it will not be re-populated " <<
			"\n and it will remain empty. A now empty copy of the vector 'numbers' is " <<
			"\n sent to the xfrByVal function; that function outside 'main' populates it" <<
			"\n remotely of the 'main' block..  What you see display is the result of" <<
			"\n the function call that populated its received vector from main" <<
			"\n After the functin call the original vector 'numbers' will be " <<
			"\n checked to verify if it is still empty by invoking the empty()" <<
			"\n vector class method \n" << 
	endl;

	system("pause");

	xfrByVal(numbers);
	
	cout << "\n Finished Part Two " <<
			"\n The contents of the vector 'numbers' here within 'main' has" <<
			"\n not been populated, the vector contents outside main was populated" <<
			"\n Checking contents of the vector 'numbers' within 'main' with vector method" <<
			"\n Checking empty(): " << numbers.empty() << " - '1' means 'numbers' is empty! \n" << 
	endl;

	system("pause");

	cout << "\n Part Three - Transfer the vector 'numbers' by 'reference' to a " <<
			"\n function outside 'main' to do the work of populating it" <<
			"\n This time, since the argument was passed by reference the" <<
			"\n vector that the function is modifying is the vector within" <<
			"\n the 'main' block. Once the function completes, the contents " <<
			"\n of the vector 'numbers' is displayed showing that it has been " <<
			"\n populated \n" << 
	endl;

	system("pause");

	xfrByRef(numbers);

	cout << "\n Finished Part Three " << 
			"\n Note the contents of the vector numbers below within the 'main' block" <<
			"\n has NOW been populated by using a call by reference: " << 
	endl;

	for (int j = 0; j < 10; j++) {				// Display the contents of the vector
		cout << " " << numbers[j] << ", "; 	// note the interation index [j] is (0-9) not (1-10)
	}
	cout << endl;

	system("pause");
	return 0;
}

// .............................................   Function Code Definition Implementation  .................................................

void xfrByVal(vector<int> xfrVector) {	// Call by value
	for (int i = 1; i <= 10; i++) {
		xfrVector.push_back(i);			// Add intergers to vector the mumbers
	}

	for (int j = 0; j < 10; j++) {				// Display the contents of the vector
		cout << " " << xfrVector[j] << ", "; 	// note the interation index [j] is (0-9) not (1-10)
	}
	cout << endl;


	return;
}

										// Call by reference
void xfrByRef(vector<int>& xfrVector) {	// Note the ampersand for reference proceeding the vector name
	for (int i = 1; i <= 10; i++) {
		xfrVector.push_back(i);			// Add intergers to vector the mumbers
	}

	for (int j = 0; j < 10; j++) {				// Display the contents of the vector
		cout << " " << xfrVector[j] << ", "; 	// note the interation index [j] is (0-9) not (1-10)
	}
	cout << endl;

	return;
}

