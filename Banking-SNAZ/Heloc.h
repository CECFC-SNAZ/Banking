#pragma once
/*
Heloc.h
Zach Partain
3-5-2020
Prototypes for the Heloc class
*/

#include "BaseClass.h"
using namespace std;

class Heloc : public Base
{
private:
	float interestRate;
	double amountOwed;
public:
	Heloc(double bal, int accountNumberIn);
	//Withdraw funds from the line of credit
	bool withdrawal(double amount);
	//Pay back what was withdrawn plus interest
	void deposit(double amount);
	//Main user interface menu
	void menu();
	//cout account type
	void displayType()
	{
		cout << "HELOC";
	}
};