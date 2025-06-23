/*
Monopoly.c
*/

#include "monopoly.h"

void init_board(Board *board)
{
	board[0].owner=0;
	board[0].ishere[0]=HERE;
	board[0].ishere[1]=HERE;
	board[0].ishere[2]=HERE;
	board[0].ishere[3]=HERE;
	board[0].ishere[4]=HERE;
	board[0].ishere[5]=HERE;
	for(int i=1;i<_boardsize;i++)
	{
		board[i].owner=0;
		for(int j=0;j<_maxplayer;j++)board[i].ishere[j]=NOTHERE;
	}
	
	mystrcpy(board, 1, "참다랑어", 100);
	mystrcpy(board, 2, "가다랑어", 110);
	mystrcpy(board, 3, "간고등어", 150);
	mystrcpy(board, 4, "백상아리", 240);
	mystrcpy(board, 5, "참돌고래", 420);
	mystrcpy(board, 6, "바다거북", 230);
	mystrcpy(board, 7, "하프물범", 140);
	mystrcpy(board, 8, "메갈로돈", 1000);
	mystrcpy(board, 9, "독가오리", 200);
	mystrcpy(board, 10, "피라루쿠", 500);
	mystrcpy(board, 11, "혼마구로", 300);
	mystrcpy(board, 12, "까치상어", 140);
	mystrcpy(board, 13, "피라니아", 160);
	mystrcpy(board, 14, "귀신고래", 230);
	mystrcpy(board, 15, "혹등고래", 210);
	mystrcpy(board, 16, "수염고래", 130);
	mystrcpy(board, 17, "젠투팽귄", 420);
	mystrcpy(board, 18, "황제팽귄", 220);
	mystrcpy(board, 19, "고리문어", 540);
	mystrcpy(board, 20, "가시복어", 300);
	mystrcpy(board, 21, "철갑상어", 290);
	mystrcpy(board, 22, "갑오징어", 410);
	mystrcpy(board, 23, "대왕문어", 250);
	mystrcpy(board, 24, "세발낙지", 270);
	mystrcpy(board, 25, "고래상어", 170);
	mystrcpy(board, 26, "귀상아리", 190);
	mystrcpy(board, 27, "청상아리", 360);
	mystrcpy(board, 28, "장수거북", 560);
	mystrcpy(board, 29, "바다장어", 730);
	mystrcpy(board, 30, "디아루가", 620);
	mystrcpy(board, 31, "파루키아", 310);
	mystrcpy(board, 32, "기라티나", 610);
	mystrcpy(board, 33, "다크라이", 510);
	mystrcpy(board, 34, "레시라무", 660);
	mystrcpy(board, 35, "제크로무", 720);
	mystrcpy(board, 36, "가이오가", 610);
	mystrcpy(board, 37, "환도상어", 460);
	mystrcpy(board, 38, "찌르호크", 260);
	mystrcpy(board, 39, "닥터피쉬", 100);
}

void mystrcpy(Board*board, int dest, char src[], int prize)
{
	strcpy(board[dest].name, src);
	board[dest].prize = prize;
	return; 
}

void print_board(Board *board, Player *player)
{
	int i;
	int player_num = 0;
	
	system("cls");
	
	printf("______________________________________________________________________________________________________________\n");
	
	for(i=20;i<=30;i++)
	{
		printf("|%s|",board[i].name);
	}
	puts("");
	
	
	for(i=20;i<=30;i++)
	{
		printf("|    %d   |", board[i].owner); 
	}
	
	puts("");
	
	for(i=20;i<=30;i++)
	{
		int j;
		
		printf("|_"); 
		
		for(j=0;j<6;j++)
		{
			if(board[i].ishere[j]==1){
				printf("%d",j+1);
			}
			
			else{
				printf("_");
			}
		}
		
		printf("_|");
	}
	
	
	printf("\n|________|__________________________________________________________________________________________|________|");

	puts("");

	for(i=19;i>=11;i--)
	{
		int j;
		
		if(19-i<6)
		{
			printf("|%s|Player %d : %3d$\t\t\t\t\t\t\t\t\t    |%s|\n",board[i].name, 20-i, player[19-i].money, board[50-i].name);
			
			printf("|    %d   |\t\t\t\t\t\t\t\t\t\t\t    |    %d   |\n", board[i].owner, board[50-i].owner);
		}
		else
		{
			printf("|%s|\t\t\t\t\t\t\t\t\t\t\t    |%s|\n",board[i].name, board[50-i].name);
			
			printf("|    %d   |\t\t\t\t\t\t\t\t\t\t\t    |    %d   |\n", board[i].owner, board[50-i].owner);	
		}
		 
		printf("|_");
		
		for(j=0;j<6;j++)
		{
			if(board[i].ishere[j]){
				printf("%d",j+1);
			}
			
			else{
				printf("_");
			}
		}
		
		printf("_|");
		
		printf("\t\t\t\t\t\t\t\t\t\t\t    ");
		
		printf("|_");
			
		for(j=0;j<6;j++)
		{
			if(board[50-i].ishere[j]){
				printf("%d",j+1);
			}
			
			else{
				printf("_");
			}
		}
		
		printf("_|");
		
		puts("");
	}
	
	printf("|________|__________________________________________________________________________________________|________|\n");
	
	for(i=10;i>=0;i--)
	{
		printf("|%s|",board[i].name);
	}
	
	puts(""); 
	
	for(i=10;i>=0;i--)
	{
		printf("|    %d   |",board[i].owner); 
	}
	
	puts("");
		
	for(i=10;i>=0;i--)
	{
		int j;
		
		printf("|_");
		
		for(j=0;j<6;j++)
		{
			if(board[i].ishere[j]){
				printf("%d",j+1);
			}
			
			else{
				printf("_");
			}
		}
		
		printf("_|");
	}
	
	puts("");
	
	printf("|____________________________________________________________________________________________________________|");
	puts("");
}
