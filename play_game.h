#pragma once

#ifndef HEADER7_FILE
#define HEADER7_FILE

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<conio.h>
#include <windows.h>
#include<stdlib.h>
#include"bead_map.h"
#include "important.h"
#include"log_sign.h"
#include"Movement.h"
#include"endgame.h"

int leave, pnum;
int x1, y01, x2, y2;
int lastest[4][8] = { 0 };
int winner1 = 0, winner2 = 20, amar1 , amar2 = 0;//amar 1va2 dar payan bazi estefade mishavand.
int term = 1, flag = 1,sw = 1, again = 0;
int counter = 0, temp = 0, turn = 3;
int swLeave = 0, games = 1;
int xx1, yy01,key1,key2;
int xi,yj;//dar computerArray mukhtasate mohrei ke bayad harkat kunad ast.

int computerArray(int board[][100],int n,struct playerCo pCo,int max,int &xi,int &yj){
	srand(time(NULL));
	int computerBead[65][3]={0};
	int r=0;
	for(i=1;i<2*n;i+=2){
		for(j=1;j<3*n;j+=3){
			if(board[i][j]==turn){
				computerBead[r][0]=i;
				computerBead[r][1]=j;
				r++;
			}
		}
	}
	int num=(1+max)*max/2+max-1;//tedad mohre ha
	int random = rand()% num ;
	xi=computerBead[random][0];
	yj=computerBead[random][1];
}

int computerMove(int xi,int yj,int n,int turn,int board[][100]){
	int sw=1;
	int i2,j2;
	int p=3*n,m=2*n;
	switch(turn){
		case 2:
			//2 nd player
			for (i2 = xi + 2; i2 > xi - 3; i2 -= 2) {//baraye check kardane mohre haye atraf
				for (j2 = yj - 3; j2 < yj + 4; j2 += 3) {//baraye check kardane mohre haye atraf
					//baraye dar mahdodeye safhe ye bazi bodan
					if (i2 > 0 && i2 < m && j2>0 && j2 < p && pow(i2 - xi, 2) + pow(j2 - yj, 2) != 0) {//be divar nakhurde
						if(board[i2][j2]==0){//mojaver
							board[xi][yj]=0;
							board[i2][j2]=turn;
							sw=0;
							return 0;//amaliat movaffaghiyat amiz!
						}
						else {
							int i1,j1;
							i1=(i2*2)-xi;
							j1=(j2*2)-yj;
							if(i1>0 && i1<m && j1>0 && j1<p && board[(i2*2)-xi][(j2*2)-yj]==0){
								//jump
								board[i1][j1]=turn;
								board[xi][yj]=0;
								sw=0;
								return 0;//amaliat movaffaghiyat amiz!
							}
						}
					}
				}
			}
			break;
		case 3://3rd player			
			for (i2 = xi - 2; i2 < xi + 3; i2 += 2) {//baraye check kardane mohre haye atraf
				for (j2 = yj - 3; j2 < yj + 4; j2 += 3) {//baraye check kardane mohre haye atraf
					//baraye dar mahdodeye safhe ye bazi bodan
					if (i2 > 0 && i2 < m && j2>0 && j2 < p && pow(i2 - xi, 2) + pow(j2 - yj, 2) != 0) {//be divar nakhurde
						if(board[i2][j2]==0){//mojaver
							board[xi][yj]=0;
							board[i2][j2]=turn;
							sw=0;
							return 0;//amaliat movaffaghiyat amiz!
						}
						else {
							int i1,j1;
							i1=(i2*2)-xi;
							j1=(j2*2)-yj;
							if(i1>0 && i1<m && j1>0 && j1<p && board[(i2*2)-xi][(j2*2)-yj]==0){//jump
								board[i1][j1]=turn;
								board[xi][yj]=0;
								sw=0;
								return 0;//amaliat movaffaghiyat amiz!
							}
						}
					}
				}
			}
			break;
		case 4://4th player
			for (i2 = xi - 2; i2 < xi + 3; i2 += 2) {//baraye check kardane mohre haye atraf
				for (j2 = yj + 3; j2 > yj - 4; j2 -= 3) {//baraye check kardane mohre haye atraf
					//baraye dar mahdodeye safhe ye bazi bodan
					if (i2 > 0 && i2 < m && j2>0 && j2 < p && pow(i2 - xi, 2) + pow(j2 - yj, 2) != 0) {//be divar nakhurde
						if(board[i2][j2]==0){//mojaver
							board[xi][yj]=0;
							board[i2][j2]=turn;
							sw=0;
							return 0;//amaliat movaffaghiyat amiz!
						}
						else {
							int i1,j1;
							i1=(i2*2)-xi;
							j1=(j2*2)-yj;
							if(i1>0 && i1<m && j1>0 && j1<p && board[(i2*2)-xi][(j2*2)-yj]==0){//jump
								board[i1][j1]=turn;
								board[xi][yj]=0;
								sw=0;
								return 0;//amaliat movaffaghiyat amiz!
							}
						}
					}
				}
			}
			break;
	}
	return 1;//nashud ke beshe	
}

