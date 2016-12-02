// Kyle Gray
// CS2420-001
// Program06
// Dec 1, 2016
//
// I verify that all code was written by me.


#include "Header.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <vector>
#include <time.h>
#include <stdio.h>
#include <dos.h>

using namespace std;






// The swap Function
// Purpose: Swaps two items in a vector
// Parameters: vector to be worked on, location 1, and location 2
// Returns: none
void swap(vector<int> &data, int location1, int location2) {
		int temp = data[location1];
		data[location1] = data[location2];
		data[location2] = temp;
}

/*
void insertionHelper(vector<int> &data, int location) {
	swap(data, location);
	if (location - 1 == 0 || data[location - 1] > data[location - 2]) {
		return;
	} else {
		return insertionHelper(data, location - 1);
	}

}
*/


// The insertionSort Function
// Purpose: implements insertions sort
// Parameters: vector<int> data to be worked on.
// Returns: none
void insertionSort(vector<int> &data) {
	for (int i = 1; i < data.size(); i++) {
		//cout << i << endl;
		if (data[i] < data[i - 1]) {
			int temp = data[i];
			int j = i - 1;
			while (j >= 0 && temp < data[j]) {
				data[j + 1] = data[j];
				j--;
			}
			data[j + 1] = temp;
		}
	}
}



// The partition Function
// Purpose: helper function for the quickSort function
// Parameters: vector<int> data, the lower bound of the segement to be sorted, and the upper bound
// Returns: int pivotIndex - location of pivot after sorting
int partition(vector<int> &data, int lowerBound, int upperBound) {
	int j = lowerBound - 1;
	int pivotIndex = lowerBound + ((upperBound - lowerBound) / 2);
	int pivot = data[pivotIndex];

	for (int i = lowerBound; i <= upperBound; i++) {
		if (data[i] < pivot) {
			j++;
			swap(data, i, j);
			if (j == pivotIndex) {
				pivotIndex = i;
			}
		}
	}
	swap(data, j + 1, pivotIndex);
	return j + 1;
}


// The quickSort Function
// Parameters: vector<int> of interest, int lower bound to be sorted, int upper bound to sort to
// Purpose: Implements the a QuickSort algorithm
// Returns: none
void quickSort(vector<int> &data, int lowerBound, int upperBound) {
	if (lowerBound < upperBound) {
		int x = partition(data, lowerBound, upperBound);
		if (lowerBound < x - 1) {
			quickSort(data, lowerBound, x - 1);
		}
		if (upperBound > x + 1) {
		quickSort(data, x + 1, upperBound);
		}
		
	}
}


// The shellSort Function
// Purpose: implements a shellsort algorithm
// Parameters: vector<int> of interest
// Returns: none.  Vector parameters is changed.
void shellSort(vector<int> &data) {
	int temp;
	int j;
	int gap = (data.size() / 2);
	do{
		for (int i = 0 + gap; i < data.size(); i++) {
			if (data[i] < data[i - gap]) {
				temp = data[i];
				j = i - gap;
				while (j >= 0 && temp < data[j]) {
					data[j + gap] = data[j];
					j -= gap;
				}
				data[j + gap] = temp;
			}
		}
		gap /= 2;
	} while (gap > 0);
}


