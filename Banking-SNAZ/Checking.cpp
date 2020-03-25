// Checking.cpp
// Nicholas Pie
// 5 March 2020
// Function definitions for the checking class

#include "Checking.h"
using namespace std;

CheckingAccount::CheckingAccount(double bal, int accountNumberi) : Base(bal, accountNumberi)
{
	annualInterestRate = 0;
	overdraftfee = 0;
	overdraftInterest = 0;
	withdrawLimit = 0;
	monthlyFee = 0;
}