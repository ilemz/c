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
			//관리자용 선택지
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

		//일반 유저용 선택지
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
			if(menu == 7)//화면 나가기
			{
				break;
			}
		}
		FileOutput();
	}
}
