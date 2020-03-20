/*
TransactionStorage.cpp
Zach Partain
3-6-2020
Function deffinitions for the TransactionsStorage class
Generates fstream obgect for storing transactions and initializes accounts
*/

#include "TransactionStorage.h"
using namespace std;


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

void TransactionStorage::initializeAccount(int accountNum)
{
	accountNumber = accountNum;
}

void TransactionStorage::readAll()
{
	transactionFile.open("transactions.dat", ios::in | ios::binary);
	allTransactions.clear();
	Transaction tempTrans;
	Transaction* transptr = nullptr;
	transptr = &tempTrans;
	if (stat("transactions.dat", &results) == 0)
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
	string ch;
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
		case Transaction::Type::Fee:
			cout << "Fee";
			break;
		default:
			cout << "*Transaction type error*";
		}
		cout << "\nTransaction ammount: " << thisAccountTransactions[i].getAmount()
			<< "\nPrevious balance: " << thisAccountTransactions[i].getPrevBalance()
			<< "\nNew account balance: " << thisAccountTransactions[i].getNewBalance() << "\n\n";
	}
	cout << "\n\n\nPress \"Enter\" to exit: ";
	cin.ignore();
	getline(cin, ch);
}

void TransactionStorage::withdrawal(timeStruct timeIn, double amount, int ID, double pBal, double nBal)
{
	Transaction newTransaction(Transaction::Type::Withdrawal, timeIn, amount, ID, pBal, nBal);
	storeTrans(newTransaction);
}

void TransactionStorage::deposit(timeStruct timeIn, double amount, int ID, double pBal, double nBal)
{
	Transaction newTransaction(Transaction::Type::Deposit, timeIn, amount, ID, pBal, nBal);
	storeTrans(newTransaction);
}

void TransactionStorage::fee(timeStruct timeIn, double amount, int ID, double pBal, double nBal) {
	Transaction newTransaction(Transaction::Type::Fee, timeIn, amount, ID, pBal, nBal);
	storeTrans(newTransaction);
}

void TransactionStorage::storeTrans(Transaction transIn) {
	transactionFile.open("transactions.dat", ios::out | ios::binary | ios::app);
	//transactionFile.seekp(ios_base::end + 1);
	transIn.storeInFile(transactionFile);
	transactionFile.close();
	allTransactions.push_back(transIn);
	if (accountNumber == transIn.getAcctID()) thisAccountTransactions.push_back(transIn);
}