#include<reg51.h>
void delay(unsigned int x)
{
	int i,j;
	for(i=0;i<=500;i++)
	for(j=0;j<x;j++);
}
void main()
{
	unsigned int a[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
	int k;
	while(1)
	{
		for(k=0;k<10;k++)
		{
			P2=a[5];
			delay(500);
		}
	}
}
