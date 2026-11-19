// FileOps_WriteData - File_Operations - Writing data to a file. Code functionality lifted from 
// program 12-1 of textbook C++ "From Control Structures Through Objects" by author 'Tont Gaddis'
//
// 
// 					//      *** Preprocessor Directives ***
//                  // Directive #include causes another file to be included
#include <iostream>	// Account for input-output stream library functions
#inclusw <iomanip>	// Provides stream manipulators to control formatting of input and output
#include <format>   // Used for displaying text with format syntax
#include <ifstream>	// Input File Stream used only to read data from files into memory
#include <ofstream> // Output File Stream used to create files and write data to them
#include <fstream>	// Used create files, read and write data to them - Requires 2 arguments
#include <string>	// Note the quotes around the 'Non-standard' class       
//					// 	
/*	Notes 
	When used by itself, the 'ios::out flag causes the file contents to be deleted if
	the file already exists. When used with the 'ios::in' flag, however, the files's
	existing contents are preserved. If the file does not already exist, it will be 
	created. 
	
	The data filer object can be opened in output and input modes at the same time:
	Example: [dataFile.open("info.txt*, ios::in | ios::out);] using the or operator '|'
	
	If the ios::out flag is left alone without ios::app when attempting to append data
	to the file the contents will be deleted!  Only the second attempt data will be 
	added to the file with the original contents lost/deleted
	
	Checking if a file exist Before writing to a file, check if it exist by attempting to 
	open the file for input (ios::in) [ dataFile.open("fileName.txt", ios::in]. If the 
	file doesnot exist the open operation will fail. In this case create the file by 
	opening it for output > Create the file [dataFile.open("fileName.txt:, ios::out);]
	
	File stream objects may be passed to functions, but only by its reference. Use the 
	syntax reference '&" before the object name.within the function parameter list.
	The code below using an file stream object is passed by referece to the function
	*/
//					
using std::format;	// Option: Could have used general: 'using namespace std;'
using std::cin;     // Part of of the input-output stream library
using std::cout;	// Function definitions use 'Scope Resolution" operator 
using std::endl;	// Scope resolution operator < :: > is used to explicitly 
					// specify the scope in which an identifier is defined.
					// Identifiers: (variable, function, class, enum, etc.)
					// It helps the compiler disambiguate names when the same
					// dentifier exists in multiple scopes, and it can also
					// be used to access members without creating an object.
//
//                     ***** Function Declarations / Prototypes *****
//
	bool openFile(fstream &, string); 			// Included for stream object reference passing
	void showFileContents(fstream &);			// See code below for function definitions
//	
int main()
{
	fstream dataFile;							// Create a File Stream object - "dataFile"
	dataFile.open("demofile.txt", ios::out);	// Name dataFile object "demofile" & designate as mode output 
	cout << format(" 'File Stream object '{}' is created and opened, named {} \n", "dataFile", "demofile");
	cout << format(" Presently writing data to the dataFile file object: {}\n", "demoFile");
	dataFile << "Ben\n";						// Write to line 1
	dataFile << "Don\n";						// Write to line 2
	dataFile << "Tom\n";						// Write to line 3
	dataFile << "Joe\n";						// Write to line 4
	dataFile << "\n\n";							// Write to line 5
	dataFile.close();							// fstream file object 'dataFile' is closed
	cout << format(" 'File Stream object '{}' is closed\n", "dataFile');
	//											// Open fstream file object again for appending data
	dataFile.open("demofile.txt", ios::out | ios.app);	
	cout << format(" 'File Stream object '{}' is opened again for appending\n", "dataFile');
	cout << format(" Presently writing additional data (appending) to the dataFile file object named: {}\n", "dataFile");
	dataFile << "Tim\n";						// Write to line 2
	dataFile << "Dan\n";						// Write to line 3
	dataFile.close();							// fstream file object 'dataFile' is closed
	cout << endl;								// Verify file's existence before attempting to open it
	cout << "Next, Demonstrate checking if a file exists before opening it\n";
	string fileName = "testfile.txt;
	data.File.open(fileName, ios::in);			// Note using 'in' mode for testing file existence
	if (dataFile.fail()) {
		cout << format( " The file {} does not exist, so creating it\n", fileName);
		fstream dataaFile;
		dataFile.open(fileName, , ios::out);
		cout << " Processing the file here\n";
	}
	else {
		cout << " The file does exist, so continue processing the file\n";
		cout << " Processing the file here\n";
	}
	dataFile.close();
	cout << endl;		
	cout << " Next demonstrate file stream object formatting data with specified precision\n";
	double num 3.1415926535;
	fstream dataFile;
	dataFile.open(("numfile", ios::out);			// Open a file file in output mode
	dataFile << fixed;								// Format for fixed-point notation
	dataFile << nmm << endl;
	dataFile << setprecision(4);					// The #include <iomanip> above is required 
	dataFile << nmm << endl;						// to implement the setprecision function
	dataFile << setprecision(3);
	dataFile << nmm << endl;
	dataFile << setprecision(1;
	dataFile << nmm << endl;
	dataFile << setprecision(1);
	dataFile << nmm << endl;
	dataFile.close();
	cout << endl;
//													// Code demo of writing data to a file:
													// Declare and define table
	const int rows =3;								// Rows to write
	const int cols = 3;								// Cols to write
	int numTbl[rows][cols] = 	
	{ 
		897, 5, 837,
		34, 7, 1623,
		390, 3456, 12
	}; 
	// ????? Why Did not have to use syntax [  fstream outfile  ]  ???????
	fstream outFile("numTble", ios::out);			// Create a File Stream object - "outFile" and name the file
													// Write three rows of numbera in a field of 8 character spaces
	for (int row = 0; row < rows; row++) {			// The "setw(8) functions sets width of output field
		for (int col = 0; col < cols; col++)		// The #include <iomanip> is required for setw(), setfill() functions
			outFile << setfill('-') << setw{8) << numTbl[row][col];
		}		
	outFile.close();
	cout << " Done writing data to a 3 x 3 row / column table" ]\n;
	cout << endl;
//													// Demo how file stream objects may be passed by reference to functions
//
	fstream dataFile;
	
	if (openFileIn(dataFile,"demofile.txt")) {
		cout << format(" The 'dataFile' {} opened successfully\n", "demofile.txt");
		cout << format(" Presently reading data from the {} file\n", "demofile.txt");
		showContents(dataFile);
		cout << " Completed code demo: Calling a function by passing a file stream object\n");
	e
	
   	cout << " \t\t  ***  Goodbye!  *** \n\n";
	cout << endl << endl << endl;
	system("pause>0");
	return 0;
}													// End of 'main' function
//
//                     						***** Function Definitions *****
//															
/*
	Function: 'openFileIn' Accepts a reference to an fstream object as an argument. The file is opened for input. 
	The file is opened for input. The function returns true upon success. False upon failure.

	Function: 'showContents' Accents an fstream reference as its argument. Uses a loop to readeach name from the 
	file and and displays it onthe screen.	
*/
	bool openFile(fstream &, string fileName) {
	file.open(fileNmae, ios::in);
		if (file.fail()) {
			cout " File failed to open\n";
			return false;
		}
	else {
			cout << "File opened successfully\n";
			return true;
		}
	}
//
	void showFileContents(fstream & file) {
		string line;
		while (file >> line) {
			cout >> line;	
			cout << line << endl;
		}
	}
		