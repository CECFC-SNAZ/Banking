/*
Saving.cpp
Adam Weibler
3-4-2020
Function definitions for Saving class
*/

#include "Saving.h"
using namespace std;

#define elif else if

Saving::Saving(double bal, int accountNumberIn, int interestTimes) : Base(bal, accountNumberIn)
{
    timeStruct tempTime, currentTime;
    InterestPercent = 0.09;
    if (bal < 0)
    {
        balance = 0;
    }
    if (interestTimes < 0)
    {
        timesInterestApplied = 0;
    }
    else
    {
        timesInterestApplied = interestTimes;
    }
    withdrawLimit = 15;
    transactionStorage.readAll();
    transactionStorage.findAccountTransactions(accountNumber);
    numWithdrawals = transactionStorage.numberOfWithdrawals();
    tempTime = transactionStorage.getFirstTime();
    currentTime = getTime();
    //To test monthly interest, uncomment the line below after making a deposit and restart the program.
    //currentTime.month += 1;
    if (((currentTime.month - tempTime.month) + ((currentTime.year - tempTime.year)) * 12) > timesInterestApplied && tempTime.year >= 0)
    {

        for (int i = 0; i < (((currentTime.month - tempTime.month) + ((currentTime.year - tempTime.year)) * 12) - timesInterestApplied); i++)
        {
            balance += (balance * InterestPercent);
            timesInterestApplied++;
        }
    }
}

bool Saving::withdrawal(double amount)
{
    string cont;
    float sBal = balance;
    timeStruct storeTime = getTime();
    if ((balance - amount <= 0) || withdrawLimit <= 0)
    {
        cout << " Error: Insufficient funds or you have reached the withdrawal limit \nPress \"Enter\" to continue: ";
        cin.ignore();
        getline(cin, cont);
    }
    else
    {
        balance -= amount;
        transactionStorage.withdrawal(storeTime, amount, accountNumber, sBal, balance);
        numWithdrawals++;
        return true;
    }
    return false;
}

void Saving::deposit(double amount)
{
    double pBal = balance;
    timeStruct storeTime = getTime();
    balance = balance + amount;
    transactionStorage.deposit(storeTime, amount, accountNumber, pBal, balance);
}

void Saving::menu()
{
    int choice;
    double amount;
    bool valid = true, exit = false;
    while (!exit)
    {
        do
        {
            if (!valid)
            {
                cout << "Please enter a valid selection.\n";
            }
            displayType();
            cout << " account #" << accountNumber << "\nCurrent balance including interest: " << balance
                << "\nNumber of withdrawals left: " << withdrawLimit - numWithdrawals
                << "\n1 - Withdraw funds\n2 - Deposit funds\n3 - View past transactions"
                << "\n4 - Exit to main menu\nChoice:";
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

