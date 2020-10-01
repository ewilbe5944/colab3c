//Emily Wilber
//CPSC 1071: 003
//Bug Smashers
// Sept 29, 2020

#ifndef REG_H
#define REG_H

#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Register {
    public:    
        Register();    
        bool readFromFile();    
        string getFileName();    
        void setFileName(string);    
        bool processTransaction();    
        void printFile();

    
    private:    
        enum Transactions {RESTAURANT, MERCHANDISE, UTILITY, COFFEESHOP, AUTOMOTIVE, DEPOSIT, OTHER};
        string printTransactionStrings[7] = {"Restaurant", "Merchandise", "Utility", "Coffeeshop", "Automotive", "Deposit", "Other" };
        string transactionStrings[7] = { "RESTAURANT", "MERCHANDISE", "UTILITY", "COFFEESHOP", "AUTOMOTIVE", "DEPOSIT", "OTHER"};
        Transactions transaction;    
        string fileName;    
        ifstream inputFile;    
        vector <double> amount;    
        vector <string> location;    
        vector <string> date;    
        vector <Transactions> transactionType;    
        //i dont know what this is but it's not in the lab instructions
        //void printEnum(Transactions);    
        string convertFromEnum(int);
        int convertToEnum(string);

//something for the file
};

#endif