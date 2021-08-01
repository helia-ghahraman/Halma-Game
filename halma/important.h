/*Helia Ghahraman B| Yasamin Azizi =) Yasaman Hamedtabei :D */
/*1399/11/16*/
/*00:54*/
#pragma once
#ifndef HEADER1_FILE
#define HEADER1_FILE

#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <time.h>

void clearScreen() {
	system("cls");
}

void colorizedText(int k) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, k);
}

void sleep(unsigned int mseconds) {
	clock_t goal = mseconds + clock();
	while (goal > clock());
}


void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}

struct playerCo {
	int turn[5];
	int color[5];
	int computer[5];//0 computer _ 1 human

};
struct player {
	char username[20];
	char password[20];
	int win;
	int lose;
	int draw;
};
struct playerCo pCo;
struct player players;
int  i, j;

#endif
