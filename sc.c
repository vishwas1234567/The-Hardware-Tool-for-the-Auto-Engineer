#include<reg51.h>
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
	
	TX(a);
	string("GOUTHAM");
	//while(1);
}
}