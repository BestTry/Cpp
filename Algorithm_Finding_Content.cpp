// Algorithm_Finding_Content.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// 				      // Example code pulled from viewing a Pluralsight -  Kate Gregory tutorial "C++ Algorithyms Playbook"
//                   // Header Section - Files containing information the compiler needs to enable the code to funciton
#include <algorithm> // Algorithms-function templates that perform common data manipulations: searching, sorting, copying, .... etc.
#include <Filter.h>
#include <iostream>  // Standard Input / Output Stream header
#include <map>       // Required for map declaration and definition
#include <ranges>
#include <vector>    // Required for vector declaration and definition - Standard vector class definition
#include <string>    // Required for string declaration and definition along with #include <format>
#include <format>    // Required for the Cpp20 formatting output function

using namespace std; // Had to insert this before string class would work

using std::vector;
using std::count;
using std::search;
using std::search_n;
using std::find_end;
using std::adjacent_find;
using std::cout;
using std::endl;
/* ..................................................................................................................*/
/*   Note: 
      This eample code makes use of iterators which are 'ponter-like' objects to keep track of indexes of elements 
      within containers such as arrays, vectors, deques, queues, lists, stacks etc.  

*/
/* ..................................................................................................................*/
                     // Declaration of function to display vector contents - Passing integer vector by reference
void dispVector(vector<int> vctr);
/* ..................................................................................................................*/

int main()
{                    // Declared and defined vector with contents with single digit integers
   vector<int> intVctr{ 2, 5, 0, 2, 6, 3, 9, 6, 8, 8, 4, 0, 7, 5, 3, 4, 8, 4, 6, 0, 5, 8, 3, 1, 4, 2, 6, 8 };
   int vctrSize = intVctr.size();
   cout << "\n Contents of original vector of size: " << vctrSize << endl;
   cout << format(" Original vector content with {} elements:\n", vctrSize );
   dispVector(intVctr);
   cout << " Press 'Enter' key to continue" << endl << endl;
   system("pause>0");
   /* ..................................................................................................................*/
                     // Demo / Example of using 'find_it' algorithm to find all odd integers in the vector intVctr
   auto iterator = begin(intVctr);
   while (iterator != end(intVctr))
   {                 // Recommended to use ' auto ' instead of spelling out the specific type
      iterator = find_if(iterator, end(intVctr),
         [](auto element) { return element % 2 != 0; }   // <-- This is a Lambda expression
      );             // If remainder is not zero the number is an odd number     
                     // Increment iterator through collection
      if (iterator != end(intVctr)) {
         cout << " Occurance of an odd integer " << *iterator << " within the vector\n"
              << " was found at iterator address location:  " << &(*iterator) << endl << endl;
      }              // Prevents end of loop error message if iterator goes past end of vector
      if (iterator != end(intVctr)) { ++iterator; }
   }

   cout << " Press 'Enter' key to continue" << endl << endl;
   system("pause>0");
   /* ..................................................................................................................*/
                     // Find the integer eight in vector collection using 'find' algorithm function
   auto itResult = find(begin(intVctr), end(intVctr), 8);
   itResult = std::ranges::find(intVctr, 8);  // Ranges version of above
   cout << " The find variable itResult is an iterator " << endl;
   cout << " The find function (using indirection of (*itResult)) found the number =>: " << *itResult << endl;
   int findSought = *itResult; // Contents of iterator (*itResult) was extracted to an interger variable 
                     // Find the first 2 starting from the place the zero was found
   itResult = find(itResult, end(intVctr), 2);
   cout << " The find function looked for indirection of (*itResult) =>: " << *itResult << endl;
                     // Increment terator; show what integer is pointing to (using the indirection operator)
   itResult++;
   cout << " Interator is now pointing to: " << *itResult << " which is one element past the '2' " << endl;
                     // Find first 'odd' value within vector using 'find_if' and a Lamda Expression
   itResult = find_if(begin(intVctr), end(intVctr), [](auto elem) { return elem % 2 == 8; });
   itResult = std::ranges::find_if(intVctr, [](auto elem) { return elem % 2 != 0; });  // Ranges version
   cout << " First odd interger found with the vector is: " << *itResult << endl;
   //
   cout << "\n Contents of original vector: " << endl;
   dispVector(intVctr);
   cout << " Press 'Enter' key to continue" << endl << endl;
   system("pause>0");
   //
   /* ...............................................................................................................*/
                              // Example of walking through a collection in a forward direction
   cout << "\n Sequencing through the vector collection in a forward direction " << endl;
   auto three = (begin(intVctr), end(intVctr), 3);
   auto interator3 = find(begin(intVctr), end(intVctr), 3);
   cout << " The first occurence of number " << three << " was found within the vector" << endl;
   auto distance = interator3 - begin(intVctr);
   cout << " at the element of index " << distance++ << " " << endl << endl;
   //
/* ..................................................................................................................*/
                              // Example of indexing through the vector collection in reverse direction
   cout << " Sequencing through the vector collection in a reverse direction " << endl;
                              // Finds the first element of value '3' - Then finds the value of its iterator with indirection
   auto rthree = (rbegin(intVctr), rend(intVctr), 3);
   auto rinterator3 = find(rbegin(intVctr), rend(intVctr), 3);
   cout << " The last occurence of number " << *rinterator3 << " was found within the vector" << endl;
                              // rbegin(intVctr) is the LAST element (index) in the vector; rend is one iterator before the vector
                              // Distance represents how many elements from end of the vector
                              // Go through these steps cause the interator is not an interger index ??????
   distance = rinterator3 - rbegin(intVctr);
   int index = (vctrSize - ++distance);
   cout << " at the element of index " << index << " " << endl << endl;
                                 // Changing the contents of the vector using find_if 
                                 // Once odd num found, change every odd integer to a '99'                              
   auto itr = begin(intVctr);
   while (itr != end(intVctr)) {
      itr = find_if(itr, end(intVctr), [](auto elem) { return elem % 2 != 0; });
      if (itr != end(intVctr)) {
         *itr = 99; itr++;    // Replace oiginal value within interator, Increment to next iterator
      }
   }
   cout << " Contents of modified vector replacing every odd integer with '99' " << endl;
   dispVector(intVctr);

   cout << " Press 'Enter' key to quit" << endl << endl;
   cout << endl << endl;
   system("pause>0");
   return 0;
};
/* ..................................................................................................................*/
                              // Function Definition - "dispVector"  Using the 'for-range' 
                              // loop format which indexes through the vector collection
void dispVector(vector<int> vctr) {
   int vctSize = vctr.size(); // Is this necessary  ?????
   cout << " { ";
   for (int val : vctr) {
      cout << format(" {} ", val);
   }
   cout << " } " << endl << endl;
}
