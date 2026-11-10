// StringSearch function: The string search function "strstr" searches for a string insdied of a string.
// The functions first argument is the string to be searched, and the second argument is the string for
// which to look.  If the funcition finds the second string inside the firest string, it returns the 
// address of the first occurance of the second string whithin the first string.  Otherwise it returns
// a nullptr

// Code below demos the funcrtion "strstr" to search for an array

#include <iostream>
#include <format>
#include <string>
#include <cstring>				// Required for the function "strstr" 

using std::cout;
using std::cin;
using std::endl;
using std::format;
using std::string;
using std::cstring;

int main()
{
	char chrArry[] = "Four scorre and seven years ago";
	char *strPtr = nullPtr;		// Initialize string pointer to nullPtr (Keyword)
	cout << format(" The character array content: {}\n", chrArry);
								// Serach for the string "seven"
	strPtr = strstr(arr, "seven"); 
	cout << format(" The string 'seven' was found: {}\n", strPtr);
	cout << endl;
   
   
   
   
   
   
   

   cout << endl << endl;
   system("pause>0");
   return 0;
}

