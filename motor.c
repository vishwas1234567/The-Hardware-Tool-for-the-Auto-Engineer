#include<reg51.h>
sbit motor = P0^0;
void delay(unsigned int x)
{
	int i,j;
	for(i=0;i<=x;i++)
	for(j=0;j<300;j++);
}
void main()
{
	int z;
	for(z =0;z<=9;z++)
	{
	motor=1;
	delay(1000);
	motor =0;
	delay(180);
}
	motor=1;
	delay(100000);
	
	}