#pragma once
/*
Account.h
Zach Partain
3-2-2020
Prototypes for the Account class
*/

#include "BaseClass.h"
#include "Cls.h"
#include "Checking.h"
#include "Heloc.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define elif else if

class Account
{
private:
	
	int totalAccounts, totalAccountIDs;
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
		double balance[10], amountOwed[10];
		vector<accountID> aaccountIDs;
	};
	struct accountStorage
	{
		char sname[40], suserName[40], spassword[40];
		int saccountNuber, index;
		double balance[10], amountOwed[10];
		accountID saccountIDs[10];
		bool filled = false;
	};
	activeAccount userAccount;
	vector<accountStorage> accountsForStorage;
	accountStorage availableAccounts[10];

public:
	Account();
	//Read saved data from a file
	void useSaved();
	//Gather information and create a new account (note: either createAccount or signIn is used to set the initial active account, not both)
	void createAccount();
	//Allow the user to sign in
	bool signIn();
	//Search file for given username. Returns true if the account exists.
	bool searchUsername(string username);
	//Search file for given account username and password. Returns the index of the account if it is found, or -1 if not found.
	int searchAccountInfo(string username, string password);
	//Add an account's info to an array for storage
	void storeAccountInfo();
	//Check for a file's existence. Returns true if the file exists and false if it does not.
	bool checkFile(string fileName);
	//Save all accounts to a file
	void saveAccounts();
	//Access user's banking accounts (Most user input will be handled here)
	int accessAccounts();
};