// Transaction.cpp
// Nicholas Pie
// 28 February 2020
// Function definitions for the transaction class

#include "Transaction.h"
#include <iostream>
#include <vector>
using namespace std;

const bool debug = false;

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

void Transaction::readFromFile(fstream& fileIn) {
	fileIn.read(reinterpret_cast<char*>(this), sizeof(this));
}

void Transaction::readFromFile(ifstream& fileIn) {
	fileIn.read(reinterpret_cast<char*>(this), sizeof(this));
}

vector<Transaction> Transaction::readEntireFile(fstream& fileIn) {
	vector<Transaction> tmpTransVect;
	Transaction tmpTrans;
	try {
		while (true) {
			fileIn.read(reinterpret_cast<char*>(&tmpTrans), sizeof(tmpTrans));
			tmpTransVect.push_back(tmpTrans);
		}
	}
	catch (...) {
		return tmpTransVect;
	}
}

vector<Transaction> Transaction::readEntireFile(ifstream& fileIn) {
	vector<Transaction> tmpTransVect;
	Transaction tmpTrans;
	try {
		while (true) {
			fileIn.read(reinterpret_cast<char*>(&tmpTrans), sizeof(tmpTrans));
			tmpTransVect.push_back(tmpTrans);
		}
	}
	catch (...) {
		return tmpTransVect;
	}
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
	for (int i = 0; i < 10; i++) {
		tmpTrans.setTransaction(Transaction::Type::Deposit, { 2010 + i,3,2,10,33,37 }, 3.56, 8809567, 100, 103.56);
		tmpTransVect.push_back(tmpTrans);
	}
	for (int i = 0; i < 10; i++) {
		tmpTransVect[i].storeInFile(coolfile);  // Saves the transactions to a file
		tmpTransVect[i].setTime({ 2010,3,2,10,33,37 }); // Sets the time to something else, that way if the read fails it will return the wrong value
	}
	coolfile.close();
	coolfile.open("coolfile.dat", ios::in | ios::binary);
	tmpTransVect = tmpTrans.readEntireFile(coolfile);  // Reads the transactions back in from the file
	for (int i = 0; i < 10; i++) {
		if (tmpTransVect[i].getTime().year != 2010 + i) return false; // Making sure they're in the right order
	}
	return true;
}