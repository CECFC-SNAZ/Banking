// Source.cpp
// Team SNAZ
// 2 March 2020

#include "Transaction.h"
#include "BaseClass.h"
#include <iostream>
using namespace std;

const bool debug = true;

int main() {
	if (debug) { // If debug is set to true, it will run a series of test to make sure everything is working properly
		Transaction tmpTrans;
		if (not tmpTrans.test()) cout << "Error with transaction file I/O\n";
	}


	return 0;
}