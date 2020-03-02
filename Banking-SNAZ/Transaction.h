#pragma once
// Transaction.h
// Nicholas Pie
// 28 February 2020
// A class to store transactions

#ifndef TRANSACTION_H
#define TRANSACTION_H

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
	bool setAmount(double);                         // Returns false in the case of an error, otherwise returns true
	bool setAcctID(int);                            // Returns false in the case of an error, otherwise returns true

	void setType(Type typeIn) { transType = typeIn; }
	void setTime(timeStruct timeIn) { transTime = timeIn; }
	Type getType() { return transType; }
	timeStruct getTime() { return transTime; }
	double getAmount() { return transAmount; }
	int getAcctID() { return accountID; }
};

#endif TRANSACTION_H