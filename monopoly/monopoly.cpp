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
	
	mystrcpy(board, 1, "���ٶ���", 100);
	mystrcpy(board, 2, "���ٶ���", 110);
	mystrcpy(board, 3, "������", 150);
	mystrcpy(board, 4, "���Ƹ�", 240);
	mystrcpy(board, 5, "������", 420);
	mystrcpy(board, 6, "�ٴٰź�", 230);
	mystrcpy(board, 7, "��������", 140);
	mystrcpy(board, 8, "�ް��ε�", 1000);
	mystrcpy(board, 9, "��������", 200);
	mystrcpy(board, 10, "�Ƕ����", 500);
	mystrcpy(board, 11, "ȥ������", 300);
	mystrcpy(board, 12, "��ġ���", 140);
	mystrcpy(board, 13, "�Ƕ�Ͼ�", 160);
	mystrcpy(board, 14, "�ͽŰ�", 230);
	mystrcpy(board, 15, "Ȥ���", 210);
	mystrcpy(board, 16, "������", 130);
	mystrcpy(board, 17, "�����ر�", 420);
	mystrcpy(board, 18, "Ȳ���ر�", 220);
	mystrcpy(board, 19, "������", 540);
	mystrcpy(board, 20, "���ú���", 300);
	mystrcpy(board, 21, "ö�����", 290);
	mystrcpy(board, 22, "����¡��", 410);
	mystrcpy(board, 23, "��չ���", 250);
	mystrcpy(board, 24, "���߳���", 270);
	mystrcpy(board, 25, "�����", 170);
	mystrcpy(board, 26, "�ͻ�Ƹ�", 190);
	mystrcpy(board, 27, "û��Ƹ�", 360);
	mystrcpy(board, 28, "����ź�", 560);
	mystrcpy(board, 29, "�ٴ����", 730);
	mystrcpy(board, 30, "��Ʒ簡", 620);
	mystrcpy(board, 31, "�ķ�Ű��", 310);
	mystrcpy(board, 32, "���Ƽ��", 610);
	mystrcpy(board, 33, "��ũ����", 510);
	mystrcpy(board, 34, "���ö�", 660);
	mystrcpy(board, 35, "��ũ�ι�", 720);
	mystrcpy(board, 36, "���̿���", 610);
	mystrcpy(board, 37, "ȯ�����", 460);
	mystrcpy(board, 38, "�ȣũ", 260);
	mystrcpy(board, 39, "�����ǽ�", 100);
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
