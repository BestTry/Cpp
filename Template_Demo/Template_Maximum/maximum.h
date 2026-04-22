// Lifted from Deitel and Deitel ' C++20 For Programmers ' page 137
// Fig. 5.13: maximum.h file
// Function template maximum header.
// Function code was contained in this separate header file to simplify readability of main()

// The 'typename' is a keywork. I think T can be replace with any name like 'Type"
// or template(<class> - Defining maximum function for all types T
template <typename T> 
T maximum (T value1, T value2, T value3)
{	
	// Intializes maximumValue to value1 - (Assumes value1 is maximum to start)
	T maximumValue{ value1 }; 	
	
	// Determine if value2 is larger than maximumValue, replace maximumValue with value2
	if (value2 > maximumValue)
		maximumValue = value2;
	
	
	// Determine if value3 is larger than maximumValue, replace maximumValue with value3
	if (value3 > maximumValue)
		maximumValue = value3;
	
	// In any case return maximumValue from this generic / template function
	return maximumValue;
}	