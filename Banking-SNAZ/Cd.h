#pragma once
// Cd.h
// Nicholas Pie
// 5 March 2020
// A class to store checking accounts

#ifndef CD_H
#define CD_H

#include "Transaction.h"
#include "BaseClass.h"
using namespace std;

class CD : public Base {
public:
	CD(double bal, int accountNumberi);
	void displayType() { cout << "CD"; }
	bool setMonthsUntilWithdrawal(int);      // Returns false in the case of an error
	bool isEarly();                          // Returns true if a withdrawal can be made without incuring an early withdrawal fee
	timeStruct getTimeStruct();              // Returns entryTime as a timeStruct
	bool withdrawal(double amount) override; // Calls withdraw from the base class, but with a check for early withdrawal

	int getMonthsUntilWithdrawal() { return monthsUntilWithdrawal; }
};

#endif CD_H