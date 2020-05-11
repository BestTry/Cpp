// ForLoop_RangeBased.cpp : This file contains the 'main' function. Program execution begins and ends here.
// Copied this from Microsoft docs:     https://docs.microsoft.com/en-us/cpp/cpp/range-based-for-statement-cpp?view=vs-2019 
// Made some slight modifications and added more comments
//
#include <iostream>
#include <vector>
using namespace std;

int main()
{    
    cout << "Integer array testing using Range-based For Loop" << endl;
    int x[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
                                                // Basic 10-element integer array.
    for (int y : x) {                           // Range-based for loop to iterate through the array.
        cout << y << " ";                       // Access by value using a copy declared as a specific type. Not preferred.
    }                                           // Preferred syntax is to use 'auto' as the type - let compiler designate type
    cout << endl;                               // See example below
    

    for (auto y : x) {                          // The auto keyword causes type inference to be used. Preferred.
        cout << y << " ";                       // Copy of 'x', almost always undesirable - Use reference instead!        
    }
    cout << endl;


    for (auto& y : x) {                         // Type inference by reference.
                                                // Observes and/or modifies in-place. Preferred when modify is needed.
        cout << y << " ";
    }
    cout << endl;


    for (const auto& y : x) {                   // Type inference by const reference.  - Array interger element are constants
                                                // Observes in-place. Preferred when no modify is needed.
        cout << y << " ";
    }
    cout << endl << "end of integer array test" << endl << endl;
  

    cout << "Vectors - Transversing Through Their Elements" << endl;
    vector<int> intVect{ 3, 1, 6, 3 ,7, 9, 5, 0, 8, 1, 6, 6, 4, 2, 2 };
    cout << "Contents of the interger vector having " << intVect.size() 
         << " elements is: " << endl;
    for (auto& intElm : intVect) {                // Display array element using the 'Range-based For Loop'
        cout << intElm << ", ";
    } 
    cout << endl << endl;

    cout << "Display same vector contents using standard for-loop syntax" << endl;
    for (int i = 0; i < intVect.size(); i++) {     // Display array element using the 'Range-based For Loop'
        cout << intVect[i] << ", ";
    }
    cout << endl << endl;



    vector<double> v;                           // Empty vector wit zero elements - v.size() is zero
    for (int i = 0; i < 10; ++i) {              // Create a vector object that contains 10 elements of type double.
        v.push_back(i + 0.14159);               // Add element to end of vector using dot notation
    }

    
    for (const auto& j : v) {                       // Range-based for loop to iterate through the vector, observing in-place.
        cout << j << " ";
    }
    cout << endl;
    cout << "end of vector test" << endl;
}
