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
	};

public:
	Account();
	void setName();
	void setUsername();
	void setpassword();
	void setAccountNumber();
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