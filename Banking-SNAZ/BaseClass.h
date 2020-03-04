#pragma once
/*BaseClass.h
by Sedona Dionne
February 28, 2020
Struct stores time of entry.  Base Class includes fees, interest rate, and a withdrawal limit.
*/

#include "Transaction.h"
#include <iostream>
using namespace std;
struct entrystruct {
    int tm_min, tm_hour, tm_mday, tm_mon, tm_year;
};
class Base {
private:
    double balance;
    double depositfees, checkfees, overdraftfee, latefee, earlywithdrawfee, totalfees;
    entrystruct entryTime;
public:
    Base() { depositfees = 0, checkfees = 0, overdraftfee = 0, latefee = 0, earlywithdrawfee = 0, totalfees = 0; }
    Base(double bal);
    ~Base() {}
    double get_balance() const;
    void calcDeposit(double);
    void calcCheck(double);
    void calcOverdraft(double);
    void calcLate(double);
    void calcEarlywithdraw(double);
    void calcMonthInt();
    static float annualInterestRate;
    static void modifyIntRate(float value);
    void displayFee();
    void setEntryTime(entrystruct enteredtime) { entryTime = enteredtime; }
   entrystruct getEntryTime() { return entryTime; }
   const int withdrawLimit = 500;
};

