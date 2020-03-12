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
	tmpTimeStruct = getTime();
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
	nowTime = getTime();
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