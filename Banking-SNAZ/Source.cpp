// Source.cpp
// Team SNAZ
// 2 March 2020

#include "Transaction.h"
#include "BaseClass.h"
#include <iostream>
using namespace std;

int main() {
	// A test for transaction file I/O
	// Will output 2020,2020,2019,2020 if file I/O works properly
	/*
	fstream coolfile;
	coolfile.open("coolfile.dat", ios::out | ios::binary);
	Transaction transTesting(Transaction::Type::Deposit, { 2020,3,2,10,33,37 }, 3.56, 67);
	cout << transTesting.getTime().year << endl;
	if (transTesting.storeInFile(coolfile)) cout << "new file made\n";
	cout << transTesting.getTime().year << endl;
	transTesting.setTransaction(Transaction::Type::Deposit, { 2019,3,2,10,33,37 }, 3.56, 67);
	cout << transTesting.getTime().year << endl;
	coolfile.close();
	coolfile.open("coolfile.dat", ios::in | ios::binary);
	transTesting.readFromFile(coolfile);
	cout << transTesting.getTime().year << endl;
	*/
	return 0;
}