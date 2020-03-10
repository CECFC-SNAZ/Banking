// Transaction.cpp
// Nicholas Pie
// 28 February 2020
// Function definitions for the transaction class + the getTime() function

#include "Transaction.h"
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

const bool debug = false;

timeStruct _getTime(){
	time_t t = time(0);
#define _CRT_SECURE_NO_WARNINGS
	tm* now = localtime(&t);
#undef _CRT_SECURE_NO_WARNINGS
	return { now->tm_year + 1900, now->tm_mon + 1, now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec };
}

Transaction::Transaction() {
	transType = Transaction::Type::Deposit;
	transTime = { 0,0,0,0,0,0 };
	transAmount = -17;
	accountID = -13;
	prevBalance = -35;
	newBalance = -52;
}

Transaction::Transaction(Type type, timeStruct timeIn, double amount, int ID, double pBal, double nBal) {
	transType = type;
	transTime = timeIn;
	transAmount = amount;
	accountID = ID;
	prevBalance = pBal;
	newBalance = nBal;
}

bool Transaction::setTransaction(Type type, timeStruct timeIn, double amount, int ID, double pBal, double nBal) {
	try {
		if (amount <= 0) throw(1);
		if (ID <= 0) throw(2);
		transType = type;
		transTime = timeIn;
		transAmount = amount;
		accountID = ID;
		prevBalance = pBal;
		newBalance = nBal;
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
		return true;
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
		return true;
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

void Transaction::readFromFile(fstream& fileIn) {
	fileIn.read(reinterpret_cast<char*>(this), sizeof(this));
}

void Transaction::readFromFile(ifstream& fileIn) {
	fileIn.read(reinterpret_cast<char*>(this), sizeof(this));
}

bool Transaction::storeInFile(fstream& fileIn) {
	bool didFileExist = false;
	if (fileIn) didFileExist = true;
	fileIn.write(reinterpret_cast<char*>(this), sizeof(this));
	return didFileExist;
}

bool Transaction::storeInFile(ofstream& fileIn) {
	bool didFileExist = false;
	if (fileIn) didFileExist = true;
	fileIn.write(reinterpret_cast<char*>(this), sizeof(this));
	return didFileExist;
}

bool Transaction::test() {
	fstream coolfile;
	coolfile.open("coolfile.dat", ios::out | ios::binary);
	vector<Transaction> tmpTransVect;
	Transaction tmpTrans;
	for (int i = 0; i < 10; i++) { // Initializes the transaction vector
		tmpTrans.setTransaction(Transaction::Type::Deposit, { 2010 + i,3,2,10,33,37 }, 3.56, 8809567, 100, 103.56);
		tmpTransVect.push_back(tmpTrans);
	}
	for (int i = 0; i < 10; i++) {
		tmpTransVect[i].storeInFile(coolfile);  // Saves the transactions to a file
		tmpTransVect[i].setTime({ 2000,3,2,10,33,37 }); // Sets the time to something else, that way if the read fails it will return the wrong value
	}
	coolfile.close();
	coolfile.open("coolfile.dat", ios::in | ios::binary);
	tmpTransVect.erase(tmpTransVect.begin(), tmpTransVect.end());
	for (int i = 0; i < 10; i++) { // Reads the transactions back in from the file
		tmpTrans.readFromFile(coolfile);
		tmpTransVect.push_back(tmpTrans);
	}
	for (int i = 0; i < 10; i++) {
		if (tmpTransVect[i].getTime().year != 2010 + i) return false; // Making sure they're in the right order
	}
	return true;
}