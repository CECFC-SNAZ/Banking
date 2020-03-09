#pragma once
/*
TransactionStorage.h
Zach Partain
3-6-2020
Prototypes for the TransactionStorage class
This class stores and searches all transactions made
*/

#include "Transaction.h"
#include <sys/stat.h>
#include <iostream>
#include <string>
using namespace std;

class TransactionStorage
{
private:
	fstream transactionFile;
	vector<Transaction> allTransactions, thisAccountTransactions;
	struct stat results;
	int accountNumber;
public:
	//Open a file for use
	TransactionStorage();
	~TransactionStorage();
	//Check for a file's existence
	bool checkFile(string fileName);
	//Set the active account
	void initializeAccount(int accountNum);
	//Read all transactions from the file
	void readAll();
	//Find all transactions matching the active account
	void findAccountTransactions();
	//Display all transactions for the active account
	void displayAccountTransactions();
	//Store a withdrawal
	void withdrawal(timeStruct timeIn, double amount, int ID, double pBal, double nBal);
	//Store a deposit
	void deposit(timeStruct timeIn, double amount, int ID, double pBal, double nBal);
};