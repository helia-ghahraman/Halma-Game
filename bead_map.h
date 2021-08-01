#pragma once

#ifndef HEADER2_FILE
#define HEADER2_FILE

#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "important.h"

int n,board[100][100] = { 0 };
int max;
char beadPos[25];
char color[5][8];
void structComplete(char color[][8],struct playerCo &pCo){
	for (i = 0; i < 4; i++)pCo.turn[i] = i + 1;//meghdardehi be structure.
	switch (color[0][0]) {//range nafare 1
		case 'G':
		case 'g':
			pCo.color[0] = 226;
			break;
		case 'Y':
		case 'y':
			pCo.color[0] = 230;
			break;
		case 'B':
		case 'b':
			pCo.color[0] = 225;
			break;
		case 'R':
		case 'r':
			pCo.color[0] = 228;
			break;
	}
	switch (color[1][0]) {//range nafare 2
		case 'G':
		case 'g':
			pCo.color[1] = 226;
			break;
		case 'Y':
		case 'y':
			pCo.color[1] = 230;
			break;
		case 'B':
		case 'b':
			pCo.color[1] = 225;
			break;
		case 'R':
		case 'r':
			pCo.color[1] = 228;
			break;
	}
	switch (color[2][0]) {//range nafare 3
		case 'G':
		case 'g':
			pCo.color[2] = 226;
			break;
		case 'Y':
		case 'y':
			pCo.color[2] = 230;
			break;
		case 'B':
		case 'b':
			pCo.color[2] = 225;
			break;
		case 'R':
		case 'r':
			pCo.color[2] = 228;
			break;
	}
	switch (color[3][0]) {//range nafare 4
		case 'G':
		case 'g':
			pCo.color[3] = 226;
			break;
		case 'Y':
		case 'y':
			pCo.color[3] = 230;
			break;
		case 'B':
		case 'b':
			pCo.color[3] = 225;
			break;
		case 'R':
		case 'r':
			pCo.color[3] = 228;
			break;
	}
}
//color havii nam rang haye vorodi ast
int home(int m, int n, int board[][100], playerCo& pCo) {
	
	if (board[m][n] == 0)printf("  ");
	else if (board[m][n] == 1) {
		colorizedText(pCo.color[0]);
		printf("%c%c", 219, 219);
	}
	else if (board[m][n] == 2) {
		colorizedText(pCo.color[1]);
		printf("%c%c", 219, 219);
	}
	else if (board[m][n] == 3) {
		colorizedText(pCo.color[2]);
		printf("%c%c", 219, 219);
	}
	else if (board[m][n] == 4) {
		colorizedText(pCo.color[3]);
		printf("%c%c", 219, 219);
	}
	else if (board[m][n] == 11) {//chap pointer 
		colorizedText(237);
		printf("%c%c", 178, 178);
	}
	return 0;
}

void gameMenu() {//menu gooshe safhe( bala - rast) ba gozine haye SAVE va MENU va EXIT.
	const int iMenu = 13;
	const int jMenu = 30;
	char Menu[iMenu][jMenu];
	for (int i = 0; i < iMenu; i++) {
		for (int j = 0; j < jMenu; j++) {
			if (i == 0) {//Top
				if (j == 0) {
					Menu[i][j] = 201;
				}
				else if (j == jMenu - 1) {
					Menu[i][j] = 187;
				}
				else {
					Menu[i][j] = 205;
				}
			}
			else if (i == iMenu - 1) {	//Down
				if (j == 0) {
					Menu[i][j] = 200;
				}
				else if (j == jMenu - 1) {
					Menu[i][j] = 188;
				}
				else {
					Menu[i][j] = 205;
				}
			}
			else if (i > 0 && i < iMenu - 1 && i != 4 && i != 8) {
				if (j == 0 || j == jMenu - 1) {
					Menu[i][j] = 186;
				}
				else Menu[i][j] = ' ';
			}
			else if (i == 4) {
				if (j == 0) Menu[i][j] = 204;
				else if (j == jMenu - 1) Menu[i][j] = 185;
				else Menu[i][j] = 205;
			}
			else if (i == 8) {
				if (j == 0) Menu[i][j] = 204;
				else if (j == jMenu - 1) Menu[i][j] = 185;
				else Menu[i][j] = 205;
			}
		}
	}
	int  l = 4;//print
	for (int i = 0; i < iMenu; i++) {
		for (int j = 0; j < jMenu; j++) {
			colorizedText(8);
			gotoxy(128 + j, l);
			printf("%c", Menu[i][j]);
			colorizedText(15);
		}
		l++;
		printf("\n");
	}
	char list4[3][20] = { "PRESS 1 TO MENU ","PRESS 2 TO SAVE ","PRESS 3 TO EXIT " };
	gotoxy(135, 6);
	colorizedText(11);
	printf("%s", list4[0]);
	gotoxy(135, 10);
	printf("%s", list4[1]);
	gotoxy(135, 14);
	printf("%s", list4[2]);
	gotoxy(3,7);
}


