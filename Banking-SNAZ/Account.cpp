/*
Account.cpp
Zach Partain
3-3-2020
Function definitions for the Account class
*/

#include "Account.h"
using namespace std;

Account::Account()
{
	name = '\0';
	username = '\0';
	password = '\0';
	accountNumber = -1;
}

void Account::useSaved()
{
	if (checkFile("userAccounts.dat"))
	{
		fstream inputFile;
		inputFile.open("userAccounts.dat", ios::in | ios::binary);
		inputFile.read(reinterpret_cast<char*>(availableAccounts), sizeof(availableAccounts));
		inputFile.close;
	}
}

void Account::createAccount()
{
	int choice;
	bool exists = true, invalid = false, exit = false;
	string tempUsername;
	accountID tempID;
	cout << "Enter your name: ";
	cin >> userAccount.aname;
	while (exists == true)
	{
		exists = false;
		cout << "Enter a new username: ";
		cin >> tempUsername;
		exists = searchUsername(tempUsername);
		if (exists)
		{
			cout << "This username already exists.";
		}
	}
	userAccount.aname = tempUsername;
	cout << "Enter a new password: ";
	cin >> userAccount.apassword;
	userAccount.aaccountNumber = totalAccounts + 1;
	totalAccounts += 1;
	while (!exit)
	{
		if (invalid)
		{
			cout << "Invalid selection.\n\n";
		}
		cout << "Which kinds of account do you want to open?\n:1 - Checking\n2 - Savings\n3 - HELOC\n4 - CD\n5 - Finished opening accounts."
			<< " Note, you may open more than \nChoice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			tempID.type = CHECKING;
			tempID.IDnumber = totalAccounts + 1;
			totalAccounts += 1;
			userAccount.aaccountIDs.push_back(tempID);
			invalid = false;
			break;
		case 2:
			tempID.type = SAVINGS;
			tempID.IDnumber = totalAccounts + 1;
			totalAccounts += 1;
			userAccount.aaccountIDs.push_back(tempID);
			invalid = false;
			break;
		case 3:
			tempID.type = HELOC;
			tempID.IDnumber = totalAccounts + 1;
			totalAccounts += 1;
			userAccount.aaccountIDs.push_back(tempID);
			invalid = false;
			break;
		case 4:
			tempID.type = CD;
			tempID.IDnumber = totalAccounts + 1;
			totalAccounts += 1;
			userAccount.aaccountIDs.push_back(tempID);
			invalid = false;
		case 5:
			exit = true;
			break;
		default:
			invalid = true;
		}
	}
}

void Account::signIn()
{
	string tempUsername, tempPassword;
	cout << "Enter your username: ";
	cin >> tempUsername;
	cout << "\nEnter your password: ";
	cin >> tempPassword;
	//Search stored files for an account with this info
}

void Account::storeAccountInfo()
{
	accountStorage storeAccount;
	strcpy(storeAccount.sname, userAccount.aname.c_str());
	strcpy(storeAccount.suserName, userAccount.ausername.c_str());
	strcpy(storeAccount.spassword, userAccount.apassword.c_str());
	storeAccount.saccountNuber = userAccount.aaccountNumber;
	for (int i = 0; i < userAccount.aaccountIDs.size() || i <= 10; i++)
	{
		storeAccount.saccountIDs[i] = userAccount.aaccountIDs[i];
	}
	storeAccount.filled = true;
	accountsForStorage.push_back(storeAccount);
}

bool Account::checkFile(string fileName)
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

void Account::saveAccounts()
{
	accountStorage saveAccounts[10];
	for (int i = 0; i < accountsForStorage.size(); i++)
	{
		saveAccounts[i] = accountsForStorage[i];
	}
	fstream storefile;
	storefile.open("UserAccounts.dat", ios::out | ios::binary);
	storefile.write(reinterpret_cast<char*>(saveAccounts), sizeof(saveAccounts));
	storefile.close;
}