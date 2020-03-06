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
public:
	Heloc(int accountNumberIn);
};