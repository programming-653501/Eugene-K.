// Lab3.2.11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <conio.h>
#include <time.h>

void printArr(char**, int);
void fillArr(char**, int);
void putTraveler(char**, int);
void findWayOut(char**, int);
bool isMovable(char**, char**, int, int, int);

int main()
{
	srand(time(0));

	int size;
	printf("Enter size of maze: ");
	scanf_s("%d", &size);
	
	char** maze = (char**)malloc(size * sizeof(char*));
	for (int i = 0; i < size; i++) {
		maze[i] = (char*)malloc(size * sizeof(char));
	}

	fillArr(maze, size);
	putTraveler(maze, size);
	printArr(maze, size);

	findWayOut(maze, size);

	system("pause");

    return 0;
}

void fillArr(char** arr, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			int temp = rand() % 2;
			arr[i][j] = temp ? '0' : '1';
		}
	}
}

void printArr(char** arr, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
}

void putTraveler(char** arr, int size) {
	int temp = 1;
	int rX, rY;
	while (temp != '0') {
		rY = rand() % (size - 2) + 1;
		rX = rand() % (size - 2) + 1;
		temp = arr[rY][rX];
	}
	arr[rY][rX] = '+';
}

void findWayOut(char** arr, int size) {
	int y = 0, x = 0;
	for (int i = 1; i < size - 1; i++) {
		for (int j = 1; j < size - 1; j++) {
			if (arr[i][j] == '+') {
				y = i;
				x = j;
				break;
			}
		}
		if (x && y) break;
	}

	char** mazecp = (char**)malloc(size * sizeof(char*));
	for (int i = 0; i < size; i++) {
		mazecp[i] = (char*)malloc(size * sizeof(char));
		for (int j = 0; j < size; j++) {
			mazecp[i][j] = arr[i][j];
		}
	}

	bool hasExit = isMovable(mazecp, arr, size, y, x);
	if (hasExit) printf("\nThere is exit!\n");
	else printf("\nThere is no exit!\n");
	printArr(arr, size);

}

bool isMovable(char** arrcp, char** arr, int size, int y, int x) {
	bool hasExit = false;
	arrcp[y][x] = '-';
	if (y == 0 || x == 0 || x == (size - 1) || y == (size - 1)) {
		hasExit = true;
	}
	if (!hasExit && arrcp[y - 1][x] == '0') {
		hasExit = isMovable(arrcp, arr, size, y - 1, x);

	}
	if (!hasExit && arrcp[y][x - 1] == '0') {
		hasExit = isMovable(arrcp, arr, size, y, x - 1);
	}
	

	if (!hasExit && arrcp[y][x + 1] == '0') {
		hasExit = isMovable(arrcp, arr, size, y, x + 1);
	}

	if (!hasExit && arrcp[y + 1][x] == '0') {
		hasExit = isMovable(arrcp, arr, size, y + 1, x);
	}
	if (hasExit && arr[y][x] != '+') {
		arr[y][x] = '*';
	}
	return hasExit;
}