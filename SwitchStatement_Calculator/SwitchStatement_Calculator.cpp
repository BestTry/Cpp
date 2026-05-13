// Switch_Statement_Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// SwitchStatement_Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//
#include <iostream>
#include <typeinfo>

using std::cout;
using std::cin;
using std::endl;

int main()
{												// Note for the '%' operator the doubles num1 and num2
	double num1{ 0.0 }, num2{ 0.0 };	// may be an integer such as 32.0 and 8.0
	char opRator{ '+' };					// Initializing variable to the addition operator
	char run{ 'c' };						// Run or continue executing calculator

	while (run == 'c')					// Check user response to continue calculator execution
	{
		cout << " Enter a number, an operator and a number"
			<< " to run the calulator:" << endl;
		cin >> num1 >> opRator >> num2;
												// Any user input automatically converts the entry into a 
												// double value, because the variables are declared doubles
												// I was confused with the while statement logic below	
												// Dispay user input on 'Terminal'	

												// ***** Need to check for illegal character entry *****

		cout << " " << num1 << " " << opRator << " " << num2;
		switch (opRator)
		{
		case '*': { cout << " = " << (num1 * num2) << endl; }
				  break;						// Required to behave correctly     

		case '/': { cout << " = " << (num1 / num2) << endl; }
				  break;                // Required to behave correctly 

		case '+': { cout << " = " << (num1 + num2) << endl; }
				  break;						// Required to behave correctly     

		case '-': { cout << " = " << (num1 - num2) << endl; }
				  break;                // Required to behave correctly 

		case '%':							// Varify aurguments of the % modulus operator are integers
		{										// Check if num1 & num2 are integers before using modulus '%'
			bool isNum1Int, isNum2Int;	// Checking for integer operation (operands must be integers)
			isNum1Int = (num1 / (int)(num1 + .1) == 1);
			isNum2Int = (num2 / (int)(num2 + .1) == 1);

			if (isNum1Int && isNum2Int)
			{
				int num1Int = (int)num1;
				int num2Int = (int)num2;
				cout << " = " << (num1Int % num2Int) << endl;
				break;						// Required to behave correctly 
			}
			else
			{
				cout << " Both numbers must be integers for the 'Remainder' - '%' modulo operator to execute" << endl;
				cout << " Please try again " << endl;
				break;						// Required to behave correctly 
			}
		}
		default: {
			cout << "\n An non-recognized/illegal operator was entered\n"
				<< " Please enter a legal characters\n" << endl;
			break;
		}
				 break;
		}										// End of 'switch' block

		cout << endl;
		cout << " Hit the keyboard \" c \" key to continue running the calculator\n"
			<< " Entering any other key terminates the calculator execution: => " << endl;
		cin >> run;
	}											// End of 'while' block

	cout << "			Exiting Calcultor - Good Bye!" << endl;
												// Avoids text messages at end of run
	system("pause>0");					// Waits for a key press before continuation
	return 0;
}												// End of 'main' block

//
//														*****		// Code to verify input is a interger type    *****
//	int a, b;
//	cout << "Enter your parameters a and b." << endl;
//	while (!(cin >> a >> b) || cin.get() != '\n')	// If a or b are not an interger, while condition fails 
//	{
//		cout << "Error. One of your parameters isn't a number. Please, input correct values." << endl;
//		cin.clear();											// Clears the error condtion in cin but input is still left there
//		while (cin.get() != '\n');							// Reads and discards the input until the newline character is encountered. 
//}																// After that your code is ready to read fresh input and cin is in a good 
																	// state to process the input.
/*			Alternate Solution by CodeBeauty tutorial - probably better
			isNum1Int = (num1 == (int)(num1); // i.e Check if 5 == 5.0 (Will result in a true value)
			isNum2Int = (num2 == (int)(num2); // i.e check if 3 == 3.0 (Reult is a boolean true)
*/