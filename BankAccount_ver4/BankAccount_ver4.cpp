// BankAccount_ver4.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Code was retrieved from "C++20 for Programmers" textbook - Deitel and related video from "O'Reilly Leaning" web site
// Fig. 9.6 AccountTest.cpp of textbook - Version C++20 compiled
// 
// Activate C++20 version of compiler by right-clicking on project name and drilling down on 'Properties"
// 
                                  
// Fig. 9.6: AccountTest.cpp
// Displaying and updating Account balances.
#include <format>                                  // Included with C++20 
#include <iostream>
#include "Account.h"

using namespace std;
using std::cout;
using std::cin;
using std::end;

int main() {
   Account account1{ "Jane Green", 50.00 };        // Custom constructor designed to take two arguements
   Account account2{ "John Blue", -7.00 };         // Finacial apps should use floating point even though double here

                                                   // Display initial balance of each object
   cout << format(" account1: {} balance is: ${:.2f}\n",
      account1.getName(), account1.getBalance());
   cout << format(" account2: {} balance is: ${:.2f}\n\n",
      account2.getName(), account2.getBalance());

   cout << " Enter deposit amount for account1: ";  // Prompt
   double amount;
   cin >> amount;                                  // Obtain user input
   cout << format(                                 // Two digits to right of the decimal point for floating point number
      " adding ${:.2f} to account1 balance\n\n", amount);
   account1.deposit(amount);                       // Add to account1's balance

                                                   // Display account balances
   cout << format(" account1: {} balance is: ${:.2f}\n",
      account1.getName(), account1.getBalance());
   cout << format(" account2: {} balance is: ${:.2f}\n\n",
      account2.getName(), account2.getBalance());

   cout << " Enter deposit amount for account2: ";  // Prompt
   cin >> amount;                                  // Obtain user input
   cout << format(
      " adding ${:.2f} to account2 balance\n\n", amount);
   account2.deposit(amount);                       // Aadd to account2 balance

                                                   // Display balances
   cout << format(" account1: {} balance is: ${:.2f}\n",
      account1.getName(), account1.getBalance());
   cout << format(" account2: {} balance is: ${:.2f}\n",
      account2.getName(), account2.getBalance());


   cout << endl << endl;
   system("pause>0");
   return 0;			                              // Required as the last statement placed at the end of each program
}


