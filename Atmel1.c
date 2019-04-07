#include<reg52.h>
//sfr DPTR//THIS MIGHT NOT TAKE THE USE HERE
sbit rs =P2^0;//the pins for the lcd will be taken here
sbit rw = P2^1;
sbit en = P2^2;
sbit BUSY = P1^7;//the end of the pins taken for the lcd in here
sbit CS = P2^4;//the pins for the ADC is taken in here
sbit WR = P2^5;//THE WRITE ENABLE PIN FOR THE ADC
sbit RD = P2^6;//THE READ ENABLE PIN FOR THE ADC
sbit INTR = P2^7;//the pins for the ADC0848
sbit c = P1^1;
sbit MYSWW  = P2^0;
sbit led = P3^2;
sbit led3 = P3^1;
sbit led2 = P3^0;
sbit led1 = P1^0; //the data for the led1 pin to be used as the P! port of the MICROCONTROLLER
sfr SBUF1 = 0XC1;
sfr SCON1 = 0XC0;
sfr ldata = 0x90;
sbit TI1 = 0XC1;
sbit enable1 =P1^3;
sbit enable2 = P1^4;
sbit enable3 = P1^5;
sbit enable4 = P1^6;
void delay()  //THE DELAY FUNCTION WILL BE WRITTEN IN THIS FUNCTION HERE
{
	TMOD = 0X01;
	TR2 = 0X00;
	TR2 = 1;
	TCLK = 1;
	RCLK = 1;
	while(EXF2 == 0)
	{
		TMOD = 0X23;
		TL1 = 0X09;
		TH1 = 0X90;
		TMOD = 0X01;
		TL0 = 0X00;
		TH0 = 0X35;
		while(EXF2 == 1);
		TH2 = 1;
		TL2= 0XFD;
		TH2 = 0XFF;
	}
}
void mili()
{
	TMOD = 0X01;
	TL0 = 0XFD;
	TH0 = 0X4B;
	TR0 = 1;
	while(TF0 == 0 );
	TR0 = 0;
	TF0 = 0;
}
void mili1() //WE GET THE 50ms CODE FOR THE DEALY
{
	TMOD = 0X01;
	TL0 = 0XFD;
	TH0 = 0X4D;
	TR0 = 1;
	while(TF0 == 0 );
	TR0 = 0;
	TF0 = 0;
}	
void mili500()
{
	TMOD = 0X10;
	TL1 = 0XFE;
	TH1 = 0XA5;
  TR1 = 1;	
	while(TF1 == 0);
	TR1 = 0;
	TF1 = 0;
}
//void ECU(void); //the functionality has to be learnt
void micro(void);
void make();
void delay1();
void Sertex(unsigned char x);
void numpy();
void sbufwrite(unsigned char c);
void del(unsigned int x);
void LCDREADY();
void lcd_data(unsigned char cha);
void lcd_cmd(unsigned char cha);
void print(unsigned char *str);//the code for the printing statement in the microcontroller
void dismantel();//the command for all the enable lines for the multiplexer will be according to the given command here
void inspire();
void main()//main function to run the codeded dat'a to run
{
	//sfr ldata = 0x90;
	if(led1 ==1)
	{
		numpy();
	}
	if(led1 == 0)
	{
		delay();
		TMOD = 0x20;
		TH1 = 0XFF;
		SCON = 0X50;
		TR1 = 1;
		SBUF ='A';//THE CODE FOR THE DISCIPLIN
	}
	if((led1 == 1) && (led2 == 1))
	{
		//ecu_write();
	}		
	if(led3 == 0)
	{
		make();
	}
	{
	while(1)
	{
		P1 = 0x55;
		delay();
		P1 = 0x66;
		delay();
		led1 = 1;
		mili();
		led1 = 0;
		mili();
		led1= 1;
		mili500();
		led1 = 0;
		TMOD = 0X20;
		TH1= 0XFD;
		SCON = 0X50;
		TR1 = 1;
		while(1)
		{
			Sertex('y');
			Sertex('z');
			Sertex('a');
		}
		
	}
}
}
void Sertex(unsigned char x)
{
	SBUF = x;
	while(TI == 0);
	
	TI = 0;
}
//the microsecond delay program wil be written here
void micro(void) //THE CALCULATED VALUE WILL BE 180 MICRO SECONDS APPROXIMATELY
{
	TMOD = 0X20;
	TH1 = -184;
	TR1 = 1;
	while(TF1 == 0)
	TR1 = 0;
	TF1 = 0;
}
void delay1(void)//the progra here will be writte for the 900 micro seconds
{
	TMOD = 0X01;
	if(c == 0)
	{
		TL0 =0X67;
		TH0 = 0XFC;
	}
	else
	{
		TL0 = 0X9A;
		TH0 = 0XFD;
	}
	TR0 = 1;
	while(TF0 == 0)
		TR0 = 0;
		TF0 = 0;
}
void numpy()
{
	
	unsigned char z;
	unsigned char MESS1[] = "CAN SPEED"; //THE CAN BUS SPEED CAN BE CONFIGURED IN THE CODE
	unsigned char MESS2[] = "LIN SPEED";//THE LIN SPPED IS BEING CONFIGURED FOR THE DATA TRANSMISSION
	TMOD = 0X20;
	TH1 = 0XFF;
	SCON = 0X50;
	TR1 = 1;
	if(MYSWW == 0)
	{
		for(z = 0 ;z<12 ;z++)
		{
			SBUF = MESS1[z];
			while(TI == 0)
			TI = 0;
		}
	}
	else
	{
		PCON = PCON |0X80; // THANKS FOR THE SYNTAX
		for(z = 0 ; z < 10 ; z++)
		{
			SBUF = MESS2[z];
			while(TI == 0);
				TI = 0;
		}
	}
}
void ecu_write()
{
	TMOD = 0X20;
	TH1 =0XFA;
	SCON1 = 0X50;
	TR1 = 1;
	while(1)
	{
		if(led3 == 1)
		{
		SBUF = 'A';
		while(TI == 0);
			TI = 0;
		}
		else
		{
			SBUF ='B';
			while(TI == 0);
			TI = 0;
		}
	}
}
void make()
{
	if(led==1)
	{
		led1 = 1;
		TMOD =0X20;
		TH1 = 0X30;
		SCON = 0X50;
		TR1 = 1;
		sbufwrite('e');
		mili500();
		sbufwrite('f');
		mili500();
		sbufwrite('h');
		mili500();
		sbufwrite('s');
		mili500();
		sbufwrite('i');
	}
	else
	{
		TMOD = 0X20;
		TH1 = 0X30;
		SCON = 0X50;
		TR1= 0;
		sbufwrite('v');
	}
}
void sbufwrite(unsigned char c)
{
	SBUF = c;
	while(TI == 0);
	TI =0;
	TF1 = 0;
}
void adc()
{
	unsigned char value;
	INTR = 1;
	CS = 1;
	WR = 1;
	RD = 1;
	while(1)
	{
		P1 = 0X0A;
		CS = 0;
		WR = 0;
		delay();
		WR = 1;
		CS = 1;
		P1 = 0xFF;
		while(INTR == 1);
		{
			CS = 0;RD =0;
			delay();
			RD =1;
			value = P1;
			CS = 1;
		  //THE PRINT FUNCTION HAS TO BE WRITTEN HERE
		}
	}
}
void lcd_cmd(unsigned char cha) //here we will take the chzrecter into the consideration
{
	//sfr ldata = 0x90;
	LCDREADY();
	ldata = cha;
	rs = 0;
	rw = 0;
	en = 1;
	del(1);
	en = 0;
	return;
}
	
	
void lcd_data(unsigned char cha)//here aslo the charecter is being considerd
{
	LCDREADY();
	ldata = cha;
	rs = 1;
	rw = 0;
	en = 1;
	del(1);
	en =0;
	return;
}

void LCDREADY()
{
	BUSY = 1;
	rs =0;
	rw =1;
	while(BUSY == 1)
	{
		en =0;
		del(1);
		en =1;
	}
	return;
}
void print(unsigned char *str)//the code for the printing statement in the microcontroller
{
	char str1=++str;
	str = *++str;
}
void del(unsigned int x)//the delay that dont use timer but uses the processor for the for loop operation
{
	int i,j;
	for( i = 0 ; i < x ; i++);
	for(j=0;j<1275;j++);
}
void dismantel()//the command for all the enable lines for the multiplexer will be according to the given command here
{
	print("dismantelled");
	enable1 = 1;
	enable2 =1;
	enable3 =1;
	enable4 =1;
}
void inspire()
{
	int i,j;
	for(i = 0 ; i < 1000 ; i++);
	P1 = 0XAD;
	del(1000);
	P1 = 0XAB;
}