// The main Function
// Purpose: simple graphic interface to implements search functions
// Parameters: none
// Returns: 0 if successful
int main() {

	// header output
	cout << "Kyle Gray" << endl;
	cout << "CS2420" << endl;
	cout << "Project05\n" << endl;
	bool again = true;

	int loopCounter = 0;

	while (again) {
		loopCounter++;
		string input;
		ifstream reader;

		// get file from user
		do {
			std::cout << "Enter the next file name you would like to use: " << std::endl;


			//save user input to input variable
			getline(cin, input);

			// try to open file
			try {
				reader.open(input);
				if (reader.fail()) {
					throw Exception(2);
				}
				// if fails, check error and throw exception message
			} catch (Exception e) {
				e.check();
			}

			// repeat to allow user to enter new file name
		} while (reader.fail());
		vector<int> insertion, shell, quick;

		int counter = 0;
		// loop as long as reader is not at end of file
		while (!reader.eof()) {
			string test;

			reader >> test;

			int value = stoi(test);
			insertion.push_back(value);
			shell.push_back(value);
			quick.push_back(value);
			counter++;


		}

		// close reader
		reader.close();
		cout << endl;



		// initialize clock variables
		
		clock_t insertionStart;
		clock_t insertionEnd;
		clock_t insertionElapsedClock;
		clock_t insertionElapsedTime;
		


		clock_t shellStart;
		clock_t shellEnd;
		clock_t shellElapsedClock;
		clock_t shellElapsedTime; 
		


		clock_t quickStart;
		clock_t quickEnd;
		clock_t quickElapsedClock;
		clock_t quickElapsedTime;


		// run insertion sort and capture times
		insertionStart = clock();
		insertionSort(insertion);
		insertionEnd = clock();
		// calculate clock and time
		insertionElapsedClock = insertionEnd - insertionStart;
		insertionElapsedTime = ((insertionElapsedClock /CLOCKS_PER_SEC) * 1000);


		// run shell sort and capture times
		shellStart = clock();
		shellSort(shell);
		shellEnd = clock();
		// calculate clock and time
		shellElapsedClock = shellEnd - shellStart;
		shellElapsedTime = shellElapsedClock / (CLOCKS_PER_SEC / 1000);

		// run quicksort and capture times
		quickStart = clock();
		quickSort(quick, 0, counter-1);
		quickEnd = clock();
		// calculate clock and time
		quickElapsedClock = quickEnd - quickStart;
		quickElapsedTime = quickElapsedClock / (CLOCKS_PER_SEC / 1000);


		cout << "SORT\t\tFILE#\tITEMS\tTOTAL CLOCK\tTOTAL TIME(ms)\tFILE NAME" << endl;
		cout << "------------------------------------------------------------------------------" << endl;
		
		cout << "Insertion\t" << loopCounter << "\t" << counter << "\t" << insertionElapsedClock << "\t\t" << insertionElapsedTime << "\t\tI" + to_string(loopCounter) << endl;
		cout << "Shellsort\t" << loopCounter << "\t" << counter << "\t" << shellElapsedClock << "\t\t" << shellElapsedTime << "\t\tS" + to_string(loopCounter) << endl;
		cout << "Quicksort\t" << loopCounter << "\t" << counter << "\t" << quickElapsedClock << "\t\t" << quickElapsedTime << "\t\tQ" + to_string(loopCounter) << endl;

// saving all results
		cout << endl;
		cout << "Saving Results" << endl;
		// saving the insertion results as .txt
		ofstream iWriter("I" + to_string(loopCounter));
		for (int i = 0; i < counter; i++) {
			iWriter << insertion[i] << endl;
		}
		iWriter.close();

		// saving the Shellsort results
		ofstream sWriter("S" + to_string(loopCounter));
		for (int i = 0; i < counter; i++) {
			sWriter << shell[i] << endl;
		}
		sWriter.close();

		// saving the Quicksort results
		ofstream qWriter("Q" + to_string(loopCounter));
		for (int i = 0; i < counter; i++) {
			qWriter << quick[i] << endl;
		}
		qWriter.close();




		cout << endl;
		cout << "Operation complete." << endl;
		// ask user if they would like to run another file
		std::cout << "Would you like to open another file?"  << endl;
		cout << "Enter 'y' for Yes or any other letter to end the program:  " << endl;
		getline(cin, input);
		// if user enters 'y' return to beginning and ask for file name.  otherwise close the program.
		if (input == "y" || input == "Y") {
		} else {
			again = false;
		}
	}
	cout << "Now closing the program..." << endl;
	std::system("pause");


	return 0;
}