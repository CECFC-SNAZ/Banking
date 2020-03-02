// Transaction.cpp
// Nicholas Pie
// 28 February 2020
// Function definitions for the transaction class

#include "Transaction.h"
#include <iostream>
using namespace std;

const bool debug = false;

Transaction::Transaction() {
	transType = Transaction::Type::Deposit;
	transTime = 0;
	transAmount = -17;
	accountID = -13;
}

Transaction::Transaction(Type type, time_t timeIn, double amount, int ID) {
	transType = type;
	transTime = timeIn;
	transAmount = amount;
	accountID = ID;
}

bool Transaction::setTransaction(Type type, time_t timeIn, double amount, int ID) {
	try {
		if (amount <= 0) throw(1);
		if (ID <= 0) throw(2);
		transType = type;
		transTime = timeIn;
		transAmount = amount;
		accountID = ID;
		return true;
	}
	catch (int e) {
		if (e == 1) {
			if (debug) cout << "\nAmount less than/equal to 0\n";
		}
		if (e == 2) {
			if (debug) cout << "\nAccount ID less than/equal to 0\n";
		}
		return false;
	}
	catch (...) {
		if (debug) cout << "\nUnknown Error\n";
		return false;
	}
}

bool Transaction::setAmount(double amount) {
	try {
		if (amount <= 0) throw(1);
		transAmount = amount;
	}
	catch (int e) {
		if (e == 1) {
			if (debug) cout << "\nAmount less than/equal to 0\n";
		}
		return false;
	}
	catch (...) {
		if (debug) cout << "\nUnknown Error\n";
		return false;
	}
}

bool Transaction::setAcctID(int ID) {
	try {
		if (ID <= 0) throw(1);
		accountID = ID;
	}
	catch (int e) {
		if (e == 1) {
			if (debug) cout << "\nID less than/equal to 0\n";
		}
		return false;
	}
	catch (...) {
		if (debug) cout << "\nUnknown Error\n";
		return false;
	}
}