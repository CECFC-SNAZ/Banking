#pragma once
// Transaction.h
// Nicholas Pie
// 28 February 2020
// A class to store transactions

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <ctime>
using namespace std;

class Transaction {
public:
	enum class Type { Deposit, Withdrawal };
private:
	Type transType;
	time_t transTime;
	double transAmount;
	int accountID;
public:
	Transaction();
	Transaction(Type, time_t, double, int);
	bool setTransaction(Type, time_t, double, int); // Returns false in the case of an error, otherwise returns true 
	bool setAmount(double);                         // Returns false in the case of an error, otherwise returns true
	bool setAcctID(int);                            // Returns false in the case of an error, otherwise returns true

	void setType(Type typeIn) { transType = typeIn; }
	void setTime(time_t timeIn) { transTime = timeIn; }
	Type getType() { return transType; }
	time_t getTime() { return transTime; }
	double getAmount() { return transAmount; }
	int getAcctID() { return accountID; }
};

#endif TRANSACTION_H