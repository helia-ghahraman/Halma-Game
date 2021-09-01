#pragma once
#ifndef HEADER5_FILE
#define HEADER5_FILE

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include"important.h"

char list1[2][16],list2[2][26],list3[8][16],list5[10][16];;
char recUsername[20],recPassword[20];
int option = 0,option1 = 0,option2=2;

void loginOptions(char list1[][16]) {//chap option LOGIN va SIGNIN
	strcpy(list1[0], "    LOG IN");
	strcpy(list1[1], "   SIGN IN");
	gotoxy(88, 10);
	colorizedText(3);
	printf("%s", list1[0]);
	colorizedText(8);
	gotoxy(88, 14);
	printf("%s", list1[1]);
}
void print1(char list1[][16]) {//chap kadre menu LOGIN va SIGNIN
	const int iMenu = 9;
	const int jMenu = 30;
	char Menu[iMenu][jMenu];//araye chap khat ha
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
			else if (i > 0 && i < iMenu - 1 && i != 4) {
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
		}
	}
	//print
	int  l = 8;
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
	loginOptions(list1);
}

int moveMenu1(char list1[][16], int& option) {
	char v = getch();
	int	h = 10;
	while (v != 13) {	//choosing between options!!!
		if (_kbhit) {
			//up
			if (v == 72) {
				colorizedText(8);
				gotoxy(88, h);
				printf("%s", list1[option]);
				if (option == 0) option = 1;
				else option--;
				if (h == 10) h = 14;
				else h -= 4;
				gotoxy(88, h);
				colorizedText(3);
				printf("%s", list1[option]);
				colorizedText(8);
			}
			//down
			else if (v == 80) {
				colorizedText(8);
				gotoxy(88, h);
				printf("%s", list1[option]);
				if (option == 1) option = 0;
				else option++;
				if (h == 14) h = 10;
				else h += 4;
				gotoxy(88, h);
				colorizedText(3);
				printf("%s", list1[option]);
				colorizedText(8);
			}
		}
		v = getch();
	}
}
void user_passOptions(char list2[][26]) {//chap user va pass
	strcpy(list2[0], "username:");
	strcpy(list2[1], "password:");
	gotoxy(82, 10);
	colorizedText(3);
	printf("%s", list2[0]);
	colorizedText(3);
	gotoxy(82, 14);
	printf("%s", list2[1]);
}
void receive(char recUsername[], char recPassword[]) {//daryafte username va password
	colorizedText(8);
	gotoxy(91, 10);
	gets(recUsername);//username
	gotoxy(91, 14);
	int i = 0;
	recPassword[i] = getch();//password
	while (recPassword[i] != 13 && i < 16) {
		if (recPassword[i] == 8) {
			if (i != 0) { //this is for avoiding the ENTER instructions getting deleted 
				printf("\b");  //printing backspace to move cursor 1 pos back
				printf("%c", 32);//making the char invisible which is already on console
				printf("\b"); //printing backspace to move cursor 1 pos back
				i--;
				recPassword[i] = '\0';
				recPassword[i] = getch();
			}
		}
		else {
			printf("*");
			i++;
			recPassword[i] = getch();
		}
	}
	recPassword[i] = '\0';
}
void coding(char recUsername[], char recPassword[]){
	int uLen=0,pLen=0;
	uLen=strlen(recUsername);
	pLen=strlen(recPassword);
	
	for(i=0;i<uLen;i++)recUsername[i]+=80;
	for(i=0;i<pLen;i++)recPassword[i]+=80;
}
void print2(char list2[][26], char recUsername[], char recPassword[]) {//chap menu va guzine haye pass va user 
	const int iMenu = 9;
	const int jMenu = 40;
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
			else if (i > 0 && i < iMenu - 1 && i != 4) {
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
		}
	}
	//print
	int  l = 8;
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
	user_passOptions(list2);//chap guzine ha
	receive(recUsername, recPassword);//daryafte username va password
	coding(recUsername, recPassword);
}
int signin(char recUsername[], char recPassword[], struct player players) {//agar signin entekhab shud
	FILE *playerStatics;
	playerStatics = fopen("players.dat", "ab");
	if (!playerStatics) {
		printf("error2!");
		return 0;
	}
	strcpy(players.username, recUsername);
	strcpy(players.password, recPassword);
	players.win = 0;
	players.draw = 0;
	players.lose = 0;
	fwrite(&players, sizeof(player), 1, playerStatics);
	colorizedText(10);
	gotoxy(81, 18);
	printf("YOU ARE REGISTERED SUCCESSFULLY!");
	sleep(2000);
	fclose(playerStatics);
	return 0;
}
int login(char recUsername[], char recPassword[], struct player players) {//agar login entekhab shud
	FILE* playerStatics;
	playerStatics = fopen("players.dat", "r+b");
	if (!playerStatics) {
		printf("error1!");
		return 0;
	}
	fread(&players, sizeof(player), 1, playerStatics);
	while (!feof(playerStatics)) {
		if (strcmp(players.username, recUsername) == 0 && strcmp(players.password, recPassword) == 0) {//yaft shud!
			return 1;//yaft shud
		}
		fread(&players, sizeof(player), 1, playerStatics);
	}
	return 0;//yaft nashud
}


int log_check(char list1[][16], char list2[][26], struct player players, char recUsername[], char recPassword[], int option) {

	if (option == 0) {//login
		if (login(recUsername, recPassword, players) == 0) {
			colorizedText(12);
			gotoxy(81, 5);
			printf("USERNAME OR PASSWORD IS WRONG!");
			sleep(2000);
			clearScreen();
			return 0;
		}
	}
	else if (option == 1) signin(recUsername, recPassword, players);

	return 1;
}



#endif
