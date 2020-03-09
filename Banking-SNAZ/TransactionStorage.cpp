/*
TransactionStorage.cpp
Zach Partain
3-6-2020
Function deffinitions for the TransactionsStorage class
Generates fstream obgect for storing transactions and initializes accounts
*/

#include "TransactionStorage.h"
using namespace std;

TransactionStorage::TransactionStorage()
{
	transactionFile.open("transactions.dat", ios::in | ios::binary);
}

TransactionStorage::~TransactionStorage()
{
	transactionFile.close();
}

bool TransactionStorage::checkFile(string fileName)
{
	bool check;
	fstream inputData;
	inputData.open(fileName, ios::in | ios::binary);
	if (inputData)
	{
		check = true;
	}
	else
	{
		check = false;
	}
	inputData.close();

	return check;
}

double TransactionStorage::initializeAccount(int accountNum)
{
	accountNumber = accountNum;
}

void TransactionStorage::readAll()
{
	allTransactions.clear();
	Transaction tempTrans;
	Transaction* transptr = nullptr;
	transptr = &tempTrans;
	if (stat("transactions.dat", &results))
	{
		for (int i = 0; i < results.st_size; i += sizeof(tempTrans))
		{
			transactionFile.read(reinterpret_cast<char*>(transptr), sizeof(tempTrans));
			allTransactions.push_back(tempTrans);
		}
	}
	transactionFile.close();
}

void TransactionStorage::findAccountTransactions()
{
	thisAccountTransactions.clear();
	for (int i = 0; i < allTransactions.size(); i++)
	{
		if (allTransactions[i].getAcctID() == accountNumber)
		{
			thisAccountTransactions.push_back(allTransactions[i]);
		}
	}
}

void TransactionStorage::displayAccountTransactions()
{
	for (int i = 0; i < thisAccountTransactions.size(); i++)
	{
		timeStruct time = thisAccountTransactions[i].getTime();
		cout << "Date and time of transaction: " << time.month << "-" << time.day << "-" << time.year
			<< "  " << time.hour << ":" << time.minute << "." << time.second
			<< "\nType of transaction: ";
		Transaction::Type type = thisAccountTransactions[i].getType();
		switch (type)
		{
		case Transaction::Type::Deposit:
			cout << "Deposit";
			break;
		case Transaction::Type::Withdrawal:
			cout << "Withdrawal";
			break;
		default:
			cout << "*Transaction type error*";
		}
		cout << "\nTransaction ammount: " << thisAccountTransactions[i].getAmount()
			<< "\nPrevious balance: " << thisAccountTransactions[i].getPrevBalance()
			<< "\nNew account balance: " << thisAccountTransactions[i].getPrevBalance() << "\n\n";
	}
}

void TransactionStorage::withdrawal(timeStruct timeIn, double amount, int ID, double pBal, double nBal)
{
	Transaction newTransaction(Transaction::Type::Withdrawal, timeIn, amount, ID, pBal, nBal);
	newTransaction.storeInFile(transactionFile);
}

void TransactionStorage::deposit(timeStruct timeIn, double amount, int ID, double pBal, double nBal)
{
	Transaction newTransaction(Transaction::Type::Deposit, timeIn, amount, ID, pBal, nBal);
	newTransaction.storeInFile(transactionFile);
}