//Emily Wilber
//CPSC 1071: 003
//Bug Smashers
// Sept 29, 2020

#ifndef LOAN_H
#define LOAN_H
class Loan { 
    public: 
        double calculateMonthlyInterest(double, double);
        double calculateTotalInterest(double, double, int, double);
        void paymentDriver(); 

    private: 
        int paymentMonths(double, double, double);
    
};
    #endif