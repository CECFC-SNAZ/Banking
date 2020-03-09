/*BaseClass.cpp
Sedona Dionne
March 4, 2020
*/

#include "BaseClass.h"
#include <iostream>

#define elif else if


  Base::Base() {
      entryTime.tm_min = 0;
      entryTime.tm_hour = 0;
      entryTime.tm_mday = 0;
      entryTime.tm_mon = 0;
      entryTime.tm_year = 0;
}

Base::Base(double bal) {
  balance = bal;
}

bool Base::withdrawal(double amount)
{
    double pBal = balance;
    timeStruct storeTime = getTime();
    if (withdrawLimit > 0)
    {
        if ((balance - amount) < 0 && numWithdrawals < withdrawLimit)
        {
            calcOverdraft(amount - balance);
            transactionStorage.withdrawal(storeTime, amount, accountNumber, pBal, balance);
            numWithdrawals++;
            return true;
        }
        elif((balance - amount) >= 0 && numWithdrawals < withdrawLimit)
        {
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
            calcOverdraft(amount - balance);
            transactionStorage.withdrawal(storeTime, amount, accountNumber, pBal, balance);
            numWithdrawals++;
            return true;
        }
        elif((balance - amount) >= 0)
        {
            balance -= amount;
            transactionStorage.withdrawal(storeTime, amount, accountNumber, pBal, balance);
            numWithdrawals++;
            return true;
        }
        return false;
    }
}

void Base::deposit(double amount)
{
    double pBal = balance;
    timeStruct storeTime = getTime();
    balance += amount;
    transactionStorage.deposit(storeTime, amount, accountNumber, pBal, balance);
}

void Base::calcDeposit(double)
{
}

void Base::calcCheck(double)
{
}

void Base::calcOverdraft(double overdraft)
{
    balance -= (overdraft + overdraftfee + (overdraft * overdraftInterest));
}

void Base::calcLate(double)
{
}

void Base::calcEarlywithdraw(double)
{
}

void Base::calcMonthInt()
{
}

void Base::displayFee()
{
}

void Base::setOverdraft(double fee, double interest)
{
    overdraftfee = fee;
    overdraftInterest = interest;
}

void Base::setWithdrawLimit(int limit)
{
    withdrawLimit = limit;
}

timeStruct Base::getTime()
{
    timeStruct timeStore;
    time_t time_ptr;
    time_ptr = time(NULL);
    tm tm_local;
    localtime_s(&tm_local, &time_ptr);
    timeStore.year = tm_local.tm_year;
    timeStore.month = tm_local.tm_mon;
    timeStore.day = tm_local.tm_mday;
    timeStore.hour = tm_local.tm_hour;
    timeStore.minute = tm_local.tm_min;
    timeStore.second = tm_local.tm_sec;
    return timeStore;
}

void Base::displayTransactions()
{
    string ch;
    transactionStorage.readAll();
    transactionStorage.findAccountTransactions();
    transactionStorage.displayAccountTransactions();
    cout << "\n\n\nPress \"Enter\" to return to the main menu: ";
    cin >> ch;
}