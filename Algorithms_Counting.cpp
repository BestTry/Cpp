// Algorithms_Counting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Algorithms_Counting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// AlgorithmsPlaybook1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Example pulled form Pluralsight website  -  Kate Gregory tutorial "C++ Algorithyms Playbook"
//                            // Header Section - Files containing information the compiler needs to enable the code to funciton
#include <iostream>           // Standard Input / Output Stream header
#include <algorithm>          // Algorithms-function templates that perform common data manipulations: searching, sorting, copying, .... etc.
#include <vector>             // Required for vector declaration and definition
#include <map>                // Required for map declaration and definition
using std::vector;
using std::count;
using namespace std;

int main()
{                             // Delared and defined vector with contents of integers
   vector<int> intVctr{ 2, 5, 6, 1, 3, 9, 6, 3, 8, 4, 0, 7, 5, 3, 3, 9, 4, 6, 5, 8, 1, 2 };
   auto ndx1 = intVctr.begin();// Acquire beginning index contents of vector
   auto ndx2 = intVctr.end(); // Grabs ending index contents of one index address past last vector element
                              // Pluralsight's Kate Gregory recommends always used "auto" for interators - Algorithms course

   int element;
   element = *ndx1;           // Element contents of first <(0)> index of integer vector
   ndx1++;                    // Element contents of second <(1)> index of integer vector 
   element = *ndx1;
                              // Conventional method (Raw Loop) of finding the number of occurences of < 3 >
   int target = 3;            // Target element value is defined as < 3 >
   int numOf3s = 0;           // How many vector elements contain < 3 >, Initialized to zero>
   for (int i = 0; i < intVctr.size(); i++) {
      if (intVctr[i] == 3)
         numOf3s++;
   }


   cout << " Using the conventional legacy for-loop syntax" << endl;
   cout << " The number of 3's in the vector 'intVctr' is: " << numOf3s << endl << endl;
   cout << " Press 'Enter' to continue" << endl;

   /* 
      cout  
      << " The conventional for-loop legacy method has potentially multiple issues prone to errors\n"
      << " Such as incorrect index initiation, comparison operators, increment syntaxes etc.\n "
      << " Takes time to type and time to read and challenging to comprehend, check for errors etc."  
      << endl << endl;
  */

   system("pause>0");

   // *** New Policy *** from Kate Gregory of Pluralsight - Avoid using raw loops! *** => Use Algorithms instead!
   // Calling algorithm called 'count' passing iterators 'begin' & 'end' - Note: 'end' is one element past last element
   // First example uses member functions of the vector class, Second example uses free or non-member function of a class
   // Recommend to always use second example format - free version as it is more univeral 
   numOf3s = count(intVctr.begin(), intVctr.end(), target);
   numOf3s = count(begin(intVctr), end(intVctr), target);

   // Algorithm with 'Range' implementation - Implemented with C++20 
   numOf3s = ranges::count(intVctr, target);

   cout << "\n Implementing the Algorithm count function syntax: ";
   cout << "\n The number of 3's in the vector 'intVctr' is: " << numOf3s << endl << endl;

   cout << " Press 'Enter' to continue" << endl << endl;
   system("pause>0");
   //
   //
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                              // *** Find the amount of odd numbes in the vector ***
                              // First Raw Loop method
   int oddNums = 0;           // Initialize number of odd numbers with the vector referenced
   for (auto elem : intVctr) { if (elem % 2 != 0) oddNums++; }
   // Range-based syntax for above loop - elem is a copy of each element, not a reference
   cout << " Using the conventional 'if' syntax control within Range-based loop syntax:" << endl;
   cout << " The amount of odd intergers in the vector 'intVctr' is: " << oddNums << endl;
   oddNums = 0;               // Re-zero oddNums variable for for occurences of odd numbers
   for (auto& elem : intVctr) { if (elem % 2 != 0) oddNums++; }
   // Above for-loop uses Range-based syntax - elem is a reference (alias) of each element
   cout << " The amount of odd intergers in the vector 'intVctr' is: " << oddNums << endl;

   oddNums = 0;               // Re-zero oddNums variable for for occurences of odd numbers
   // Using Algorithm 'count_if' - Two versions of   
   // Version One ...
   oddNums = count_if(begin(intVctr), end(intVctr), [](auto elem) {return elem % 2 != 0; });
   cout << " The amount of odd intergers in the vector 'intVctr' is: " << oddNums << endl;
   oddNums = 0;               // Re-zero oddNums variable for for occurences of odd numbers
   // Verion Two ...
   oddNums = std::ranges::count_if(intVctr, [](auto elem) {return elem % 2 != 0; });
   cout << " The amount of odd intergers in the vector 'intVctr' is: " << oddNums << endl << endl;
   //
   cout << " Press 'Enter' to continue" << endl << endl;
   system("pause>0");
   //
                              // Algorithm count_if used with map - 'map' is like a look-up table 
   map<int, int> monthLengths{ {1, 31}, {2, 28}, {3, 31}, {4, 30}, {5, 31}, {6, 30}, {7, 31}, {8, 31},
                               {9, 30}, {10, 31}, {11, 30}, {12, 31} };
   // Populate map with month number and days within month
   int monthsOf30Days = count_if(begin(monthLengths), end(monthLengths), [](auto elem) {return elem.second == 30; });
   cout << " There are " << monthsOf30Days << " months having a length of 30 days" << endl;

   cout << " Press 'Enter' to continue" << endl << endl;
   system("pause>0");
   //
   cout << endl << endl; cout << " Demo of using the the algorithms functions of 'all_of', 'none_of', 'any_of'" << endl;

   // Demo using the boolean 'all_of', 'non_of', 'any_of' 
   bool allof, nonof, anyof;  // Creating the boolean variables
   // Checking if the amount of odd numbers in the vector equals the size of it
   allof = (oddNums == intVctr.size());
   nonof = (oddNums == 0);    // Checks if there are 'NO' odd numbers
   anyof = (oddNums > 0);     // Checks if there any odd numbers
   // Above boolean expressions are legal BUT not prefered as the below statements
   // Statement below are more expressive / understandable and so are preferred

   allof = all_of(begin(intVctr), end(intVctr), [](auto elem)
      {return elem % 2 != 0; });
   cout << " Does the vector intVctr contains all odd intergers: " << (allof ? "True" : "False") << endl;
   allof = ranges::all_of(intVctr, [](auto elem) {return elem % 2 != 0; });
   cout << " Does the vector intVctr contains all odd intergers: " << (allof ? "True" : "False") << endl;

   nonof = none_of(begin(intVctr), end(intVctr), [](auto elem)
      {return elem % 2 != 0; });
   cout << " Does the vector intVctr contains no odd intergers: " << (nonof ? "True" : "False") << endl;
   nonof = ranges::none_of(intVctr, [](auto elem) {return elem % 2 != 0; });
   cout << " Does the vector intVctr contains no odd intergers: " << (nonof ? "True" : "False") << endl;

   anyof = any_of(begin(intVctr), end(intVctr), [](auto elem)
      {return elem % 2 != 0; });
   cout << " Does the vector intVctr contains any odd intergers: " << (anyof ? "True" : "False") << endl;
   anyof = ranges::any_of(intVctr, [](auto elem) {return elem % 2 != 0; });
   cout << " Does the vector intVctr contains any odd intergers: " << (anyof ? "True" : "False") << endl;

   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   //
   // More Algorithm Functions: 
   //       count,   count_if
   //       find,    find_if
   //       copy,    copy_i
   //  ...  More Yet (General Descriptions) ...
   // Comparing and Accumalating
   // Copying and Moving
   // Transforming - Going thru a collection and modifying elements
   // Generating and Manipulating
   // Conventions
   // and much, much more ... (Over 0ne hundred functions at present)
   // Algorithms to work on: vectors, arrays lists, stacks, maps, queues, strings etc.
   // May need to add some of theses headers: <iterator>, <utility>, <tuple>, <numeric> and many others
   // 
   /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   cout << endl << endl;
   system("pause>0");
   return 0;

};
