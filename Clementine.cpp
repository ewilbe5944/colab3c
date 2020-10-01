//Emily Wilber
//CPSC 1071: 003
//Bug Smashers
// Sept 29, 2020

#include "Loan.h"
#include "Register.h"
#include "Retirement.h"
#include <iostream>
using namespace std;

#define TRUE 1
#define FALSE 0 

	int main() {
		//register is a keyword so make it reg
		Register reg;
		Loan loan;
		Retirement retirement; 
		int isRunning = TRUE;
	
		while(isRunning) {	
			cout << "Starting Clementine Financial Bank\r\n";
			cout << "******* Welcome to Clementine Financial *******\r\n\r\n";
			cout << "Menu:\r\n";
			cout << "\t[E] Estimate how much money you  will have at retirement\r\n\t[L] Loan Payoff Calculator\r\n\t[R] Run transaction classifier\r\n\t[Q] Quit program\r\n\r\n";
			char selection = 'a';
			cout << " Enter your choice and press enter: ";
			cin >> selection;

			if (selection == 'E' || selection == 'e') {
				//retirement
				retirement.estimateDriver();
			}
			else if (selection == 'L' || selection == 'l') {
				//loan
				loan.paymentDriver();			
			}
			else if (selection == 'R' || selection == 'r') {
				//register
				reg.processTransaction();
				isRunning = FALSE;
			}
			else if (selection == 'Q' || selection == 'q') {
				cout << "Thank you for using this program.\r\n";
				isRunning = FALSE;
			}
			else {
				cout << "This is not a valid input. Please try again.\r\n";
			}
	
		}
}
	
