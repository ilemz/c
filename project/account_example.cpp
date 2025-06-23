#include<stdio.h>
#include<string.h>
#include<conio.h>

#define LIST_MAX 100

struct account{
	int account_num;
	char password[20];
	int balance;
	char user_name[10];
	int isOP;
}account_list[LIST_MAX];

int people_num;
int index=-1;

void FileInput()
{
	FILE *f ;
	f = fopen("input.txt","r");
	
	fscanf(f,"%d",&people_num);
	
	int i;
	
	for(i=0;i<people_num;i++)
	{
		fscanf(f,"%d",&account_list[i].account_num);
		fscanf(f,"%s",account_list[i].password);
		fscanf(f,"%d",&account_list[i].balance);
		fscanf(f,"%s",account_list[i].user_name);
		fscanf(f,"%d",&account_list[i].isOP);
	}
	
	fclose(f);
}

void FileOutput()
{
	FILE *f;
	f = fopen("input.txt","w");
	
	fprintf(f,"%d\n",people_num);
	
	int i;
	
	for(i=0;i<people_num;i++)
	{
		fprintf(f,"%d ",account_list[i].account_num);
		fprintf(f,"%s ",account_list[i].password);
		fprintf(f,"%d ",account_list[i].balance);
		fprintf(f,"%s ",account_list[i].user_name);
		fprintf(f,"%d\n",account_list[i].isOP);
	}
	
	fclose(f);
}

void log(int user, char *option_name, int body)
{
	FILE *f;
	f = fopen("log.txt","a");
	
	fprintf(f,"%s ",option_name);
	fprintf(f,"%d ",user);
	fprintf(f,"%d\n",body);
	
	fclose(f);
}

void staff_check_f()
{
	FILE *f;
	f = fopen("log.txt","r");
	
	//fscanf(f,"");
	//print("");
	fclose(f);
}

int WhoAreU()
{
	int account_num;
	char password[20];
	int i;
	
	printf("Enter your account number : ");
	scanf("%d",&account_num);
	
	for(i=0;i<people_num;i++)
	{
		if (account_num==account_list[i].account_num)
		{
			index = i;
			break;
		}
	}
	
	if (index==-1)
	{
		printf("Wrong account.\n");
		return 0;
	}
	
	printf("Enter your password : ");
	i=0;
	while(1)
	{
		password[i] = getch();
		if(password[i] == 13)
		{
			password[i]=0;
			puts("");	
			break;
		}
		if(password[i] == '\b')
		{
			printf("%\b \b");
			password[i--]=0;
			continue;
		}
		i++;
		printf("*");
	}
	
	if (strcmp(password,account_list[index].password)==0)
	{
		printf("Welcome, %s.\n",account_list[index].user_name);
		if(account_list[index].isOP)
		{
			return 2;
		}
		return 1; 
	}
	else
	{
		printf("Wrong password.\n");	
		return 0;
	}
}

void deposit(){
	int d_money;
	int will_you_d;

	printf("Will you deposit?\n1.Yes 2.No : ");
	scanf("%d",&will_you_d);
	
	if(will_you_d==1)
	{
		printf("How much will you deposit? : ");
		scanf("%d",&d_money);
		
		account_list[index].balance+=d_money;
		
		printf("Success to deposit.\n");
	}
	else if(will_you_d==2)
	{
		printf("Return to menu.\n");
	}
	else
	{
		printf("Please try again.\n");
		return;
	}
	char s[10]="Deposit";
	log(account_list[index].account_num, s, d_money);
	return;
}

void withdraw(){
	int wd_money;
	int will_you_wd;
	
	printf("will you withdraw?\n1.Yes 2.No : ");
	scanf("%d",&will_you_wd);
	
	if(will_you_wd==1)
	{
		printf("How much will you withdraw? : ");
		scanf("%d",&wd_money);
		
		account_list[index].balance-=wd_money;
		
		printf("Success to withdraw.\n");
	}
	else if(will_you_wd==2)
	{
		printf("Return to menu.\n");
	}
	else
	{
		printf("please try again.\n");
		return;
	}
	char s[10]="Withdraw";
	log(account_list[index].account_num , s, wd_money);
	return;
	
}

