#include<reg51.h>
void delay(int k)
{
	int i,j;
	for(i=0;i<k;i++)
	for(j=0;j<1275;j++);
}
void main()
{
	unsigned char i;
	unsigned char arr[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67};
	P1=0x00;
	while(1)
	{
		for(i=0;i<10;i++)
		{
			P1 = arr[i];
			delay(100);
		}
	}
}
