// Binary_Num_Count_Demo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Binary_Count_Logic_Demo.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Code is similar to a program I authored within the "Arduino" IDE. Modified her to test the logic and to run under C++20 
//
// To modify a cout statement in C++ to update output variables on the same line, you can use the carriage return character < \r >.
// The character moves the cursor to the beginning of the current line, allowing subsequent output to overwrite the previous content.
/*
            \r moves the cursor to the start of the current line.
            The new progress percentage overwrites the previous one.
            std::flush ensures the output is displayed immediately.
            std::this_thread::sleep_for introduces a delay to visualize the progress.
            std::cout << std::endl; moves the cursor to a new line after the loop
            to prevent next output from overwriting.
*/

#include <iostream>
#include <format>
#include <chrono>
#include <thread>
#include <Windows.h>                            // Required to implement the 'Sleep()' function

using namespace std;

using std::thread;
using std::format;
using std::flush;                               // Ensures the output is displayed immediately.
using std::cout;
using std::endl;

int mSec = 1000;                                // Milliseconds to work with 'Sleep' function
int row = 0;
int col = 0;

int loopCnt = 0;
int dNum = 0;

int bin0 = 0;
int bin1 = 0;
int bin2 = 0;
int bin3 = 0;
int carry = 0;

// ...............................................................................................................
void dsplyBinNum() {
   cout << format("      {}      {}      {}      {}          {}\n", bin3, bin2, bin1, bin0, dNum) << std::flush;
   //cout << format("\r      {}      {}      {}      {}          {}\n", bin3, bin2, bin1, bin0, dNum) << std::flush;
}  // "Carriage Return" character cause output errors after the first full pass (output: 0-15)                                  
// ...............................................................................................................

int main() {

   cout << format("\n\n Simulation of Incrementing a Binary Number") << endl << endl;
   cout << "    dgt-3  dgt-2  dgt-1  dgt-0     Decimal\n";
   cout << "    -----  -----  -----  -----     -------\n";

   do {

      Sleep(mSec);
      bin0 = bin0 + carry;                // Binary 0 place digit       
      if (bin0 <= 1) { bin0 = bin0; carry = 0; }
      if (bin0 > 1) { bin0 = 0;    carry = 1; }

      bin1 = bin1 + carry;
      if (bin1 <= 1) { bin1 = bin1; carry = 0; }
      if (bin1 > 1) { bin1 = 0;     carry = 1; }

      bin2 = bin2 + carry;
      if (bin2 <= 1) { bin2 = bin2; carry = 0; }
      if (bin2 > 1) { bin2 = 0;     carry = 1; }

      bin3 = bin3 + carry;
      if (bin3 <= 1) { bin3 = bin3; carry = 0; }
      if (bin3 > 1) { bin3 = 0;     carry = 1; }

      if (bin3 == 0 && bin2 == 0 && bin1 == 0 && bin0 == 0 && carry == 1)
      {
         carry = 0;
      }                                   // Reset carry on 1111 -> 0000 transition

      dsplyBinNum();

      loopCnt++;
      bin0++;                             // Increment least significant digit 
      dNum++;                             // Increment decimal number to reflect binary value equivalent
      if (dNum == 16) { dNum = 0; }       // Reset decimal on 15 -> 16 transition to zero

   } while (loopCnt <= 47);               // Use one less than total number display i.e.  (48 - 1);

   cout << "\n\n            >>>> Finished <<<<<";

   cout << endl << endl;
   system("pause>0");
   return 0;
}

