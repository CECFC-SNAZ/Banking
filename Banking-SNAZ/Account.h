#pragma once
/*
Account.h
Zach Partain
3-2-2020
Prototypes for the Account class
*/

#include "BaseClass.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Account
{
private:
	string name, username, password;
	int accountNumber;
	enum accountTypes
	{
		Checking, saving, CD, HELOC
	};
	struct accountStorage
	{
		char sname[40], suserName[40], spassword[40];
		int saccountNuber;
		accountTypes types[40];
	};

public:
	Account();
	void setName();
	void setUsername();
	void setpassword();
	void setAccountNumber();
	void createAccount();
	//Allow the user to sign in
	void signIn();
	//Search file for given username. Returns true if the account exists.
	bool searchUsername(string username);
	//Search file for given account username and password. Returns the account if it is found.
	accountStorage searchAccountInfo(string username, string password);
	//Store vital account information in a file
	void storeAccountInfo(accountStorage);
	//Retrive account information from file. May not be necessary.
	accountStorage getAccountInfo();
	//Access user's banking accounts (Most user input will be handled here)
	void accessAccounts();
	string getName() const
	{
		return name;
	}
	string getUsername() const
	{
		return username;
	}
	string getPassword() const
	{
		return password;
	}
	int getAccountNumber() const
	{
		return accountNumber;
	}

};