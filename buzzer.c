#include<reg51.h>
sbit led=P0^0;
sbit buzzer = P0^1;
void delay(unsigned int x)
{
	int i,j;
	for(i= 0 ;i<=x ;i++)
	for(j =0;j<500;j++);
}
void main()
{
	int i;
	for(i=0 ;i<=10 ;i++)
	{
	led =1;
	buzzer =1;
	delay(100);
	led =0;
	buzzer =0;
	delay(1000);

	}
	buzzer =1;
}