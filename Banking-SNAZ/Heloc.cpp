/*
Heloc.cpp
Zach Partain
6-3-2020
Function definitios for the Heloc class
*/

#include "Heloc.h"
using namespace std;

#define elif else if

Heloc::Heloc(double bal, int accountNumberIn) : Base(bal, accountNumberIn)
{

}

bool Heloc::withdrawal(double amount)
{
    double pBal = balance;
    timeStruct storeTime = getTime();
    if (withdrawLimit > 0)
    {//Change from withdrawal limit to max withdrawal amount
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