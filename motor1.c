#include<reg51.h>
sbit motor = P0^0;
void delay(unsigned int x)
{
	int i,j;
	for(i=0;i<=x;i++);
}
void main()
{
	motor=1;
	delay(1000);
	motor =0;
	delay(180);
}