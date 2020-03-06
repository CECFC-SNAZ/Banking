// Checking.cpp
// Nicholas Pie
// 5 March 2020
// Function definitions for the checking class

#include "Checking.h"
using namespace std;

CheckingAccount::CheckingAccount() {
	annualInterestRate = 0;
}

Transaction CheckingAccount::Deposit(double inp) {
	Transaction tmpTrans;
	if (inp <= 0) tmpTrans.setTransaction(Transaction::Type::Deposit, getTime(), 0, 0, get_balance(), get_balance());
	else tmpTrans.setTransaction(Transaction::Type::Deposit, getTime(), inp, 0, get_balance(), get_balance() + inp);
	return tmpTrans;
}

Transaction CheckingAccount::Withdrawal(double inp) {
	Transaction tmpTrans;
	if (inp > withdrawLimit or inp > get_balance() or inp <= 0) {
		tmpTrans.setTransaction(Transaction::Type::Withdrawal, getTime(), 0, 0, get_balance(), get_balance());
	}
	else {
		tmpTrans.setTransaction(Transaction::Type::Withdrawal, getTime(), inp, 0, get_balance(), get_balance() - inp);
	}
	return tmpTrans;
}