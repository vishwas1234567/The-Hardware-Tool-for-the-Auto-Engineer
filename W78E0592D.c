#include<reg51.h>
void delay(unsigned int x)
{
	int i,j;
	for(i=0;i<x;i++);
	for(j=0;j<1275;j++);
}
void main()
{
	P0 = 0XFFFF;
	delay(100);
	P1 = 0XFFFF;
	delay(100);
	P2 = 0XFFFF;
	delay(1000);
	P3 = 0XFFFF;
	delay(1000);
}
	