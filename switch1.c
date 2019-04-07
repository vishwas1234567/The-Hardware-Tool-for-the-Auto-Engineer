#include<reg51.h>
sbit sw1=P0^0;
sbit sw2=P0^1;
sbit sw3=P0^2;
sbit led=P1^0;
sbit buzzer=P1^1;
sbit motor=P1^2;
void main()
{
	sw1 = sw2 = sw3 =0;
	while(1)
	{
	if(sw1==1)
{
led=1;
}
else if(sw2==1)
{
buzzer=1;
}
else if(sw3==1)
{
motor=1;
}
else
{
	
led=0;
buzzer=0;
motor=0;
}
}
}