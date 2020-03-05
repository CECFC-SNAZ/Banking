#pragma once
// Checking.h
// Nicholas Pie
// 5 March 2020
// A class to store checking accounts

#ifndef CHECKING_H
#define CHECKING_H

#include "BaseClass.h"
#include "Transaction.h"
using namespace std;

class Checking : public Base {
public:
	Transaction Deposit(double);
	Transaction Withdrawal(double);
};



#endif CHECKIN_H