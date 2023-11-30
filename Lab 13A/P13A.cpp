/*
	P13A
	Wesley Casselman
	November 30th of 2023
*/

#include <iostream>
#include <fstream>

using namespace std;

const int ALPHABET_LETTERS = 26;

void pressEnterToContinue(void);
void letterCounts(string filename, int* pointer);

int main(void)
{
	int letters[ALPHABET_LETTERS];
	for (int i = 0; i < ALPHABET_LETTERS; i++)
	{
		letters[i] = 0;
	}
	int* ptr = letters;

	letterCounts("test.txt", ptr);

	for (int i = 0; i < ALPHABET_LETTERS; i++)
	{
		cout << letters[i] << "  ";
	}

	pressEnterToContinue();
	return 0;
}

void pressEnterToContinue() {
	cout << "\nPress enter to continue...";
	cin.clear();
	while (cin.get() != '\n') continue;
}

void letterCounts(string filename, int* pointer)
{
	ifstream incoming;
	incoming.open(filename);

	if (!incoming.is_open())
	{
		cout << "\nError - file did not open\n";
		return;
	}

	while (!incoming.eof())
	{
		char ch;
		incoming >> ch;
		for (int i = 0; i < ALPHABET_LETTERS; i++)
		{
			if (ch == 'a' + i || ch == 'A' + i)
			{
				*(pointer + i) += 1;
				break;
			}
		}
	}

	incoming.close();
	return;
}