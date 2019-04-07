#include<reg51.h>
sbit relay=P0^0;
void delay(unsigned int x);
void main()
{
	relay= 1;
	delay(1000);
	relay =0;
}
void delay(unsigned int x)
{
	int i,j;
	for(i=0;i<x;i++)
	for(j=0;j<500;j++);
}
