#include<reg51.h>
sbit led1=P0^0;
sbit led2=P0^1;
sbit led3=P0^2;
sbit led4=P0^3;
sbit led5=P0^4;
	void delay(unsigned int x)
	{
		int i,j;
		for(i=0;i<=x;i++);
		for(j=0;j<1000;j++);

	}
void main()
	{
		led1=1;
		delay(1000);
		led1=0;
		delay(1000);
				led2=1;
		delay(1000);
		led2=0;
		delay(1000);
				led3=1;
		delay(1000);
		led3=0;
		delay(1000);
				led4=1;
		delay(1000);
		led4=0;
		delay(1000);
				led5=1;
		delay(1000);
		led5=0;
	delay(1000);
		
	}
