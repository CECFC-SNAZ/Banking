/*
Heloc.cpp
Zach Partain
6-3-2020
Function definitions for the Heloc class
*/

#include "Heloc.h"
using namespace std;

#define elif else if

Heloc::Heloc(double bal, double amountOwe, int accountNumberIn) : Base(bal, accountNumberIn)
{
    interestRate = 0.1;
    amountOwed = 0;
    maxWithdrawAmount = 500;
    amountOwed = amountOwe;
    transactionStorage.setAccountNumber(accountNumberIn);
    if (balance <= 0)
    {
        balance = 50000;
        amountOwed = 0;
    }
}

bool Heloc::withdrawal(double amount)
{
    string ch;
    double pBal = balance;
    timeStruct storeTime = getTime();
        if ((balance - amount) <= 0 || amount > maxWithdrawAmount)
        {
            cout << "Error: not enough funds for withdrawal or the maximum withdrawal amount was exceeded.\nPress \"Enter\"to countinue: ";
            cin.ignore();
            getline(cin, ch);
        }
        else
        {
            balance -= amount;
            amountOwed += (amount + (amount * interestRate));
            transactionStorage.withdrawal(storeTime, amount, accountNumber, pBal, balance);
            return true;
        }
        return false;
}

void Heloc::deposit(double amount)
{
    double pBal = amountOwed;
    timeStruct storeTime = getTime();
    amountOwed -= amount;
    transactionStorage.payment(storeTime, amount, accountNumber, pBal, amountOwed);
}

void Heloc::menu()
{
    int choice;
    double amount;
    bool valid = true, exit = false;
    while (!exit)
    {
        do
        {
            if (amountOwed < 0.01)
            {
                amountOwed = 0;
            }
            if (!valid)
            {
                cout << "Invalid selection.\n\n";
            }
            displayType();
            cout << " account #" << accountNumber << "\nCurrent balance: " << balance << "\nAmount owed: " << amountOwed
                << "\n\n1 - Withdraw funds\n2 - Make payment\n3 - Veiw past transactions"
                << "\n4 - Exit to main menu\nChoice: ";
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
                cout << "Enter the amount you want to pay: ";
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