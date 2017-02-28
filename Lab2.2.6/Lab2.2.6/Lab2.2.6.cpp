// Lab2.2.6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <math.h>
#include <conio.h>
#include <time.h>
#include <locale.h>

long double countByIter(double x, double e);
long double countByRec(double x, double e, long double res = 0, int n = 1, long long factorial = 1);

int main()
{
	setlocale(LC_ALL, "Russian");

	double x, e;

	printf("Введите х: ");
	scanf_s("%lf", &x);
	printf("Введите e: ");
	scanf_s("%lf", &e);
	printf("\n");

	clock_t tBeginning, tFinish;

	tBeginning = clock();
	printf("sin(x) = %.15g\nИтерационная функция = %.15g\n", sin(x), countByIter(x, e));
	tFinish = clock();
	printf("Время выполнения: %g\n\n", (float)(tFinish - tBeginning) / CLOCKS_PER_SEC);

	tBeginning = clock();
	printf("sin(x) = %.15g\nРекурсивная функция = %.15g\n", sin(x), countByRec(x, e));
	tFinish = clock();
	printf("Время выполнения: %g\n", (float)(tFinish - tBeginning) / CLOCKS_PER_SEC);

	_getch();
    return 0;
}

long double countByIter(double x, double e) {
	double sample = sin(x);
	long double res = 0;
	double factorial = 1;
	int n;
	for (n = 1; fabs(res - sample) > e; n++) {
		res += pow(-1, n - 1) * pow(x, 2 * n - 1) / factorial;
		factorial *= (2 * n) * (2 * n + 1);
	}
	printf("n = %d\n", n);
	return res;
}

long double countByRec(double x, double e, long double res, int n, long long factorial) {
	static double sample = sin(x);
	if (fabs(res - sample) > e) {
		res += pow(-1, n - 1) * pow(x, 2 * n - 1) / factorial;
		factorial *= (2 * n) * (2 * n + 1);
		return countByRec(x, e, res, n + 1, factorial);
	}
	else {
		printf("n = %d\n", n);
		return res;
	}
}