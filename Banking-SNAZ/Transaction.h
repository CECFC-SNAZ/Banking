#pragma once
// Transaction.h
// Nicholas Pie
// 28 February 2020
// A class to store transactions + a struct to store time

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <fstream>
#include <vector>
using namespace std;

struct timeStruct {
	int year = -1, month = -1, day = -1, hour = -1, minute = -1, second = -1;
};

class Transaction {
public:
	enum class Type { Deposit, Withdrawal };
private:
	Type transType;
	timeStruct transTime;
	double transAmount;
	int accountID;
	double prevBalance;
	double newBalance;
public:
	Transaction();
	Transaction(Type, timeStruct, double, int, double, double);
	bool setTransaction(Type, timeStruct, double, int, double, double); // Returns false in the case of an error, otherwise returns true 
	bool setAmount(double);                             // ^
	bool setAcctID(int);                                // ^
	void readFromFile(fstream&);
	void readFromFile(ifstream&);
	vector<Transaction> readEntireFile(fstream&);  // Returns a vector containing every transaction stored in the specified file
	vector<Transaction> readEntireFile(ifstream&); // ^
	bool storeInFile(fstream&);  // Returns true if file already existed, returns false if not
	bool storeInFile(ofstream&); // ^
	bool test(); // The test that is run at the beginning of main(), returns false in the event of an error

	void setPrevBalance(double balIn) { prevBalance = balIn; }
	void setNewBalance(double balIn) { newBalance = balIn; }
	double getPrevBalance() { return prevBalance; }
	double getNewBalance() { return newBalance; }
	void setType(Type typeIn) { transType = typeIn; }
	void setTime(timeStruct timeIn) { transTime = timeIn; }
	Type getType() { return transType; }
	timeStruct getTime() { return transTime; }
	double getAmount() { return transAmount; }
	int getAcctID() { return accountID; }
};

#endif TRANSACTION_H