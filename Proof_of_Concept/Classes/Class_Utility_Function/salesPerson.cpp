// Fig. 6.10: salesp.cpp from Deitel "How to Program edition 4. // Member functions for class SalesPerson.
// Include calling reference to the private utility function: 'totalAnnualSales()'

#include "salesPerson.h"                        // Include SalesPerson class Declaration from salesp.h

#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::fixed;
using std::setprecision;

using namespace std;	// Common practice to implement the "std" namespace as it contains multiple supporting useful functions

SalesPerson::SalesPerson()                      // Constructor initializes elements of array sales to 0.0
{
    for (int i = 0; i < 12; i++)
        sales[i] = 0.0;

}                                               // End SalesPerson constructor


void SalesPerson::getSalesFromUser()            // Get 12 sales figures from the user at the keyboard
{
    double salesFigure;

    for (int i = 1; i <= 12; i++) {
        cout << " Enter sales amount for month " << i << ": ";
        cin >> salesFigure;
        setSales(i, salesFigure);               // Filling the 'sales[] array by calling setSales()

    }                                           // End acquiring monthly sales amount for 12 months / year

}                                               // End function getSalesFromUser


void SalesPerson::setSales(int month, double amount)
{                                               // Set 1 of 12 month sales figure; function, subtract 1 from month value for proper array subscript
                                                
    if (month >= 1 && month <= 12 && amount > 0)// test for valid month and amount values
        sales[month - 1] = amount;              // Adjust for array element subscripts 0-11

    else                                        // Invalid month or amount value
        cout << "Invalid month or sales figure" << endl;

}                                               // End function setSales


void SalesPerson::printAnnualSales()            // Print total annual sales (with the help of utility function)
{
    cout << setprecision(2) << fixed
         << "\n The total annual sales amount for 12 months is: $"
         << totalAnnualSales() << endl;          // Call utility function which is PRIVATE

}                                               // End function printAnnualSales


double SalesPerson::totalAnnualSales()          // Private utility function to total annual sales
{
    double total = 0.0;                         // Initialize total before summation

    for (int i = 0; i < 12; i++)                // Summarize sales results by adding each month's value
        total += sales[i];

    return total;

}                                               // End function totalAnnualSales