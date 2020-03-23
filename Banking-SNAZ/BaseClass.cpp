/*BaseClass.cpp
Sedona Dionne
March 4, 2020
*/

#include "BaseClass.h"
#include <iostream>

#define elif else if

Base::Base(double bal, int accountNumberi)
{
    accountNumber = accountNumberi;
    balance = bal;
    entryTime.minute = 0;
    entryTime.hour = 0;
    entryTime.day = 0;
    entryTime.month = 0;
    entryTime.year = 0;
    /*if (bal <= 0)
    {
        bal = 0;
    }
    elif(bal >= 1)
    {
        transactionStorage.readAll();
        transactionStorage.findAccountTransactions();
        numWithdrawals = transactionStorage.numberOfWithdrawals();
    }*/
    transactionStorage.readAll();
    transactionStorage.findAccountTransactions();
    numWithdrawals = transactionStorage.numberOfWithdrawals();
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
    double pBal = balance;
    timeStruct storeTime = getTime();
    balance -= (overdraft + overdraftfee + (overdraft * overdraftInterest));
    transactionStorage.fee(storeTime, (overdraft + overdraftfee + (overdraft * overdraftInterest)), accountNumber, pBal, balance);
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
    timeStore.year = tm_local.tm_year + 1900;
    timeStore.month = tm_local.tm_mon + 1;
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
}

void Base::menu()
{
    int choice;
    double amount;
    bool valid = true, exit = false;
    displayType();
    cout << " account #" << accountNumber;
    while (!exit)
    {
        do
        {
            if (!valid)
            {
                cout << "Invalid selection.\n\n";
            }
            cout << "\nCurrent balance: " << balance << "\nNumber of withdrawals left: " << 500 - numWithdrawals
                << "\n1 - Withdraw funds\n2 - Deposit funds\n3 - Veiw past transactions"
                <<"\n4 - Exit to main menu\nChoice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                cls();
                cout << "Enter the amount you want to withdraw: ";
                cin >> amount;
                withdrawal(amount);
                valid = true;
                break;
            case 2:
                cls();
                cout << "Enter the amount you want to deposit: ";
                cin >> amount;
                deposit(amount);
                valid = true;
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