int config(int &n,int &pnum,char color[][8],int &leave, char beadPos[]){
	n = 10;//maghadire pishfarz
	pnum = 2;
	strcpy(color[0], "blue");
	strcpy(color[2], "green");
	strcpy(color[1], "red");
	strcpy(color[3], "yellow");
	leave = 30;
	strcpy(beadPos, "1 2 3 2");
	FILE* config;
	char Character, string[200];
	config = fopen("config.txt","rt");
	if(!config){
		printf("ERROR 4!");
		return 2;
	}
	else{
		fscanf(config, "%c\n", &Character);
		for(i=0;i<8;i++){
		    fgets(string,4,config);
		    if (strstr(string, "Si") !=NULL) {
				fgets(string,5,config);
				fscanf(config, "%d\n", &n);
				fgets(string,100,config);
			}
		    else if (strstr(string, "Pl") !=NULL) {
				fgets(string,12,config);
				fscanf(config, "%d\n", &pnum);
			}
			else if (strstr(string, "Fi") !=NULL) {
				fgets(string,12,config);
				fscanf(config, "%s\n", color[0]);
			}
			else if (strstr(string, "Se") !=NULL) {
				fgets(string,13,config);
				fscanf(config,"%s\n", color[2]);
			}
			else if (strstr(string, "Th") !=NULL) {
				fgets(string,12,config);
				strcpy(color[1],color[2]);
				fscanf(config,"%s\n", color[2]);
			}
			else if (strstr(string, "Fo") !=NULL) {
				fgets(string,12,config);
				fscanf(config,"%s\n", color[3]);
			}
			else if (strstr(string, "le") !=NULL) {
				fgets(string,17,config);
				fscanf(config,"%d\n", &leave);
			}
			else if (strstr(string, "Be") !=NULL) {
				fgets(string,12,config);
				fgets(beadPos,30,config);
			}
		}		
	}
	fclose(config);
}
int newGame(int &flag,int &counter,int &temp,int &again,int &swLeave,int &term,int &sw ,int &winner1 ,int &winner2 ,int &amar1,int &amar2 , char color[][8], char beadPos[], int board[][100], int& x1, int& y01, int& n, int& pnum, int &leave, int& max, int& games, int& turn, struct playerCo &pCo) {
	turn = 4;
	games = 1;
	winner2 = 20;
	if (pnum == 4) {
		winner2=0;
		games = 2;
	}
	structComplete(color,pCo);
	for(i=0;i<2*n;i++){
		for(j=0;j<3*n;j++){
			board[i][j]=0;
		}
	}
	clearScreen();
	beadPosition(n, board, beadPos, pnum, max);
	int m = 2 * n, p = 3 * n, y = 2;
	//makan avvaliye pointer
	gotoxy((-5 * n) + 105, y);
	if (n % 2 == 0)x1 = n - 1;
	else x1 = n;
	if ((p / 2) % 3 == 0)y01 = p / 2 + 1;
	else if ((p / 2) % 3 == 2)y01 = p / 2 - 1;
	else y01 = p / 2;
	board[x1][y01] = 11;
	printMap(n, board, pCo);
	for(i=0;i<2*n;i++){
		for(j=0;j<3*n;j++){
			lastest[i][j] = 0 ;
		}
	}
	winner1 = amar1 = amar2 = 0;
	term = flag = 1;
	sw =  1;
	counter = temp = again =swLeave = 0;
	return 1;	
}

