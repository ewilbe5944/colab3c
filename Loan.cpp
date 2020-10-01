//Emily Wilber
//CPSC 1071: 003
//Bug Smashers
// Sept 29, 2020

#include "Loan.h"
#include <iostream>
#include <cmath>
#include <cstdio>
#include <limits>

#define TRUE 1
#define FALSE 0 
using namespace std;

	
//function for calculating the amount of interest on a monthly payment
double Loan::calculateMonthlyInterest(double air, double p) {
	return (air / 1200 * p);
}


//calculates the total interest for a loan
double Loan::calculateTotalInterest(double air, double p, int months, double monthlyPayment) {
	double sum = 0;
	int i = 0;
	double monthlyInterest = 0;

	for (i = 0; i < months; i++) {
		monthlyInterest = calculateMonthlyInterest(air, p);
		sum += monthlyInterest;
		p -= monthlyPayment - monthlyInterest;
	}
	return sum;
}


// function for calculating number of months remaining assuming compounded monthly
int Loan::paymentMonths(double p, double air, double mp) {

	int  months = 0.5 + (log(mp) - log(mp - (air / 1200.0 * p))) / log(air / 1200.0 + 1.0);
	int plusTen = 0.5 + (log(mp + 10) - log(mp + 10 - (air / 1200.0 * p))) / log(air / 1200.0 + 1.0);


	printf("%d months (%.1f years) are needed to pay your loan off.\r\n\r\n", months, static_cast<double>(months) / 12);
	printf("Did you know that if you paid an additional $10 per month, you would pay off your loan %d month(s) earlier?\r\n\r\n", months - plusTen);

	double totalInterest = calculateTotalInterest(air, p, months, mp);
	printf("The total interest paid is $%.2f and the total amount you'll pay is $%0.2f.\r\n\r\n", totalInterest, totalInterest + p);

	return months;
}

// finds input to calculate loan with
void Loan::paymentDriver() {
	//variable inputValid is initially set to false so that it goes through the while loop at least once
	//the while loop will keep prompting for input until it is valid
	//and when you make sure that it is valid, you set inputValid to true and the loop wont go again
	int inputValid = FALSE;
	char anotherLoan = 'y';
	while (anotherLoan == 'y' || anotherLoan == 'Y') {
		double monthlyPayment = 0;
		double principal = 0;
		double annIntRate = 0;
		cout << "Loan Payment Calculator\r\n";
		cout << "Please input your principal amount: ";
		cin >> principal;
		while (!inputValid) {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "This input is invalid. Try again: ";
				cin >> principal;
			}
			else {
				if (principal >= 0) {
					inputValid = TRUE;
				}
				else {
					cout << "Principal cannot be negative\r\nRe-enter principal: ";
					cin >> principal;
				}
			}

		}

		cout << "Please input your annual interest rate (in %): ";
		cin >> annIntRate;
		inputValid = FALSE;
		while (!inputValid) {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "This input is invalid. Try again: ";
				cin >> annIntRate;
			}
			else {
				if (annIntRate >= 0) {
					inputValid = TRUE;
				}
				else {
					cout << "Annual Interest Rate cannot be negative\r\nRe-enter annual interest rate: ";
					cin >> annIntRate;
				}
			}

		}

		cout << "Please input your monthly payment: ";
		cin >> monthlyPayment;
		inputValid = FALSE;
		while (!inputValid) {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "This input is invalid. Try again: ";
				cin >> monthlyPayment;
			}
			else {
				if (monthlyPayment > 0) {
					inputValid = TRUE;
				}
				else {
					cout << "Monthly payment must be positive\r\nRe-enter monthly payment: ";
					cin >> monthlyPayment;
				}
			}

		}
		cout << "\r\nCalculating...\r\n";
	}
}