void check_balance(){
	int will_you_cb;
	
	printf("Will you check your balance?\n1.Yes 2.No : ");
	scanf("%d",&will_you_cb);
	
	if(will_you_cb==1)
	{
		printf("Your balance is %d.\n",account_list[index].balance);
	}
	else if(will_you_cb==2)
	{
		printf("Return to menu.\n");
	}
	else
	{
		printf("Please try again.\n");
		return;
	}
	char s[14]="Check Balance";
	log(account_list[index].account_num, s, will_you_cb);
	return;
	
}

void send(){
	int s_money;
	int will_you_s;
	
	printf("Will you send money?\n1.Yes 2.No : ");
	scanf("%d",&will_you_s);
	
	if(will_you_s==1)
	{
		int account_num,password;
		int search=-1;
		int i;
		
		printf("How much will you send? : ");
		scanf("%d",&s_money);
		
		printf("Enter account number : ");
		scanf("%d",&account_num);
		
		for(i=0;i<people_num;i++)
		{
			if (account_num==account_list[i].account_num)
			{
				search = i;
			
				printf("Sending to %s\n.",account_list[search].user_name);
				break;
			}
			
		}
		
		if (search==-1)
		{
			printf("Wrong account.\n");
			return;
		}
		
		account_list[index].balance-=s_money;
		account_list[search].balance+=s_money;
	}
	else
	{
		printf("Please try again.");
		return;
	}
	char s[10]="Send to";
	log(account_list[index].account_num, s, s_money);
	return;
}
/*
void lent(){
	int l_money;
	int will_you_i;
	
	
	
	break:
}

void exchange(){
	
	break:
}
*/

void check_body()
{
	FILE *f;
	f = fopen("log.txt","r");
	
	while(0 == feof(f))
	{
		char s[20];
		int a,b;
		fscanf(f,"%s",s);
		fscanf(f,"%d",&a);
		fscanf(f,"%d",&b);
		printf("%s ",s);
		printf("%d ",a);
		printf("%d\n",b);
	}
	
	fclose(f);
}


int main()
{
	FileInput();
	
	while(true)
	{
		int account_num, password, staff=0;
		while(!(staff=WhoAreU()));
		
		if(staff == 2)
		{
			while(1)
			{
				int i;
				int s_w_d;
				int Body, ATM, money, Exchange_R, Loan_H;
				
				printf("What will you do?\n1.Check Body\n2.Control ATM\n3.Change money\n4.Change Exchange Rate\n5.Check Loan History\n6.Close : ");
				scanf("%d",&s_w_d);
				switch(s_w_d)
				{
					case 1:{
						check_body();
						break;			
					}/*
					case 2:{
						withdraw();
						break;
					}
					case 3:{
						check_balance();
						break;
					}
					case 4:{
						send();
						break;
					}
					case 5:{
						lent();	
						break;
					}*/
					default:{
						break;
					}
				}
				if(s_w_d == 6)break;
								
				/*
				활동로그도 알 수 있고
				ATM기기 종료도 할 수 있고
				돈 조정, 환율 조정 이런것들 도 할 수 있고
				대출 내역 같은 것도 확인할 수 있어야함.
 				*/
 				
			}
			continue;
		}
		
		while(true)
		{
			int menu;
			
			printf("What will you do?\n"
			"1.Deposit\n2.Withdraw\n3.Check Balance\n4.Send\n5.Lent\n6.Exchange\n7.Exit\n");
			scanf("%d",&menu);
			
			switch(menu)
			{
				case 1:{
					deposit();
					break;			
				}
				case 2:{
					withdraw();
					break;
				}
				case 3:{
					check_balance();
					break;
				}
				case 4:{
					send();
					break;
				}/*
				case 5:{
					lent();
					break;
				}
				case 6:{
					exchange();
					break;
				}*/
				default:{
					break;
				}
			}
			if(menu == 7)
			{
				break;
			}
		}
		FileOutput();
	}
}	
