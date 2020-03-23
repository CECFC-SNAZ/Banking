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
public:
    Saving(double bal, int accountNumberIn);
    bool withdrawal(double amount);
    void deposit(double amount);
    void menu();
    void displayType()
    {
        cout << "Savings";
    }
};
