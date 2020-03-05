// Source.cpp
// Team SNAZ
// 2 March 2020


#include "Transaction.h"
#include "BaseClass.h"
#include <iostream>
#include "Cls.h"
#include <string>
using namespace std;

const bool debug = true;

int main() {
	if (debug) { // If debug is set to true, it will run a series of test to make sure everything is working properly - Nick
		Transaction tmpTrans;
		if (not tmpTrans.test()) cout << "Error with transaction file I/O\n";
	}
	while (false) {
		timeStruct tmpTime;
		tmpTime = getTime();
		cout << tmpTime.month << "/" << tmpTime.day << "/" << tmpTime.year << " " << tmpTime.hour << ":" << tmpTime.minute << ":" << tmpTime.second;
		string tmpStr;
		cin.clear();
		getline(cin, tmpStr);
	}
	return 0;
}