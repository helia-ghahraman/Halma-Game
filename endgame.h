#pragma once
#ifndef HEADER4_FILE
#define HEADER4_FILE

#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include<math.h>
#include<stdlib.h>
#include"bead_map.h"
#include "important.h"

/*int muhasere(int temp,int flagArray[][60], int board[][100], int n,int i, int j){
	int p=3*n,m=2*n;
	int x1,y1,counter=0;
	flagArray[i][j]=1;
	for(x1=i-2; x1<i+3; x1+=2){//baraye check kardane mohre haye atraf
		for(y1=j-3; y1<j+4; y1+=3){//baraye check kardane mohre haye atraf
			//baraye dar mahdodeye safhe ye bazi bodan
			if(x1>0 && x1<m && y1>0 && y1<p&& x1!=i && y1!=j ){
				if( board[x1][y1]==0 )return 0;//muhasere  nashude}
				else if(board[x1][y1]==11 && temp==0)return 0;
				else if((board[x1][y1]!=board[i][j]&&board[x1][y1]!=0) ||(board[x1][y1]==11 && temp!=board[i][j])){//dushman bood
					counter++;
					int x2=2*x1-i, y2=2*y1-j;
					if(x2>0 && x2<m && y2>0 && y2<p ){//i2 va j2 khanehayi hastand ke nemikhahim muhasere barayeshan check shavad
						if(board[x2][y2]==0 )return 0;//muhasere  nashude
						else if(board[x2][y2]==11 && temp==0)return 0;//muhasere  nashude
						else if((board[x2][y2]!=board[i][j] && board[x2][y2]!=0)  ||(board[x2][y2]==11 && temp!=board[i][j])){
							counter++;//dushman bood
						}
					}
			    }
			}
		}
	}
	if(counter!=16){
		for(x1=i-2; x1<i+3; x1+=2){//baraye check kardane mohre haye atraf
			for(y1=j-3; y1<j+4; y1+=3){
				if(board[x1][y1]==board[i][j] && flagArray[x1][y1]!=1){
					if(muhasere(temp,flagArray,board,n,x1,y1)==0)return 0;
				}
			}
		}
	}
	return 1;//muhasere shude	
}


int mohasereCheck(int temp,int flagArray[][60],int n, int board[][100], int& winner1, int& winner2) {
	int i, j, p = 3 * n, m = 2 * n;
	for (i = 1; i < m; i += 2) {
		for (j = 1; j < p; j += 3) {
			if (board[i][j] != 0) {
				if (muhasere(temp,flagArray,board,n,i,j) == 1) {
					printf("* %d * %d *",i,j);
					sleep(5000);
					gotoxy(130,19);
					colorizedText(11);
					printf("mohasere");
					if (board[i][j] == 1)winner1 = 3;
					else if (board[i][j] == 3)winner1 = 1;
					else if (board[i][j] == 2)winner2 = 4;
					else if (board[i][j] == 4)winner2 = 2;
					
					printf("*%d %d*",winner1,winner2);
					sleep(3000);
				}
				for(i=0;i<40;i++){
					for(j=0;j<60;j++){
						flagArray[i][j]=0;
					}
				}
			}
			
		}
	}
	return 0;
}*/

