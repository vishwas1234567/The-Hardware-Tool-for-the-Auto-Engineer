#include<reg51.h>
#define lcd_port P1
sbit rs=P3^5;
sbit en=P3^4;
void delay(unsigned int x)
{
	int i,j;
	for(i=0;i<x;i++)
	for(j=0;j<500;j++);
}
void lcd_cmd(unsigned char a)
{
	rs=0;
	delay(10);
	lcd_port=a;
	en=1;
	delay(10);
	en=0;
}
void lcd_data(unsigned char b)
{
	rs=1;
	delay(10);
	lcd_port=b;
	delay(10);
	en=1;
	delay(10);
	en=0;
}
void lcd_string(unsigned char *s)
{
	while(*s != 0)
	{
		lcd_data(*s);
	}
}
void main()
{
	lcd_cmd(0x38);
	lcd_cmd(0x01);
	lcd_cmd(0x06);
	lcd_cmd(0x0c);
	lcd_cmd(0x80);
	while(1)
	{
		lcd_cmd(0x01);
		lcd_string("hello world\0");
		delay(1000);
		lcd_string("helloworld\0");
		lcd_cmd(0x01);
	}
}