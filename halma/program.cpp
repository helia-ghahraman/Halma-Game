#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "important.h"
#include"bead_map.h"
#include"endgame.h"
#include"Movement.h"
#include"log_sign.h"
#include"main_menu.h"
#include"play_game.h"
#include"selection.h"
//sw ta 1 nashavad nubat taghir nemikunad.
//again tedad harkate yek mohre dar yek nubat ast.
//yesNo[5] tamayul be jump haye motavali.
//beadPos[25] chideman avvaliye muhre ha(1 2 3 4 3 OR 1 2 3 4 5 4 ).
//temp mohtaviyate khanei ke pointer dar aan ast.
//charecter = ra az reshte mikhanad.
//string unvan ra az file  vorodi(config) mikhanad.
/*swWinner2 : zira winner2=20 dar 2 halate bazi 2 nafare va 4 nafare mani mutafavet darad( dar 4 nafare aval 0 ast,
baad 20 ya 40 ya 240 mishavad ama dar bazi 2 nafare az avval 20 ast ta nubat ha durust becharkhand.vali dar GS_update 
baese moshkel mishavad va bazi ha ra hatta agar kamel nabashand be amar ezafe mikunad*/
int main(){
	//int flagArray[40][60] = { 0 };
	int sw1 = 1, sw2 = 1, sw3 = 1, sw4 = 1,v, k;
	int sw5=1,sw6 = 0, swWinner2;
	
	while(sw5==1){//agar eshtebah zad dar login, dubare entekhab kune.
		//menu login va signin
		print1(list1);
		moveMenu1(list1,option);
		//menu username 
		print2(list2,recUsername,recPassword);
		if(log_check(players,recUsername,recPassword,option)!=0)sw5=0;
	}
	clearScreen();
	
	while (sw6 == 0) {//main menu
        print3(list3);
        moveMenu2(list3, option1, recUsername, recPassword);
        selection(/*flagArray,*/swWinner2,option1,beadPos, recUsername, recPassword, sw6,color,board,n,pnum,games,turn,pCo);
    }
	return 0;
}
/*Ferdowsi University of Mashhad*//*Our First Big Project*/
/*Helia Ghahraman B| Yasamin Azizi =) Yasaman Hamedtabei :D */
/*20210205*//*1:44 am*/
