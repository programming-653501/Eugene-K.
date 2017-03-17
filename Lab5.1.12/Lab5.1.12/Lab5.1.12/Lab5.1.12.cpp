// Lab5.1.12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <list>
#include <iterator>
#include <iomanip>

#define REALLY_BIG_NUM 1000000000

void getFactorial(int n, std::list<long long>&);
void countFactorial(int n, std::list<long long>& numList);
void printBigNum(std::list<long long>& numList);

int main()
{
	std::list<long long> mylist;

	int num;

	std::cout << "Enter integer for factorial (shouldn't be much more than 1000 or stack overflow possible): ";
	std::cin >> num;

	getFactorial(num, mylist);

	std::cout << num << "! = " << std::endl;

	printBigNum(mylist);

	_getch();

    return 0;
}

void getFactorial(int n, std::list<long long>& numList) {
	numList.push_back(1);
	countFactorial(n, numList);
	numList.reverse();
}

void countFactorial(int n, std::list<long long>& numList) {
	std::list<long long>::iterator it = numList.begin();

	if (n <= 1) return;

	for (int i = 0; i < numList.size(); i++) {
		*it *= n;
		it = std::next(it);
	}

	it = numList.begin();

	for (int i = 0; i < numList.size(); i++) {

		int nextDigit = 0;
		while (*it >= REALLY_BIG_NUM) {
			nextDigit++;
			*it -= REALLY_BIG_NUM;
		}

		if (it == std::prev(numList.end()) && nextDigit > 0) {
			numList.push_back(nextDigit);
			it = std::next(it);
			continue;
		}
		else if (nextDigit > 0) {
			it = std::next(it);
			*it += nextDigit;
		}
		else it = std::next(it);
	}

	countFactorial(n - 1, numList);
}

void printBigNum(std::list<long long>& numList) {
	int size = numList.size();
	std::list<long long>::iterator it = numList.begin();

	std::cout << std::setfill('0');

	for (int i = 0; i < size; i++) {
		if (!i) std::cout << *it << " ";
		else std::cout << std::setw(9) << *it << " ";
		it = std::next(it);
	}
}