#include<reg51.h>
sbit relay=P0^0;
sbit sw1=P1^0;
void delay(unsigned int x);
void main()
{
	if(sw1 ==0)
	{
	relay= 0;
	}
  else{
	relay =1;
	}
}
void delay(unsigned int x)
{
	int i,j;
	for(i=0;i<x;i++)
	for(j=0;j<500;j++);
}
