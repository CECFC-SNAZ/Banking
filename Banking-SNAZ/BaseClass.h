#pragma once
/*BaseClass.h
by Sedona Dionne
February 28, 2020
Struct stores time of entry.  Base Class includes fees, interest rate, and a withdrawal limit.
*/

#include "Transaction.h"
#include "TransactionStorage.h"
#include <iostream>
#include <ctime>
using namespace std;
struct entrystruct {
    int tm_min, tm_hour, tm_mday, tm_mon, tm_year;
};
class Base {
protected:
    TransactionStorage transactionStorage;
    int accountNumber;
    int numWithdrawals, withdrawLimit;
    double balance;
    double depositfees, checkfees, overdraftfee, overdraftInterest, latefee, earlywithdrawfee, totalfees;
    entrystruct entryTime;
public:
    Base() { depositfees = 0, checkfees = 0, overdraftfee = 0, latefee = 0, earlywithdrawfee = 0, totalfees = 0; }
    Base(double bal);
    ~Base() {}
    //Withdraw funds. Returns true if withdrawal was accepted, or false if the withdrawal was denied.
    bool withdrawal(double amount);
    //Deposit funds
    void deposit(double amount);
    double get_balance() const;
    void calcDeposit(double);
    void calcCheck(double);
    //Determines the fee owed on an overdraft and applies this fee
    void calcOverdraft(double);
    void calcLate(double);
    void calcEarlywithdraw(double);
    void calcMonthInt();
    static float annualInterestRate;
    static void modifyIntRate(double value);
    void displayFee();
    void setEntryTime(entrystruct enteredtime) { entryTime = enteredtime; }
   entrystruct getEntryTime() { return entryTime; }


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
   virtual void displayType();
};

