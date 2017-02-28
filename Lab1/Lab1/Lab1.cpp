// Lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <locale>


int main()
{
	setlocale(LC_ALL, "Russian");

	double p = 1;
	int n = 0;
	double f;

	while (n <= 0) {
		printf("¬ведите натуральное n: ");
		scanf_s("%d", &n);
	}
	printf("¬ведите вещественное f (через зап€тую) : ");
	scanf_s("%lf", &f);

	for (int i = 1, k = 1; i <= n; i++, k++) {
		static double sum = f;
		sum += f + k;
		p *= 1 / sum;
	}

	printf("ќтвет: %g\n", p);
	system("pause");

    return 0;
}

