// Source.cpp
// Team SNAZ
// 2 March 2020
// Banking program


#include "Transaction.h"
#include "BaseClass.h"
#include "Account.h"
#include <iostream>
#include "Cls.h"
#include <string>
using namespace std;

const bool debug = false;

int main() {
	if (debug) { // If debug is set to true, it will run a test to make sure everything is working properly - Nick
		Transaction tmpTrans;
		if (not tmpTrans.test()) cout << "Error with transaction file I/O\n";
	}

	bool valid = true, exit = false;
	int choice;
	Account account;
	while (!exit)
	{
		do
		{
			if (account.checkFile("userAccounts.dat"))
			{
				account.useSaved();
			}
			if (!valid)
			{
				cout << "Invalid selection.\n\n";
			}
			cout << "1 - Sign in\n2 - Create new account\n3 - Exit program\nChoice: ";
			cin >> choice;
			switch (choice)
			{
			case 1:
				if (account.signIn())
				{
					account.accessAccounts();
				}
				valid = true;
				break;
			case 2:
				account.createAccount();
				account.accessAccounts();
				valid = true;
				break;
			case 3:
				valid = true;
				exit = true;
				break;
			default:
				valid = false;
			}
		} while (!valid);
	}
	return 0;
}