#pragma once
// Checking.h
// Nicholas Pie
// 5 March 2020
// A class to store checking accounts

#ifndef CHECKING_H
#define CHECKING_H

#include "BaseClass.h"
#include "Transaction.h"
using namespace std;

class CheckingAccount : public Base {
private:
	static float annualInterestRate;
	double overdraftfee = 0;
public:
	CheckingAccount(double bal, int accountNumberi);
	Transaction Deposit(double);
	Transaction Withdrawal(double);
	//cout account type
	void displayType()
	{
		cout << "Checking";
	}
};

#endif CHECKING_H