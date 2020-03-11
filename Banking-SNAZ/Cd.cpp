// Cd.cpp
// Nicholas Pie
// 5 March 2020
// Function definitions for the checking class

#include "Cd.h"
using namespace std;

CD::CD(double bal, int accountNumberi) : Base(bal, accountNumberi)
{
	withdrawLimit = 0;

	timeStruct tmpTimeStruct;
	tmpTimeStruct = _getTime();
	entryTime.tm_year = tmpTimeStruct.year;
	entryTime.tm_mon = tmpTimeStruct.month;
	entryTime.tm_mday = tmpTimeStruct.day;
	entryTime.tm_hour = tmpTimeStruct.hour;
	entryTime.tm_min = tmpTimeStruct.minute;
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
	nowTime = _getTime();
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
	tmpTimeStruct.year = entryTime.tm_year;
	tmpTimeStruct.month = entryTime.tm_mon;
	tmpTimeStruct.day = entryTime.tm_mday;
	tmpTimeStruct.hour = entryTime.tm_hour;
	tmpTimeStruct.minute = entryTime.tm_min;
	tmpTimeStruct.second = 0;
	return tmpTimeStruct;
}

bool CD::withdrawal(double amount) : bool withdrawal(amount)
{
	double pBal = balance;
	timeStruct storeTime = getTime();
	if (withdrawLimit > 0)
	{
		if ((balance - amount) < 0 && numWithdrawals < withdrawLimit)
		{
			if (isEarly()) balance -= earlywithdrawfee;
			calcOverdraft(amount - balance);
			transactionStorage.withdrawal(storeTime, amount, accountNumber, pBal, balance);
			numWithdrawals++;
			return true;
		}
		elif((balance - amount) >= 0 && numWithdrawals < withdrawLimit)
		{
			if (isEarly()) balance -= earlywithdrawfee;
			balance -= amount;
			transactionStorage.withdrawal(storeTime, amount, accountNumber, pBal, balance);
			numWithdrawals++;
			return true;
		}
		return false;
	}
	else
	{
		if ((balance - amount) < 0)
		{
			if (isEarly()) balance -= earlywithdrawfee;
			calcOverdraft(amount - balance);
			transactionStorage.withdrawal(storeTime, amount, accountNumber, pBal, balance);
			numWithdrawals++;
			return true;
		}
		elif((balance - amount) >= 0)
		{
			if (isEarly()) balance -= earlywithdrawfee;
			balance -= amount;
			transactionStorage.withdrawal(storeTime, amount, accountNumber, pBal, balance);
			numWithdrawals++;
			return true;
		}
		return false;
	}
}