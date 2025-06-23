#include<stdio.h>

int main()
{
	int d[40];
	int i;
	for(i=0;i<40;i++)
	{
		d[i]=i+1;
	}
	
	for(i=20;i<=30;i++)
	{
		printf(" %2d  ",d[i]);
	}
	puts("");
	for(i=20;i<=30;i++)
	{
		printf("here ");
	}
	puts("");
	for(i=19;i>=11;i--)
	{
		printf(" %2d\t\t\t\t\t\t   %2d\n",d[i],d[50-i]);
		printf("here\t\t\t\t\t\t  here\n");
	}
	for(i=10;i>=0;i--)
	{
		printf(" %2d  ",d[i]);
	}
	puts("");
	for(i=10;i>=0;i--)
	{
		printf("here ");
	}
	puts("");
}
