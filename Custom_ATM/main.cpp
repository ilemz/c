#include "Custom_ATM.h"

int main()
{
	FileInput();

	while(1)
	{
		int account_num, password, staff=0;
		while(!(staff=WhoAreU()));

		if(staff == 2)
		{
			//�����ڿ� ������
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
				Ȱ���α׵� �� �� �ְ�
				ATM��� ���ᵵ �� �� �ְ�
				�� ����, ȯ�� ���� �̷��͵� �� �� �� �ְ�
				���� ���� ���� �͵� Ȯ���� �� �־����.
 				*/

			}
			continue;
		}

		//�Ϲ� ������ ������
		while(1)
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
			if(menu == 7)//ȭ�� ������
			{
				break;
			}
		}
		FileOutput();
	}
}
