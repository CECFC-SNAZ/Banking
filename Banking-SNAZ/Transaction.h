#pragma once
// Transaction.h
// Nicholas Pie
// 28 February 2020
// A class to store transactions + a struct to store time

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <fstream>
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
public:
	Transaction();
	Transaction(Type, timeStruct, double, int);
	bool setTransaction(Type, timeStruct, double, int); // Returns false in the case of an error, otherwise returns true 
	bool setAmount(double);                             // ^
	bool setAcctID(int);                                // ^
	bool readFromFile(fstream);                         // ^
	bool readFromFile(ifstream);                        // ^
	bool storeInFile(fstream);                          // Returns true if file already existed, returns false if not
	bool storeInFile(ofstream);                         // ^

	void setType(Type typeIn) { transType = typeIn; }
	void setTime(timeStruct timeIn) { transTime = timeIn; }
	Type getType() { return transType; }
	timeStruct getTime() { return transTime; }
	double getAmount() { return transAmount; }
	int getAcctID() { return accountID; }
};

#endif TRANSACTION_H