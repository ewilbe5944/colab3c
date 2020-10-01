//Emily Wilber
//CPSC 1071: 003
//Bug Smashers
// Sept 29, 2020

#include "Register.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <limits>

#define TRUE 1
#define FALSE 0 
using namespace std;

Register::Register() {		
}

string Register::getFileName() {
	string fileName = "";
	cout << "\tPlease enter file name: ";
	cin >> fileName;
	return fileName;	
}

//takes in getFileName and set private var fileName to input
void Register::setFileName(string name) {
	fileName = name;
}

//returns true if it worked and false if it didn't
bool Register::processTransaction() {
	bool wasRead = false; // TEST CODE
	do {
		string locFileName = getFileName();
		setFileName(locFileName);
		inputFile.open(fileName);
		cout << "\tOpening the file <" << fileName << ">\r\n";
		
		if (inputFile) {
			readFromFile();
			printFile();
			wasRead = true; // TEST CODE
		}

		else {
			cout << "Error opening file. Please retry.\r\n"; 
		}
	} while (!wasRead /*TEST CODE*/);
	return true;
}

//use the internal private filename to read through the input file and populate the classes’ vectors to store information.
//returns back true if the file is opened and read successfully, false otherwise.
bool Register::readFromFile() {
	string dateTemp, enumTemp, locationTemp, amountTemp;
	while (inputFile >> dateTemp && inputFile >> enumTemp && inputFile >> locationTemp && inputFile >> amountTemp) {
		date.push_back(dateTemp);
		location.push_back(locationTemp);
		amount.push_back(atof(amountTemp.c_str()));
		transactionType.push_back(static_cast<Transactions>(convertToEnum(enumTemp)));
	}
	return (amount.size() >= 0);
}

//prints out the neat table
void Register::printFile() {
	cout << "Printing transaction ledger\r\n";
	for (int i = 0; i < date.size(); i++) {
		cout << " ";
		cout << setw(10) << right << date[i] << " | ";
		cout << setw(15) << right << location[i] << " | ";
		cout << setw(10) << right << amount[i] << " | ";
		cout << setw(20) << right << convertFromEnum(transactionType[i]) << "\r\n\r\n";
	}
}
	

string Register::convertFromEnum(int i) {	
	return printTransactionStrings[i];
}

int Register::convertToEnum(string s) {
	for (int i = 0; i < 7; i++) {
		if (s == transactionStrings[i]) {
			return i;
		}
	}
}

