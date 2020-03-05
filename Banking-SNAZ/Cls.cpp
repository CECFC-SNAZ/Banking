// Cls.cpp
// Nicholas Pie
// 6 February 2020
// A function to clear the screen and one to set the console color
#include <Windows.h>
#include <string>
#include <iostream>
using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void setColor(int inp) {
	SetConsoleTextAttribute(hConsole, inp);
}

void cls() {
	SetConsoleCursorPosition(hConsole, { 0,0 });
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	string tmpStr = "";
	for (int y = 0; y < columns; y++) {
		tmpStr += " ";
	}
	for (int i = 0; i < 100; i++) {
		cout << tmpStr << "\n";
	}
	SetConsoleCursorPosition(hConsole, { 0,0 });
}