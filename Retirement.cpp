//Emily Wilber
//CPSC 1071: 003
//Bug Smashers
// Sept 29, 2020

#include "Retirement.h"
#include <iostream>
#include <cmath>
#include <cstdio>
#include <limits>

#define TRUE 1
#define FALSE 0 
using namespace std;

//calculates earnings

double Retirement::estimateEarnings(int ageCurrent, int ageRetired, double moneySaved, double monthlyContribution, double annualReturn) {
	for (int months = 0; months < (ageRetired - ageCurrent) * 12; months++) {
		moneySaved += moneySaved * static_cast<double>(annualReturn) / 1200;
		moneySaved += static_cast<double>(monthlyContribution);
	}
	return moneySaved;
}

//function to estimate savings at retirement
void Retirement::estimateDriver() {
	int ageCurrent = 0;
	int ageRetired = 0;
	double moneySaved = 0;
	double monthlyContribution = 0;
	double annualReturn = 0;
	int inputValid = FALSE;
	char anotherEstimate = 'y';

	while (anotherEstimate == 'y' || anotherEstimate == 'Y') {
		cout << "Estimate savings at retirement\r\nDisclaimer: This is only a rough estimate!\r\n\r\n";
		cout << "Enter your current age in years: ";
		cin >> ageCurrent;
		inputValid = FALSE;
		while (!inputValid) {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "This input is invalid. Try again: ";
				cin >> ageCurrent;
			}
			else {
				if (ageCurrent > 0) {
					inputValid = TRUE;
				}
				else {
					cout << "Age cannot be 0 or less\r\nRe-enter age in years: ";
					cin >> ageCurrent;
				}
			}
		}

		cout << "Enter your target retirement age: ";
		cin >> ageRetired;
		inputValid = FALSE;
		while (!inputValid) {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "This input is invalid. Try again: ";
				cin >> ageRetired;
			}
			else {
				if (ageRetired > ageCurrent) {
					inputValid = TRUE;
				}
				else {
					cout << "Age cannot be less than or equal to current age\r\nRe-enter retirement age in years: ";
					cin >> ageRetired;
				}
			}
		}

		cout << "How much have you saved towards retirement?: ";
		cin >> moneySaved;
		inputValid = FALSE;
		while (!inputValid) {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "This input is invalid. Try again: ";
				cin >> moneySaved;
			}
			else {
				if (moneySaved >= 0) {
					inputValid = TRUE;
				}
				else {
					cout << "You cannot have negative savings\r\nRe-enter savings: ";
					cin >> moneySaved;
				}
			}
		}

		cout << "Enter your monthly contribution to retirement: ";
		cin >> monthlyContribution;
		inputValid = FALSE;
		while (!inputValid) {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "This input is invalid. Try again: ";
				cin >> monthlyContribution;
			}
			else {
				if (monthlyContribution > 0) {
					inputValid = TRUE;
				}
				else {
					cout << "You must contribute more than $0 per month\r\nRe-enter monthly contribution: ";
					cin >> monthlyContribution;
				}
			}
		}

		cout << "Enter the estimate annual return on investment (in percent): ";
		cin >> annualReturn;
		inputValid = FALSE;
		while (!inputValid) {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "This input is invalid. Try again: ";
				cin >> annualReturn;
			}
			else {
				if (annualReturn >= 0) {
					inputValid = TRUE;
				}
				else {
					cout << "Annual Return cannot be negative\r\nRe-enter annual return: ";
					cin >> annualReturn;
				}
			}
		}

		double earnings = estimateEarnings(ageCurrent, ageRetired, moneySaved, monthlyContribution, annualReturn);

		printf("Estimated retirement savings: $%0.2f\r\n", earnings);
		cout << "Estimated retirement growth: $" << earnings - moneySaved - (monthlyContribution * 12) * (ageRetired - ageCurrent) << "\r\n";

		// ask use if another estimate is desired and validate response
		inputValid = FALSE;
		while (!inputValid) {
			cout << "Calculate another estimate? (y/n): ";
			cin >> anotherEstimate;
			if ((anotherEstimate == 'y') || (anotherEstimate == 'Y') || (anotherEstimate == 'n') || (anotherEstimate == 'N')) {
				inputValid = TRUE;
			}
		}

	}

}