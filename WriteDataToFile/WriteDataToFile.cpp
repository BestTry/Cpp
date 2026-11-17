// WriteDataToFile - File_Operations - Writing data to a file. Code functionality lifted from 
// program 12-1 of textbook C++ "From Control Structures Through Objects" by author 'Tont Gaddis'
//
// 
// 					//      *** Preprocessor Directives ***
//                  // Directive #include causes another file to be included
#include <iostream>	// Account for input-output stream library functions
#include <format>
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
	dataFile << setprecision(4);
	dataFile << nmm << endl;
	dataFile << setprecision(3);
	dataFile << nmm << endl;
	dataFile << setprecision(1;
	dataFile << nmm << endl;
	dataFile << setprecision(1);
	dataFile << nmm << endl;
	dataFile.close();
	
	
   	cout << " \t\t  ***  Goodbye!  *** \n\n";
	cout << endl << endl << endl;
	system("pause>0");
	return 0;
}
+