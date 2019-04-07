#include<reg51.h>
#define led P1
#define led1 P2
void delay(unsigned int x)
{
	int i,j;
	for(i=0;i<=x;i++)
	for(j=0;j<500;j++);
}
void main()
{
	led=0X00;
	while(1)
	{
		led=0xFF;
		led1=0xab;
		delay(1000);
		led =0x00;
		led1=0x0F;
		delay(1000);
		led=0x0A;
		led1=0x00;
		delay(1000);
	}
}