int mohasere(int board[][100], int n, int i, int j) {
	int x1, y01, m = 2 * n, p = 3 * n;
	for (x1 = i - 2; x1 < i + 3; x1 += 2) {//baraye check kardane mohre haye atraf
		for (y01 = j - 3; y01 < j + 4; y01 += 3) {//baraye check kardane mohre haye atraf
			//baraye dar mahdodeye safhe ye bazi bodan
			//flagArray[i][j]=1;
			if (x1 > 0 && x1 < m && y01>0 && y01 < p && pow(x1 - i, 2) + pow(y01 - j, 2) != 0) {//be divar nakhurde
				if (board[x1][y01] == 0 || board[x1][y01] == board[i][j])return 0;//muhasere  nashude?!
				else {//roghaba
					int x2 = 2 * x1 - i, y2 = 2 * y01 - j;
					if (x2 > 0 && x2 < m && y2>0 && y2 < p) {
						if (board[x2][y2] == 0 || board[x1][y01] == board[i][j])return 0;//muhasere  nashude
					}
				}
			}
		}
	}
	return 1;//muhasere shude
}
int mohasereCheck(int n, int board[][100], int& winner1, int& winner2) {
	int i, j, p = 3 * n, m = 2 * n;
	for (i = 1; i < m; i += 2) {
		for (j = 1; j < p; j += 3) {
			if (board[i][j] != 0) {
				if (mohasere(board, n, i, j) == 1) {
					printf("mohasere");
					sleep(8000);
					if (board[i][j] == 1)winner1 = 3;
					else if (board[i][j] == 3)winner1 = 1;
					else if (board[i][j] == 2)winner2 = 4;
					else if (board[i][j] == 4)winner2 = 2;
				}
			}
		}
	}
	return 0;
}
int tasaviKhas(int leave, int n, int turn, int x1, int y01, int x2, int y2, int& winner1, int& winner2, int lastest[][8], int board[][100], playerCo pCo) {
	int i, j, flag = 0, a = 0;
	int e = 0;
	char draw[6], answer[5];
	for (i = 2; i < 4; i++) {
		for (j = 2 * turn - 2; j < 2 * turn; j++) {
			lastest[i - 2][j] = lastest[i][j];
		}
	}
	lastest[i - 2][2 * turn - 2] = x1;
	lastest[i - 2][2 * turn - 1] = y01;
	lastest[i - 1][2 * turn - 2] = x2;
	lastest[i - 1][2 * turn - 1] = y2;
	//barrasi emkane tasavi
	if (lastest[0][2 * turn - 2] == lastest[3][2 * turn - 2] && lastest[0][2 * turn - 1] == lastest[3][2 * turn - 1] && lastest[1][2 * turn - 2] == lastest[2][2 * turn - 2] && lastest[1][2 * turn - 1] == lastest[2][2 * turn - 1]) {
		int a;
		switch (turn) {
		case 1:
			a = 4;
			break;
		case 2:
			a = 6;
			break;
		case 3:
			a = 0;
			break;
		case 4:
			a = 2;
			break;
		}
		if (lastest[0][a] == lastest[3][a] && lastest[0][a + 1] == lastest[3][a + 1] && lastest[1][a] == lastest[2][a] && lastest[1][a + 1] == lastest[2][a + 1])flag = 1;//mogheiyase harif
	}
	if (flag == 1 && leave == 1) {
		gotoxy(3, 3);
		while (turn != pCo.turn[e]) {
			e++;
		}
		colorizedText(pCo.color[e] - 216);
		printf("if you want to offer draw , enter 'draw' .if not, enter something else:");
		scanf("%s", draw);
		if (strcmp(draw, "draw") == 0) {
			if (e == 0 || e == 1)colorizedText(pCo.color[e + 2] - 216);
			else colorizedText(pCo.color[e - 2] - 216);
			printf("    your rival offers a DRAW . Do you accept?(yes or no)");//56
			
			if(pCo.computer[turn-1]==1){//harif adam ast
				gets(answer);
				gets(answer);
				if (strcmp(answer, "yes") == 0) {
					if (turn == 1 || turn == 3)winner1 = 13;//tasavi 1 va 3
					else winner2 = 24;//tasavi 2 va 4
					gotoxy(130,19);
					colorizedText(11);
					printf("TASAVI KHAS");
					sleep(3000);
				}
			}
			else{//harif computer ast
				srand(time(NULL));
				char com_answer[2][5];
				strcpy(com_answer[0],"YES");
				strcpy(com_answer[1],"NO");
				int random = rand()% 2;
				gotoxy(59,4);
				printf("%s",com_answer[random]);
				if(random==0){
					if (turn == 1 || turn == 3)winner1 = 13;//tasavi 1 va 3
					else winner2 = 24;//tasavi 2 va 4
					gotoxy(130,19);
					colorizedText(11);
					printf("TASAVI KHAS");
					sleep(3000);
				}
			}
		}
		clearScreen();
		printMap(n, board, pCo);
	}
	return 0;
}
int tasahubeCamp(int turn,int max, int temp, int n, int board[][100], int& winner1, int& winner2) {
	int i, j, r = -3;
	int p = 3 * n, m = 2 * n, sw1 = 1, sw2 = 1, sw3 = 1, sw4 = 1;
	for (i = 1; i < 2 * max; i += 2) {//bala-chap va rast
		for (j = 1; j < p; j += 3) {
			if (i == 1 || i == 3) {
				if (j < 3 * max) {
					if (board[i][j] == 11) {
						if (temp != 3)sw3 = 0;//shayad pointer dar khanei az camp bashad. aan khane ham bayad check shavad.	
					}
					else if (board[i][j] != 3)sw3 = 0;//bazi 1
				}
				if (j > p - (3 * max)) {
					if (board[i][j] == 11) {
						if (temp != 4)sw4 = 0;//shayad pointer dar khanei az camp bashad. aan khane ham bayad check shavad.	
					}
					else if (board[i][j] != 4)sw4 = 0;//bazi 2
				}
			}
			else {
				if (j < 3 * max - r) {
					if (board[i][j] == 11) {
						if (temp != 3)sw3 = 0;//shayad pointer dar khanei az camp bashad. aan khane ham bayad check shavad.	
					}
					else if (board[i][j] != 3)sw3 = 0;
				}
				if (j > p - (3 * max) + r) {
					if (board[i][j] == 11) {
						if (temp != 4)sw4 = 0;//shayad pointer dar khanei az camp bashad. aan khane ham bayad check shavad.	
					}
					else if (board[i][j] != 4)sw4 = 0;
				}
			}
		}r += 3;
	}
	r = -3;
	for (i = m - 1; i > m - (2 * max); i -= 2) {//payin-chap va rast
		for (j = 1; j < p; j += 3) {
			if (i == m - 1 || i == m - 3) {
				if (j > p - (3 * max)) {
					if (board[i][j] == 11) {
						if (temp != 1)sw1 = 0;//shayad pointer dar khanei az camp bashad. aan khane ham bayad check shavad.	
					}
					else if (board[i][j] != 1)sw1 = 0;//bazi 1
				}
				if (j < 3 * max) {
					if (board[i][j] == 11) {
						if (temp != 2)sw2 = 0;//shayad pointer dar khanei az camp bashad. aan khane ham bayad check shavad.	
					}
					else if (board[i][j] != 2)sw2 = 0;//bazi 2
				}
			}
			else {
				if (j > p - (3 * max) + r) {
					if (board[i][j] == 11) {
						if (temp != 1)sw1 = 0;//shayad pointer dar khanei az camp bashad. aan khane ham bayad check shavad.	
					}
					else if (board[i][j] != 1)sw1 = 0;
				}
				if (j < 3 * max - r) {
					if (board[i][j] == 11) {
						if (temp != 2)sw2 = 0;//shayad pointer dar khanei az camp bashad. aan khane ham bayad check shavad.	
					}
					else if (board[i][j] != 2)sw2 = 0;
				}
			}
		}
		r += 3;
	}
	
	int e = 0;
	while (turn != pCo.turn[e]) {
		e++;
	}
	colorizedText(pCo.color[e] - 216);
	if (sw1 == 1){
		gotoxy(130,19);
		printf("tasahube urdogah");
		winner1 = 1;
	}
	if (sw2 == 1){
		gotoxy(130,19);
		printf("tasahube urdogah");
		winner2 = 2;
	}
	if (sw3 == 1){
		gotoxy(130,19);
		printf("tasahube urdogah");
		winner1 = 3;
	}
	if (sw4 == 1){
		gotoxy(130,19);
		printf("tasahube urdogah");
		winner2 = 4;
	}
	//sleep(2000);
		
	return 0;
}
int ghanoneKhas(int leave, int n, int board[][100], int& winner1, int& winner2, int max, int temp) {
	int i, j, p = 3 * n, m = 2 * n, r = -3;
	int sw1 = 1, sw2 = 1, sw3 = 1, sw4 = 1;
	for (i = 1; i < 2 * max; i += 2) {//bala-chap va rast
		for (j = 1; j < p; j += 3) {
			if (i == 1 || i == 3) {
				if (j < 3 * max) {
					if (board[i][j] == 11) {
						if (temp == 1)sw1 = 0;//shayad pointer dar khanei az camp bashad. aan khane ham bayad check shavad.	
					}
					else if (board[i][j] == 1)sw1 = 0;//bazi 1
				}
				if (j > p - (3 * max)) {
					if (board[i][j] == 11) {
						if (temp == 2)sw2 = 0;//shayad pointer dar khanei az camp bashad. aan khane ham bayad check shavad.	
					}
					else if (board[i][j] == 2)sw2 = 0;//bazi 2
				}
			}
			else {
				if (j < 3 * max - r) {
					if (board[i][j] == 11) {
						if (temp == 1)sw1 = 0;//shayad pointer dar khanei az camp bashad. aan khane ham bayad check shavad.	
					}
					else if (board[i][j] == 1)sw1 = 0;
				}
				if (j > p - (3 * max) + r) {
					if (board[i][j] == 11) {
						if (temp == 2)sw2 = 0;//shayad pointer dar khanei az camp bashad. aan khane ham bayad check shavad.	
					}
					else if (board[i][j] == 2)sw2 = 0;
				}
			}
		}r += 3;
	}
	r = -3;
	for (i = m - 1; i > m - (2 * max); i -= 2) {//payin-chap va rast
		for (j = 1; j < p; j += 3) {
			if (i == m - 1 || i == m - 3) {
				if (j > p - (3 * max)) {
					if (board[i][j] == 11) {
						if (temp == 3)sw3 = 0;//shayad pointer dar khanei az camp bashad. aan khane ham bayad check shavad.	
					}
					else if (board[i][j] == 3)sw3 = 0;//bazi 1
				}
				if (j < 3 * max) {
					if (board[i][j] == 11) {
						if (temp == 4)sw4 = 0;//shayad pointer dar khanei az camp bashad. aan khane ham bayad check shavad.	
					}
					else if (board[i][j] == 4)sw4 = 0;//bazi 2
				}
			}
			else {
				if (j > p - (3 * max) + r) {
					if (board[i][j] == 11) {
						if (temp == 3)sw3 = 0;//shayad pointer dar khanei az camp bashad. aan khane ham bayad check shavad.	
					}
					else if (board[i][j] == 3)sw3 = 0;
				}
				if (j < 3 * max - r) {
					if (board[i][j] == 11) {
						if (temp == 4)sw4 = 0;//shayad pointer dar khanei az camp bashad. aan khane ham bayad check shavad.	
					}
					else if (board[i][j] == 4)sw4 = 0;
				}
			}
		}r += 3;
	}
	if (leave == 1) {
			
		if (sw1 == 0 && sw3 == 0){
			winner1 = 13;//tasavi
			gotoxy(130,19);
			colorizedText(11);
			printf("END OF THE LEAVE-CAMP-VALUE");
		}
		else if (sw1 == 0 && sw3 != 0){
			winner1 = 3;//borde 3rd player
			gotoxy(130,19);
			colorizedText(pCo.color[2]-216);
			printf("END OF THE LEAVE-CAMP-VALUE");
		}	
		else if (sw1 != 0 && sw3 == 0){
			winner1 = 1;//borde 1st player
			gotoxy(130,19);
			colorizedText(pCo.color[0]-216);
			printf("END OF THE LEAVE-CAMP-VALUE");
		}
		if (sw2 == 0 && sw4 == 0){
			winner2 = 24;//tasavi
			gotoxy(130,19);
			colorizedText(11);
			printf("END OF THE LEAVE-CAMP-VALUE");
		}
		else if (sw2 == 0 && sw4 != 0){
			winner2 = 4;//borde 4th player
			gotoxy(130,19);
			colorizedText(pCo.color[3]-216);
			printf("END OF THE LEAVE-CAMP-VALUE");
		}
		else if (sw2 != 0 && sw4 == 0){
			winner2 = 2;//borde 2nd player
			gotoxy(130,19);
			colorizedText(pCo.color[1]-216);
			printf("END OF THE LEAVE-CAMP-VALUE");
		}
	}
}

