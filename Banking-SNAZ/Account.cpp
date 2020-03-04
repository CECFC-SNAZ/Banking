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

void Account::createAccount()
{
	int choice;
	bool exists = true, invalid = false, exit = false;
	string tempUsername;
	activeAccount newAccount;
	cout << "Enter your name: ";
	cin >> newAccount.aname;
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
	newAccount.aname = tempUsername;
	cout << "Enter a new password: ";
	cin >> newAccount.apassword;
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
			newAccount.atypes.push_back(CHECKING);
			invalid = false;
			break;
		case 2:
			newAccount.atypes.push_back(SAVINGS);
			invalid = false;
			break;
		case 3:
			newAccount.atypes.push_back(HELOC);
			invalid = false;
			break;
		case 4:
			newAccount.atypes.push_back(CD);
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