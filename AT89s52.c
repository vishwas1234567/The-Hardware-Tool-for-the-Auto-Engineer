#include<reg52.h>
void delay();
void main()
{
	while(1)
	{
		P1 = 0x55;
		delay();
		P1 = 0x66;
		delay();
	}
}
void delay()
{
	TMOD = 0X01;
	TL0= 0X00;
	TH0 = 0X35;
	TR0 = 1;
while(TF0 == 0 );
TR0 = 0;
TF0 = 0;
}	
	