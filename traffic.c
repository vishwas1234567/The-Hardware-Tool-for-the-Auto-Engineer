#include<reg51.h>
sbit red =P0^0;
sbit yellow=P0^1;
sbit greeen = P0^2;
void delay(unsigned int x);
void main()
{
	yellow=0;
	greeen= 0;
	red = 1;
	delay(1000);
	red= 0 ;
	greeen=0;
	yellow = 1;
	delay(900);
	yellow=0;
	red = 0;
	greeen =1;
	delay(1200);
}
	
void delay(unsigned int x)
{
	int i,j;
	for(i=0;i<=x;i++)
	for(j=0;j<200;j++);
}