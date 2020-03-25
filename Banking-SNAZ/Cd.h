#pragma once
// Cd.h
// Nicholas Pie
// 5 March 2020
// A class to store checking accounts

#ifndef CD_H
#define CD_H

#include "BaseClass.h"
#include <iostream>
using namespace std;

class CD : public Base {
private:
	timeStruct matureTime;
	bool depositWithdrawal;
	int timesInterestApplied;
public:
	CD(double bal, int accountNumberi, int innterestTimes);
	void displayType() { cout << "CD"; }
	bool setMonthsUntilWithdrawal(int);      // Returns false in the case of an error
	bool isEarly();                          // Returns true if a withdrawal can be made without incuring an early withdrawal fee
	timeStruct getTimeStruct();              // Returns entryTime as a timeStruct
	bool withdrawal(double amount) override; // Calls withdraw from the base class, but with a check for early withdrawal

	int getMonthsUntilWithdrawal() { return monthsUntilWithdrawal; }
	void menu();
	//Checks to see if interest should be applied, and applies it if necessary. Only applies interest once.
	void applyInterest();
	int getTimesInterestApplied() const
	{
		return timesInterestApplied;
	}
};

#endif CD_H