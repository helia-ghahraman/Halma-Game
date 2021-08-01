#pragma once

#ifndef HEADER6_FILE
#define HEADER6_FILE

#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "important.h"
#include"log_sign.h"
#include"endgame.h"

void mainOptions(char list3[][16]) {
    strcpy(list3[0], " GAME STATICS");
    strcpy(list3[1], "PLAYER STATICS");
    strcpy(list3[2], "COMPUTER RIVAL");
    strcpy(list3[3], "  HUMAN RIVAL");
    strcpy(list3[4], "   NEW GAME");
    strcpy(list3[5], " RESUME GAME");
    strcpy(list3[6], "    RULES");
    strcpy(list3[7], "    EXIT");
    gotoxy(88, 10);
    colorizedText(3);
    printf("%s", list3[0]);
    colorizedText(8);
    gotoxy(88, 14);
    printf("%s", list3[1]);
    gotoxy(88, 18);
    printf("%s", list3[2]);
    gotoxy(88, 22);
    printf("%s", list3[3]);
    gotoxy(88, 26);
    printf("%s", list3[4]);
    gotoxy(88, 30);
    printf("%s", list3[5]);
    gotoxy(88, 34);
    printf("%s", list3[6]);
    gotoxy(88, 38);
    printf("%s", list3[7]);
}

