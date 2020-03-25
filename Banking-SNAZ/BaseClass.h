#pragma once
/*BaseClass.h
by Sedona Dionne
February 28, 2020
Base Class includes fees, interest rates, and withdrawal limits.
*/

#include "Transaction.h"
#include "TransactionStorage.h"
#include "Cls.h"
#include <iostream>
#include <ctime>
using namespace std;

class Base {
protected:
    TransactionStorage transactionStorage;
    int accountNumber;
    int numWithdrawals, withdrawLimit;
    float annualInterestRate;
    double balance;
    double depositfees, checkfees, overdraftfee, overdraftInterest, latefee, earlywithdrawfee, totalfees, monthlyFee, maxWithdrawAmount;
    timeStruct entryTime;
    int monthsUntilWithdrawal = 0;
public:
    Base() { depositfees = 0, checkfees = 0, overdraftfee = 0, latefee = 0, earlywithdrawfee = 0, totalfees = 0; }
    Base(double bal, int accountNumberi);
    ~Base() {}
    //Withdraw funds. Returns true if withdrawal was accepted, or false if the withdrawal was denied.
    virtual bool withdrawal(double amount);
    //Deposit funds
    void deposit(double amount);
    //Returns the current account balance
    double get_balance() const
    {
        return balance;
    }
    //Determines the fee owed on an overdraft and applies this fee
    void calcOverdraft(double);
    //Set the interest rate for an account
    void setIntRate(double rate)
    {
        annualInterestRate = rate;
    }
    void setEntryTime(timeStruct enteredtime) { entryTime = enteredtime; }
   timeStruct getEntryTime() { return entryTime; }
   //Set the initial overdraft fee and overdraft interest rate (interest rate is ideally 10% - 20%)
   void setOverdraft(double fee, double interest);
   //Set the withdraw limit for the account.
   void setWithdrawLimit(int limit);
   //Return a timeStruct structure
   timeStruct getTime();
   //Displays all transactions associated with the account
   void displayTransactions();
   //Main menu for accessing the account's features
   void menu();
   //cout the type of account that is currently active (must be defined for each account)
   virtual void displayType()
   {
       cout << "Error, type not found.";
   }
   //Sets the monthly fee for the account
   void setMonthlyFee(double fee)
   {
       monthlyFee = fee;
   }
   //Sets the maximum amount that may be withdrawn at one time
   void setMaxWithdrawAmount(double amount)
   {
       maxWithdrawAmount = amount;
   }
};

