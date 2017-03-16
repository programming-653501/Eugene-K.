// Lab4.1.11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>


int main()
{
	char text[256][81];
	int symbolsEntered = 1;
	char currentChar = ' ';
	char currText[81] = "";
	while (currentChar != 13) {
		int currRow = symbolsEntered / 80;
		int numOfSpaces = (symbolsEntered % 80 + 1) / 2;

		int currNumOfSpaces = 40 - numOfSpaces;

		for (int j = 0; j < currNumOfSpaces; j++) {
			text[currRow][j] = ' ';
		}
		if (symbolsEntered % 80 == 1 || symbolsEntered % 80 == 2) text[currRow][currNumOfSpaces] = ' ';

		for (int i = currNumOfSpaces + 1; text[currRow][i] = currText[i - currNumOfSpaces]; i++);

		currentChar = _getch();
		system("cls");

		

		text[currRow][currNumOfSpaces + symbolsEntered % 80] = currentChar;
		text[currRow][currNumOfSpaces + symbolsEntered % 80 + 1] = '\0';
		symbolsEntered++;



		if ((symbolsEntered) / 80 > currRow) currText[0] = '\0';
		for (int i = currNumOfSpaces; currText[i - currNumOfSpaces] = text[currRow][i]; i++);

		for (int i = 0; i <= currRow; i++) {
			std::cout << text[i] << "|" << std::endl;
		}
	}

    return 0;
}

