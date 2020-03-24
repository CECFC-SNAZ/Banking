#pragma once
/*
Saving.h
Adam Weibler
3-4-2020
A class to store saving accounts
*/

#include "BaseClass.h"
using namespace std;

class Saving : public Base
{
private:
    float InterestPercent;
    float WithdrawlLimit;
    int timesInterestApplied;
public:
    Saving(double bal, int accountNumberIn, int interestTimes);
    bool withdrawal(double amount);
    void deposit(double amount);
    void menu();
    void displayType()
    {
        cout << "Savings";
    }
    int getTimesInterestApplied() const
    {
        return timesInterestApplied;
    }
};
