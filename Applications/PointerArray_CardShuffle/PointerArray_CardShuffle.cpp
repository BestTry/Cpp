// PointersArraysCardshuffle.cpp : Code Example lifted from Dietel "How to Program" 4th edition, Exercise / or  / Textbook Example - Chapter 05 - Arrays of Pointers
// Code shows how arrays are passed to their funtions using their pointers.  In C++, arrays can not be passed but their pointers are able to be passed
//
// Description of Program: Shuffles Deck of Cards and Deal the Deck using Arrays of Pointers..........................
// Significant example of using the legacy method of implementing string arrays using character pointers!
// Significant example of outputing in multiple column within the display console
//
// Additonal Code Description : Steps Enumerated 
// 1 - Initialize suit array
// 2 - Initialize face array
// 3 - Initialize deck array
// 4 - Shuffle the deck
// 5 - Deal the 52 cards
// 						
						// Below is what is known as the Preprocessor Directives 
						// The Preprocessor Directives: 							
						//
#include <iostream> 	// Part of the standard library  -  Used for cout, cin, cerr  ( That is the  reason for brackets < > )
#include <string>		// Part of the standard library  - 'string' class is req to be included as the new way of using strings as opposed the old char sequence
#include <ctime>		// Required to implement date and time functions

						// Functions within the standard library are as follows:
						// Since classes below are part of C++ stadard library < > are placed around them
#include <cmath>		// Enables the use of the "pow" function with the math library
#include <thread>		// std::this_thread::sleep_for(std::chrono::seconds(XX) << endl;
#include <chrono>		// std::chrono::seconds(XX)
#include <iomanip>		// Required to utilize parameterized stream manipulator ie. calling setprecision(3) & fixed functions
#include <cstdlib>		// Required to implement the rand() function; Contains function prototype for the rand()  & srand() function
#include <ctime>		// Required to implement the time(0) function providing a number to seed rand() using srand(): srand( time( 0 )  << endl;
					// Arguement (0) yields an interger value of the calendar in seconds

						// The double colons is defined as the "Scope Resolution Operator"
using std::cout;		// Console output
using std::cin;			// Console input
using std::endl;		// End of Line - Clears output buffer and terminates with a new-line character
using std::fixed;		// Both 'fixed' & 'showpoint' are nonparamatized stream manipulators that Do Not require the <iomanip> header file
using std::left;		// Justify console output left
using std::right;		// Justify console output right
using std::pow;			// Standard Library Function pow(x,y) definded as x raised to the y power
using std::setw;		// Assure #include <iomanip> is included which requires a parameterized stream manipulator
using std::setprecision;// setprecision(2)indicates a double variable value should be printed with 2 digits to the right of the decimal point

using namespace std;


#define _win32_winnt 0x0500		// ##### Necessary for the getconsolewindow() function to work! - Code works for  running this program on windows 2000 or higher			
#include <windows.h>    		// ................................................................................................................................

// ...............................................................   Function Prototype Declaration Code   ........................................................
								// Shuffle takes a two dimensional integer array;  Previous version of statement below: < void shuffle(int[0][13]); > was legal
void shuffle(int[4][13]);		// shuffle deck of cards with 4 string array suites and 13 face cards (The first element is a character to the start of the string
void deal(const int[4][13], const char* [], const char* []);


