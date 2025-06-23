#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include"monopoly.h"

int roll_the_dice();

int main()
{
	srand((unsigned int)time(NULL));
	
	Board board[_boardsize]={
		{" Start! ",0,{0,0,0,0,0,0}},
	};
	init_board(board);
	
	Player player[_maxplayer]={
		{0,500}, {0,500}, {0,500},
		{0,500}, {0,500}, {0,500}};

	print_board(board,player);
	
	int player_num=0;
	while(1)
	{
		int dice = roll_the_dice(), i;
		char a;
		
		board[player[player_num].location].ishere[player_num] = NOTHERE;
		
		player[player_num].location += dice;
		
		if(player[player_num].location>=40)
		{
			printf("You've got 100$ more, Player no.%d!\n", player_num);
			
			player[player_num].money = player[player_num].money + 100;
		}
		
		player[player_num].location %= 40;

		board[player[player_num].location].ishere[player_num] = HERE;
		
		print_board(board,player);
		
		if(player[player_num].location == 0)
		{
			player_num+=1;
			player_num%=6;
			
			continue;
		}
		
		printf("Will you buy it?(y/n) : ");
			
		scanf(" %c", &a);
			
		if(a == 'y')
		{
			if(board[player[player_num].location].owner > 0)
			{
					if(player[player_num].money >= board[player[player_num].location].prize *2)
					{
						printf("You'll pay twice more then first time.");
						
						player[player_num].money = player[player_num].money - (board[player[player_num].location].prize) *2;
						
						board[player[player_num].location].owner = player_num+1;
					}
			}
			
			else if(player[player_num].money >= board[player[player_num].location].prize)
			{
				player[player_num].money = player[player_num].money - board[player[player_num].location].prize;
				
				board[player[player_num].location].owner = player_num+1;
			}
			 
			else{
				printf("You don't have enough money to buy it.");
			}	
		}
		
		if(player[player_num].money == 0)
		{
			board[player[player_num].location].ishere[player_num] = NOTHERE;
			
		}
		
		system("pause");
		
		player_num+=1;
		player_num%=6;
	}
}

int roll_the_dice()
{
	int Dice1 = rand()%6+1, Dice2 = rand()%6+1;	

	return Dice1 + Dice2; 
}
