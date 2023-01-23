// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
using std::cout;
using std::cin;
using std::string;
using std::endl;

int main()
{
	string targetWord = "limit";
	string guess;
	int guessNo = 0;
	int maxGuessLimit = 6;

	//Colours
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	const int CORRECT_COLOUR = 10;
	const int CLOSE_COLOUR = 6;
	const int WRONG_COLOUR = 8;

	cout << "Welcome to worlde!\n";
	do{
		cout << "Please enter your guess: ";
		cin >> guess;
		guessNo++;
		for (int i = 0; i < guess.length(); i++)
		{
			if (toupper(guess[i]) == toupper(targetWord[i]))
			{
				SetConsoleTextAttribute(hConsole, CORRECT_COLOUR);
			}
			else if (targetWord.find(toupper(guess[i])) != string::npos)
			{
				SetConsoleTextAttribute(hConsole, CLOSE_COLOUR);
			}
			cout << guess[i];
			SetConsoleTextAttribute(hConsole, WRONG_COLOUR);
		}
		cout << std::endl;

		if (guess == targetWord)
		{
			cout << "You win!";
			guessNo = 6;
		}
		else
		{
			int guessesLeft = maxGuessLimit - guessNo;
			cout << "Wrong, you have " << guessesLeft << " guesses left" << std::endl;

		}
	} while (guessNo < maxGuessLimit);
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