//in tabe shart haye payane bazi ra check mikunad
int endGame(/*int flagArray[][60],*/int games,int max, int temp, int board[][100], int lastest[][8], int n, int& winner1, int& winner2, int swLeave, int x1, int y01, int x2, int y2, int turn, playerCo pCo) {
	ghanoneKhas(swLeave, n, board, winner1, winner2, max, temp);//leave-camp-value
	tasahubeCamp(turn,max, temp, n, board, winner1, winner2);
	mohasereCheck(/*temp,flagArray,*/n,board,winner1, winner2);
	tasaviKhas(swLeave, n, turn, x1, y01, x2, y2, winner1, winner2, lastest, board, pCo);
	
    //printf("*%d-%d-%d*",winner1,winner2,games);
	//sleep(7000);


/*	int v,w;
	gotoxy(45,45);
	for(v=0;v<4;v++){

		for(w=0;w<8;w++){
			printf("%d ",lastest[v][w]);
		}
		printf("\n");
	}*/
}

int beadDelete(int &games,int& key1, int& key2, int& temp, int n, int board[][100], playerCo pCo) {
	int i, j, p = 3 * n, m = 2 * n;
	if (key1== 1) {//hazf mohre ha
		for (i = 1; i < m; i += 2) {//hazf mohre haye 1 va 3 az bazi
			for (j = 1; j < p; j += 3) {
				if (board[i][j] == 1 || board[i][j] == 3)board[i][j] = 0;
			}
		}
		if (temp == 1 || temp == 3)temp = 0;//hazf mohrei ke akharin harkat ra karde
		gotoxy(130, 21);
		printf("game 1 ended.");
		sleep(7000);
		clearScreen();
		printMap(n, board, pCo);
		//winner1 = -2;
		games--;
		key1=0;
	}
	if (key2 == 1) {//hazf mohre ha
		for (i = 1; i < m; i += 2) {//hazf mohre haye 1 va 3 az bazi
			for (j = 1; j < p; j += 3) {
				if (board[i][j] == 2 || board[i][j] == 4)board[i][j] = 0;
			}
		}
		if (temp == 2 || temp == 4)temp = 0;//hazf mohrei ke akharin harkat ra karde
		gotoxy(130, 21);
		printf("game 2 ended.");
		sleep(7000);
		clearScreen();
		printMap(n, board, pCo);
		//winner2 = -2;
		games--;
		key2=0;
	}
}
int winLose(int &key1,int &key2,int &amar1,int &amar2,int& games, int& winner1, int& winner2, int& temp, int n, int board[][100], playerCo pCo) {
	int i, j, m = 2 * n, p = 3 * n;
	key1=0,key2=0;
	gotoxy(130, 20);
	switch (winner1) {
	case 1:
		//amar1=winner1;
		colorizedText(pCo.color[0] - 216);
		printf("1st player won!\n");
		winner1 = 10;
		key1=1;
		break;
	case 3:
		//amar1=winner1;
		colorizedText(pCo.color[2] - 216);
		printf("2nd player won!\n");
		winner1 = 30;
		key1=1;
		break;
	case 13:
		//amar1=winner1;
		colorizedText(11);
		printf("DRAW in the game 1 !\n");
		winner1 = 130;
		key1=1;
		break;
	}
	beadDelete(games,key1, key2, temp, n, board, pCo);
	gotoxy(130, 20);
	switch (winner2) {
	case 2:
		//amar2=winner2;
		colorizedText(pCo.color[1] - 216);
		printf("1st player won!\n");
		winner2 = 20;
		key2=1;
		break;
	case 4:
		//amar2=winner2;
		colorizedText(pCo.color[3] - 216);
		printf("2nd player won!\n");
		winner2 = 40;
		key2=1;
		break;
	case 24:
		//amar2=winner2;
		colorizedText(11);
		printf("DRAW in the game 2 !\n");
		winner2 = 240;
		key2=1;
		break;
	}
	beadDelete(games,key1, key2, temp, n, board, pCo);
}
#endif
