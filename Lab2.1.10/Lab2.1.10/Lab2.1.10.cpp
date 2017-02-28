// Lab2.1.10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <locale.h>

void menu();
float getPrice();
int getYear();
int getVolume();
float getDistance();
void calculateTotal(float price, float distance, int volume, int year);
void info();

int main()
{
	setlocale(LC_ALL, "Russian");
	
	menu();

    return 0;
}

void menu() {
	const int EMPTY = -1;
	float price = EMPTY, distance = EMPTY;
	int volume = EMPTY, year = EMPTY, quit = 0;
	while (!quit) {
		system("cls");
		printf("����� ���������� � Gross Transport!\n");
		printf("1. ���� ��������� ���������� � ������ ���������.\n");
		printf("2. ���� ���� ������� ����������.\n");
		printf("3. ���� ������ ���������.\n");
		printf("4. ���� ���������� �������.\n");
		printf("5. ������ ��������� ������.\n");
		printf("6. ���������� � ������ � ������ ���������\n");
		printf("7. ����� �� ���������.\n");

		char choice = ' ';

		while (choice < '1' || choice > '7') {
			switch (choice = _getch()) {
			case '1':
				price = getPrice();
				system("cls");
				printf("���� ������� �������");
				_getch();
				break;
			case '2':
				year = getYear();
				system("cls");
				printf("��� ������� ������� ������");
				_getch();
				break;
			case '3':
				volume = getVolume();
				system("cls");
				printf("����� ��������� ������� ������");
				_getch();
				break;
			case '4': 
				distance = getDistance();
				system("cls");
				printf("���������� ������� ������� �������");
				_getch();
				break;
			case '5': 
				system("cls");
				if (price != EMPTY && volume != EMPTY && distance != EMPTY && year != EMPTY) {
					calculateTotal(price, distance, volume, year);
				}
				else {
					printf("�� ��� ������ �������");
				}
				_getch();
				break;
			case '6': 
				info(); 
				_getch();
				break;
			case '7': 
				quit = 1;
				system("cls");
				//printf("�� ��������!");
				//_getch();
			}
		}
	}
}

float getPrice() {
	float result;
	system("cls");
	printf("������� ��������� ���������� � ������� ��������� (����) : ");
	scanf_s("%f", &result);
	while (result < 0) {
		printf("�������� ����!\n������� ��������� ���������� � ������� ��������� (����) : ");
		scanf_s("%f", &result);
	}

	return result;
}

int getYear() {
	time_t t = time(NULL);
	struct tm tm;
	localtime_s(&tm, &t);

	int result;
	system("cls");
	printf("������� ��� ������� ���������� (����) : ");
	scanf_s("%d", &result);
	while (result < 1900 || result > tm.tm_year + 1900) {
		printf("�������� ����!\n������� ��� ������� ���������� (����) : ");
		scanf_s("%d", &result);
	}

	return result;
}

int getVolume() {
	int result;
	system("cls");
	printf("������� ����� ��������� ����������� (��.���.) : ");
	scanf_s("%d", &result);
	while (result < 1000) {
		printf("������� ����� ��������� ����������� (��.���.) : ");
		scanf_s("%d", &result);
	}

	return result;
}

float getDistance() {
	float result;
	system("cls");
	printf("������� ���������� ������� ���������� (��) : ");
	scanf_s("%f", &result);
	while (result < 0) {
		printf("�������� ����!\n������� ���������� ������� ���������� (��) : ");
		scanf_s("%f", &result);
	}

	return result;
}

void calculateTotal(float price, float distance, int volume, int year) {
	time_t t = time(NULL);
	struct tm tm;
	localtime_s(&tm, &t);

	system("cls");

	float priceForDistance = distance / 2.0f;
	float priceForMoving;
	int age = tm.tm_year - year + 1900;
	if (age <= 3) {
		priceForMoving = volume * 0.6f;
	}
	else if (age > 3 && age <= 10) {
		if (volume < 2500) {
			priceForMoving = volume * 0.35f;
		}
		else {
			priceForMoving = volume * 0.6f;
		}
	}
	else if (age > 10 && age <= 14) {
		priceForMoving = volume * 0.6f;
	}
	else {
		priceForMoving = volume * 2.0f;
	}

	printf("���� ��������: %g ����\n", priceForDistance);
	printf("���� ��������������: %g ����\n", priceForMoving);
	printf("�����: %g ����\n", priceForDistance + priceForMoving + price);
}

void info() {
	system("cls");
	printf("Gross Transport v1.0\nBy Eugene Kachanovski\nSince 2017 (c)");
}