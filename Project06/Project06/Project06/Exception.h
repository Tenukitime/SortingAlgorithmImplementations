// Kyle Gray
// CS2420-001
// Program06
// Dec 1, 2016
//
// I verify that all code was written by me.


#pragma once

#include <iostream>

using namespace std;


class Exception {
private:
	int errorCode;
public:
	Exception();
	Exception(int _errorCode);
	~Exception();
	void check();
};

