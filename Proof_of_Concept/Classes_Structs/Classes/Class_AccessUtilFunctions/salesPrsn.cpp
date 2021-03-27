// salesPrsn.cpp
// Member functions for class SalesPerson.

#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::fixed;

#include "salesPrsn.h"                                  // Include SalesPerson class definition from salesPrsn.h
#include <iomanip>

using std::setprecision;

                                                        // Constructor of the SalesPerson class and it initialization
SalesPerson::SalesPerson() {                            // Initialize elements of array sales to 0.0 when object 
    for (int i = 0; i < 12; i++) {                      // is instantiated / created    
        sales[i] = 0.0;
    }
}                                                       // end SalesPerson constructor


void SalesPerson::getSalesFromUser()                    // Get 12 sales figures from the user at the keyboard
{
    double salesFigure;

    for (int i = 1; i <= 12; i++) {
        cout << "Enter sales amount for month " << i << ": ";
        cin >> salesFigure;
        setSales(i, salesFigure);                       // Public 'setSales' function places doubles in private array 'sales' 
    }                                                   // End for-loop
}                                                       // End function getSalesFromUser

                                                        // Public function 'setSales' fills (private)  array with doubles
void SalesPerson::setSales(int month, double amount)    // Set one of the 12 monthly sales figures; function subtracts -
{                                                       // one from month value for proper subscript in sales array
    if (month >= 1 && month <= 12 && amount > 0) {      // Test for valid month and amount values
        sales[month - 1] = amount;                      // Adjust for subscripts 0-11
    }
    else {                                              // Invalid month or amount value
        cout << "Invalid month or sales figure" << endl;
    }
} // end function setSales


void SalesPerson::printAnnualSales()                    // Print total annual sales (with the help of utility function)
{
    cout << setprecision(2) << fixed
         << "\nThe total annual sales are: $"
         << totalAnnualSales() << endl;                 // Call utility function

}                                                       // End function printAnnualSales

                                                        // Private UTILITY FUNCTION to PUBLIC total annual sales
double SalesPerson::totalAnnualSales()                  // Takes private scoped values and provides total result                   
{                                                       // to public code client: 'printAnnualSales'
    double total = 0.0;                                 // Initialize total
    for (int i = 0; i < 12; i++)                        // Summarize sales results
        total += sales[i];
    return total;                                       // Returns private access of total annual sales to public client
}                                                       // End function totalAnnualSales