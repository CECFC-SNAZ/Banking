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