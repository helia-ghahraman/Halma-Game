#pragma once

#ifndef HEADER8_FILE
#define HEADER8_FILE

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include"important.h"
#include"log_sign.h"
#include"bead_map.h"
#include"Movement.h"
#include"endgame.h"
#include"play_game.h"
#include"endgame.h"
void selection(/*int flagArray[][60],*/int &swWinner2,int& option1, char beadPos[], char recUsername[], char recPassword[], int& sw6, char color[][8], int board[][100], int& n, int& pnum, int& games, int& turn, struct playerCo& pCo) {
	switch (option1) {
	case 0://sefr();
		GameStatics();
		break;
	case 1:
		PlayerStatics(recUsername, recPassword);
		option1 = 0;
		break;
	case 2:
		config(n,pnum,color,leave, beadPos);
		pCo.computer[0]=1;//nafare aval human (lasi ke varede bazi shude).
		if(pnum==4){
			clearScreen();
			while(1){
				print4(list5);
				if(moveMenu3(list5,option2)==1)break;
				switch(option2){
					case 2:
					case 3:
						gotoxy(118,14);
						colorizedText(10);
						printf("player 2 is chosen");
						pCo.computer[1]=option2 % 2;
						option2=2;
						break;
					case 5:
					case 6:
						gotoxy(118,22);
						colorizedText(10);
						printf("player 3 is chosen");
						pCo.computer[2]=(option2+1) % 2;
						option2=2;
						break;
					case 8:
					case 9:
						gotoxy(118,30);
						colorizedText(10);
						printf("player 4 is chosen");
						pCo.computer[3]=option2 % 2;
						option2=2;
						break;
				}
			}
			clearScreen();
		}
		else {
			clearScreen();
			pCo.computer[2]=0;
			gotoxy(55,18);
			colorizedText(10);
			printf("YOUR RIVAL IS COMPUTER!");
		}
		option1 = 0;
		break;
	case 3://4 nafare adam
		config(n,pnum,color,leave, beadPos);
		for(i=0;i<4;i++)pCo.computer[i]=1;
		clearScreen();
		gotoxy(55,22);
		colorizedText(10);
		printf("ALL PLAYERS ARE HUMAN!");
		option1 = 0;
		break;
	case 4://new game
		swWinner2=0;
		config(n,pnum,color,leave, beadPos);
		pCo.computer[0]=1;
		newGame(flag, counter, temp, again, swLeave, term, sw, winner1, winner2, amar1, amar2, color, beadPos, board, x1, y01, n, pnum, leave, max, games, turn, pCo);
		if(winner2==0)swWinner2=1;//bazi 4 nafare
		if (play(/*flagArray,*/pCo, pnum, turn, games, winner1, winner2, term, x1, y01, x2, y2, again, board, amar1, amar2, leave, counter) == 1)sw6 = 1;
		PS_update(winner1, recUsername, recPassword);
		GS_update(winner1, winner2,swWinner2);
		option1 = 0;
		if (games == 0) {
			int y;
			for (y = 0; y < 16; y++) {
				clearScreen();
				gotoxy(60, 20);
				colorizedText(y);
				printf("END OF THE GAME!GOODBYE :) ");
				sleep(900);
			}
		}
		break;
	case 5://load game
		swWinner2=0;
		load(max, games, pnum, temp, board, lastest, pCo, n, turn, winner1, winner2, amar1, amar2, leave, counter, term, x1, y01, x2, y2);
		if(winner2==0)swWinner2=1;//bazi 4 nafare
		if (play(/*flagArray,*/pCo, pnum, turn, games, winner1, winner2, term, x1, y01, x2, y2, again, board, amar1, amar2, leave, counter) == 1)sw6 = 1;
		clearScreen();
		PS_update(winner1, recUsername, recPassword);
		GS_update(winner1, winner2,swWinner2);
		option1 = 0;
		if (games == 0) {
			int y;
			for (y = 0; y < 16; y++) {
				clearScreen();
				gotoxy(60, 20);
				colorizedText(y);
				printf("END OF THE GAME!GOODBYE :) ");
				sleep(900);
			}
		}
		break;
	case 6:
		option1 = 0;
		clearScreen();
		rules();
		break;
	case 7:
		clearScreen();
		sw6 = 1;
		break;
	}
}
#endif
