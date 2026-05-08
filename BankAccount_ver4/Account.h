#pragma once
// Fig. 9.5: Account.h
// Account class with m_name and m_balance data members, and a 
// Constructor and deposit function that each perform validation.
#include <algorithm>                               // Required in implement the max() function in code below
#include <string>
#include <string_view>

using std::max;                                    // Part of the included "algorithm" class

class Account {
public:
                                                   // Account constructor taking two parameters       
   Account(std::string_view name, double balance)  // Initializing name and balance delimited with comma < , >
   : m_name{ name }, m_balance{ max(0.0, balance) }// Member initialization list follows colon < : >
   {                                               // Initializing m_balance member to max of either 0.0 or balance arguments
   }                                               // Empty body of constructor
   
   void deposit(double amount) {                   // Function that deposits (adds) only a valid amount to the 
      if (amount > 0.0) {                          // If the amount is valid
         m_balance += amount;                      // Add it to the "m_balance" data member     
      }
   }

   double getBalance() const {                     // Function that returns the account balance
      return m_balance;
   }
   
   void setName(std::string_view name) {           // Function that sets the account name
      m_name = name;                               // Replace m_name's value with name
   }
   
   const std::string& getName() const {            // Function that returns the account name
      return m_name;
   }

private:                                           // Private data hidden at bottom of the class
   std::string m_name;                             // Hidden from account clients
   double m_balance;
};                                                 // End class Account with terminating semicolon


