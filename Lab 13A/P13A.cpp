/*
	P13A
	Wesley Casselman
	November 30th of 2023
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int ALPHABET_LETTERS = 26;

void pressEnterToContinue(void);
void letterCounts(string filename, int* pointer);
void displayLetterFrequency(int* pointer);

int main(void)
{
	string filename;
	cout << "Enter filename: ";
	getline(cin, filename);
	
	int letters[ALPHABET_LETTERS];
	int* ptr = letters;
	for (int i = 0; i < ALPHABET_LETTERS; i++)
	{
		letters[i] = 0;
	}

	letterCounts(filename, ptr);
	displayLetterFrequency(ptr);
	pressEnterToContinue();
	return 0;
}

void pressEnterToContinue() {
	cout << "Press enter to continue...";
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

		if (incoming.eof())
		{
			break;
		}

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

void displayLetterFrequency(int* pointer)
{
	int sum = 0;
	for (int i = 0; i < ALPHABET_LETTERS; i++)
	{
		sum += *(pointer + i);
	}

	if (sum == 0)
	{
		return;
	}

	cout << "\nTotal number of letters: " << sum << endl;
	cout << "Frequency: " << endl << setprecision(3) << fixed;
	for (int i = 0; i < ALPHABET_LETTERS; i++)
	{
		cout << "'" << char('A' + i) << "':" << setw(7) << 100 * double(*(pointer + i)) / sum << endl;
	}

	return;
}