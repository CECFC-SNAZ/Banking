#pragma once
/*BaseClass.h
by Sedona Dionne
February 28, 2020
*/

#include "Transaction.h"
#include <iostream>
using namespace std;

class Base {
private:
    double balance;
    double depositfees, checkfees, overdraftfee, totalfees;
public:
    Base() { depositfees = 0, checkfees = 0, overdraftfee = 0, totalfees = 0;}
    Base(double bal);
    ~Base() {}
    double get_balance() const;
    void calcDeposit(double);
    void calcCheck(double);
    void calcOverdraft(double);
    void calcMonthInt();
    static float annualInterestRate;
    static void modifyIntRate(float value);
    void displayFee();
};


 //Time of entries, # of allowed withdrawals.
/*Withdrawal
Deposit
Pass transactions to the transactions class*/
