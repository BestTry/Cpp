// InErrChk_OutFormat.cpp : InpErrChkg_OutFormatg_1.cpp : Input error checking and output formating example: Using code example 'Invoice' lifted from: 
// Code was adopted and enhanced from Marach's 'C++ Programming' by Mary Delamater - Introduction to Streams and Buffers
// 
//
                        // The Preprocessor Directives: (Header Files) 							
#include <iostream> 	// Standard Template Library class  -  Used for cout, cin, cerr, printf  ( That is the  reason for brackets < > )
#include <string>		// Use the s suffix for literal strings 'string' class - required as a new way of using strings, non char sequence

#include <iomanip>		// Required to utilize parameterized stream manipulator ie. calling setprecision(3) & fixed functions

                        // The double colons operator '::' is defined as the "Scope Resolution Operator"
using std::cout;		// Console output
using std::cin;			// Console input
using std::endl;		// End of Line - Clears output buffer and terminates with a new-line character
using std::fixed;		// Both 'fixed' & 'showpoint' are nonparamatized stream manipulators that Do Not require the <iomanip> header file
using std::setw;		// Assure #include <iomanip> is included which requires a parameterized stream manipulator
using std::setprecision;// setprecision(2)indicates a double variable value should be printed with 2 digits to the right of the decimal point


using namespace std;	// Common practice to implement the "std" namespace as it contains multiple supporting useful functions


// ..............................................   Function Prototype Declaration Code   ..............................................

void exitPrgm();							// Use this function as a optional default to terminate the program


int main()									// Function main() begins program execution - Entry point for the program
{
    cout << "\n\n >>>>>>>>>>>>>>>>>>>>>>>>>>>>   Main Code Execution   <<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
    cout << "            Input Error Checking and Output Formating Example             \n\n" << endl;

    char customer_type;                         // Acquire Retail or Wholesale customer type
    while (true) {                          // Loop until user types in 'r' or 'w'
        cout << "Enter customer type ('r' - Retail / 'w' - Wholesale): ";
        cin >> customer_type;
        if (tolower(customer_type) == 'r' || tolower(customer_type) == 'w') {
            break;
        }
        else {
            cout << "Invalid customer type! Please try again.\n";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    double subtotal;                        // Assure user input enter a numerical value
    while (true) {                          // loop continues until break statement
        cout << "Enter subtotal:            ";
        cin >> subtotal;

        if (cin.good()) {                   // stream good - end loop
            break;
        }
        else if (cin.fail()) {              // stream OK - try again
            cout << "Invalid number! Please try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (cin.bad()) {               // stream bad - exit program
            cout << "Sorry, an unexpected error has occurred. Bye! ";
            return 0;
        }
    }


    double discount_percent;                // Setting discount percent
    if (tolower(customer_type) == 'r') {    // Retail discount   
        if (subtotal < 100) {
            discount_percent = .0;
        }
        else if (subtotal >= 100 && subtotal < 250) {
            discount_percent = .1;
        }
        else {
            discount_percent = .2;
        }
    }
    else if (tolower(customer_type) == 'w') { // Wholesale discount
        if (subtotal < 500) {
            discount_percent = .4;
        }
        else {
            discount_percent = .5;
        }
    }
    else {
        discount_percent = .0;
    }

    // Calculate cost after discount and round results
    double discount_amount = subtotal * discount_percent;
    discount_amount = round(discount_amount * 100) / 100;

    double invoice_total = subtotal - discount_amount;
    invoice_total = round(invoice_total * 100) / 100;

    // display output
    int col1 = 18;
    int col2 = 8;
    cout << fixed << setprecision(2) << endl   // Set to two decimal places
        << "INVOICE" << endl
        << left << setw(col1) << "Subtotal:"
        << right << setw(col2) << subtotal << endl
        << left << setw(col1) << "Discount percent:"
        << right << setw(col2) << discount_percent << endl
        << left << setw(col1) << "Discount amount:"
        << right << setw(col2) << discount_amount << endl
        << left << setw(col1) << "Invoice total:"
        << right << setw(col2) << invoice_total << endl;

    // Display exit message
    cout << endl << left << "Bye! ";

    exitPrgm();					// Option function member to terminate program
    system("pause");			// Some compilers do not recognize this statement
    return 0; 					// Indicates successful termination
}								    // End of main


// .............................................   Function Code Definition Implementation  .................................................

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