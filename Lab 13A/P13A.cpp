/*
	P13A
	Wesley Casselman
	November 30th of 2023
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void pressEnterToContinue(void);

int main(void)
{
	pressEnterToContinue();
	return 0;
}

void pressEnterToContinue() {
	cout << "\nPress enter to continue... \n";
	cin.clear();
	while (cin.get() != '\n') continue;
}