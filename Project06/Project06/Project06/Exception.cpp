// Kyle Gray
// CS2420-001
// Program06
// Dec 1, 2016
//
// I verify that all code was written by me.
#include "Exception.h"



//The Exception Constructor
// Purpose: Exception Constructor
// Parameters: none
// Returns: none
Exception::Exception() {
}

// The Exception Paramatized Constructor
// Purpose: creates error exception of the given type
// Parameters: int _errorcode
// Returns: none
Exception::Exception(int _errorCode) {
	errorCode = _errorCode;
}


// The Exception Deconstructor
// Purpose: deconstructor
// Parameters: none
// Returns: none
Exception::~Exception() {
}


// The check Method
// Purpose: checks returned exception code and outputs error message
// Parameters: none
// Returns: none
void Exception::check() {
	if (errorCode == 0) {
		cout << "Error: end of file" << endl;
	} else if (errorCode == 1) {
		cout << "Error: read error" << endl;
	} else {
		cout << "Error: could not open the file" << endl;
	}
}
