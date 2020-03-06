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
	cls();
	int choice;
	bool exists = true, invalid = false, exit = false;
	string tempUsername;
	accountID tempID;
	cout << "Enter your name: ";
	cin >> userAccount.aname;
	while (exists == true)
	{
		exists = false;
		cout << "\n\nEnter a new username: ";
		cin >> tempUsername;
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
		cout << "\n\nWhich kinds of account do you want to open?\n:1 - Checking\n2 - Savings\n3 - HELOC\n4 - CD\n5 - Finished opening accounts."
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
	cls();
}

void Account::signIn()
{
	cls();
	string tempUsername, tempPassword;
	int index;
	bool exists = false;
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
	}
	cls();
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

void Account::accessAccounts()
{
	int choice = -1, index = 0;
	string ch;
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
			cout << "HELOC Account #";
			break;
		case HELOC:
			cout << "CD Account #";
			break;
		default:
			cout << "Account ID error.";
		}
		cout << userAccount.aaccountIDs[i].IDnumber << "\n";
		index = i;
	}
	while ((choice - 1) < 0 || (choice - 1) > index)
	{
		cout << "Select an account to access: ";
		cin >> choice;
		if ((choice - 1) < 0 || (choice - 1) > index)
		{
			cout << "\n\nInvalid selection.\n\n";
		}
	}
	switch (userAccount.aaccountIDs[choice].type)
	{
	case CHECKING:
		break;
	case SAVINGS:
		cout << "Savings Account #";
		break;
	case CD:
		cout << "HELOC Account #";
		break;
	case HELOC:
		cout << "CD Account #";
		break;
	default:
		cout << "Account ID error.\n\nPress enter to continue.";
		getline(cin, ch);
	}
	if (userAccount.aaccountIDs[choice].type == CHECKING)
	{
		Checking checking;
	}
	elif (userAccount.aaccountIDs[choice].type == SAVINGS)
	{
		//Savings
	}
	elif (userAccount.aaccountIDs[choice].type == HELOC)
	{
		//HELOC
	}
	elif(userAccount.aaccountIDs[choice].type == CD)
	{
		//CD
	}
}