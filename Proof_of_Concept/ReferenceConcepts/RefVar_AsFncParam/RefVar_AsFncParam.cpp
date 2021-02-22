// RefVar_AsFncParam.cpp : Example code pulled from textbook 'C++ Control Structures through Objects' - Tony Gaddis
// Example of reference variable used as parameters to functions (The original variable value is modified)
//
#include <iostream>
using namespace std;

void fncDblNum(int&);                       // Function Prototypes where the parameter is a reference variable
void fncSqrNum(int& refNum);                // Parameter described as 'A reference to an integer type variable 'refNum')
void fncIncr4Num(int&, int&, int&, int&);   // Function taking three reference numbers as parameters
void fncMath4Num(int&, int&, int&, int&);

void takeDonutOrder(int&);                  // Request number of donuts This reference of int number will point
                                            // to the address of the variable holding the donut order count

int main()
{
    int dblNum;
    int orgNum;
    int refNum1, refNum2, refNum3, refNum4;
    int jellyDonutCount;                    // This integer variable will be a variable that is referenced
                                            // Anything you do to a reference variable is actually done to the 
                                            // variable it references. The 'donuts' variable in the takeDonutOrder
                                            // function is the reference variable that references this 'jellyDonutCount'

    std::cout << " Demonstraing reference variables as parameters to functions \n"
              << " As arguments to functions the original variable IS MODIFIED in value\n" << endl;

    cout << " Enter a number to be doubled: ";
    cin >> dblNum; orgNum = dblNum;         // Save orignal value of reference variable
    cout << " Originl value of reference variable number entered was: " << dblNum << endl;
    fncDblNum(dblNum);
    cout << " Modified (doubled) value of reference variable number is now: ";
    cout << dblNum;
    cout << endl;
    fncSqrNum(dblNum);
    cout << " Squaring this number gives it a new value of value:  ";
    cout << dblNum << endl;
    cout << " The original value saved in an alternate variable was: ";
    cout << orgNum << "\n\n" << endl;
    
    cout << " Enter four more numbers to be incremented (No commas): ";
    cin >> refNum1 >> refNum2 >> refNum3 >> refNum4; cout << endl;
    fncIncr4Num(refNum1, refNum2, refNum3, refNum4);
    cout << " Incrementing these numbers by one give them the values of: ";
    cout << refNum1 << " " << refNum2 << " " << refNum3 << " " << refNum4 << endl << endl;

    fncMath4Num(refNum1, refNum2, refNum3, refNum4);
    cout << " Lastly these numbers are manipulated with simple math functions: \n"
         << " Double: (n1 = n1 * 2)  => " << refNum1 << ", Add: (n2 = n3 + n4 ) => " << refNum2 << " \n"
         << " Subtract: (n3 = n2 - n1) => " << refNum3 << " and Multiply: (n4 = n1 * n2) => " << refNum4 << endl;
    cout << " In summary the refernce numbers n1, n2, n3, n4 have the final values of: ";
    cout << refNum1 << ", " << refNum2 << ", " << refNum3 << ", " << refNum4 << endl <<  endl;

    cout << " Another exmaple of using a reference variable follows: \n";
    takeDonutOrder(jellyDonutCount);
    cout << " There were " << jellyDonutCount << " donuts ordered \n" << endl;

    system("pause");			            // Some compilers do not recognize this statement
    return 0; 					            // Indicates successful termination
}								            // End of main


void fncDblNum(int& refVar)
{
    refVar *= 2;
}

void fncSqrNum(int& refNum)
{
    refNum *= refNum;
}

void fncIncr4Num(int& n1, int& n2, int& n3, int&n4)
{
    n1++; n2++; n3++; n4++;
}

void fncMath4Num(int& n1, int& n2, int& n3, int& n4)
{
    n1 *= 2;
    n2 = n3 + n4;
    n3 = n2 - n1;
    n4 = n1 * n2;
}

void takeDonutOrder(int& donuts)                // The reference variable 'donuts' is pointing to the variable
{                                               // 'jellyDonutCount' from the function call 'takeDonutOrder' above
    cout << " How many donuts do you wish to order? Enter here: ";
    cin >> donuts;                              // Since 'donuts' variable is a reference variable
}                                               // return; statement is not neccessary 
