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
	//Set the account number for the class
	void setAccountNumber(int number)
	{
		accountNumber = number;
	}
	//Check for a file's existence
	bool checkFile(string fileName);
	//Set the active account
	void initializeAccount(int accountNum);
	//Read all transactions from the file
	void readAll();
	//Find all transactions matching the active account
	void findAccountTransactions(int num);
	//Display all transactions for the active account
	void displayAccountTransactions();
	//Store a withdrawal
	void withdrawal(timeStruct timeIn, double amount, int ID, double pBal, double nBal);
	//Store a deposit
	void deposit(timeStruct timeIn, double amount, int ID, double pBal, double nBal);
	//Store a fee
	void fee(timeStruct timeIn, double amount, int ID, double pBal, double nBal);
	//Store a payment
	void payment(timeStruct timeIn, double amount, int ID, double pBal, double nBal);
	//Return the time of the first transaction made in an account
	timeStruct getFirstTime()
	{
		timeStruct retval;
		if (!thisAccountTransactions.empty())
		{
			retval = thisAccountTransactions[0].getTime();
		}
		return retval;
	}
	//Returns the number of withdrawals made in an account
	int numberOfWithdrawals();
private:
	void storeTrans(Transaction transIn);
};