int main()									// Function tmain(...) begins program execution - Entry point for the program
{
	// ##############################################################
	// Modify position and size of Console Application Window
	HWND console = GetConsoleWindow();		// Get the console handle
	RECT r;									// Stores the console's current dimensions
	GetWindowRect(console, &r);				// MoveWindow(window_handle, x, y, width, height, redraw_window);											
	MoveWindow(console, 600, 400, 1020, 400, true);
	// ###############################################################



// 
	// The "main" block of code begins !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	// Initialize suit array with 4 pointers of string constants begining with the first character of each string in element[0] 
	// Element[0] points to the first chararcter of the string.  AND note that each string ends with the '/0' null character
	// Arrays may contain pointers. Legacy data structure: Array of strings in C++ => a string is a pointer to its first character.
	// Each entry in an array of strings is actually a POINTER (address) to the first character of a string at some memory location.
	// The (char*) portion of the statement indicates that each element of the array suit is of type POINTER to char and the four
	// values to be placed into the array are "Hearts", "Diamonds", "Clubs", "Spades" Each of these is stored in memory with a null
	// terminated character string that is one character longer in length than the number of charactes between the quotes. It may appear 
	// that these strings are stored in the array but in fact only POINTERS are stored in the corresponding array.  And each POINTER pointer
	// points to the first character of its corresponding string!  Even thought the suit array is of fixed size, it provides access 
	// (pointers)/addresses) of character strings of any length.

	const char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };
	// Initialize Face array with 13 pointers of string constants begining with the first character of each string in element[0]. 
	// Eement[0] points to the first chararcter of the string.  AND note that each string ends with the '/0' null character.
	// Read the above array description for a better understanding of how this works in the C++ language.
	const char* face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
	int deck[4][13] = { 0 };	// Declare/Init array elements with contents of 0; Will be populated with cards ranging with interger values from 1 to 52	
	srand(time(0)); 			// Seed random-number generator with present time

	shuffle(deck);
	deal(deck, face, suit);
	cout << "\n\n" << endl;

	system("pause");
	return 0; 					// Indicates successful termination
}								// End of main

								// .......................................................   Function Description Code   ................................................................


void shuffle(int wDeck[][13])// Shuffle all 52 cards using the random function srand() in deck		
{
	int row;
	int col;
	// Find a slot for each of the 52 card numbers (Looking for an empty element, content = 0 in all randomly selected rows and columns
	for (int card = 1; card <= 52; card++)
	{
		do
		{
			// rand() returns value between 0 and 32767 minimum which could be more: specified by RAND_MAX;
			row = rand() % 4;		// Using operand %4 gives values between 0 => 3
			col = rand() % 13;		// Using operand %13 give values between 0 => 12
									// Looking for an slot/element that has not been populated yet
		} while (wDeck[row][col] != 0);
		// At this point a row/column combination has found an empty element in the wDeck array:  wDeck[row][column] == 0
		// So assign the present card number to the wDeck array empty element with these row, column indices
		wDeck[row][col] = card;
	}								// The element (with present row, col) now contains the present card number
}									// At this point each row and column of the wDeck two dimensional array has a card number

									// Deal - Display the deck of all 52 shuffled cards
void deal(const int wDeck[][13], const char* wFace[], const char* wSuit[])
{
	cout << "\n\n >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   Cards Shuffled / Deck Dealt   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n" << endl;
	
	for (int card = 1; card <= 52; card++)
	{							// Find suit and face for each card by looping throught all 52 cards
		for (int row = 0; row <= 3; row++)
		{						// Suit for loop: "Hearts", "Diamonds", "Clubs", "Spades" 
			for (int col = 0; col <= 12; col++)
			{					// Face card loop: "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"  
				if (wDeck[row][col] == card)
				{				// Display card suit/face if wDeck[row,col] has the card number
								// When dard number is found with the row/col combination
								// Display the row/col Suit-Face combination for this card
								// The "setw" together with right/left sandwiches the "of" with the Face and Suit of the card description
					if (card == 1) { cout << " "; } // Account for the first column left shift

					cout << setw(5) << right << wFace[col] << " of "
						<< setw(8) << left << wSuit[row];

					if (card % 4 == 0)				// Four cards existing in row here, therfore go to next line before entering the loop
					{
						cout << "\n ";
					}
					else
						if (card % 4 == 3)			// Three cards existing in row here
						{
							cout << "\t\t\t";
						}
						else
							if (card % 2 == 0)		// Two cards existing in row here
							{
								cout << "\t\t     ";
							}
							else
								if (card % 2 == 1)	// One card existing in row here
								{
									cout << "\t         ";
								}
					//
					//
					//	if (card %2 == 0)			// Code for two column output
					//		{ cout << "\n "; }
					//	else	
					//		{ cout << "\t"; }	
				}	// end if
			}
		}
	}
}

/*

|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|
01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
		  |         |         |         |         |         |         |         |         |
		  10        20        30        40        50        60        70        80        90
*/