int saveGame(int max,int games,int pnum,int temp,struct playerCo pCo, int board[][100], int lastest[][8], int n, int turn, int term, int winner1, int winner2, int amar1, int amar2, int leave, int counter,  int x1, int y01, int x2, int y2){//winner1 va 2 baraye charkhidane nobat
	int p=3*n;
	FILE* save;
	save = fopen("save.bin", "wb");
	fwrite(&n, sizeof(int), 1, save);
	fwrite(&turn, sizeof(int), 1, save);
	fwrite(&x1, sizeof(int), 1, save);
	fwrite(&y01, sizeof(int), 1, save);
	fwrite(&x2, sizeof(int), 1, save);
	fwrite(&y2, sizeof(int), 1, save);
	fwrite(&winner1, sizeof(int), 1, save);
	fwrite(&winner2, sizeof(int), 1, save);
	fwrite(&amar1, sizeof(int), 1, save);
	fwrite(&amar2, sizeof(int), 1, save);
	fwrite(&temp, sizeof(int), 1, save);
	fwrite(&leave, sizeof(int), 1, save);
	fwrite(&counter, sizeof(int), 1, save);
	fwrite(&term, sizeof(int), 1, save);
	fwrite(&pnum, sizeof(int), 1, save);
	fwrite(&games, sizeof(int), 1, save);
	fwrite(&max, sizeof(int), 1, save);
	fwrite(&pCo, sizeof(playerCo), 1, save);
	for(i=0;i<=2*n;i++){
		for(j=0;j<=3*n;j++){
			fwrite(&board[i][j], sizeof(int), 1 , save);		
		}
	}
	for(i=0;i<4;i++){
		for(j=0;j<8;j++){
			fwrite(&lastest[i][j], sizeof(int), 1, save);		
		}
	}
	fclose(save);
}

void load(int &max,int &games,int &pnum,int &temp,int board[][100],int lastest[][8],struct playerCo &pCo,int &n,int &turn,int &winner1,int &winner2,int &amar1,int &amar2,int &leave,int &counter,int &term,int &x1,int &y01,int &x2,int &y2){
	FILE* load;
	load = fopen("save.bin", "rb");
	fread(&n, sizeof(int), 1, load);
	fread(&turn, sizeof(int), 1, load);
	fread(&x1, sizeof(int), 1, load);
	fread(&y01, sizeof(int), 1, load);
	fread(&x2, sizeof(int), 1, load);
	fread(&y2, sizeof(int), 1, load);
	fread(&winner1, sizeof(int), 1, load);
	fread(&winner2, sizeof(int), 1, load);
	fread(&amar1, sizeof(int), 1, load);
	fread(&amar2, sizeof(int), 1, load);
	fread(&temp, sizeof(int), 1, load);
	fread(&leave, sizeof(int), 1, load);
	fread(&counter, sizeof(int), 1, load);
	fread(&term, sizeof(int), 1, load);
	fread(&pnum, sizeof(int), 1, load);
	fread(&games, sizeof(int), 1, load);
	fread(&max, sizeof(int), 1, load);
	fread(&pCo, sizeof(playerCo), 1, load);
	for(i=0;i<=2*n;i++){
		for(j=0;j<=3*n;j++){
			fread(&board[i][j], sizeof(int), 1, load);
		}
	}
	for(i=0;i<4;i++){
		for(j=0;j<8;j++){
			fread(&lastest[i][j], sizeof(int), 1, load);	
		}
	}
	fclose(load);
	flag=1;
	if(turn==1)turn=4;
	else turn--;
	clearScreen();
	printMap(n,board,pCo);
}

