/*
Heloc.cpp
Zach Partain
6-3-2020
Function definitios for the Heloc class
*/

#include "Heloc.h"
using namespace std;

Heloc::Heloc(int accountNumberIn)
{
	accountNumber = accountNumberIn;
	annualInterestRate = 1; //Set this to a reasonable value.
}

void Heloc::displayType()
{
	cout << "HELOC";
}