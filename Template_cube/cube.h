// Modified the template concept presented in textbook shown
// below to demonstrate a template with a cube function instead
//
// Lifted from Deitel and Deitel ' C++20 For Programmers ' page 137
// Fig. 5.13: maximum.h file
// Function template maximum header.
// Function code was contained in this separate header file to simplify readability of main()

// The 'typename' is a keywork. I think T can be replaced with any name like 'Type"
// or template(<class> - Defining maximum function for all types T
template <typename T> 
T cube (T number)
{	
	// Calculate the cubed value of the given number
	T cubedNumber = number * number * number; 	
	
	// Return the cubed value of the provide number with this generic / template function
	return cubedNumber;
}	