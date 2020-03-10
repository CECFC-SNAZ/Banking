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
	if (checkFile("userAccounts.dat"))
	{
		useSaved();
	}
	else
	{
		totalAccounts = 0;
		totalAccountIDs = 0;
	}
}

void Account::useSaved()
{
	if (checkFile("userAccounts.dat"))
	{
		fstream inputFile;
		inputFile.open("userAccounts.dat", ios::in | ios::binary);
		inputFile.read(reinterpret_cast<char*>(availableAccounts), sizeof(availableAccounts));
		inputFile.read(reinterpret_cast<char*>(totalAccounts), sizeof(totalAccounts));
		inputFile.read(reinterpret_cast<char*>(totalAccountIDs), sizeof(totalAccountIDs));
		inputFile.close();
	}
}

void Account::createAccount()
{
	cls();
	int choice;
	bool exists = true, invalid = false, exit = false;
	string tempUsername;
	accountID tempID;
	cout << "Enter your name: ";
	cin.ignore();
	getline(cin, userAccount.aname);
	while (exists == true)
	{
		exists = false;
		cout << "\n\nEnter a new username: ";
		getline(cin, tempUsername);
		exists = searchUsername(tempUsername);
		if (exists)
		{
			cout << "This username already exists.";
		}
	}
	userAccount.aname = tempUsername;
	cout << "\n\nEnter a new password: ";
	cin >> userAccount.apassword;
	userAccount.aaccountNumber = totalAccounts + 1;
	totalAccounts += 1;
	while (!exit)
	{
		if (invalid)
		{
			cout << "\n\nInvalid selection.\n\n";
		}
		cout << "\n\nWhich kinds of account do you want to open?:\n1 - Checking\n2 - Savings\n3 - HELOC\n4 - CD\n5 - Finished opening accounts."
			<< " Note, you may open up to ten accounts of any type.\nChoice: ";
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
	userAccount.balance = 0;
	cls();
}

bool Account::signIn()
{
	cls();
	string tempUsername, tempPassword;
	int index;
	bool exists = false, retval = false;
	if (checkFile("userAccounts.dat"))
	{
		while (!exists)
		{
			cout << "Enter your username: ";
			cin >> tempUsername;
			cout << "\nEnter your password: ";
			cin >> tempPassword;
			//Search stored files for an account with this info
			index = searchAccountInfo(tempUsername, tempPassword);
			if (index >= 0)
			{
				userAccount.aname = availableAccounts[index].sname;
				userAccount.ausername = availableAccounts[index].suserName;
				userAccount.apassword = availableAccounts[index].spassword;
				userAccount.aaccountNumber = availableAccounts[index].saccountNuber;
				userAccount.balance = availableAccounts[index].balance;
				userAccount.aaccountIDs.clear();
				for (int i = 0; i < 10; i++)
				{
					//Add check for ID existance
					userAccount.aaccountIDs.push_back(availableAccounts[index].saccountIDs[i]);
				}
				exists = true;
			}
			else
			{
				cout << "\n\nYour username or password is incorrect.\n\n";
				exists = false;
			}
			retval = true;
		}
	}
	else
	{
		cout << "There are no accounts created yet.\nPress \"Enter\" to exit: ";
		cin.ignore();
		getline(cin, tempUsername);
		retval = false;
		
	}
	cls();
	return retval;
}

bool Account::searchUsername(string username)
{
	for (int i = 0; i < 10; i++)
	{
		if (availableAccounts[i].suserName == username)
		{
			return true;
		}
	}
	return false;
}

int Account::searchAccountInfo(string username, string password)
{
	for (int i = 0; i < 10; i++)
	{
		if (availableAccounts[i].suserName == username && availableAccounts[i].spassword == password)
		{
			return i;
		}
	}
	return -1;
}

void Account::storeAccountInfo()
{
	accountStorage storeAccount;
	strcpy_s(storeAccount.sname, 40 , userAccount.aname.c_str());
	strcpy_s(storeAccount.suserName, 40 , userAccount.ausername.c_str());
	strcpy_s(storeAccount.spassword, 40 , userAccount.apassword.c_str());
	storeAccount.saccountNuber = userAccount.aaccountNumber;
	storeAccount.balance = userAccount.balance;
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
	storefile.write(reinterpret_cast<char*>(totalAccounts), sizeof(totalAccounts));
	storefile.write(reinterpret_cast<char*>(totalAccountIDs), sizeof(totalAccountIDs));
	storefile.close();
}

int Account::accessAccounts()
{
	string ch;
	bool exit = false;
	while (!exit)
	{
		int choice = -1, index = 0;
		cout << "Available accounts: \n";
		for (int i = 0; i < userAccount.aaccountIDs.size(); i++)
		{
			cout << i + 1 << " - ";
			switch (userAccount.aaccountIDs[i].type)
			{
			case CHECKING:
				cout << "Checking Account #";
				break;
			case SAVINGS:
				cout << "Savings Account #";
				break;
			case CD:
				cout << "CD Account #";
				break;
			case HELOC:
				cout << "HELOC Account #";
				break;
			default:
				cout << "Account ID error.";
			}
			cout << userAccount.aaccountIDs[i].IDnumber << "\n";
			index = i;
		}
		while ((choice - 1) < 0 || (choice - 1) > index)
		{
			cout << "Select an account to access or enter " << index + 2 << " to exit: ";
			cin >> choice;
			if ((choice - 1) < 0 || (choice - 1) > index + 2)
			{
				cout << "\n\nInvalid selection.\n\n";
			}
		}
		if (choice == index + 2)
		{
			return 0;
		}
		switch (userAccount.aaccountIDs[choice - 1].type)
		{
		case CHECKING:
			break;
		case SAVINGS:
			cout << "Savings Account #";
			break;
		case CD:
			cout << "CD Account #";
			break;
		case HELOC:
			cout << "HELOC Account #";
			break;
		default:
			cout << "Account ID error.\n\nPress enter to continue.";
			getline(cin, ch);
		}
		if (userAccount.aaccountIDs[choice - 1].type == CHECKING)
		{
			CheckingAccount checking(userAccount.balance, userAccount.aaccountIDs[choice].IDnumber);
		}
		elif(userAccount.aaccountIDs[choice - 1].type == SAVINGS)
		{
			//Savings
		}
		elif(userAccount.aaccountIDs[choice - 1].type == HELOC)
		{
			cls();
			Heloc heloc(userAccount.balance, userAccount.aaccountIDs[choice - 1].IDnumber);
			heloc.menu();
		}
		elif(userAccount.aaccountIDs[choice - 1].type == CD)
		{
			//CD
		}
	}
	storeAccountInfo();
	saveAccounts();
}