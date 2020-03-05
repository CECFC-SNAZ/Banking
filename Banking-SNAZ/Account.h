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
	static int totalAccounts, totalAccountIDs;
	string name, username, password;
	int accountNumber;
	enum accountTypes
	{
		CHECKING, SAVINGS, CD, HELOC
	};
	struct accountID
	{
		accountTypes type;
		int IDnumber;
	};
	struct activeAccount
	{
		string aname, ausername, apassword;
		int aaccountNumber;
		vector<accountID> aaccountIDs;
	};
	struct accountStorage
	{
		char sname[40], suserName[40], spassword[40];
		int saccountNuber;
		accountID saccountIDs[10];
		bool filled = false;
	};
	activeAccount userAccount;
	vector<accountStorage> accountsForStorage;
	accountStorage availableAccounts[10];

public:
	Account();
	void setName();
	void setUsername();
	void setpassword();
	void setAccountNumber();
	//Read saved data from a file
	void useSaved();
	//Gathe rinformation and create a new account
	void createAccount();
	//Allow the user to sign in
	void signIn();
	//Search file for given username. Returns true if the account exists.
	bool searchUsername(string username);
	//Search file for given account username and password. Returns the account if it is found.
	void searchAccountInfo(string username, string password);
	//Add an account's info to an array for storage
	void storeAccountInfo();
	//Check for a file's existance. Returns true if the file exists and false if it does not.
	bool checkFile(string fileName);
	//Save all accounts to a file
	void saveAccounts();
	//Retrive account information from file. May not be necessary.
	void getAccountInfo();
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