void printMap(int n, int board[][100],struct playerCo pCo) {
	int i, j, m, p, y = 10;
	
	m = 2 * n;
	p = 3 * n;
	colorizedText(7);
	for (i = 1; i <= n; i++) {//in bakhsh shumare satr va sutun chap mikunad.
		colorizedText(7);
		gotoxy((-5 * n) + 102, (2 * i) + 10);
		printf("%d", i);
		gotoxy((5 * i) + (-5 * n) + 102, 10);
		printf("%d", i);
	}
	for (i = 0; i <= m; i++) {
		y++;
		gotoxy((-5 * n) + 105, y);
		for (j = 0; j <= p; j++) {
			if (i == 0) {
				if (j == 0) {
					colorizedText(pCo.color[0]);
					printf("%c", 201);
				}
				else if (j == p) {
					colorizedText(pCo.color[1]);
					printf("%c", 187);
				}
				else if (j % 3 == 0) {
					colorizedText(224);
					printf("%c", 203);
				}
				else {
					colorizedText(224);
					printf("%c%c", 205, 205);
				}
			}
			else if (i == m) {
				if (j == 0) {
					colorizedText(pCo.color[3]);
					printf("%c", 200);
				}
				else if (j == p) {
					colorizedText(pCo.color[2]);
					printf("%c", 188);
				}
				else if (j % 3 == 0) {
					colorizedText(224);
					printf("%c", 202);
				}
				else {
					colorizedText(224);
					printf("%c%c", 205, 205);
				}
			}
			else if (i > 0 && i < m) {
				if (i % 2 == 0) {
					if (j == 0) {
						colorizedText(224);
						printf("%c", 204);
					}
					else if (j == p) {
						colorizedText(224);
						printf("%c", 185);
					}
					else if (j % 3 == 0) {
						colorizedText(224);
						printf("%c", 206);
					}
					else {
						colorizedText(224);
						printf("%c%c", 205, 205);
					}
				}
				else {
					if (j % 3 == 0) {
						colorizedText(224);
						printf("%c", 186);
					}
					else {
						home(i, j, board, pCo);
					}
				}
			}
		}
		printf("\n");
	}
	gameMenu();
}

int beadPosition(int n, int board[][100],char beadPos[], int pnum, int& max) {
	int  i, j;
	int m, p, r = -3;
	m = 2 * n;
	p = 3 * n;
	for (i = strlen(beadPos) - 1; beadPos[i] < 48; i--);//bedast avardane akharin adad reshte.
	max = beadPos[i] - 48 + 1;//max n dar reshteye vorodi ast.
	for (i = 1; i < 2 * max; i += 2) {//bala-chap va rast
		for (j = 1; j < p; j += 3) {
			if (i == 1 || i == 3) {
				if (j < 3 * max)board[i][j] = 1;
				if (pnum == 4) {
					if (j > p - (3 * max))board[i][j] = 2;
				}
			}
			else {
				if (j < 3 * max - r)board[i][j] = 1;
				if (pnum == 4) {
					if (j > p - (3 * max) + r)board[i][j] = 2;
				}
			}
		}
		r += 3;
	}
	r = -3;
	for (i = m - 1; i > m - (2 * max); i -= 2) {//payin-chap va rast
		for (j = 1; j < p; j += 3) {
			if (i == m - 1 || i == m - 3) {
				if (j > p - (3 * max))board[i][j] = 3;
				if (pnum == 4) {
					if (j < 3 * max)board[i][j] = 4;
				}
			}
			else {
				if (j > p - (3 * max) + r)board[i][j] = 3;
				if (pnum == 4) {
					if (j < 3 * max - r)board[i][j] = 4;
				}
			}
		}
		r += 3;
	}
	return 0;
}

#endif