void print3(char list3[][16]) {
    const int iMenu = 33;
    const int jMenu = 30;
    char Menu[iMenu][jMenu];
    for (int i = 0; i < iMenu; i++) {
        for (int j = 0; j < jMenu; j++) {
            //Top
            if (i == 0) {
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
            //Down
            else if (i == iMenu - 1) {
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
            else if (i > 0 && i < iMenu - 1 && i != 4 && i != 8 && i != 12 && i != 16 && i != 20 && i != 24 && i != 28) {
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
            else if (i == 12) {
                if (j == 0) Menu[i][j] = 204;
                else if (j == jMenu - 1) Menu[i][j] = 185;
                else Menu[i][j] = 205;
            }
            else if (i == 16) {
                if (j == 0) Menu[i][j] = 204;
                else if (j == jMenu - 1) Menu[i][j] = 185;
                else Menu[i][j] = 205;
            }
            else if (i == 20) {
                if (j == 0) Menu[i][j] = 204;
                else if (j == jMenu - 1) Menu[i][j] = 185;
                else Menu[i][j] = 205;
            }
            else if (i == 24) {
                if (j == 0) Menu[i][j] = 204;
                else if (j == jMenu - 1) Menu[i][j] = 185;
                else Menu[i][j] = 205;
            }
            else if (i == 28) {
                if (j == 0) Menu[i][j] = 204;
                else if (j == jMenu - 1) Menu[i][j] = 185;
                else Menu[i][j] = 205;
            }
        }
    }
    //print
    int l = 8;
    for (int i = 0; i < iMenu; i++) {
        for (int j = 0; j < jMenu; j++) {
            colorizedText(8);
            gotoxy(80 + j, l);
            printf("%c", Menu[i][j]);
            colorizedText(15);
        }
        l++;
        printf("\n");
    }
    mainOptions(list3);
}
void moveMenu2(char list3[][16], int& option1, char recUsername[], char recPassword[]) {
    char v = getch();
    int h = 10;
    while (v != 13) { //choosing between options!!!
        if (_kbhit) {
            //up
            if (v == 72) {
                colorizedText(8);
                gotoxy(88, h);
                printf("%s", list3[option1]);
                if (option1 == 0) option1 = 7;
                else option1--;
                if (h == 10) h = 38;
                else h -= 4;
                gotoxy(88, h);
                colorizedText(3);
                printf("%s", list3[option1]);
                colorizedText(8);
            }
            //down
            else if (v == 80) {
                colorizedText(8);
                gotoxy(88, h);
                printf("%s", list3[option1]);
                if (option1 == 7) option1 = 0;
                else option1++;
                if (h == 38) h = 10;
                else h += 4;
                gotoxy(88, h);
                colorizedText(3);
                printf("%s", list3[option1]);
                colorizedText(8);
            }
        }
        v = getch();
    }
}
//////////////////////
int GameStatics() {
    FILE * gameStatus;
    int playNum, win, draw, lose;
    char best[20], weak[20];
    gameStatus = fopen("gameStatics.dat", "rb");
    if(!gameStatus){
    	printf("ERROR404!");
		return 1;
	}
    fread(&playNum ,sizeof(int),1,gameStatus);
    fread(&win ,sizeof(int),1,gameStatus);
    fread(&draw ,sizeof(int),1,gameStatus);
    fread(&lose,sizeof(int),1,gameStatus);
    fread(best ,20*sizeof(char),1,gameStatus);
    fread(weak ,20*sizeof(char),1,gameStatus);
    clearScreen();
    colorizedText(10);
    gotoxy(40, 11);
    printf("G A M E   S T A T I C S");
    colorizedText(2);
    gotoxy(40, 14);
    printf("NUMBER OF GAMES: %d", playNum);
    gotoxy(40, 16);
    printf("NUMBER OF WIN: %d", win);
    gotoxy(40, 18);
    printf("NUMBER OF DRAW: %d", draw);
    gotoxy(40, 20);
    printf("NUMBER OF LOSE: %d", lose);
    gotoxy(40, 22);
    printf("BEST PLAYER: %s", best);
    gotoxy(40, 24);
    printf("WEAK PLAYER: %s", weak);
    fclose(gameStatus);

}

int sefr(){
	FILE *sefr;
	sefr= fopen("gameStatics.dat","wb");
	int playNum=0, win=0, draw=0,lose=0;
	char best[20]={"unknown"}, weak[20]={"unknown"};
	fwrite(&playNum ,sizeof(int),1,sefr);
    fwrite(&win ,sizeof(int),1,sefr);
    fwrite(&draw ,sizeof(int),1,sefr);
    fwrite(&lose,sizeof(int),1,sefr);
    fwrite(best,20*sizeof(char),1,sefr);
    fwrite(weak,20*sizeof(char),1,sefr);
    fclose(sefr);
}

int GS_numbers(int winner1,int winner2,int &swWinner2){//game statics numbers
	int playNum, win, draw, lose;
    char best[20], weak[20];
	FILE *gs;
	gs=fopen("gameStatics.dat","r+b");
	if(!gs){
		printf("Error6");
		return 0;
	}
	fread(&playNum ,sizeof(int),1,gs);
    fread(&win ,sizeof(int),1,gs);
    fread(&draw ,sizeof(int),1,gs);
    fread(&lose,sizeof(int),1,gs);
	switch(winner1){
		case 10:
		case 30:
			win++;
			lose++;
			playNum++;
			break;
		case 130:
			draw++;
			playNum++;
			break;
	}
	if(swWinner2==1){
		switch(winner2){
		case 20:
		case 40:
			win++;
			lose++;
			playNum++;
			break;
		case 240:
			draw++;
			playNum++;
			break;
		}
	}
	fseek(gs,0,SEEK_SET);//enteghale eshare gar be avvale file.
	fwrite(&playNum ,sizeof(int),1,gs);
    fwrite(&win ,sizeof(int),1,gs);
    fwrite(&draw ,sizeof(int),1,gs);
    fwrite(&lose,sizeof(int),1,gs);
	fclose(gs);
}

int GS_Best(){
	FILE *Best;
	int Win,Draw,Lose;
	struct player BestP;//havi amre tamami bazikon hayi ba borde bishtar
	Best=fopen("players.dat","rb");
	if(!Best){
		printf("ERROR9!");
		return 1;
	}
	fread(&BestP,sizeof(player),1,Best);
	fseek(Best,40 *sizeof(char),SEEK_CUR);
	fread(&Win,sizeof(int),1,Best);
	while(!feof(Best)){
		if(Win>BestP.win){
			fseek(Best,-1L*sizeof(int),SEEK_CUR);
			fseek(Best,-40L *sizeof(char),SEEK_CUR);
			fread(&BestP,sizeof(player),1,Best);
		}
		else if(Win==BestP.win){
			fseek(Best,1L*sizeof(int),SEEK_CUR);//avale draw
			fread(&Draw,sizeof(int),1,Best);
			if(BestP.draw < Draw){
				fseek(Best,-3L*sizeof(int),SEEK_CUR);
				fseek(Best,-40L *sizeof(char),SEEK_CUR);
				fread(&BestP,sizeof(player),1,Best);
			}
			else if(BestP.draw ==Draw){//tasavi tasavi ha (XD)
				fseek(Best,-2L*sizeof(int),SEEK_CUR);//avale lose
				fread(&Lose,sizeof(int),1,Best);
				if(BestP.lose > Lose){
					fseek(Best,-2L*sizeof(int),SEEK_CUR);
					fseek(Best,-40L *sizeof(char),SEEK_CUR);
					fread(&BestP,sizeof(player),1,Best);
				}
				else fseek(Best,1L*sizeof(int),SEEK_CUR);
			}
		}
		else fseek(Best,2*sizeof(int),SEEK_CUR);
		fseek(Best,40 *sizeof(char),SEEK_CUR);
		fread(&Win,sizeof(int),1,Best);
	}
	fclose(Best);
	int uLen;
	FILE *gst;//game statics
	gst=fopen("gameStatics.dat","r+b");
	if(!gst){
		printf("Error7");
		return 0;
	}
	fseek(gst,4*sizeof(int),SEEK_SET);
	uLen = strlen(BestP.username);
	for(i=0;i<uLen;i++)BestP.username[i]-=80;//ramzgushayi
	fwrite(BestP.username,20*sizeof(char),1,gst);
	fclose(gst);
}

int GS_Weak(){
	FILE *Weak;
	int Win,Draw,Lose;
	struct player WeakP;//havi amre tamami bazikon hayi ba borde bishtar
	Weak=fopen("players.dat","rb");
	if(!Weak){
		printf("ERROR10!");
		return 1;
	}
	fread(&WeakP,sizeof(player),1,Weak);
	fseek(Weak,40 *sizeof(char),SEEK_CUR);
	fseek(Weak,1*sizeof(int),SEEK_CUR);//avvale lose
	fread(&Lose,sizeof(int),1,Weak);
	while(!feof(Weak)){
		if(Lose>WeakP.lose){
			fseek(Weak,-2L*sizeof(int),SEEK_CUR);
			fseek(Weak,-40L *sizeof(char),SEEK_CUR);
			fread(&WeakP,sizeof(player),1,Weak);
		}
		else if(Lose==WeakP.lose){
			fread(&Draw,sizeof(int),1,Weak);
			if(WeakP.draw > Draw){
				fseek(Weak,-3L*sizeof(int),SEEK_CUR);
				fseek(Weak,-40L *sizeof(char),SEEK_CUR);
				fread(&WeakP,sizeof(player),1,Weak);
			}
			else if(WeakP.draw ==Draw){//tasavi tasavi ha (XD)
				fseek(Weak,-3L*sizeof(int),SEEK_CUR);//avale lose
				fread(&Win,sizeof(int),1,Weak);
				if(WeakP.win > Win){
					fseek(Weak,-1L*sizeof(int),SEEK_CUR);
					fseek(Weak,-40L *sizeof(char),SEEK_CUR);
					fread(&WeakP,sizeof(player),1,Weak);
				}
				else fseek(Weak,2L*sizeof(int),SEEK_CUR);
			}
		}
		else fseek(Weak,1*sizeof(int),SEEK_CUR);
		fseek(Weak,40 *sizeof(char),SEEK_CUR);
		fseek(Weak,1*sizeof(int),SEEK_CUR);//avvale lose
		fread(&Lose,sizeof(int),1,Weak);
	}
	fclose(Weak);
	int uLen;
	FILE *gst;//game statics
	gst=fopen("gameStatics.dat","r+b");
	if(!gst){
		printf("Error11");
		return 0;
	}
	fseek(gst,4*sizeof(int),SEEK_SET);
	fseek(gst,20*sizeof(char),SEEK_CUR);//avvale weak player 
	uLen = strlen(WeakP.username);
	for(i=0;i<uLen;i++)WeakP.username[i]-=80;//ramzgushayi
	fwrite(WeakP.username,20*sizeof(char),1,gst);
	fclose(gst);
}

void GS_update(int winner1,int winner2, int &swWinner2){
	GS_numbers(winner1,winner2 , swWinner2);
	GS_Best();
	GS_Weak();
}
/////////////

int PlayerStatics(char recUsername[], char recPassword[]) {
    FILE* pStatics;
    int sw = 0;
    pStatics = fopen("players.dat", "rb");
    if (!pStatics) {
        printf("ERROR3!");
        return 1;
    }
    struct player temp;
    fseek(pStatics, -1L * sizeof(player), SEEK_END);
    while (sw == 0) {
        fread(&temp, sizeof(player), 1, pStatics);
        if (strcmp(temp.username, recUsername) == 0 && strcmp(temp.password, recPassword) == 0) {
           	sw = 1;
        }
        else fseek(pStatics, -2L * sizeof(player), SEEK_CUR);
    }
    fclose(pStatics);
    clearScreen();
    colorizedText(10);
    gotoxy(40, 11);
    printf("P L A Y E R   S T A T I C S");
    colorizedText(2);
    gotoxy(40, 14);
    printf("NUMBER OF GAMES: %d", temp.draw + temp.win + temp.lose);
    gotoxy(40, 16);
    printf("NUMBER OF WIN: %d", temp.win);
    gotoxy(40, 18);
    printf("NUMBER OF DRAW: %d", temp.draw);
    gotoxy(40, 20);
    printf("NUMBER OF LOSE: %d", temp.lose);
}

int PS_update(int winner1,char recUsername[],char recPassword[]){//player statics update
	int win, lose,draw;
	FILE *playerStatus;
	playerStatus=fopen("players.dat","r+b");
	if(!playerStatus){
		printf("ERROR 8!");
		return 1;
	}
	struct player temp;
	fread(&temp, sizeof(player), 1, playerStatus);
	while (strcmp(temp.username, recUsername) != 0 || strcmp(temp.password, recPassword) != 0) {//yaft shud!
		fread(&temp, sizeof(player), 1, playerStatus);
	}
	switch(winner1){
		case 10:
			temp.win++;
			break;
		case 30:
			temp.lose++;
			break;	
		case 130:
			temp.draw++;
			break;
	}
	fseek(playerStatus,-1*sizeof(player),SEEK_CUR);
	fwrite(&temp ,sizeof(player),1,playerStatus);
	fclose(playerStatus);
}
///////////
void menuOptions(char list5[][16]) {
	strcpy(list5[0], " PLAYER1 (YOU)");
	strcpy(list5[1], "   PLAYER2");
	strcpy(list5[2], "  computer");
	strcpy(list5[3], "    human");
	strcpy(list5[4], "   PLAYER3");
	strcpy(list5[5], "   computer");
	strcpy(list5[6], "    human");
	strcpy(list5[7], "   PLAYER4");
	strcpy(list5[8], "   computer");
	strcpy(list5[9], "    human");
	gotoxy(88, 10);
	colorizedText(13);
	printf("%s", list5[0]);
	gotoxy(88, 14);
	printf("%s", list5[1]);
	gotoxy(88, 17);
	colorizedText(3);
	printf("%s", list5[2]);
	gotoxy(88, 19);
	colorizedText(8);
	printf("%s", list5[3]);
	gotoxy(88, 22);
	colorizedText(13);
	printf("%s", list5[4]);
	gotoxy(88, 25);
	colorizedText(8);
	printf("%s", list5[5]);
	gotoxy(88, 27);
	printf("%s", list5[6]);
	gotoxy(88, 30);
	colorizedText(13);
	printf("%s", list5[7]);
	gotoxy(88, 33);
	colorizedText(8);
	printf("%s", list5[8]);
	gotoxy(88, 35);
	printf("%s", list5[9]);
}

void print4(char list5[][16]) {
	const int iMenu = 29;
	const int jMenu = 30;
	char Menu[iMenu][jMenu];
	for (int i = 0; i < iMenu; i++) {
		for (int j = 0; j < jMenu; j++) {
			//Top
			if (i == 0) {
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
			//Down
			else if (i == iMenu - 1) {
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
			else if (i > 0 && i < iMenu - 1 && i != 4 && i != 8 && i != 10 && i != 12 && i != 16 && i != 18 && i != 20&& i != 24&& i != 26 && i != 28) {
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
			else if (i == 10) {
				if (j == 0) Menu[i][j] = 204;
				else if (j == jMenu - 1) Menu[i][j] = 185;
				else Menu[i][j] = 205;
			}
			else if (i == 12) {
				if (j == 0) Menu[i][j] = 204;
				else if (j == jMenu - 1) Menu[i][j] = 185;
				else Menu[i][j] = 205;
			}
			else if (i == 16) {
				if (j == 0) Menu[i][j] = 204;
				else if (j == jMenu - 1) Menu[i][j] = 185;
				else Menu[i][j] = 205;
			}
			else if (i == 18) {
				if (j == 0) Menu[i][j] = 204;
				else if (j == jMenu - 1) Menu[i][j] = 185;
				else Menu[i][j] = 205;
			}
			else if (i == 20) {
				if (j == 0) Menu[i][j] = 204;
				else if (j == jMenu - 1) Menu[i][j] = 185;
				else Menu[i][j] = 205;
			}
			else if (i == 24) {
				if (j == 0) Menu[i][j] = 204;
				else if (j == jMenu - 1) Menu[i][j] = 185;
				else Menu[i][j] = 205;
			}
			else if (i == 26) {
				if (j == 0) Menu[i][j] = 204;
				else if (j == jMenu - 1) Menu[i][j] = 185;
				else Menu[i][j] = 205;
			}
			else if (i == 28) {
				if (j == 0) Menu[i][j] = 204;
				else if (j == jMenu - 1) Menu[i][j] = 185;
				else Menu[i][j] = 205;
			}
		}
	}
	int l = 8;
	for (int i = 0; i < iMenu; i++) {
		for (int j = 0; j < jMenu; j++) {
			colorizedText(8);
			gotoxy(80 + j, l);
			printf("%c", Menu[i][j]);
			colorizedText(15);
		}
		l++;
		printf("\n");
	}
	gotoxy(85,38);
	colorizedText(13);
	printf("#PRESS 1 TO SUBMIT");
    menuOptions(list5);
}
int moveMenu3(char list5[][16],int &option2) {
	char v = getch();
	int h = 17;
	while (v != 13) { //choosing between menuOptions!!!
		if (_kbhit) {
			//up
			if (v == 72) {
				colorizedText(8);
				gotoxy(88, h);
				printf("%s", list5[option2]);
				if (option2 == 2) option2 = 9;
				else if(option2 == 3 ||option2 ==6 ||option2 == 9) option2--;
				else if(option2 == 5 ||option2 == 8) option2-=2;
				if (h == 17) h = 35;
				else if(h == 25||h == 33) h -= 6;
				else if(h == 19||h == 27||h == 35) h -= 2;
				gotoxy(88, h);
				colorizedText(3);
				printf("%s", list5[option2]);
				colorizedText(8);
			}
			//down
			else if (v == 80) {
				colorizedText(8);
				gotoxy(88, h);
				printf("%s", list5[option2]);
				if (option2 == 9) option2 = 2;
				else if(option2 == 3 ||option2 ==6) option2+=2;
				else if(option2 == 2 ||option2 == 5 ||option2 == 8) option2++;
				if (h == 35) h = 17;
				else if(h == 25||h == 33|| h==17) h += 2;
				else if(h == 19||h == 27) h += 6;
				gotoxy(88, h);
				colorizedText(3);
				printf("%s", list5[option2]);
				colorizedText(8);
			}
			//submit
			else if(v==49){
				return 1;
			}
		}
		v = getch();
	}
}
void rules() {
     gotoxy(15, 1);
     colorizedText(13);
     printf("HEY WELCOME TO THE GAME !");
      gotoxy(3, 3);
     colorizedText(13);
     printf("1)YOU CAN CHOOSE PLAY FOR TWO OR FOUR PEOPLE.");
      gotoxy(3, 5);
     colorizedText(13);
     printf("2)YOU CAN CHOOSE THE PLAY WITH YOUR FRIENDS OR");
     gotoxy(4, 6);
     colorizedText(13);
     printf("PLAY WITH THE COMPUTER.");
      gotoxy(3, 8);
     colorizedText(13);
     printf("3)YOU HAVE TO GET ALL YOUR PIESCE TO THE OPPONENT'S");
     gotoxy(4, 9);
     colorizedText(13);
     printf("PLAYING FIELD IN FRONT OF YOU.");
      gotoxy(3, 11);
     colorizedText(13);
     printf("4)AND UNTIL THE LEAVE_CAMP COUNT IS COMPLETED,YOU");
      gotoxy(4, 12);
     colorizedText(13);
     printf("MUST REMOVE ALL YOUR PIECES FROM YOUR PLAYROUND.");
      gotoxy(3, 14);
     colorizedText(13);
     printf("5)SIEG:IF YOU CAN ONLY BLOCK ONE OF THE OPPONENT'S ");
      gotoxy(4, 15);
     colorizedText(13);
     printf("PIECES THAT CAN NOT MOVE YOU WILL BE INTRODUCED AS");
     gotoxy(4, 16);
     colorizedText(13);
     printf("THE WINNER OF THE GAME.");
      gotoxy(3, 18);
     colorizedText(13);
     printf("6)TOW PLAYER PIECES CAN NOT BE IN THE SAME HOUSE OF");
     gotoxy(3, 19);
     colorizedText(13);
     printf("THE GAME.");
      gotoxy(3, 21);
     colorizedText(13);
     printf("7)SIMPLE MOVE:YOU CAN ONLY MOVE ONE HOUSE FRONT");
      gotoxy(4, 22);
     colorizedText(13);
     printf("OR BEHIND OR LEFT OR RIGHT AND DO IT ONLY ONCE");
      gotoxy(4, 23);
     colorizedText(13);
     printf("IN YOUR TURN.");
      gotoxy(3, 25);
     colorizedText(13);
     printf("8)JUMP:YOU CAN JUMP OVER A PLAYER AS LONG AS YOU ARE");
     gotoxy(4, 26);
     colorizedText(13);
     printf("ONLY ONE HOUSE AWAY,AND YOU CAN DO THIS SEVERAL ");
     gotoxy(4,27);
     colorizedText(13);
     printf("TIMES IN A ROUND AS LONG AS THE SITUATION ALLOWS.");
     gotoxy(3,29);
     colorizedText(13);
     printf("9)SUPER JUMP:YOU CAN ONLY JUMP OVER A BEAD FROM");
     gotoxy(4,30);
     colorizedText(13);
     printf("A DISTANCE,PROVIDED THAT THE DISTANCE BETWEEN");
     gotoxy(4,31);
     colorizedText(13);
     printf("THE BEAD AND THE BEAD IS THE SAME AND DO IT ONLY");
     gotoxy(4,32);
     colorizedText(13);
     printf("ONCE IN YOUR TURN.");
     gotoxy(3,34);
     colorizedText(13);
     printf("10)YOU MUST USE THE KEYBOARD TO MOVE THE PIECES.");
     gotoxy(3,36);
     colorizedText(13);
     printf("11)COMPUTER RIVAL OPTION,YOU CAN CHOOSE WHETHER");
     gotoxy(4,37);
     colorizedText(13);
     printf("THE PLAYER IS A HUMAN OR A COMPUTER ,AND WE PUT ");
     gotoxy(4,38);
     colorizedText(13);
     printf("THE HUMAN RIVAL OPTION CARD FOR CONVENIENCE, SO");
     gotoxy(4,39);
     colorizedText(13);
     printf("IF YOU JUST WAMTED TO PLAY WITH A HUMAN ,YOU CAN ");
     gotoxy(4,40);
     colorizedText(13);
     printf("SELECT THIS OPTION.");
}
#endif