int pointer(int n, int& flag, int board[][100], int lastest[][8], int& x1, int& y01, int& x2, int& y2, int term, int turn, int& temp,struct playerCo pCo, int winner1, int winner2, int amar1, int amar2, int leave, int counter, int& games) {
	int m = 2 * n, p = 3 * n, y = 2, swi1 = 1, swi = 1;
	if (flag == 0) {

		x1 = x2;
		y01 = y2;
	}
	//daryaft harakate pointer ba keyboard
	while (swi1 == 1 && term == 1) {
		_kbhit();
		char c = getch();
		switch (c) {
		case 72://bala
			if (x1 - 2 > 0) {
				x1 = x1 - 2;
				board[x1 + 2][y01] = temp;
				temp = board[x1][y01];
				board[x1][y01] = 11;//pointer						
			}
			printMap(n, board, pCo);
			break;
		case 77://rast
			if (y01 + 3 < p) {
				y01 = y01 + 3;
				board[x1][y01 - 3] = temp;
				temp = board[x1][y01];
				board[x1][y01] = 11;
			}
			printMap(n, board, pCo);
			break;
		case 80://payin	
			if (x1 + 2 < m) {
				x1 = x1 + 2;
				board[x1 - 2][y01] = temp;
				temp = board[x1][y01];
				board[x1][y01] = 11;
			}
			printMap(n, board, pCo);
			break;	
		case 75://chap
			if (y01 - 3 > 0) {
				y01 = y01 - 3;
				board[x1][y01 + 3] = temp;
				temp = board[x1][y01];
				board[x1][y01] = 11;
			}
			printMap(n, board, pCo);
			break;
		case 13://enter( entekhabe x1,y01 )
			if (temp == turn) {
				swi1 = 0;
				temp = 0;
				printMap(n, board, pCo);
			}
			break;
			//guzine haye menu safhe bazi
			//menu
		case 49://ba feshurdane 1 dar safheye bazi
			clearScreen();
			return 1;
			break;
			//zakhire bazi ba feshurdane 2 dar safheye bazi
		case 50://ZAKHIRE KARDANE BAZI 
			saveGame(max,games,pnum,temp,pCo, board, lastest, n, turn, term, winner1, winner2, amar1, amar2, leave, counter, x1, y01, x2, y2);//winner1 va 2 baraye charkhidane nobat
			colorizedText(10);
			gotoxy(3, 7);
			printf("THE GAME WAS SAVED SUCCESSFULLY!");
			sleep(2500);
			clearScreen();
			printMap(n,board,pCo);
			break;
			//ba feshurdane 3 dar safheye bazi
		case 51://EXIT
			games = 0;
			swi1 = 0;//az halghe X1 y01 kharej shavad.
			swi = 0;//vared halghe x2 y2 NASHAVAD.
			break;
		}
		flag = 0;
	}
	swi1 = 1;
	//term=2jump bade jump
	if (term == 0 || term == 1){//harkate binaghs va eshtebah
		x2 = x1;
		y2 = y01;
	}
	while (swi == 1) {
		_kbhit();
		char c = getch();
		switch (c) {
		case 72://bala
			if (x2 - 2 > 0) {
				x2 = x2 - 2;
				board[x2 + 2][y2] = temp;
				temp = board[x2][y2];
				board[x2][y2] = 11;//pointer	 
			}
			printMap(n, board, pCo);
			break;
		case 77://rast
			if (y2 + 3 < p) {
				y2 = y2 + 3;
				board[x2][y2 - 3] = temp;
				temp = board[x2][y2];
				board[x2][y2] = 11;
			}
			printMap(n, board, pCo);
			break;
		case 80://payin	
			if (x2 + 2 < m) {
				x2 = x2 + 2;
				board[x2 - 2][y2] = temp;
				temp = board[x2][y2];
				board[x2][y2] = 11;
			}
			printMap(n, board, pCo);
			break;
		case 75://chap	
			if (y2 - 3 > 0) {
				y2 = y2 - 3;
				board[x2][y2 + 3] = temp;
				temp = board[x2][y2];
				board[x2][y2] = 11;
			}
			printMap(n, board, pCo);
			break;
		case 13://enter( entekhabe x2,y2)
			if (temp != 0)printf("\a");
			if (temp == 0)swi = 0;
			break;
		}
	}swi = 1;
}
int play(/*int flagArray[][60],*/struct playerCo pCo, int pnum, int& turn, int& games, int& winner1, int& winner2, int& term, int& x1, int& y01, int& x2, int& y2, int again, int board[][100], int amar1, int amar2, int leave, int counter) {
	
	while (1) {
		playerTurn(winner1, winner2, pnum, turn, games, pCo);
		if(pCo.computer[turn-1]==1){
			while (sw == 1 && games != 0) {//nobat yek nafar
				if(pointer(n, flag, board, lastest, x1, y01, x2, y2, term, turn, temp, pCo, winner1, winner2, amar1, amar2, leave, counter, games)==1)return 2;//vaghti dar safhe bazi menu ra entekhab mikunad
				if (games == 0)break;//DAR SORATI KE EXIT ZADE SHAVAD (DAR SAFHEYE BAZI).
				char yesNo[5];
				int e = 0;
				xx1 = x1;
				yy01 = y01;
				//term harkate eshtebah va jump baad jump
				movement(n, turn, temp, x1, y01, x2, y2, again, board);
				int move = movement(n, turn, temp, x1, y01, x2, y2, again, board);//meghdari ke barmigardanad
				if (move == 0) {//wRONG move
					while (turn != pCo.turn[e]) {
						e++;
					}
					colorizedText(pCo.color[e] - 216);
					printf("WRONG move!\a");
					sleep(2000);
					clearScreen();
					if (board[x1][y01] == 11)temp = turn;
					else board[x1][y01] = turn;
					printMap(n, board, pCo);
				}
				else if (move == 1) {//jump sahih
					int sw3 = 1;
					while (sw3 == 1) {
						e = 0;
						while (turn != pCo.turn[e]) {
							e++;
						}
						colorizedText(pCo.color[e] - 216);
						printf("Do you want to jump again?(yes OR no)\a");
						sleep(2000);
						gets(yesNo);
						clearScreen();
						printMap(n, board, pCo);
						if (yesNo[0] == 'n') {
							sw = 0;
							sw3 = 0;
							term = 1;
						}
						else if (yesNo[0] == 'y') {
							e = 0;
							while (turn != pCo.turn[e]) {
								e++;
							}
							colorizedText(pCo.color[e] - 216);
							printf("choose the next destination\a");
							again++;
							sw3 = 0;
							term = 2;
							temp = 0;
						}
					}
				}
				else if (move == 2) {
					sw = 0;
					term = 1;
				}
				else {
					e = 0;
					while (turn != pCo.turn[e]) {
						e++;
					}
					colorizedText(pCo.color[e] - 216);
					printf("WRONG move!You can only JUMP!\a");
					sleep(2000);
					clearScreen();
					printMap(n, board, pCo);
					term = 2;
				}
			}
		}
		else{
			while(sw==1 && games!=0){
				computerArray(board, n,pCo,max,xi,yj);
				if(computerMove(xi,yj,n,turn,board)==0)sw=0;
			}
			printMap(n,board,pCo);
			sleep(1000);
		}
		sw = 1;
		again = 0;
		counter++;
		if (counter == leave)swLeave = 1;
		gotoxy(3, 2);
		colorizedText(13);//shumareshe makoos
		printf("remain of leave-camp-value:%d", leave - counter);
		endGame(/*flagArray,*/games,max,temp, board,lastest,n,winner1,winner2,swLeave,x1,y01,x2,y2,turn,pCo);
		winLose(key1,key2,amar1, amar2, games, winner1, winner2, temp, n, board, pCo);
		if (games == 0)return 1;
	}
}

#endif
