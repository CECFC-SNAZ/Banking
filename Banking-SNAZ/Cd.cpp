// Cd.cpp
// Nicholas Pie
// 5 March 2020
// Function definitions for the checking class

#include "Cd.h"
using namespace std;

#define elif else if

//Set to true to artificially advance time and test time based functions
bool testTime = false;

CD::CD(double bal, int accountNumberi) : Base(bal, accountNumberi)
{
	earlywithdrawfee = 100;
	monthsUntilWithdrawal = 2;
	withdrawLimit = 0;
	if (bal <= 0)
	{
		bal = 0;
		depositWithdrawal = true;
	}
	elif (bal >= 1)
	{
		depositWithdrawal = false;
		transactionStorage.readAll();
		transactionStorage.findAccountTransactions(accountNumber);
		entryTime = transactionStorage.getFirstTime();
	}
}

bool CD::setMonthsUntilWithdrawal(int inp) {
	if (inp > 0) {
		monthsUntilWithdrawal = inp;
		return true;
	}
	return false;
}

bool CD::isEarly() {
	timeStruct nowTime, endTime;
	nowTime = getTime();
	if (testTime)
	{
		nowTime.month += 2;
		//nowTime.day += 1;
	}
	endTime = getTimeStruct();
	endTime.month += monthsUntilWithdrawal;
	while (endTime.month > 12) {
		endTime.month -= 12;
		endTime.year++;
	}
	if (endTime.year == nowTime.year) {
		if (endTime.month == nowTime.month) {
			if (endTime.day == nowTime.day) {
				return false;
			}
			else if (endTime.day > nowTime.day) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (endTime.month > nowTime.month) {
			return true;
		}
		else {
			return false;
		}
	}
	else if(endTime.year > nowTime.year) {
		return true;
	}
	else {
		return false;
	}
}

timeStruct CD::getTimeStruct() {
	timeStruct tmpTimeStruct;
	tmpTimeStruct.year = entryTime.year;
	tmpTimeStruct.month = entryTime.month;
	tmpTimeStruct.day = entryTime.day;
	tmpTimeStruct.hour = entryTime.hour;
	tmpTimeStruct.minute = entryTime.minute;
	tmpTimeStruct.second = 0;
	return tmpTimeStruct;
}

bool CD::withdrawal(double amount) {
	bool boolStore;
	boolStore = Base::withdrawal(amount);
	if (boolStore && isEarly()) {
		double pBal = balance;
		balance -= earlywithdrawfee;
		transactionStorage.fee(getTime(), earlywithdrawfee, accountNumber, pBal, balance);
	}
	return boolStore;
}

void CD::menu()
{
	string ch;
	int choice;
	double amount;
	bool valid = true, exit = false;
	timeStruct displayTime;
	displayType();
	cout << " account #" << accountNumber;
	while (!exit)
	{
		do
		{
			transactionStorage.readAll();
			transactionStorage.findAccountTransactions(accountNumber);
			entryTime = transactionStorage.getFirstTime();
			if (!valid)
			{
				cout << "Invalid selection.\n\n";
			}
			cout << "\nCurrent balance: " << balance;
			if (!depositWithdrawal)
			{
				cout << "\nTime until deposit maturity: ";
				transactionStorage.readAll();
				transactionStorage.findAccountTransactions(accountNumber);
				displayTime = transactionStorage.getFirstTime();
				displayTime.month += monthsUntilWithdrawal;
				while (displayTime.month > 12)
				{
					displayTime.month -= 12;
					displayTime.year++;
				}
				timeStruct tempTime = getTime();
				if (testTime)
				{
					tempTime.month += 2;
					//tempTime.day += 1;
				}
				cout << "Years: " << displayTime.year - tempTime.year << "  Months: " << displayTime.month - tempTime.month;
					//<< "  Days: " << displayTime.day - tempTime.day << "  Hours: " << displayTime.hour - tempTime.hour;
			}
			cout << "\n1 - Withdraw funds\n2 - Deposit funds\n3 - Veiw past transactions"
				<< "\n4 - Exit to main menu\nChoice: ";
			cin >> choice;
			switch (choice)
			{
			case 1:
				cls();
				if (!depositWithdrawal)
				{
					cout << "Enter the amount you want to withdraw: ";
					cin >> amount;
					withdrawal(amount);
					valid = true;
				}
				else
				{
					cout << "\n\nA deposit must be made first.\nPress \"Enter\" to exit: ";
					cin.ignore();
					getline(cin, ch);
				}
				break;
			case 2:
				cls();
				if (depositWithdrawal)
				{
					cout << "Enter the amount you want to deposit: ";
					cin >> amount;
					deposit(amount);
					depositWithdrawal = false;
					valid = true;
				}
				else
				{
					cout << "\n\nA deposit has already been made.\nPress \"Enter\" to exit: ";
					cin.ignore();
					getline(cin, ch);
				}
				break;
			case 3:
				cls();
				displayTransactions();
				valid = true;
				break;
			case 4:
				valid = true;
				exit = true;
				break;
			default:
				valid = false;
			}
			cls();
		} while (!valid);
	}
}