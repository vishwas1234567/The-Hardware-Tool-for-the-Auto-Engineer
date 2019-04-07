#include<reg51.h>
sbit led1=P0^0;
sbit led2=P0^1;
sbit led3=P0^2;
sbit led4=P0^3;
sbit led5=P0^4;
sbit lvdt=P0^5;
sbit buzzer=P0^7;

void TX(unsigned char x)
{
	SBUF=x;
	while(TI==0);
	TI=0;
}
unsigned char RX()
{
	unsigned char y;
	while(RI==0);
	y=SBUF;
	RI=0;
	return y;
}
void string(unsigned char *s)
{
	while(*s!=0)
	{
	TX(*s);
	s++;
	}
}
void main()
{
	unsigned char a;
	SCON=0x50;
	TMOD=0x20;
	TR1=1;
	TH1=0xFD;
while (1)
{
	a=RX();
	if(a =='a')
	{
		led2=0;
		led3=0;
		led4=0;
		led5=0;
		led1=~led1;
		buzzer=0;
	lvdt=0;
	}
	else if(a=='b')
	{
		led1=0;
		led3=0;
		led4=0;
		led5=0;
		led2=~led2;
		lvdt=0;
		buzzer=0;
	}
	else if(a=='c')
	{
		led2=0;
		led1=0;
		led4=0;
		led5=0;
		led3=~led3;
		buzzer=0;
	lvdt=0;
	}
	else if(a=='d')
	{
		led2=0;
		led3=0;
		led1=0;
		led5=0;
		led4=~led4;
		buzzer=0;
		lvdt=0;
	}
	else if(a=='e')
	{
		led2=0;
		led3=0;
		led4=0;
		led1=0;
		led5=~led5;
		buzzer=0;
		lvdt=0;
	}
	else
		{
		buzzer =1;
		lvdt=1;
		}
		
	TX(a);
	string("GOUTHAM\n HARSHITA\n VISHWAS\n");
	//while(1);
}
}
