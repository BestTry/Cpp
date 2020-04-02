#include "pch.h"
#include "MiscFunc.h"
#include <iostream>
#include <string>
#include <cctype>


using namespace std;

MiscFunc::MiscFunc()
{
}

MiscFunc::~MiscFunc()
{
}


string MiscFunc::dispUserFctn(int function) 	// Function elected from typing in 0,1,2,3 
{													// Provides a string for displaying description of user request  
	switch (function)
	{
	case 1:
		return (" a desire to acquire the number of days between two given days.");

	case 2:
		return (" a desire to find a date spanned by a number of days from a given date.");

	case 3:
		return (" a desire to find the week day week name given a date.");

	case 0:
		return(" a desire to terminate this program ");

		// case 0x001B:
		// ("\n\t\t Escape!");   
		// break;

	default:
		return("\n\t\t Error - This is not a legal option - Enter a legal option.");
	}
}


bool MiscFunc::chkUserAffrmResps()								// Checks if firsst character of user response from keyboard is a 'y'
{ 
	string keyBrdEntry;
	getline(cin, keyBrdEntry);								// Read entire line of keyboard input into character array					
	char firstChar = keyBrdEntry[0];						// Extract first character of string which is an equivalent char array							
	char lowerCase1stChar = toLowerChar(firstChar);			// Assure first character is of the lower case sequence of characters
	return (firstChar == 'y');								// Return with a resonse of boolean affirmative true if first chaaracter is a 'y' 
}

char MiscFunc::toLowerChar(char c)							// Returns lower case character if character is of upper case sequence
{
		if (c >= 'A' && c <= 'Z')
			return c + 32;

		return c;
}

