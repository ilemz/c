/*
Monopoly.h
모노폴리에 대한 전반적인 내용을 담고있다.
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define _boardsize 40
#define _maxplayer 6
#define _maxnamelegnth 20
#define HERE 1
#define NOTHERE 0

typedef struct gameboard{
	char name[_maxnamelegnth];
	int prize;
	int ishere[_maxplayer];
	int owner;
}Board;

typedef struct playerinfo{
	int location;
	int money;
}Player;

void init_board(Board *board);
void print_board(Board *board, Player *player);
void mystrcpy(Board*board, int dest, char src[], int prize);
 
