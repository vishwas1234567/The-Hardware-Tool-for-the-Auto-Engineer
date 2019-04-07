#include<reg51.h>
sbit sw1=P0^0;
sbit led=P1^0;
sbit buzzer=P1^1;
sbit m1=P1^2;
void delay(unsigned int x)
{
	int i,j;
	for(i=0;i<=x;i++)
	for(j=0;j<500;j++);
}
void main()
{
	sw1=1;
	while(1)
	{
	if(sw1==0)
	{
		led=1;
		buzzer=1;
		m1=1;
		//delay(100);
		//led=1;
	}
	else
	{
		led=0;
		buzzer=0;
		m1=0;
}
	}
}
	