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
	bool exists = true;
	string tempUsername, tempPassword;
	accountStorage newAccount;
	cout << "Enter your name: ";
	cin >> newAccount.sname;
	while (exists = true)
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
	//Store new username
	cout << "Enter a new password: ";
	cin >> tempPassword;
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