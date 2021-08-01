#pragma once
#ifndef HEADER3_FILE
#define HEADER3_FILE

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<conio.h>
#include <windows.h>
#include <math.h>
#include"bead_map.h"
#include "important.h"

int playerTurn(int winner1, int winner2, int pnum, int& turn, int& games,struct playerCo pCo) {
	if (turn < 4)turn++;
	else turn = 1;
	if (winner1 == 10 ||winner1 == 30 || winner1 == 130) {//etmame bazi1 
		switch (turn) {
		case 1:
			turn = 2;
			break;
		case 3:
			turn = 4;
			break;
		}
	}
	if (winner2 == 20 || winner2 == 40 ||winner2 == 240) {//etmame bazi1 
		switch (turn) {
		case 2:
			turn = 3;
			break;
		case 4:
			turn = 1;
			break;
		}
	}
	if (games != 0) {
		int e = 0;//rang
		while (turn != pCo.turn[e]) {
			e++;
		}colorizedText(pCo.color[e] - 216);
		gotoxy(3, 6);
		printf("it's your turn!");
	}
}

//in tabe harkate muhre ha ra modiriat mikunad
int movement(int n, int turn, int& temp, int x1, int y01, int x2, int y2, int again, int board[][100]) {//again: harkate baad az jump ra control mikunad ke super jump ya harkat be khane haye mujaver ra anjam nadahad.
	if (x1 - x2<3 && x1 - x2>-3 && y01 - y2<4 && y01 - y2>-4 && again == 0 && pow(x1 - x2, 2) + pow(y01 - y2, 2) != 0) {
		temp = turn;
		return 2;
	}
	//jump
	int x3 = (x1 + x2) / 2, y3 = (y01 + y2) / 2; //x, y;
	if (board[x3][y3] != 0) {
		if ((x2 - x1) % 2 == 0 && (y2 - y01) % 2 == 0) {
			if (x2 - x1 != 0 || y2 - y01 != 0) {
				//muvarab
				if (x2 - x1 != 0 && y2 - y01 != 0 && (3 * (x2 - x1) == 2 * (y2 - y01) || 3 * (x2 - x1) == 2 * (y01 - y2))) {
					if (x2 - x1 == 4 || x1 - x2 == 4) {//mamoli
						temp = turn;
						return 1;
					}
					else if (again == 0) {//super
						int i = 2, j = 3, sw = 0;
						while (x3 - i != x2 && x3 - i != x1) {//ghutre asli ya farii? 
							if (3 * (x3 - x2) == 2 * (y3 - y2)) {//asli
								if (board[x3 - i][y3 - j] != 0 || board[x3 + i][y3 + j] != 0)sw = 1;
								i += 2;
								j += 3;
							}
							else if (3 * (x3 - x2) == 2 * (y2 - y3)) {//farii
								if (board[x3 - i][y3 + j] != 0 || board[x3 + i][y3 - j] != 0)sw = 1;
								i += 2;
								j += 3;
							}
						}
						if (sw == 0) {
							temp = turn;
							return 2;
						}
					}
				}//dar yek suton	
				if (x2 - x1 != 0 && y2 - y01 == 0) {
					if (x2 - x1 == 4 || x1 - x2 == 4) {//mamoli
						temp = turn;
						return 1;
					}
					else if (again == 0) {//super
						int i = 2, sw = 0;
						while (x3 - i != x2 && x3 - i != x1) {
							if (board[x3 - i][y3] != 0 || board[x3 + i][y3] != 0)sw = 1;
							i += 2;
						}
						if (sw == 0) {
							temp = turn;
							return 2;
						}
					}
				}//dar yek satr
				if (x2 - x1 == 0 && y2 - y01 != 0) {//mamoli
					if (y2 - y01 == 6 || y01 - y2 == 6) {
						temp = turn;
						return 1;
					}
					else if (again == 0) {	//super
						int j = 3, sw = 0;
						while (y3 - j != y2 && y3 - j != y01) {
							if (board[x3][y3 - j] != 0 || board[x3][y3 + j] != 0)sw = 1;
							j += 3;
						}
						if (sw == 0) {
							temp = turn;
							return 2;
						}
					}
				}
			}
		}
	}
	if (again != 0)return 3;
	return 0;
}

#endif
